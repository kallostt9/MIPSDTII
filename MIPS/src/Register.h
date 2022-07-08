/*
 * Register.h
 *
 *  Created on: Jun 21, 2022
 *      Author: jean
 */

#include <stdio.h>
#include <systemc.h>


SC_MODULE(Register){
	//Ports
	sc_in <sc_lv<5>> ReadRegister1, ReadRegister2, WriteRegister;
	sc_in <sc_lv<32>> WriteData;
	sc_in <sc_logic> RegWrite, clock;
	sc_out <sc_lv<32>> ReadData1, ReadData2;

	typedef sc_lv<32> registerArray[32];
	sc_signal<registerArray> array_register;
	void registerM();

	SC_CTOR(Register) {

		array_register = {
				0x00000000,	// $zero
				0x11111111,	// $at
				0x22222222,	// $v0
				0x33333333,	// $v1
				0x44444444,	// $a0
				0x55555555,	// $a1
				0x66666666,	// $a2
				0x77777777,	// $a3
				0x88888888,	// $t0
				0x99999999,	// $t1
				0xaaaaaaaa,	// $t2
				0xbbbbbbbb,	// $t3
				0xcccccccc,	// $t4
				0xdddddddd,	// $t5
				0xeeeeeeee,	// $t6
				0xffffffff,	// $t7
				0x00000000,	// $s0
				0x11111111,	// $s1
				0x22222222,	// $s2
				0x33333333,	// $s3
				0x44444444,	// $s4
				0x55555555,	// $s5
				0x66666666,	// $s6
				0x77777777,	// $s7
				0x88888888,	// $t8
				0x99999999,	// $t9
				0xaaaaaaaa,	// $k0
				0xbbbbbbbb,	// $k1
				0x10008000,	// $gp
				0x7ffff1ec,	// $sp
				0xeeeeeeee,	// $fp
				0xffffffff, // $ra
				};
		ReadData1 = array_register[ReadRegister1.read().to_uint()];
		ReadData2 = array_register[ReadRegister2.read().to_uint()];
		SC_METHOD(registerM);
		sensitive << clock;
	}
};




