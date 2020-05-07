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
	void ScanQFloat();
	string PrintQFloat(int fraction = 0);
	string BinToDec(string binQfloat, int fraction = 0);
	string DecToBin(string decQfloat);
	int* getData() { return data; }
	QFloat();
	QFloat(string FloatStringdata, int He);
	QFloat(int data[4]);
	QFloat(const QFloat& datatmp);
	~QFloat() {};
};

//void GetBit(int x, char bit[32]);
//void SetBit(char bit[32], int& x);

void ConvertBinStringtoFloat(string a, int data[4]);
string ConvertFloattoBinString(int bytes[4]);
string WholesToBin(string dec);
string FractionsToBin(string dec, int numoffractions);
void StandardizedStringFloat(string& decQfloat);
void StandardizedWholes(string& wholes);
void StandardizedFractions(string& fractions);
int FindBitInFractions(string fractions);
string WholesToDec(string bin);
string FractionsToDec(string bin);
string PowNegative(int repeat);
void FillZeroLast(string& num, int nbit);