/*
 * main2.cpp
 *
 *  Created on: Jul 14, 2022
 *      Author: jean
 */


#include <stdio.h>
#include <systemc.h>
#include "adder.cpp"
#include "adderDebug.cpp"
#include "alu_control.cpp"
#include "Alu.cpp"
#include "control.cpp"
#include "instruction_memory.cpp"
#include "memory.cpp"
#include "mux.cpp"
#include "muxDebug.cpp"
#include "mux5bit.cpp"
#include "pc.cpp"
#include "Register.cpp"
#include "shifter.cpp"
#include "shifterSmall.cpp"
#include "sign_extend.cpp"
#include "main2.h"

void main2::main2M(void){
	switch (s) {
	case running:
		if(ck == 0)
			en = sc_logic_0;
		else en = sc_logic_1;
		break;
	default:
		en = sc_logic_0;
		break;
	}
	if (ck.event() and ck == true) {
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
	opcode = instruction.read().range(31,26);
	rt = instruction.read().range(25,21);
	rt = instruction.read().range(20,16);
	rd = instruction.read().range(15,11);
	shampt = instruction.read().range(10,6);
	funct = instruction.read().range(5,0);
	immediate = instruction.read().range(15,0);
	jump_address = instruction.read().range(25,0);
	branch_and_alu_zero.write(branch.read() & alu_zero.read());
	read_data_1 = "00000000000000000000000000000000";
	read_data_2 = "00000000000000000000000000000000";
	write_data = "00000000000000000000000000000000";
	extended_immediate = "00000000000000000000000000000000";
	alu_in_2 = "00000000000000000000000000000000";
	alu_result = "00000000000000000000000000000000";
	//last_instr_address = "00000000000000000000000000000000";
	incremented_address = "00000000000000000000000000000000";
	add2_result = "00000000000000000000000000000000";
	mux4_result = "00000000000000000000000000000000";
	concatenated_pc_and_jump_address = "00000000000000000000000000000000";
	mem_read_data = "00000000000000000000000000000000";
	adder1Y = "00000000000000000000000000000100";

	reg_dest = sc_logic_0;
	jump = sc_logic_0;
	branch= sc_logic_0;
	mem_read = sc_logic_0;
	mem_to_reg = sc_logic_0;
	mem_write = sc_logic_0;
	alu_src = sc_logic_0;
	reg_write = sc_logic_0;
	alu_zero = sc_logic_0;

}
int sc_main(int argc, char* argv[]){
	 sc_core::sc_report_handler::set_actions( "/IEEE_Std_1666/deprecated", sc_core::SC_DO_NOTHING );
	sc_trace_file *trace_file = sc_create_vcd_trace_file("main2Trace");
	trace_file->set_time_unit(1, SC_NS);
	//ports
	sc_clock ck("ck", SC_NS&10, 0.5, 0, true);

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
	sc_signal <sc_lv<32>> shifter2X, shifter2Y, adder1Y;

	main2 mainInst("mainInst");
	//port binding
	mainInst.en(en);
	mainInst.ck(ck);
	mainInst.instr_address(instr_address);
	mainInst.next_address(next_address);
	mainInst.instruction(instruction);
	mainInst.read_data_1(read_data_1);
	mainInst.read_data_2(read_data_2);
	mainInst.write_data(write_data);
	mainInst.extended_immediate(extended_immediate);
	mainInst.shifted_immediate(shifted_immediate);
	mainInst.alu_in_2(alu_in_2);
	mainInst.alu_result(alu_result);
	mainInst.last_instr_address(last_instr_address);
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
	mainInst.branch_and_alu_zero(branch_and_alu_zero);
	mainInst.adder1Y(adder1Y);


	pc pcInst("pcInst");
	pcInst.ck(en);
	pcInst.address_to_load(next_address);
	pcInst.current_address(mainInst.instr_address);

	instructionMemory instructionMemoryInst("instructionMemoryInst");
	instructionMemoryInst.read_address(instr_address);
	instructionMemoryInst.instruction(instruction);
	instructionMemoryInst.last_instr_address(mainInst.last_instr_address);

	control controlInst1("controlInst1");
	controlInst1.opcode(mainInst.opcode);
	controlInst1.reg_dest(mainInst.reg_dest);
	controlInst1.jump(mainInst.jump);
	controlInst1.branch(mainInst.branch);
	controlInst1.mem_read(mainInst.mem_read);
	controlInst1.mem_to_reg(mainInst.mem_to_reg);
	controlInst1.mem_write(mainInst.mem_write);
	controlInst1.alu_src(mainInst.alu_src);
	controlInst1.reg_write(mainInst.reg_write);
	controlInst1.alu_op(alu_op);

	mux5b muxInst1("muxInst1");
	muxInst1.x(mainInst.rt);
	muxInst1.y(mainInst.rd);
	muxInst1.s(mainInst.reg_dest);
	muxInst1.z(write_reg);

	Register RegisterInst("RegisterInst");
	RegisterInst.sig(en);
	RegisterInst.RegWrite(mainInst.reg_write);
	RegisterInst.ReadRegister1(mainInst.rs);
	RegisterInst.ReadRegister2(mainInst.rt);
	RegisterInst.WriteRegister(mainInst.write_reg);
	RegisterInst.WriteData(mainInst.write_data);
	RegisterInst.ReadData1(mainInst.read_data_1);
	RegisterInst.ReadData2(mainInst.read_data_2);

	Alu_control aluControlInst("aluControlInst");
	aluControlInst.funct(funct);
	aluControlInst.alu_op(alu_op);
	aluControlInst.alu_control_funct(alu_control_funct);

	sign_extend signExtendInst("signExtendInst");
	signExtendInst.x(mainInst.immediate);
	signExtendInst.y(mainInst.extended_immediate);

	mux muxInst2("muxInst2");
	muxInst2.x(mainInst.read_data_2);
	muxInst2.y(mainInst.extended_immediate);
	muxInst2.s(mainInst.alu_src);
	muxInst2.z(mainInst.alu_in_2);

	Alu aluInst1("aluInst1");
	aluInst1.a(read_data_1);
	aluInst1.b(alu_in_2);
	aluInst1.alu_control(alu_control_funct);
	aluInst1.zero(mainInst.alu_zero);
	aluInst1.alu_result(alu_result);

	mux muxInst3("muxInst3");
	muxInst3.x(alu_result);
	muxInst3.y(mem_read_data);
	muxInst3.s(mem_to_reg);
	muxInst3.z(write_data);

	shifter shifterInst1("shifterInst1");
	shifterInst1.x(extended_immediate);
	shifterInst1.y(shifted_immediate);

	adderDebug adderInst1("adderInst1");
	adderInst1.x(instr_address);
	adderInst1.y(adder1Y);
	adderInst1.z(incremented_address);

	muxDebug muxInst4("muxInst4");
	muxInst4.x(mainInst.incremented_address);
	muxInst4.y(mainInst.add2_result);
	muxInst4.s(mainInst.branch_and_alu_zero);
	muxInst4.z(mainInst.mux4_result);

	adder adderInst2("adderInst2");
	adderInst2.x(mainInst.incremented_address);
	adderInst2.y(mainInst.shifted_immediate);
	adderInst2.z(add2_result);

	shifterSmall shifterInst2("shifterInst2");
	//shifterInst2.n1=26;
	//shifterInst2.n2=28;
	shifterInst2.x(jump_address);
	shifterInst2.y(shifted_jump_address);

	mux muxInst5("muxInst5");
	muxInst5.x(mux4_result);
	muxInst5.y(mainInst.concatenated_pc_and_jump_address);
	muxInst5.s(jump);
	muxInst5.z(next_address);

	memory memoryInst("memoryInst");
	memoryInst.address(mainInst.alu_result);
	memoryInst.write_data(mainInst.read_data_2);
	memoryInst.MemWrite(mainInst.mem_write);
	memoryInst.MemRead(mainInst.mem_read);
	memoryInst.ck(en);
	memoryInst.read_data(mainInst.mem_read_data);

	last_instr_address="00000000000000000000000000000000";
/*
	pc pcInst("pcInst");
	pcInst.ck(mainInst.en);
	pcInst.address_to_load(mainInst.next_address);
	pcInst.current_address(mainInst.instr_address);

	instructionMemory instructionMemoryInst("instructionMemoryInst");
	instructionMemoryInst.read_address(mainInst.instr_address);
	instructionMemoryInst.instruction(mainInst.instruction);
	instructionMemoryInst.last_instr_address(mainInst.last_instr_address);

	control controlInst1("controlInst1");
	controlInst1.opcode(mainInst.opcode);
	controlInst1.reg_dest(mainInst.reg_dest);
	controlInst1.jump(mainInst.jump);
	controlInst1.branch(mainInst.branch);
	controlInst1.mem_read(mainInst.mem_read);
	controlInst1.mem_to_reg(mainInst.mem_to_reg);
	controlInst1.mem_write(mainInst.mem_write);
	controlInst1.alu_src(mainInst.alu_src);
	controlInst1.reg_write(mainInst.reg_write);
	controlInst1.alu_op(alu_op);

	mux5b muxInst1("muxInst1");
	muxInst1.x(mainInst.rt);
	muxInst1.y(mainInst.rd);
	muxInst1.s(mainInst.reg_dest);
	muxInst1.z(mainInst.write_reg);

	Register RegisterInst("RegisterInst");
	RegisterInst.sig(en);
	RegisterInst.RegWrite(mainInst.reg_write);
	RegisterInst.ReadRegister1(mainInst.rs);
	RegisterInst.ReadRegister2(mainInst.rt);
	RegisterInst.WriteRegister(mainInst.write_reg);
	RegisterInst.WriteData(mainInst.write_data);
	RegisterInst.ReadData1(mainInst.read_data_1);
	RegisterInst.ReadData2(mainInst.read_data_2);

	Alu_control aluControlInst("aluControlInst");
	aluControlInst.funct(mainInst.funct);
	aluControlInst.alu_op(mainInst.alu_op);
	aluControlInst.alu_control_funct(mainInst.alu_control_funct);

	sign_extend signExtendInst("signExtendInst");
	signExtendInst.x(mainInst.immediate);
	signExtendInst.y(mainInst.extended_immediate);

	mux muxInst2("muxInst2");
	muxInst2.x(mainInst.read_data_2);
	muxInst2.y(mainInst.extended_immediate);
	muxInst2.s(mainInst.alu_src);
	muxInst2.z(mainInst.alu_in_2);

	Alu aluInst1("aluInst1");
	aluInst1.a(mainInst.read_data_1);
	aluInst1.b(mainInst.alu_in_2);
	aluInst1.alu_control(mainInst.alu_control_funct);
	aluInst1.zero(mainInst.alu_zero);
	aluInst1.alu_result(mainInst.alu_result);

	mux muxInst3("muxInst3");
	muxInst3.x(mainInst.alu_result);
	muxInst3.y(mainInst.mem_read_data);
	muxInst3.s(mainInst.mem_to_reg);
	muxInst3.z(mainInst.write_data);

	shifter shifterInst1("shifterInst1");
	shifterInst1.x(mainInst.extended_immediate);
	shifterInst1.y(mainInst.shifted_immediate);

	adderDebug adderInst1("adderInst1");
	adderInst1.x(mainInst.instr_address);
	adderInst1.y(mainInst.adder1Y);
	adderInst1.z(mainInst.incremented_address);

	muxDebug muxInst4("muxInst4");
	muxInst4.x(mainInst.incremented_address);
	muxInst4.y(mainInst.add2_result);
	muxInst4.s(mainInst.branch_and_alu_zero);
	muxInst4.z(mainInst.mux4_result);

	adder adderInst2("adderInst2");
	adderInst2.x(mainInst.incremented_address);
	adderInst2.y(mainInst.shifted_immediate);
	adderInst2.z(mainInst.add2_result);

	shifterSmall shifterInst2("shifterInst2");
	//shifterInst2.n1=26;
	//shifterInst2.n2=28;
	shifterInst2.x(mainInst.jump_address);
	shifterInst2.y(mainInst.shifted_jump_address);

	mux muxInst5("muxInst5");
	muxInst5.x(mainInst.mux4_result);
	muxInst5.y(mainInst.concatenated_pc_and_jump_address);
	muxInst5.s(mainInst.jump);
	muxInst5.z(mainInst.next_address);

	memory memoryInst("memoryInst");
	memoryInst.address(mainInst.alu_result);
	memoryInst.write_data(mainInst.read_data_2);
	memoryInst.MemWrite(mainInst.mem_write);
	memoryInst.MemRead(mainInst.mem_read);
	memoryInst.ck(mainInst.en);
	memoryInst.read_data(mainInst.mem_read_data);

	//testbench
	//trace
	sc_trace(trace_file, mem_write, "mem_write");
	//sc_trace(trace_file, en, "en");
	sc_trace(trace_file, instruction, "instruction");
	sc_trace(trace_file, last_instr_address, "lastinstructionaddress");
	sc_trace(trace_file, alu_result, "alu_result");
	sc_trace(trace_file, alu_in_2, "alu_in_2");
	sc_trace(trace_file, read_data_1, "alu_in_1");
	sc_trace(trace_file, reg_write, "reg_write");
	sc_trace(trace_file, rs, "rs");
	sc_trace(trace_file, opcode, "opcode");


//	//add standard values
	instr_address = "00000000000000000000000000000000";
	last_instr_address = 	"00000000000000000000000000010000";
	instruction = "00100000000010000000000000000111";
	//tempop = instruction.read().range(31,26);
	opcode="001000";
	//opcode = instruction.read().range(31,26);
	//if(opcode.read() == "XXXXXX"){
	////		opcode = "001000";
	//		cout << "flag";
	//	}
	en = sc_logic_0;

	rs = "00000";
	rt = "01000";
	rd = "00000";
	shampt = "00000";
	funct = "000111";
	immediate = "0000000000000111";
	jump_address = "00000010000000000000000111";
	//rs.write(instruction.read().range(25, 21));
//	rt.write(instruction.read().range(20, 16));
//	rd.write(instruction.read().range(15, 11));
//	shampt.write(instruction.read().range(10, 6));
//	funct.write(instruction.read().range(5, 0));
//	immediate.write(instruction.read().range(15, 0));
//	jump_address.write(instruction.read().range(25, 0));

	//shifter2X.write(0x00000000 ^ jump_address.read().range(25,0));
	//shifter2Y.write(0x00000000 ^ shifted_jump_address.read().range(27, 0));
	adder1Y = "00000000000000000000000000000100";
	write_reg = "01000";

	sc_lv<28> temp1;
	sc_lv<32> temp2, tempres;

	read_data_1 = "00000000000000000001000100010001";
	read_data_2 =  "00000000000100010000000000010001";
	write_data = "00000000000100010001000100100010";
	extended_immediate = "00000000000000000000000000000111";
	shifted_immediate = "00000000000000000000000000011100";
	alu_in_2 = "00000000000100010000000000010001";
	alu_result ="00000000000100010001000100100010";
	next_address = "0000000000000000000000000000000";

	incremented_address = 	"00000000000000000000000000000100";
	add2_result = 	"00000000000000000000000000011100";
	mux4_result = 	"00000000000000000000000000000000";
	//concatenated_pc_and_jump_address =	"00000000000000000000000000000000";
	//tempop.range(27,0) = shifter2Y.read().range(27, 0);
	mem_read_data = "00000000000000000000000000000000";
	alu_op = "00";
	alu_control_funct = "0010";

	shifted_jump_address = "0000001000000000000000011100";

	temp2 = incremented_address;
	//temp1=shifted_jump_address;
	temp1 = "0000001000000000000000011100";
	//temp1 =	"0000000000000000000000000000";

	tempres.range(31,28) = temp2.range(31, 28);
	tempres.range(27,0) = temp1.range(27, 0);
	//concatenated_pc_and_jump_address = tempres;
	concatenated_pc_and_jump_address = (sc_uint<4>(0), temp1.range(27,0));

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
*/
	read_data_1 = "00000000000000000000000000000000";
	read_data_2 = "00000000000000000000000000000000";
	write_data = "00000000000000000000000000000000";
	extended_immediate = "00000000000000000000000000000000";
	alu_in_2 = "00000000000000000000000000000000";
	alu_result = "00000000000000000000000000000000";
	last_instr_address = "00000000000000000000000000000000";
	incremented_address = "00000000000000000000000000000000";
	add2_result = "00000000000000000000000000000000";
	mux4_result = "00000000000000000000000000000000";
	concatenated_pc_and_jump_address = "00000000000000000000000000000000";
	mem_read_data = "00000000000000000000000000000000";
	adder1Y = "00000000000000000000000000000100";

	reg_dest = sc_logic_0;
	jump = sc_logic_0;
	branch= sc_logic_0;
	mem_read = sc_logic_0;
	mem_to_reg = sc_logic_0;
	mem_write = sc_logic_0;
	alu_src = sc_logic_0;
	reg_write = sc_logic_0;
	alu_zero = sc_logic_0;
	branch_and_alu_zero = sc_logic_0;
	//ck = clock
	//branch_and_alu_zero.write(branch.read() & alu_zero.read());

	//branch_and_alu_zero.write(branch.read() & alu_zero.read());
	//concatenated_pc_and_jump_address.write(((incremented_address.read().range(31,28) ^ 0x00000000)^(shifted_jump_address.read().range(27,0) ^ 0x00000000)));

	//ck = sc_logic_1;
	sc_start(1, SC_NS);
	sc_start(10, SC_NS);


	return 0;
}



