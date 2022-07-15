/*
 * control.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "control.h"

inline void control::controlM (void){
	switch(opcode.read().to_uint()){
		case 0x0:
			reg_dest = sc_logic_1;
			jump = sc_logic_0;
			branch = sc_logic_0;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_0;
			reg_write = sc_logic_1;
			alu_op = "10";
			break;
		case 0x8:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_0;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_1;
			reg_write = sc_logic_1;
			alu_op = "00";
			break;
		case 0x4:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_1;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_0;
			reg_write = sc_logic_0;
			alu_op = "01";
			break;
		case 0x5:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_1;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_0;
			reg_write = sc_logic_0;
			alu_op = "11";
			break;
		case 0x2:
			reg_dest = sc_logic_0;
			jump = sc_logic_1;
			branch = sc_logic_0;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_0;
			reg_write = sc_logic_0;
			alu_op = "00";
			break;
		case 0x23:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_0;
			mem_read = sc_logic_1;
			mem_to_reg = sc_logic_1;
			mem_write = sc_logic_0;
			alu_src = sc_logic_1;
			reg_write = sc_logic_1;
			alu_op = "00";
			break;
		case 0x2B:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_0;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_1;
			alu_src = sc_logic_1;
			reg_write = sc_logic_0;
			alu_op = "00";
			break;
		default:
			reg_dest = sc_logic_0;
			jump = sc_logic_0;
			branch = sc_logic_0;
			mem_read = sc_logic_0;
			mem_to_reg = sc_logic_0;
			mem_write = sc_logic_0;
			alu_src = sc_logic_0;
			reg_write = sc_logic_0;
			alu_op = "00";
	}
	//cout << opcode << reg_dest << jump<<branch <<mem_read << mem_to_reg<<mem_write << alu_src<<reg_write <<alu_op << "control" << endl;
//			sc_in <sc_lv<6>> opcode;
//	sc_out <sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
//	sc_out <sc_lv<2>> alu_op;

}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("controlTrace");
	trace_file->set_time_unit(1,SC_NS);

	sc_signal <sc_lv<6>> opcode;
	sc_signal <sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
	sc_signal <sc_lv<2>> alu_op;

	control controlInst("controlInst");

	controlInst.opcode(opcode);
	controlInst.reg_dest(reg_dest);
	controlInst.jump(jump);
	controlInst.branch(branch);
	controlInst.mem_read(mem_read);
	controlInst.mem_to_reg(mem_to_reg);
	controlInst.mem_write(mem_write);
	controlInst.alu_src(alu_src);
	controlInst.reg_write(reg_write);
	controlInst.alu_op(alu_op);

	sc_trace(trace_file, opcode, "opcode");
	sc_trace(trace_file, reg_dest, "reg_dest");
	sc_trace(trace_file, jump, "jump");
	sc_trace(trace_file, branch, "branch");
	sc_trace(trace_file, mem_read, "mem_read");
	sc_trace(trace_file, mem_to_reg, "mem_to_reg");
	sc_trace(trace_file, mem_write, "mem_write");
	sc_trace(trace_file, alu_src, "alu_src");
	sc_trace(trace_file, reg_write, "reg_write");
	sc_trace(trace_file, alu_op, "alu_op");

	opcode = "000000";
	sc_start(10, SC_NS);

	opcode = "001000";
	sc_start(10, SC_NS);

	opcode = "000100";
	sc_start(10, SC_NS);

	opcode = "000101";
	sc_start(10, SC_NS);

	opcode = "000010";
	sc_start(10, SC_NS);

	opcode = "100011";
	sc_start(10, SC_NS);

	opcode = "101011";
	sc_start(10, SC_NS);
// testing default case
	opcode = "111111";
	sc_start(10, SC_NS);

	return 0;
}
*/

