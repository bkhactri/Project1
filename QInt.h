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
	int bitSize;
public:
	int getSize() { return bitSize; }
	void setSize(int _size) { bitSize = _size; }

	QInt();
	QInt(string input);
	~QInt();

	void ScanQInt();
	void PrintQInt(bool *bit);

	string DecToBin(string num); //he 10 sang he 2 
	string DecToHex();//he 10 sang he 16

	QInt BinToDec(bool* bit); //he 2 sang he 10
	string BinToHex(bool* bit);//he 2 sang he 16

	string HexToBin(string num); //he 16 sang he 2
	bool* StringToBitArr(string input);
	string BitArrToString(bool* bit);
};
string Div2(const string &num, char& bit);
void StandardHex(string &input);

#endif

