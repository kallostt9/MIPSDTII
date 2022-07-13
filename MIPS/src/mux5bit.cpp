/*
 * mux5bit.cpp
 *
 *  Created on: Jul 11, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>
#include "mux5bit.h"

inline void mux5b::mux5bM(void){
	if(s == sc_logic_0){
		z.write(x.read());
	}else z.write(y.read());
	cout << endl << x.read() << " x " << y.read() << " y " << z.read()<< " z "<< s.read()<< " s " << " mux5b check for mistakes" << endl;
}


