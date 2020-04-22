#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
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
	int getSize() { return size; }
	void setSize(int _size) { size = _size; }
	QInt();
	
	~QInt();
	void ScanQInt();
	void PrintQInt();
	bool* DecToBin(int& count); //he 10 sang he 2
	string DecToHex();//he 10 sang he 16

	QInt BinToDec(bool* bit); //he 2 sang he 10
	string BinToHex(bool *bit);//he 2 sang he 16

	bool* HexToBin(string num); //he 16 sang he 2

	QInt Div2(bool &sur);
};

#endif