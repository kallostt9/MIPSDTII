/*
 * instruction_memory.h
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */

#ifndef INSTRUCTION_MEMORY_H_
#define INSTRUCTION_MEMORY_H_

#include <stdio.h>
#include <systemc.h>
#include <iostream>
#include <fstream>


SC_MODULE(instructionMemory){

	sc_in <sc_lv<32>> read_address;
	sc_out <sc_lv<32>> instruction, last_instr_address;
	sc_lv<32> array_data[32];
	std::fstream line;
	int j = 0;
	std::string line_content;

	void instructionMemoryM();

	SC_CTOR(instructionMemory){
/*
		array_data[0] = 0x00000000;	// $zero
		array_data[1] = 0x11111111;	// $at
		array_data[2] = 0x22222222;	// $v0
		array_data[3] = 0x33333333;	// $v1
		array_data[4] = 0x44444444;	// $a0
		array_data[5] = 0x55555555;	// $a1
		array_data[6] = 0x66666666;	// $a2
		array_data[7] = 0x77777777;	// $a3
		array_data[8] = 0x88888888;	// $t0
		array_data[9] = 0x99999999;	// $t1
		array_data[10] = 0xaaaaaaaa;	// $t2
		array_data[11] = 0xbbbbbbbb;	// $t3
		array_data[12] = 0xcccccccc;	// $t4
		array_data[13] = 0xdddddddd;	// $t5
		array_data[14] = 0xeeeeeeee;	// $t6
		array_data[15] = 0xffffffff;	// $t7
		array_data[16] = 0x00000000;	// $s0
		array_data[17] = 0x11111111;	// $s1
		array_data[18] = 0x22222222;	// $s2
		array_data[19] = 0x33333333;	// $s3
		array_data[20] = 0x44444444;	// $s4
		array_data[21] = 0x55555555;	// $s5
		array_data[22] = 0x66666666;	// $s6
		array_data[23] = 0x77777777;	// $s7
		array_data[24] = 0x88888888;	// $t8
		array_data[25] = 0x99999999;	// $t9
		array_data[26] = 0xaaaaaaaa;	// $k0
		array_data[27] = 0xbbbbbbbb;	// $k1
		array_data[28] = 0x10008000;	// $gp
		array_data[29] = 0x7ffff1ec;	// $sp
		array_data[30] = 0xeeeeeeee;	// $fp
		array_data[31] = 0xffffffff; // $ra
*/
		for(int i = 0; i<32; i++){
			array_data[i] = 0x0;
		}

		SC_METHOD(instructionMemoryM);
		sensitive << read_address;
	}

};



#endif /* INSTRUCTION_MEMORY_H_ */
