/*
 * pc.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef PC_H_
#define PC_H_

#include <stdio.h>
#include <systemc.h>

SC_MODULE(pc){
	sc_in <sc_logic> ck;
	sc_in <sc_lv<32>> address_to_load;
	sc_out <sc_lv<32>> current_address;
	sc_lv<32> address;
	void pcM();

	SC_CTOR(pc){

		address = 0x00000000;
		SC_METHOD(pcM);
		sensitive << ck << address_to_load;
	}
};


#endif /* PC_H_ */
