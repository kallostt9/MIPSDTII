/*
 * shifter.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>

#include "shifterSmall.h"

inline void shifterSmall::shifterSmallM(void){
	temp2 = x;
	temp.range(n2-1, k) = temp2.range(n1-1,0);
	temp.range(1,0) = 0;
	y = temp;

}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("shifterSmallTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<26>> x;
	sc_signal <sc_lv<28>> y;

	shifterSmall shifterSmallInst("shifterSmallInst");

	shifterSmallInst.x(x);
	shifterSmallInst.y(y);

	sc_trace(trace_file, x, "InputX");
	sc_trace(trace_file, y, "OutputY");

	x = "00001111000011110000111100";
	sc_start(10,SC_NS);
	x = "00111111000011110001111111";
	sc_start(10,SC_NS);


	return 0;
}
*/
