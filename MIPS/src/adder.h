/*
 * adder.h
 *
 *  Created on: Jul 9, 2022
 *      Author: jean
 */

#ifndef ADDER_H_
#define ADDER_H_
#include <stdio.h>
#include <systemc.h>

SC_MODULE(Adder){
	sc_in <sc_lv<32>> x,y;
	sc_out <sc_lv<32>> z;

	void adderM();
	SC_CTOR(Adder){
		SC_METHOD(adderM);
		sensitive << x << y;
	}
};



#endif /* ADDER_H_ */
