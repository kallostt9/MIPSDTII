/*
 * muxDebug.cpp
 *
 *  Created on: Jul 13, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "muxDebug.h"

inline void muxDebug::muxDebugM(void){
	if(s == sc_logic_0){
		z.write(x.read());
	}else z.write(y.read());
	cout << endl << x.read() << " x " << y.read() << " y " << z.read()<< " z "<<" muxDebug check for mistakes" << endl;
}



