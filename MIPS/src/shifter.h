/*
 * shifter.h
 *
 *  Created on: Jul 10, 2022
 *      Author: jean
 */

#ifndef SHIFTER_H_
#define SHIFTER_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(shifter){
	sc_in <sc_lv<32>> x;
	sc_out <sc_lv<32>> y;

	int h = 0;
	int n1 =32;
	int n2 =32;
	int k = 2;

	sc_lv<32> temp;

	void shifterM();
	SC_CTOR(shifter){
		SC_METHOD(shifterM);
		sensitive << x;
	}
};

#endif /* SHIFTER_H_ */
