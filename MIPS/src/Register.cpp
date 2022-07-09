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

	ReadData1 = array_register[ReadRegister1.read().to_uint()];
	ReadData2 = array_register[ReadRegister2.read().to_uint()];
	if(sig.read() == sc_logic_0 && RegWrite.read() == sc_logic_1){
		array_register[WriteRegister.read().to_uint()] = WriteData;
	}
}

int sc_main(int argc, char* argv[]){
	sc_trace_file *trace_file = sc_create_vcd_trace_file("registerTrace");
	trace_file->set_time_unit(1, SC_NS);

	sc_signal <sc_lv<5>> ReadRegister1, ReadRegister2, WriteRegister;
	sc_signal <sc_lv<32>> ReadData1, ReadData2, WriteData;
	sc_signal <sc_logic> RegWrite, sig;

	Register registerInst("registerInst");

	registerInst.ReadRegister1(ReadRegister1);
	registerInst.ReadRegister2(ReadRegister2);
	registerInst.WriteRegister(WriteRegister);
	registerInst.ReadData1(ReadData1);
	registerInst.ReadData2(ReadData2);
	registerInst.WriteData(WriteData);
	registerInst.RegWrite(RegWrite);
	registerInst.sig(sig);

	sc_trace(trace_file, sig, "sig");
	sc_trace(trace_file, RegWrite, "RegWrite");
	sc_trace(trace_file, ReadData1, "ReadData1");
	sc_trace(trace_file, ReadData2, "ReadData2");
	sc_trace(trace_file, WriteData, "WriteData");
	sc_trace(trace_file, WriteRegister, "WriteRegister");
	sc_trace(trace_file, ReadRegister1, "ReadRegister1");
	sc_trace(trace_file, ReadRegister2, "ReadRegister2");

	sc_start(10, SC_NS);
	sig = sc_logic_0;
	RegWrite = sc_logic_0;
	ReadRegister1 = 00111;
	ReadRegister2 = 11000;
	sc_start(10, SC_NS);

	cout << ReadData1 << endl << ReadData2;

	return 0;
}
