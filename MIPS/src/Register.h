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
	sc_in <sc_logic> RegWrite, sig;
	sc_out <sc_lv<32>> ReadData1, ReadData2;

	//sc_lv<32> reg[32];
	//typedef sc_lv<32> registerArray[32];
	sc_lv<32> array_register[32];
	void registerM();

	SC_CTOR(Register) {
		array_register[0] = 0x00000000;	// $zero
		array_register[1] = 0x11111111;	// $at
		array_register[2] = 0x22222222;	// $v0
		array_register[3] = 0x33333333;	// $v1
		array_register[4] = 0x44444444;	// $a0
		array_register[5] = 0x55555555;	// $a1
		array_register[6] = 0x66666666;	// $a2
		array_register[7] = 0x77777777;	// $a3
		array_register[8] = 0x88888888;	// $t0
		array_register[9] = 0x99999999;	// $t1
		array_register[10] = 0xaaaaaaaa;	// $t2
		array_register[11] = 0xbbbbbbbb;	// $t3
		array_register[12] = 0xcccccccc;	// $t4
		array_register[13] = 0xdddddddd;	// $t5
		array_register[14] = 0xeeeeeeee;	// $t6
		array_register[15] = 0xffffffff;	// $t7
		array_register[16] = 0x00000000;	// $s0
		array_register[17] = 0x11111111;	// $s1
		array_register[18] = 0x22222222;	// $s2
		array_register[19] = 0x33333333;	// $s3
		array_register[20] = 0x44444444;	// $s4
		array_register[21] = 0x55555555;	// $s5
		array_register[22] = 0x66666666;	// $s6
		array_register[23] = 0x77777777;	// $s7
		array_register[24] = 0x88888888;	// $t8
		array_register[25] = 0x99999999;	// $t9
		array_register[26] = 0xaaaaaaaa;	// $k0
		array_register[27] = 0xbbbbbbbb;	// $k1
		array_register[28] = 0x10008000;	// $gp
		array_register[29] = 0x7ffff1ec;	// $sp
		array_register[30] = 0xeeeeeeee;	// $fp
		array_register[31] = 0xffffffff; // $ra

		ReadData1 = array_register[ReadRegister1.read().to_uint()];
		ReadData2 = array_register[ReadRegister2.read().to_uint()];
		SC_METHOD(registerM);
		sensitive << sig;
	}
};
