/*
 * alu_control.cpp
 *
 *  Created on: Jul 9, 2022
 *      Author: jean
 */

/*
 * 0000: a & b
 * 0001: a | b
 * 0010: b+a
 * 0110: b-a
 * 0111: a>b
 * 1100: a XOR b
 *
 * */

#include <stdio.h>
#include <systemc.h>
#include "alu_control.h"

void Alu_control::alu_controlM (void){
	switch ((sc_int<2> ) alu_op.read()) {
		case 0x0:
			alu_control_funct = 0010;
			break;
		case 0x1:
			alu_control_funct = 0110;
			break;
		case 0x2:
			switch((sc_int<6>)funct.read()){
				case 0x20:
					alu_control_funct = 0010;
					break;
				case 0x22:
					alu_control_funct = 0110;
					break;
				case 0x24:
					alu_control_funct = 0000;
					break;
				case 0x25:
					alu_control_funct = 0001;
					break;
				case 0x2A:
					alu_control_funct = 0111;
					break;
				case 0x2B:
					alu_control_funct = 1100;
					break;

			}
			break;
		case 0x3:
			alu_control_funct = 0111;
			break;
		default:
			alu_control_funct = 0000;
			break;
	}
}

