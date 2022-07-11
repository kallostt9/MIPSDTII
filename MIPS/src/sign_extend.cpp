/*
 * sign_extend.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "sign_extend.h"

inline void sign_extend::sign_extendM(void){
	y.write((sc_lv<32>)0x00000000 ^ x.read());
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("sign_extendTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<16>> x;
	sc_signal <sc_lv<32>> y;

	sign_extend sign_extendInst("sign_extendInst");

	sign_extendInst.x(x);
	sign_extendInst.y(y);

	sc_trace(trace_file, x, "Input_x");
	sc_trace(trace_file, y, "Output_y");

	x = 0x1101;
	sc_start(10, SC_NS);

	return 0;
}

*/
