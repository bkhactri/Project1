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
	//Constructor
	QInt();
	QInt(int _data[4]);
	QInt(const QInt& int16);
	~QInt();

	//Toán tử gán
	QInt& operator=(const QInt&);
	QInt& operator=(const string);

	//Hàm xuất cho UI
	string Print_QIntDec();
	string Print_QIntBin();
	string Print_QIntHex();

	//Hàm đọc chuỗi số
	void ScanQIntDec(string); //Hệ 10
	void ScanQIntBin(string); //Hệ 2
	void ScanQIntHex(string); //Hệ 16

	//Hàm in chuỗi số
	void PrintQIntDec(); //Hệ 10
	void PrintQIntBin(); //Hệ 2
	void PrintQIntHex(); //Hệ 16

	//Hàm chuyển đổi giữa các hệ cơ số
	string DecToBin(string nDec); //10 -> 2
	string HexToBin(string nHex); //16 -> 2
	string DecToHex(string nHex); //10 -> 16
	string BinToDec(string bit);  //2 -> 10
	string BinToHex(string bit);  //2 -> 16

	//Toán tử AND,OR,XOR,NOT
	QInt operator&(const QInt&);
	QInt operator|(const QInt&);
	QInt operator^(const QInt&);
	QInt operator~();

	//Toán tử dịch phải , dịch trái
	QInt operator>>(int nBitShifted);
	QInt operator<<(int nBitShifted);

	//Toán tử cộng,trừ,nhân,chia
	QInt operator+(const QInt&);
	QInt operator-(const QInt&);
	QInt operator*(const QInt&);
	QInt operator/(const QInt&);

	//Xoay trái,xoay phải
	QInt rol(int nBitRotate);
	QInt ror(int nBitRotate);

	//Toán tử so sánh
	bool operator==(const QInt&) const;
	bool operator>(const QInt&) const;
	bool operator<(const QInt&) const;
	bool operator>=(const QInt&) const;
	bool operator<=(const QInt&) const;

};
//Các hàm bổ trợ
//Hàm chia 2 chuỗi nhị phân tìm phần dư
string Div2(string num, char& bit);
//Hàm mũ 2
string Multi2(int repeat);
//Hàm chuyển đổi bù 2
string ConvertToOffetTwo(string num);
//Hàm cộng 2 chuỗi nhị phân
string PlusBit(string num1, string num2);
//Hàm nhân 2 chuỗi nhị phân
string MultiBit(string num1, string num2);
//Hàm chia 2 chuỗi nhị phân
string DivBit(string num1, string num2);
//Hàm cộng 2 chuỗi số thập phân
string PlusDec(string num1, string num2);
//Hàm trừ 2 chuỗi số thập phân
string MinusDec(string num1, string num2);


void GetBit(int x, char bit[32]);
void SetBit(char bit[32], int& x);
void ConvertStringtoInt4(string a, int data[4]);
string ConvertInt4toString(const int data[4]);


//Hàm thêm 0 vào đầu dãy
void FillZero(string& num, int nbit);
//Hàm xoá 0 đầu dãy
void EraseZero(string& num);
//Hàm kiểm tra dấu data 
bool CheckSign(const int bytes[4]);
//Hàm kiểm tra data có là 0
bool IsZero(const int bytes[4]);
//Hàm so sánh xem num1 < num2 ?
bool CompareBit(string num1, string num2);



#endif





