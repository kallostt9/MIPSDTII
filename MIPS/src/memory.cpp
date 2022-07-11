/*
 * memory.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>
#include "memory.h"

void memory::memoryM(void){
	if(MemRead == sc_logic_1){
		read_data.write(array_memory[address.read().to_uint()]);
	}else read_data = 0x00000000;
	if(ck == sc_logic_0 and ck.event()){
		if(MemWrite == sc_logic_1){
			array_memory[address.read().to_uint()] = write_data.read();
		}
	}
}
/*
int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("memoryTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<32>> address, write_data, read_data;
	sc_signal <sc_logic> MemWrite, MemRead, ck;

	memory memoryInst("memoryInst");

	memoryInst.address(address);
	memoryInst.write_data(write_data);
	memoryInst.read_data(read_data);
	memoryInst.MemWrite(MemWrite);
	memoryInst.MemRead(MemRead);
	memoryInst.ck(ck);

	sc_trace(trace_file, address, "address");
	sc_trace(trace_file, write_data, "write_data");
	sc_trace(trace_file, read_data, "read_data");
	sc_trace(trace_file, MemWrite, "MemWrite");
	sc_trace(trace_file, MemRead, "MemRead");
	sc_trace(trace_file, ck, "ck");

	ck = sc_logic_0;
	address = 0x0;
	write_data = 0x00011001;
	MemRead = sc_logic_0;
	MemWrite = sc_logic_0;
	sc_start(10, SC_NS);

	ck = sc_logic_1;
	address = 0x0;
	write_data = 0x00011001;
	MemRead = sc_logic_1;
	MemWrite = sc_logic_1;
	sc_start(10, SC_NS);

	ck = sc_logic_0;
	address = 0x0;
	write_data = 0x00011001;
	MemRead = sc_logic_1;
	MemWrite = sc_logic_1;
	sc_start(10, SC_NS);

	ck = sc_logic_1;
	address = 0x0;
	write_data = 0x00011001;
	MemRead = sc_logic_1;
	MemWrite = sc_logic_1;
	sc_start(10, SC_NS);

	return 0;
}
*/
