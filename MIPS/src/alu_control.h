/*
 * alu_control.h
 *
 *  Created on: Jul 9, 2022
 *      Author: jean
 */

#ifndef ALU_CONTROL_H_
#define ALU_CONTROL_H_
#include <stdio.h>
#include <systemc.h>

SC_MODULE(Alu_control){
	//Ports
	sc_in <sc_lv<6>> funct;
	sc_in <sc_lv<2>> alu_op;
	sc_out <sc_lv<4>> alu_control_funct;

	void alu_controlM();
	SC_CTOR(Alu_control) {
		SC_METHOD(alu_controlM);
		sensitive << alu_op << funct;
	}
};


#endif /* ALU_CONTROL_H_ */
