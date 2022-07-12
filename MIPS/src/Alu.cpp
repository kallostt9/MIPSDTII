/*
 * Alu.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: jean
 */
#include <systemc.h>
#include "Alu.h"

inline void Alu::aluM(void) {
	switch (alu_control.read().to_uint()){
		case 0x0:
			alu_result.write((a.read() & b.read()));
			//a and b
			break;
		case 0x1:
			alu_result.write((a.read()| b.read()));
			//a or b
			break;
		case 0x2:
			alu_result.write( (sc_uint<32>)b.read()+(sc_uint<32>)a.read());
			//b+a
			break;
		case 0x6:
			alu_result.write( (sc_uint<32>)b.read()-(sc_uint<32>)a.read());
			//b-a
			break;
		case 0x7:
			if ((sc_int<32> ) a.read() > (sc_int<32> ) b.read()) {
				alu_result = 0x00000001;
			}else alu_result = 0x00000000;
			//a>b
			break;
		case 0xc:
			alu_result.write(b.read() ^ a.read());
			//XOR
			break;
		default:
			alu_result=0x00000000;
			//null für alle Kontrollerwerte ohne zugewiesene Operation
			break;
	}
	//cout<<(sc_int<4>)alu_control.read() << " ";

	if (alu_result.read() == 0x00000000) {
		zero = sc_logic_1;
	} else
		zero = sc_logic_0;
	cout << a << " Input a " << b << " Input b " << alu_result << " Output "<< alu_control.read().to_uint()<< " alu_control "<< zero << " zero "<< endl;
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("aluTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> a,b,alu_result;
	sc_signal <sc_logic> zero;
	sc_signal <sc_lv<4>> alu_control;

	Alu aluInst("aluInst");

	aluInst.a(a);
	aluInst.b(b);
	aluInst.alu_result(alu_result);
	aluInst.alu_control(alu_control);
	aluInst.zero(zero);

	sc_trace(trace_file, a, "ALU_INPUT_A");
	sc_trace(trace_file, b, "ALU_INPUT_B");
	sc_trace(trace_file, alu_result.read(), "ALU_RESULT");
	sc_trace(trace_file, alu_control, "ALU_CONTROL");
	sc_trace(trace_file, zero, "zero");

	a = 0x10100011;
	b = 0x01111000;
	zero = sc_logic_0;
	sc_start(10, SC_NS);

	//a&b
	alu_control = "0000";
	sc_start(10, SC_NS);
	//a|b
	alu_control = "0001";
	sc_start(10, SC_NS);
	//b+a
	alu_control = "0010";
	sc_start(10, SC_NS);
	//b-a
	alu_control = "0110";
	sc_start(10, SC_NS);
	//a>b
	alu_control = "0111";
	sc_start(10, SC_NS);
	//xor a^b
	alu_control = "1100";
	sc_start(10, SC_NS);
	//null test
	alu_control = "1111";
	sc_start(10, SC_NS);

	return 0;
}
*/
