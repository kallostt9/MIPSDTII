/*
 * adderDebug.cpp
 *
 *  Created on: Jul 13, 2022
 *      Author: jean
 */


#include <stdio.h>
#include <systemc.h>
#include "adderDebug.h"

inline void adderDebug::adderDebugM(void) {
	z.write( y.read().to_uint()+x.read().to_uint());
	//cout << x << " " <<  y << " " << z << " adderDebug" << endl;
}


