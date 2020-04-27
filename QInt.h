#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
using namespace std;

#define max_bit 128 //16 byte
#define array_size 4


class QInt
{
private:
	int data[4];
public:

	QInt();
	QInt(string input);
	~QInt();


	void ScanQInt();
	
	string DecToBin(string num); //he 10 sang he 2 
	string DecToHex(string num); //he 10 sang he 16
	string BinToDec(string bit); //he 2 sang he 10
	string BinToHex(string bit); //he 2 sang he 16
	string HexToBin(string num); //he 16 sang he 2


	QInt operator&(const QInt& num16);
	QInt operator|(const QInt& num16);
	QInt operator^(const QInt& num16);
	QInt operator~();


	QInt operator>>(int nBitShifted);
	QInt operator<<(int nBitShifted);


	QInt rol(int nBitShifted);
	QInt ror(int nBitShifted);
};

string Div2(const string &num, char& bit);
void Plus1(string& num);
void StandardPrintBit(string &input);
void StandardCalcBit(string& input);





#endif

