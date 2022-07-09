/*
 * adder.cpp
 *
 *  Created on: Jul 9, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>
#include "adder.h"

void Adder::adderM(void) {
	z.write( (sc_uint<32>)y.read()+(sc_uint<32>)x.read());
}

int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("adderTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> x,y,z;

	Adder adderInst("adderInst");

	adderInst.x(x);
	adderInst.y(y);
	adderInst.z(z);

	sc_trace(trace_file, x, "InputX");
	sc_trace(trace_file, y, "InputY");
	sc_trace(trace_file, z, "OutputZ");

	x = 0x10100011;
	y = 0x01111000;
	sc_start(10, SC_NS);

	x = 0x00001111;
	y = 0x00111100;
	sc_start(10, SC_NS);

	return 0;
}
