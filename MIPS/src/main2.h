/*
 * main2.h
 *
 *  Created on: Jul 14, 2022
 *      Author: jean
 */

#ifndef MAIN2_H_
#define MAIN2_H_

#include <stdio.h>
#include <systemc.h>


enum state {
	loading, running, done
};

SC_MODULE(main2) {
	sc_in<sc_lv<32>>  next_address;
	sc_out<sc_lv<32>>  instr_address ;
	sc_out<sc_lv<32>> last_instr_address;
	sc_in<sc_lv<32>> instruction;
	sc_out<sc_lv<32>> read_data_1, read_data_2, write_data, extended_immediate, shifted_immediate, alu_in_2, alu_result, incremented_address, add2_result, mux4_result, concatenated_pc_and_jump_address, mem_read_data;
	sc_in<sc_lv<28>> shifted_jump_address;
	sc_out<sc_lv<26>> jump_address;
	sc_out<sc_lv<16>> immediate;
	sc_out<sc_lv<6>> opcode, funct;
	sc_out<sc_lv<5>> rs, rt, rd, shampt;
	sc_in<sc_lv<5>> write_reg;
	sc_in<sc_lv<4>> alu_control_funct;
	sc_in<sc_lv<2>> alu_op;
	sc_out<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_zero;
	sc_out<sc_logic> branch_and_alu_zero;

	/*
	sc_out<sc_lv<32>>  next_address, instr_address ;
		sc_out<sc_lv<32>> last_instr_address, instruction;
		sc_out<sc_lv<32>> read_data_1, read_data_2, write_data, extended_immediate, shifted_immediate, alu_in_2, alu_result, incremented_address, add2_result, mux4_result, concatenated_pc_and_jump_address, mem_read_data;
		sc_out<sc_lv<28>> shifted_jump_address;
		sc_out<sc_lv<26>> jump_address;
		sc_out<sc_lv<16>> immediate;
		sc_out<sc_lv<6>> opcode, funct;
		sc_out<sc_lv<5>> rs, rt, rd, shampt;
		sc_out<sc_lv<5>> write_reg;
		sc_out<sc_lv<4>> alu_control_funct;
		sc_out<sc_lv<2>> alu_op;
		sc_out<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_zero, branch_and_alu_zero;
		*/
	/*
	sc_out<sc_lv<32>> instr_address
	sc_out<sc_lv<28>>
	sc_out<sc_lv<26>>
	sc_out<sc_lv<16>>
	sc_out<sc_lv<6>>
	sc_out<sc_lv<5>>
	sc_out<sc_lv<4>>
	sc_out<sc_lv<2>>
	sc_out<sc_logic>*/
	//sc_in<sc_logic> en;
	sc_out <sc_lv<32>> adder1Y;
	sc_in<bool> ck;
	sc_out<sc_logic> en;
	state s;
	void main2M();

	SC_CTOR(main2) {

		s = loading;
		SC_METHOD(main2M);
		sensitive << ck;
	}
};


#endif /* MAIN2_H_ */
