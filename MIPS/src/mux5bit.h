/*
 * mux5bit.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef MUX5BIT_H_
#define MUX5BIT_H_


#include <stdio.h>
#include <systemc.h>

SC_MODULE(mux5b){
	int n;
	sc_in <sc_lv<5>> x,y;
	sc_in <sc_logic> s;
	sc_out <sc_lv<5>> z;

	void mux5bM();

	SC_CTOR(mux5b){
		n = 1;
		SC_METHOD(mux5bM);
		sensitive << x << y << s;
	}
};





#endif /* MUX5BIT_H_ */
