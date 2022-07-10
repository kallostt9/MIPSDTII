/*
 * control.h
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 *
 *
 *      reg_dest: should use rd as detsination register
 *		jump: should jump to address
 *		branch: should branch off current address
 *		mem_read: should read from data memory
 *		mem_to_reg: should write value from data memory to a register
 *		mem_write: should write to data memory
 *		alu_src: should use immediate as second parameter of alu
 *		reg_write: should write to a register
 * 		alu_op: command to use in alu control
 *
 */

#ifndef CONTROL_H_
#define CONTROL_H_

#include <stdio.h>
#include <systemc.h>

//ports
SC_MODULE(control){
	sc_in <sc_lv<6>> opcode;
	sc_out <sc_logic> reg_dest, jump, branch, mem_read, mem_to_reg, mem_write, alu_src, reg_write;
	sc_out <sc_lv<2>> alu_op;
	void controlM();

	SC_CTOR(control){
		SC_METHOD(controlM);
		sensitive << opcode;
	}

};


#endif /* CONTROL_H_ */
