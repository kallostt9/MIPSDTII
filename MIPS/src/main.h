/*
 * main.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <systemc.h>


enum state {
	loading, running, done
};

SC_MODULE(main) {
	void mainM();
	sc_in<sc_logic> ck;
	sc_signal<sc_lv<32>> instr_address, next_address, instruction;
	sc_signal<sc_lv<32>> read_data_1, read_data_2, write_data, extended_immediate, shifted_immediate, alu_in_2, alu_result,
	last_instr_address, incremented_address, add2_result, mux4_result, concatenated_pc_and_jump_address, mem_read_data;
	sc_signal<sc_lv<28>> shifted_jump_address;
	sc_signal<sc_lv<26>> jump_address;
	sc_signal<sc_lv<16>> immediate;
	sc_signal<sc_lv<6>> opcode, funct;
	sc_signal<sc_lv<5>> rs, rt, rd, shampt, write_reg;
	sc_signal<sc_lv<4>> alu_control_funct;
	sc_signal<sc_lv<2>> alu_op;
	sc_signal<sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write, alu_zero, branch_and_alu_zero, en;
	state s;

	SC_CTOR(main) {
		read_data_1 = read_data_2 = write_data = extended_immediate = shifted_immediate = alu_in_2 = alu_result = last_instr_address =
		incremented_address = add2_result = mux4_result = concatenated_pc_and_jump_address = mem_read_data = 0x00000000;
		en = sc_logic_0;
		s = loading;

		reg_dest = jump = branch = mem_read = mem_to_reg = mem_write = alu_src = reg_write = alu_zero = branch_and_alu_zero = sc_logic_0;
		SC_METHOD(mainM);
		sensitive << ck;
	}
};

#endif /* MAIN_H_ */
