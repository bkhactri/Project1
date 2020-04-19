#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#define max_bit 128 //16 byte
#define one_slot 9 //So ky tu toi da trong 1 o nho

class QInt
{
private:
	int data[4];
	int index;
public:
	QInt();
	~QInt();
	void ScanQInt(QInt& x);
	void PrintQInt(QInt x);
	bool* DecToBin(QInt x);
	QInt BinToDec(bool* bit);
	char* BinToHex(bool *bit);
	char* DecToHex(QInt x);
};

#endif