/*
 * shifter.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "shifter.h"

inline void shifter::shifterM(void){
	temp = x;
	temp.range(n2-1, k) = temp.range(n1-1,0);
	temp.range(1,0) = 0;
	y = temp;
	cout << y << " y " << x << " x " << " shifter " << endl;
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("shifterTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> x,y;

	shifter shifterInst("shifterInst");

	shifterInst.x(x);
	shifterInst.y(y);

	sc_trace(trace_file, x, "InputX");
	sc_trace(trace_file, y, "OutputY");

	x = 0x10000101;
	sc_start(10,SC_NS);
	x = 0x00111101;
	sc_start(10,SC_NS);


	return 0;
}*/
