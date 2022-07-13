/*
 * mux.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "mux.h"

inline void mux::muxM(void){
	if(s == sc_logic_0){
		z.write(x.read());
	}else z.write(y.read());
	cout << x.read() << " x " << y.read() << " y " << z.read()<< " z "<< s.read() << " s "<<" muxcheck for mistakes" << endl;
	//cout << y.read() << " muxY check for mistakes" << endl;
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("muxTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> x,y,z;
	sc_signal <sc_logic> s;

	mux muxInst("muxInst");

	muxInst.x(x);
	muxInst.y(y);
	muxInst.z(z);
	muxInst.s(s);

	sc_trace(trace_file, x, "InputX");
	sc_trace(trace_file, y, "InputY");
	sc_trace(trace_file, s, "InputS");
	sc_trace(trace_file, z, "OutputZ");

	x = 0x10100011;
	y = 0x01111000;
	s=sc_logic_0;
	sc_start(10, SC_NS);
	s=sc_logic_1;
	sc_start(10, SC_NS);
	s=sc_logic_0;
	sc_start(10, SC_NS);

	return 0;
}
*/
