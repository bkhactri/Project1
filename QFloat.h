#pragma once
#include <string>
#include <math.h>
#include <iostream>
#include "QInt.h"

#define arraysize 4
using namespace std;

class QFloat
{
private:

	int data[4];

public:
	int* getData() { return data; }

	QFloat(); // hàm khởi tạo
	QFloat(string FloatStringdata, int He);// hàm khởi tạo datam hệ đưa vào
	QFloat(int data[4]); // khởi tạo 
	QFloat(const QFloat& datatmp);// khởi tạo từ Qfloat
	~QFloat() {};

	void ScanQFloatBin(string databin); // Quét giá trị đưa vào data là bin
	void ScanQFloatDec(string datadec); // Quét giá trị đưa vào data là dec

	string PrintQFloat(int fraction = 0); // Xuất chuỗi float fraction là số lượng phần tử sau dấu chấm
	string BinToDec(string binQfloat, int fraction = 0); // Chuyển chuỗi bin sang float binQfloat: chuỗi bin, fraction số lượng phần tử sau dấu chấm
	string DecToBin(string decQfloat); // Chuyển chuỗi dec sang bin decQfloat là chuỗi float đưa vào

};
//Phần hàm bổ trợ 

// Chuyển dữ liệu bin từ string -> data
void ConvertBinStringtoFloat(string a, int data[4]); 
// Lấy dữ liệu từ bytes-> string
string ConvertFloattoBinString(int bytes[4]); 
//Chuyển phần nguyên sang nhị phân dec:Phần nguyên
string WholesToBin(string dec); 
// Chuyển phần thập phân sang bin, dec:0.0012355, numoffractions : só lượng bit lấy của phần thập phân
string FractionsToBin(string dec, int numoffractions); 
// chuẩn hoá chuỗi float
void StandardizedStringFloat(string& decQfloat); 
// chuẩn hoá chuỗi phần nguyên
void StandardizedWholes(string& wholes); 
 //chuẩn hoá phần thập phân
void StandardizedFractions(string& fractions);
// tìm bit 1 đầu tiên trong chuỗi nhị phân
int FindBitInFractions(string fractions); 
// chuyển phần nguyên từ bin sang dec
string WholesToDec(string bin); 
//Chuyển phần sau dấu phẩy từ bin sang dec
string FractionsToDec(string bin);
//Hàm tính 2^(-repeat)
string PowNegative(int repeat);
//Hàm thêm 0 vào cuỗi chuỗi
void FillZeroLast(string& num, int nbit);