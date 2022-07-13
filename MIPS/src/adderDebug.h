/*
 * adderDebug.h
 *
 *  Created on: Jul 13, 2022
 *      Author: jean
 */

#ifndef ADDERDEBUG_H_
#define ADDERDEBUG_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(adderDebug){
	sc_in <sc_lv<32>> x,y;
	sc_out <sc_lv<32>> z;

	void adderDebugM();
	SC_CTOR(adderDebug){
		SC_METHOD(adderDebugM);
		sensitive << x << y;
	}
};



#endif /* ADDERDEBUG_H_ */
