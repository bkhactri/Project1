#pragma once
#ifndef _HEADER_
#define _HEADER_
#include<iostream>
#include<string>
#include<math.h>
#include<conio.h>
using namespace std;

#define max_bit 128 //16 byte
#define array_size 4 //số phần tử mảng


class QInt
{
private:
	int data[4];
public:
	/*Tống Sơn Tùng*/
	//Constructor
	QInt();
	QInt(int _data[4]);
	QInt(const QInt& int16);
	~QInt();

	/*Trình Xuân Vỹ*/
	//Toán tử gán
	QInt& operator=(const QInt&);
	QInt& operator=(const string);

	/*Tống Sơn Tùng*/
	//Hàm trả về kết quả xuất cho UI
	string Print_QIntDec();
	string Print_QIntBin();
	string Print_QIntHex();

	/*Tống Sơn Tùng*/
	//Hàm đọc chuỗi số cho UI
	void ScanQIntDec(string); //Hệ 10
	void ScanQIntBin(string); //Hệ 2
	void ScanQIntHex(string); //Hệ 16

	/*Tống Sơn Tùng*/
	//Hàm in chuỗi số
	void PrintQIntDec(); //Hệ 10
	void PrintQIntBin(); //Hệ 2
	void PrintQIntHex(); //Hệ 16

	//Hàm chuyển đổi giữa các hệ cơ số
	/*Bùi Khắc Trí*/
	string DecToBin(string nDec); //10 -> 2
	string BinToDec(string bit);  //2 -> 10
	/*Tống Sơn Tùng*/
	string HexToBin(string nHex); //16 -> 2
	string DecToHex(string nHex); //10 -> 16
	string BinToHex(string bit);  //2 -> 16

	/*Ừng Văn Tuấn*/
	//Toán tử AND,OR,XOR,NOT
	QInt operator&(const QInt&);
	QInt operator|(const QInt&);
	QInt operator^(const QInt&);
	QInt operator~();

	/*Ừng Văn Tuấn*/
	//Toán tử dịch phải , dịch trái
	QInt operator>>(int nBitShifted);
	QInt operator<<(int nBitShifted);

	/*Bùi Khắc Trí*/
	//Toán tử cộng,trừ,nhân,chia
	QInt operator+(const QInt&);
	QInt operator-(const QInt&);
	QInt operator*(const QInt&);
	QInt operator/(const QInt&);

	/*Ừng Văn Tuấn*/
	//Xoay trái,xoay phải
	QInt rol(int nBitRotate);
	QInt ror(int nBitRotate);

	/*Trình Xuân Vỹ*/
	//Toán tử so sánh 
	bool operator==(const QInt&) const;
	bool operator>(const QInt&) const;
	bool operator<(const QInt&) const;
	bool operator>=(const QInt&) const;
	bool operator<=(const QInt&) const;
};
//Các hàm bổ trợ

/*Bùi Khăc Trí*/
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


/*Ừng Văn Tuấn*/
//Hàm lấy bit từ số nguyên x ra mảng bit
void GetBit(int x, char bit[32]);
//Hàm gán các bit trong mảng bit vào số nguyên x
void SetBit(char bit[32], int& x);
//Hàm chuyển đổi chuỗi nhị phân(string) sang lưu vào mảng số nguyên 
void ConvertStringtoInt4(string a, int data[4]);
//Hàm chuyển đổi mảng số nguyên sang chuỗi nhị phân(string)
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





