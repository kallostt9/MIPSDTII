/*
 * instruction_memory.cpp
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>
#include <iostream>
#include <fstream>
#include "instruction_memory.h"

using namespace std;

void instructionMemory::instructionMemoryM(void) {

	line.open("instructions.txt");
//	std::fstream line;
//	line.open("instructions.txt");
//	int j = 0;
//	string line_content;

	for (int i = 0; i < 32; i++) {
		getline(line, line_content);
		for (int h = 0; h < 32; h++) {
			array_data[i][31 - h] = line_content[h];
			if (line.eof()) {
				break;
			}else j = i;
		}
		cout << j << endl;
	}

	if (j >= 1) {
		last_instr_address = (sc_lv<32> ) ((uint)(j*4));
	} else
		last_instr_address = 0x00000000;
	line.close();
	instruction = array_data[read_address.read().to_uint()];
}
/*
int sc_main(int argc, char *argv[]) {
	sc_trace_file *trace_file = sc_create_vcd_trace_file("instructionMemoryTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal<sc_lv<32>> read_address, instruction, last_instr_address;

	instructionMemory instructionMemoryInst("instructionMemoryInst");

	instructionMemoryInst.read_address(read_address);
	instructionMemoryInst.instruction(instruction);
	instructionMemoryInst.last_instr_address(last_instr_address);

	sc_trace(trace_file, read_address, "read_address");
	sc_trace(trace_file, instruction, "instruction");
	sc_trace(trace_file, last_instr_address, "last_instr_address");

	read_address = 0x1;
	sc_start(10, SC_NS);
	read_address = 0x0;
	sc_start(10, SC_NS);
	read_address = 0x2;
	sc_start(10, SC_NS);
	read_address = 0xB;
	sc_start(10, SC_NS);

	return 0;
}

*/
