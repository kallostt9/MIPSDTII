/*
 * memory.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef MEMORY_H_
#define MEMORY_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(memory){
	sc_in <sc_lv<32>> address, write_data;
	sc_in <sc_logic> MemWrite, MemRead, ck;
	sc_out <sc_lv<32>> read_data;
	sc_lv<32> array_memory[32];
	void memoryM();

	SC_CTOR(memory){
		for(int i = 0; i<32; i++){
			array_memory[i] = 0x00000000;
		}
		SC_METHOD(memoryM);
		sensitive << address << write_data << MemWrite << MemRead << ck;
	}
};

#endif /* MEMORY_H_ */
