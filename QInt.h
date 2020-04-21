#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
#include<string>
#include<math.h>
using namespace std;

#define max_bit 128 //16 byte
#define one_slot 9 //So ky tu toi da trong 1 o nho
#define array_size 4
class QInt
{
private:
	int data[4];
	int index; //luu tru so o nho can thiet de luu tru
	int size; //kich thuoc cua day so
public:
	QInt();
	QInt(string input);
	~QInt();
	void ScanQInt(QInt& num);
	void PrintQInt(QInt num);
	bool* DecToBin(QInt num); //he 10 sang he 2
	char* DecToHex(QInt num);//he 10 sang he 16
	QInt BinToDec(bool* bit); //he 2 sang he 10
	char* BinToHex(bool *bit);//he 2 sang he 16

};

#endif