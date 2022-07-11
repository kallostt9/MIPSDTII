/*
 * mux.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef MUX_H_
#define MUX_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(mux){
	int n;
	sc_in <sc_lv<32>> x,y;
	sc_in <sc_logic> s;
	sc_out <sc_lv<32>> z;

	void muxM();

	SC_CTOR(mux){
		n = 1;
		SC_METHOD(muxM);
		sensitive << x << y << s;
	}
};


#endif /* MUX_H_ */
