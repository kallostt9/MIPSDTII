/*
 * alu_control.cpp
 *
 *  Created on: Jul 9, 2022
 *      Author: jean
 */

/*
 * 0000: a & b
 * 0001: a | b
 * 0010: b+a
 * 0110: b-a
 * 0111: a>b
 * 1100: a XOR b
 *
 * */

#include <stdio.h>
#include <systemc.h>
#include "alu_control.h"

void Alu_control::alu_controlM (void){
	cout << alu_op.read().to_uint() << endl;
	switch (alu_op.read().to_uint()) {
		case 0x0:
			alu_control_funct = "0010";
			break;
		case 0x1:
			alu_control_funct = "0110";
			break;
		case 0x2:
			switch(funct.read().to_uint()){
				case 0x20:
					alu_control_funct = "0010";
					break;
				case 0x22:
					alu_control_funct = "0110";
					break;
				case 0x24:
					alu_control_funct = "0000";
					break;
				case 0x25:
					alu_control_funct = "0001";
					break;
				case 0x2A:
					alu_control_funct = "0111";
					break;
				default:
					alu_control_funct = "1100";
					break;
			}
			break;
		case 0x3:
			alu_control_funct = "0111";
			break;
		default:
			alu_control_funct = "0000";
			break;
	}
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("alu_control");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<6>> funct;
	sc_signal <sc_lv<2>> alu_op;
	sc_signal <sc_lv<4>> alu_control_funct;

	Alu_control aluControlInst("aluControlInst");

	aluControlInst.alu_control_funct(alu_control_funct);
	aluControlInst.alu_op(alu_op);
	aluControlInst.funct(funct);

	sc_trace(trace_file, alu_control_funct, "AluControlFunct");
	sc_trace(trace_file, alu_op, "AluOp");
	sc_trace(trace_file, funct, "Funct");

	alu_op = 00;
	sc_start(10,SC_NS);
	alu_op = 10;
	sc_start(10,SC_NS);
	alu_op = 01;
	sc_start(10,SC_NS);
	alu_op = 11;
	sc_start(10,SC_NS);

	alu_op=10;
	funct = "100000";
	sc_start(10,SC_NS);
	funct = "100010";
	sc_start(10,SC_NS);
	funct = "100100";
	sc_start(10,SC_NS);
	funct = "100101";
	sc_start(10,SC_NS);
	funct = "101010";
	sc_start(10,SC_NS);
	funct = "101011";
	sc_start(10,SC_NS);

	return 0;
}
*/
