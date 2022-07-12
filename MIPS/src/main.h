/*
 * main.h
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#ifndef MAIN_H_
#define MAIN_H_
#include <stdio.h>
#include <systemc.h>


enum state {
	loading, running, done
};

SC_MODULE(main) {
	sc_signal<sc_lv<32>> instr_address, last_instr_address;
	sc_in<sc_logic> ck;
	sc_signal<sc_logic> en;
	state s;
	void mainM();

	SC_CTOR(main) {

		en = sc_logic_0;
		s = loading;
		SC_METHOD(mainM);
		sensitive << ck;
	}
};

#endif /* MAIN_H_ */
