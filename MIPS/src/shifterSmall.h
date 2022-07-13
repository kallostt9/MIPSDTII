/*
 * shifter.h
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */

#ifndef SHIFTERSMALL_H_
#define SHIFTERSMALL_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(shifterSmall){
	sc_in <sc_lv<26>> x;
	sc_out <sc_lv<28>> y;

	int h = 0;
	int n1 =26;
	int n2 =28;
	int k = 2;

	sc_lv<28> temp;
	sc_lv<26> temp2;

	void shifterSmallM();
	SC_CTOR(shifterSmall){
		SC_METHOD(shifterSmallM);
		sensitive << x;
	}
};

#endif /* SHIFTERSMALL_H_ */
