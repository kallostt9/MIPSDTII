/*
 * main.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>
#include "adder.cpp"
#include "alu_control.cpp"
#include "Alu.cpp"
#include "control.cpp"
#include "instruction_memory.cpp"
#include "memory.cpp"
#include "mux.cpp"
#include "mux5bit.cpp"
#include "pc.cpp"
#include "Register.cpp"
#include "shifter.cpp"
#include "sign_extend.cpp"
#include "main.h"

void main::mainM(void){
	//instr_address = 0x00000000;
	switch (s) {
	case running:
		en = ck;
		break;
	default:
		en = sc_logic_0;
		break;
	}
	if (ck.event() and ck == sc_logic_1) {
		switch (s) {
			case loading:
				s = running;
				break;
			case running:
				if (instr_address.read().to_uint()> last_instr_address.read().to_uint()) {
					s = done;
					en = sc_logic_0;
				}break;
			default:
				break;
		}
	}
}
/*
void main::mainM(void){
	switch(s){
		case running:
			en = ck;
			break;
		default:
			en = sc_logic_0;
			break;
	}
	if(ck.event() and ck == sc_logic_1){
		switch(s){
			case loading:
				s = running;
				break;
			case running:
				if(instr_address.read().to_uint() > last_instr_address.read().to_uint()){
					s = done;
					en = sc_logic_0;
				}break;
			default:
				break;
		}
	}
}*/

int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("mainTrace");
	trace_file->set_time_unit(1, SC_NS);
	//ports

	sc_signal<sc_logic> ck;
	sc_signal<sc_lv<32>> instr_address, next_address, instruction;
	sc_signal<sc_lv<32>> read_data_1, read_data_2, write_data, extended_immediate, shifted_immediate, alu_in_2, alu_result,
	last_instr_address, incremented_address, add2_result, mux4_result, concatenated_pc_and_jump_address, mem_read_data;
	sc_signal<sc_lv<28>> shifted_jump_address;
	sc_signal<sc_lv<26>> jump_address;
	sc_signal<sc_lv<16>> immediate;
	sc_signal<sc_lv<6>> opcode, funct;
	sc_signal<sc_lv<5>> rs, rt, rd, shampt, write_reg;
	sc_signal<sc_lv<4>> alu_control_funct;
	sc_signal<sc_lv<2>> alu_op;
	sc_signal<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_zero, branch_and_alu_zero;
	sc_signal<sc_logic> en;
	sc_signal <sc_lv<32>> shifter2X, shifter2Y, shifter1Y;
/*
	shifter2X.write(0x00000000 ^ jump_address.read().range(25,0));
	shifter2Y.write(0x00000000 ^ shifted_jump_address.read().range(27, 0));
	shifter1Y = 0x00000004;
	last_instr_address = 0x00000000;
	instr_address.write(0x00000000);

	read_data_1 = read_data_2 = instr_address = write_data = extended_immediate = shifted_immediate = alu_in_2 = alu_result =
	incremented_address = add2_result = mux4_result = concatenated_pc_and_jump_address = mem_read_data = 0x00000000;
	en = sc_logic_0;
	reg_dest = jump = branch = mem_read = mem_to_reg = mem_write = alu_src = reg_write = alu_zero = branch_and_alu_zero = sc_logic_0;
*/
	main mainInst("mainInst");
	//port binding
	mainInst.ck(ck);
	//mainInst.instr_address(instr_address);
	//mainInst.last_instr_address(last_instr_address);


	/*

	mainInst.next_address(next_address);
	mainInst.instruction(instruction);
	mainInst.read_data_1(read_data_1);
	mainInst.read_data_2(read_data_2);
	mainInst.write_data(write_data);
	mainInst.extended_immediate(extended_immediate);
	mainInst.shifted_immediate(shifted_immediate);
	mainInst.alu_in_2(alu_in_2);
	mainInst.alu_result(alu_result);

	mainInst.incremented_address(incremented_address);
	mainInst.add2_result(add2_result);
	mainInst.mux4_result(mux4_result);
	mainInst.concatenated_pc_and_jump_address(concatenated_pc_and_jump_address);
	mainInst.mem_read_data(mem_read_data);
	mainInst.shifted_jump_address(shifted_jump_address);
	mainInst.jump_address(jump_address);
	mainInst.immediate(immediate);
	mainInst.opcode(opcode);
	mainInst.funct(funct);
	mainInst.rs(rs);
	mainInst.rt(rt);
	mainInst.rd(rd);
	mainInst.shampt(shampt);
	mainInst.write_reg(write_reg);
	mainInst.alu_control_funct(alu_control_funct);
	mainInst.alu_op(alu_op);
	mainInst.reg_dest(reg_dest);
	mainInst.jump(jump);
	mainInst.branch(branch);
	mainInst.mem_read(mem_read);
	mainInst.mem_to_reg(mem_to_reg);
	mainInst.mem_write(mem_write);
	mainInst.alu_src(alu_src);
	mainInst.reg_write(reg_write);
	mainInst.alu_zero(alu_zero);
	mainInst.branch(branch_and_alu_zero);
	mainInst.en(en);

	opcode.write(instruction.read().range(31, 26));
	rs.write(instruction.read().range(25, 21));
	rt.write(instruction.read().range(20, 16));
	rd.write(instruction.read().range(15, 11));
	shampt.write(instruction.read().range(10, 6));
	funct.write(instruction.read().range(5, 0));
	immediate.write(instruction.read().range(15, 0));
	jump_address.write(instruction.read().range(25, 0));
*/
	pc pcInst("pcInst");
	pcInst.ck(en);
	pcInst.address_to_load(next_address);
	pcInst.current_address(instr_address);

	instructionMemory instructionMemoryInst("instructionMemoryInst");
	instructionMemoryInst.read_address(instr_address);
	instructionMemoryInst.instruction(instruction);
	instructionMemoryInst.last_instr_address(last_instr_address);

	control controlInst1("controlInst1");
	controlInst1.opcode(opcode);
	controlInst1.reg_dest(reg_dest);
	controlInst1.jump(jump);
	controlInst1.branch(branch);
	controlInst1.mem_read(mem_read);
	controlInst1.mem_to_reg(mem_to_reg);
	controlInst1.mem_write(mem_write);
	controlInst1.alu_src(alu_src);
	controlInst1.reg_write(reg_write);
	controlInst1.alu_op(alu_op);

	mux5b muxInst1("muxInst1");
	muxInst1.x(rt);
	muxInst1.y(rd);
	muxInst1.s(reg_dest);
	muxInst1.z(write_reg);

	Register RegisterInst("RegisterInst");
	RegisterInst.sig(en);
	RegisterInst.RegWrite(reg_write);
	RegisterInst.ReadRegister1(rs);
	RegisterInst.ReadRegister2(rt);
	RegisterInst.WriteRegister(write_reg);
	RegisterInst.WriteData(write_data);
	RegisterInst.ReadData1(read_data_1);
	RegisterInst.ReadData2(read_data_2);

	Alu_control aluControlInst("aluControlInst");
	aluControlInst.funct(funct);
	aluControlInst.alu_op(alu_op);
	aluControlInst.alu_control_funct(alu_control_funct);

	sign_extend signExtendInst("signExtendInst");
	signExtendInst.x(immediate);
	signExtendInst.y(extended_immediate);

	mux muxInst2("muxInst2");
	muxInst2.x(read_data_2);
	muxInst2.y(extended_immediate);
	muxInst2.s(alu_src);
	muxInst2.z(alu_in_2);

	Alu aluInst1("aluInst1");
	aluInst1.a(read_data_1);
	aluInst1.b(alu_in_2);
	aluInst1.alu_control(alu_control_funct);
	aluInst1.zero(alu_zero);
	aluInst1.alu_result(alu_result);

	mux muxInst3("muxInst3");
	muxInst3.x(alu_result);
	muxInst3.y(mem_read_data);
	muxInst3.s(mem_to_reg);
	muxInst3.z(write_data);

	shifter shifterInst1("shifterInst1");
	shifterInst1.x(extended_immediate);
	shifterInst1.y(shifted_immediate);

	adder adderInst1("adderInst1");
	adderInst1.x(instr_address);
	adderInst1.y(shifter1Y);
	adderInst1.z(incremented_address);

	//branch_and_alu_zero.write(branch.read() & alu_zero);

	mux muxInst4("muxInst4");
	muxInst4.x(incremented_address);
	muxInst4.y(add2_result);
	muxInst4.s(branch_and_alu_zero);
	muxInst4.z(mux4_result);

	adder adderInst2("adderInst2");
	adderInst2.x(incremented_address);
	adderInst2.y(shifted_immediate);
	adderInst2.z(add2_result);

	shifter shifterInst2("shifterInst2");
	shifterInst2.n1=26;
	shifterInst2.n2=28;
	shifterInst2.x(shifter2X);
	shifterInst2.y(shifter2Y);

	//	concatenated_pc_and_jump_address.write(((incremented_address.read().range(31,28) ^ 0x00000000)^(shifted_jump_address.read().range(27,0) ^ 0x00000000)));
	mux muxInst5("muxInst5");
	muxInst5.x(mux4_result);
	muxInst5.y(concatenated_pc_and_jump_address);
	muxInst5.s(jump);
	muxInst5.z(next_address);

	memory memoryInst("memoryInst");
	memoryInst.address(alu_result);
	memoryInst.write_data(read_data_2);
	memoryInst.MemWrite(mem_write);
	memoryInst.MemRead(mem_read);
	memoryInst.ck(en);
	memoryInst.read_data(mem_read_data);

	//testbench
	sc_trace(trace_file, mem_write, "mem_write");
	sc_trace(trace_file, en, "en");
	sc_trace(trace_file, instruction, "instruction");
	sc_trace(trace_file, last_instr_address, "lastinstructionaddress");
	sc_trace(trace_file, alu_result, "alu_result");
	sc_trace(trace_file, reg_write, "reg_write");





	//pcInst.current_address = instr_address;
	opcode.write(instruction.read().range(31, 26));
	rs.write(instruction.read().range(25, 21));
	rt.write(instruction.read().range(20, 16));
	rd.write(instruction.read().range(15, 11));
	shampt.write(instruction.read().range(10, 6));
	funct.write(instruction.read().range(5, 0));
	immediate.write(instruction.read().range(15, 0));
	jump_address.write(instruction.read().range(25, 0));

	shifter2X.write(0x00000000 ^ jump_address.read().range(25,0));
	shifter2Y.write(0x00000000 ^ shifted_jump_address.read().range(27, 0));
	shifter1Y = "00000000000000000000000000000100";

	instr_address = "00000000000000000000000000000000";
	read_data_1 = "00000000000000000000000000000000";
	read_data_2 =  "00000000000000000000000000000000";
	write_data = "00000000000000000000000000000000";
	extended_immediate = "00000000000000000000000000000000";
	shifted_immediate = "00000000000000000000000000000000";
	alu_in_2 = "00000000000000000000000000000000";
	alu_result ="00000000000000000000000000000000";
	last_instr_address = 	"00000000000000000000000000000000";
	incremented_address = 	"00000000000000000000000000000000";
	add2_result = 	"00000000000000000000000000000000";
	mux4_result = 	"00000000000000000000000000000000";
	concatenated_pc_and_jump_address =	"00000000000000000000000000000000";
	mem_read_data = "00000000000000000000000000000000";


	reg_dest = sc_logic_0;
	jump = sc_logic_0;
	branch = sc_logic_0;
	mem_read = sc_logic_0;
	mem_to_reg = sc_logic_0;
	mem_write = sc_logic_0;
	alu_src = sc_logic_0;
	reg_write = sc_logic_0;
	alu_zero = sc_logic_0;
	branch_and_alu_zero = sc_logic_0;

	//sc_start(10, SC_NS);
	branch_and_alu_zero.write(branch.read() & alu_zero.read());
	concatenated_pc_and_jump_address.write(((incremented_address.read().range(31,28) ^ 0x00000000)^(shifted_jump_address.read().range(27,0) ^ 0x00000000)));
	en = sc_logic_0;
	ck = sc_logic_1;
	sc_start(10,SC_NS);
	ck = sc_logic_0;
	sc_start(10,SC_NS);
	ck = sc_logic_0;
	sc_start(10,SC_NS);
	ck = sc_logic_1;
	sc_start(10,SC_NS);
	ck = sc_logic_0;
	//cout << endl <<instr_address;
	//instr_address = 0x00000000;
	sc_start(10,SC_NS);

	return 0;
}

