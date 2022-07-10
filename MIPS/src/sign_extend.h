/*
 * sign_extend.h
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */

#ifndef SIGN_EXTEND_H_
#define SIGN_EXTEND_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(sign_extend){
	sc_in <sc_lv<16>> x;
	sc_out <sc_lv<32>> y;

	void sign_extendM();
	SC_CTOR(sign_extend){
		SC_METHOD(sign_extendM);
		sensitive << x;
	}
};


#endif /* SIGN_EXTEND_H_ */
