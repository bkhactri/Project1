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
	QInt(int _data[4]);
	QInt(const QInt& int16);
	~QInt();


	void ScanQIntDec(string);
	void ScanQIntBin(string);
	void ScanQIntHex(string);

	void PrintQIntDec();
	void PrintQIntBin();
	void PrintQIntHex();

	string DecToBin(string nDec); //Chuyển từ hệ 10 sang hệ 2
	string DecToHex(string nHex); //Chuyển từ hệ 10 sang hệ 16
	string BinToDec(string bit);  //Chuyển từ hệ 2 sang hệ 10
	string BinToHex(string bit);  //Chuyển từ hệ 2 sang hệ 16
	string HexToBin(string nHex); //Chuyển từ hệ 16 sang hệ 2


	QInt operator&(const QInt&);
	QInt operator|(const QInt&);
	QInt operator^(const QInt&);
	QInt operator~();


	QInt operator>>(int nBitShifted);
	QInt operator<<(int nBitShifted);

	QInt operator+(const QInt&);
	QInt operator-(const QInt&);
	QInt operator*(const QInt&);
	QInt operator/(const QInt& );


	QInt rol(int nBitRotate);
	QInt ror(int nBitRotate);


	bool operator==(const QInt&);
	bool operator>(const QInt&);
	bool operator<(const QInt&);
	bool operator>=(const QInt&);
	bool operator<=(const QInt&);

};

string Div2(string num, char& bit);
string ConvertToOffetTwo(string num);
void FillZero(string& input,int nbit);
void EraseZero(string& nHex);
string PlusBit(string num1, string num2);
string Multi2(int repeat);
string MinusDec(string num1, string num2);
string PlusDec(string num1, string num2);

void GetBit(int x, char bit[32]);
void SetBit(char bit[32], int& x);
void ConvertStringtoInt4(string a, int data[4]);
string ConvertInt4toString(const int data[4]);
bool CheckSign(const int bytes[4]);
bool IsZero(const int bytes[4]);



#endif





