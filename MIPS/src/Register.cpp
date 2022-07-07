/*
 * Register.cpp
 *
 *  Created on: Jun 21, 2022
 *      Author: jean
 */
#include <stdio.h>
#include <systemc.h>
#include "Register.h"

void Register::registerM(void) {
	if(clock.read() == sc_logic_0 && RegWrite.read() == sc_logic_1){
		array_register[WriteRegister.read().to_int()] = WriteData;
	}
}

int sc_main(int argc, char* argv[]){

	return 0;
}
