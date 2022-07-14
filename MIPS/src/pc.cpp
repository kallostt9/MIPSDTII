/*
 * pc.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "pc.h"

inline void pc::pcM(void){

	//current_address.write(address.read());
	current_address.write(address);
	//cout << current_address<< "address";
	if(ck == sc_logic_0 ){
		address = address_to_load;

		//cout << address<< " " << address_to_load<< " " << current_address<<" pc";
	}
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("pcTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> current_address,address_to_load;
	sc_signal <sc_logic> ck;

	pc pcInst("pcInst");

	pcInst.current_address(current_address);
	pcInst.address_to_load(address_to_load);
	pcInst.ck(ck);

	sc_trace(trace_file, current_address, "current_address");
	sc_trace(trace_file, address_to_load, "address_to_load");
	sc_trace(trace_file, ck, "ck");

	ck = sc_logic_1;
	address_to_load = 0x00110011;
	sc_start(10, SC_NS);

	ck=sc_logic_0;
	sc_start(10, SC_NS);

	ck=sc_logic_1;
	sc_start(10, SC_NS);

	return 0;
}
*/
