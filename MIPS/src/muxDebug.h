/*
 * muxDebug.h
 *
 *  Created on: Jul 13, 2022
 *      Author: jean
 */

#ifndef MUXDEBUG_H_
#define MUXDEBUG_H_


#include <stdio.h>
#include <systemc.h>

SC_MODULE(muxDebug){
	int n;
	sc_in <sc_lv<32>> x,y;
	sc_in <sc_logic> s;
	sc_out <sc_lv<32>> z;

	void muxDebugM();

	SC_CTOR(muxDebug){
		n = 1;
		SC_METHOD(muxDebugM);
		sensitive << x << y << s;
	}
};




#endif /* MUXDEBUG_H_ */
