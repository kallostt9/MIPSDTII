/*
 * Alu.h
 *
 *  Created on: Jun 21, 2022
 *      Author: jean
 */

#ifndef ALU_H_
#define ALU_H_
#include <stdio.h>
#include <systemc.h>

SC_MODULE(Alu){
	//Ports
	sc_in <sc_lv<32>> a,b;
	sc_in <sc_lv<4>> alu_control;
	sc_out <sc_lv<32>> alu_result;
	sc_out <sc_logic> zero;


	void aluM();
	SC_CTOR(Alu) {
		SC_METHOD(aluM);
		sensitive << a << b << alu_control;
	}
};





#endif /* ALU_H_ */
