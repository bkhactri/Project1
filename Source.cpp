#include"QInt.h"
#include"UI.h"
#include"QFloat.h"
#include<fstream>
#define GETTEST 1000

#define NumberOfItem 6
string item[NumberOfItem] = { "QInt 'DEC'","QInt 'BIN'","QInt 'HEX'","QFloat 'DEC' 'BIN'","INPUT 'FILE'","EXIT" };
#define NumberOfItem1 10
string item1[NumberOfItem1] = { "Convert QInt 'DEC'","+ 'DEC'","- 'DEC'","* 'DEC'","/ 'DEC'","&(and) 'DEC'","|(or) 'DEC'","^(xor) 'DEC'","~(not) 'DEC'","BACK" };
#define NumberOfItem2 10
string item2[NumberOfItem2] = { "Convert QInt 'BIN'","+ 'BIN'","- 'BIN'","* 'BIN'","/ 'BIN'","&(and) 'BIN'","|(or) 'BIN'","^(xor) 'BIN'","~(not) 'BIN'","BACK" };
#define NumberOfItem3 10
string item3[NumberOfItem3] = { "Convert QInt 'HEX'","+ 'HEX'","- 'HEX'","* 'HEX'","/ 'HEX'","&(and) 'HEX'","|(or) 'HEX'","^(xor) 'HEX'","~(not) 'HEX'","BACK" };
#define NumberOfItem4 3
string item4[NumberOfItem4] = { "Convert QFloat 'DEC'","Convert QFloat 'BIN'","BACK" };
#define NumberOfItem5 3
string item5[NumberOfItem5] = { "Input File QInt","Input File QFloat", "BACK" };

// chuyển đổi thập phân sang nhi phân, thập lục phân
void QInt_Dec()
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt DEC'  ***";
	QInt a;
	string input, s, q, p, nbit;

	gotoxy(37, 11);	cin >> input;

	nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		s = a.Print_QIntBin();
		q = a.Print_QIntDec();
		p = a.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// chuyển đổi  nhi phân sang thập phân, thập lục phân
void QInt_Bin()
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt BIN'  ***";
	QInt a;
	string input, s, q, p;

	gotoxy(37, 11);	cin >> input;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		s = a.Print_QIntBin();
		q = a.Print_QIntDec();
		p = a.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// chuyển đổi thập lục phân sang nhi phân, thập phân
void QInt_Hex()
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt HEX'  ***";
	QInt a;
	string input, s, q, p;

	gotoxy(37, 11);	cin >> input;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		s = a.Print_QIntBin();
		q = a.Print_QIntDec();
		p = a.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// cộng thập phân
void Plus_Dec() // + Dec
{
	gotoxy(80, 7);
	cout << "***      '+' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a + b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// cộng nhị phân
void Plus_Bin()  // + Bin
{
	gotoxy(80, 7);
	cout << "***      '+' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a + b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// cộng thập lục phân
void Plus_Hex() // + Hex
{
	gotoxy(80, 7);
	cout << "***      '+' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a + b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// trừ thập phân
void Minus_Dec() // - Dec
{
	gotoxy(80, 7);
	cout << "***      '-' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a - b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// trừ nhị phân
void Minus_Bin() // - Bin
{
	gotoxy(80, 7);
	cout << "***      '-' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a - b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// trừ thập lục phân
void Minus_Hex() // - Hex
{
	gotoxy(80, 7);
	cout << "***      '-' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a - b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// nhân thập phân
void Mul_Dec()
{
	gotoxy(80, 7);
	cout << "***      '*' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a * b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// nhân nhị phân
void Mul_Bin()
{
	gotoxy(80, 7);
	cout << "***      '*' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a * b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// nhân thập lục phân
void Mul_Hex() // * Hex
{
	gotoxy(80, 7);
	cout << "***      '*' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = c.HexToBin(x);
	string nbit2 = c.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a * b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// chia thập phân
void Div_Dec() // / Dec
{
	gotoxy(80, 7);
	cout << "***      '/' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0 || checkDiv(nbit2) == 1)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a / b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// chia nhị phân
void Div_Bin() // / Bin
{
	gotoxy(80, 7);
	cout << "***      '/' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0 || checkDiv(y) == 1)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a / b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// chia thập lục phân
void Div_Hex() // / Hex
{
	gotoxy(80, 7);
	cout << "***      '/' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string l = a.HexToBin(x);
	string k = b.HexToBin(y);
	if (l.size() > 128 || k.size() > 128 || checkHex(l) == 0 || checkHex(k) == 0 || checkDiv(k) == 1)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(l);
		b.ScanQIntHex(k);
		c = a / b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// and dec QInt
void And_Dec()
{
	gotoxy(80, 7);
	cout << "***      '&' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a & b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// or dec QInt
void Or_Dec()
{
	gotoxy(80, 7);
	cout << "***      '|' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a | b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xor dec QInt
void Xor_Dec()
{
	gotoxy(80, 7);
	cout << "***      '^' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntDec(x);
		b.ScanQIntDec(y);
		c = a ^ b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// not bin QInt
void Not_Dec()
{
	gotoxy(80, 7);
	cout << "***      '~' 'DEC'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(37, 11);	cin >> input;

	string nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		b = ~a;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// and bin QInt
void And_Bin()
{
	gotoxy(80, 7);
	cout << "***      '&' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a & b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// or bin QInt
void Or_Bin()
{
	gotoxy(80, 7);
	cout << "***      '|' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a | b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xor bin QInt
void Xor_Bin()
{
	gotoxy(80, 7);
	cout << "***      '^' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(x);
		b.ScanQIntBin(y);
		c = a ^ b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// not bin QInt
void Not_Bin()
{
	gotoxy(80, 7);
	cout << "***      '~' 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(37, 11);	cin >> input;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		b = ~a;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// and bin QInt
void And_Hex()
{
	gotoxy(80, 7);
	cout << "***      '&' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a & b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// or hex QInt
void Or_Hex()
{
	gotoxy(80, 7);
	cout << "***      '|' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a | b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xor hex QInt
void Xor_Hex()
{
	gotoxy(80, 7);
	cout << "***      '^' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(37, 9);	cin >> x;
	gotoxy(37, 13);	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		outputInvalidQInt();
	}
	else {
		a.ScanQIntHex(x);
		b.ScanQIntHex(y);
		c = a ^ b;
		s = c.Print_QIntBin();
		q = c.Print_QIntDec();
		p = c.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// not hex QInt
void Not_Hex()
{
	gotoxy(80, 7);
	cout << "***      '~' 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(37, 11);	cin >> input;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		b = ~a;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}

// chuyển đổi thập phân sang nhị phân (QFloat)
void QFloat_Dec()
{
	gotoxy(80, 7);
	cout << "*** Input 'QFloat DEC' ***";
	// To do here
	string input, temp, s, q, p = "";
	QFloat a;

	gotoxy(37, 11);	cin >> input;

	if (checkQFloatDec(input) == 0)
	{
		outputInvalidQFloat();
	}
	else
	{
		a.ScanQFloatDec(input);
		s = a.DecToBin(input);
		q = a.BinToDec(s);
		OutPut(s, q, p);
	}
}
// chuyển đổi nhị phân sang thập phân (QFloat)
void QFloat_Bin()
{
	gotoxy(80, 7);
	cout << "*** Input 'QFloat BIN' ***";

	// To do here
	string input, temp, s, q, p = "";
	QFloat a;
	int count;

	gotoxy(37, 9);	cin >> input;
	gotoxy(37, 13);	cin >> count;

	if (checkBin(input) == 0)
	{
		outputInvalidQFloat();
	}
	else
	{
		q = a.BinToDec(input, count);
		s = a.DecToBin(q);
		OutPut(s, q, p);
	}
}
// thoát
void Exit()
{
	system("cls");
	while (1)
	{
		srand(time(NULL));
		int color = rand() % 15 + 1;
		setColor(color);
		Sleep(10);
		gotoxy(15, 17);  printf("                     ########        ######        ######      ######       ######   ##      ##  #######    ##");
		gotoxy(15, 18);  printf("                    ##      ##      ##    ##      ##    ##     ##    ##     ##    ##  ##    ##   ##         ##");
		gotoxy(15, 19);  printf("                   ##              ##      ##    ##      ##    ##     ##    ##   ##    ##  ##    ##         ##");
		gotoxy(15, 20); printf("                  ##              ##        ##  ##        ##   ##      ##   ## ##       ####     #######    ##");
		gotoxy(15, 21); printf("                 ##      ######  ##         ## ##         ##   ##       ##  ##   ##      ##      ##         ##");
		gotoxy(15, 22); printf("                  ##       ##     ##       ##   ##       ##    ##      ##   ##    ##     ##      ##         ##");
		gotoxy(15, 23); printf("                   ##     ##       ##    ##      ##    ##      ##    ##     ##    ##     ##      ##           ");
		gotoxy(15, 24); printf("                    #######         ######        ######       ######       ######       ##      ########   ##");
		gotoxy(15, 25); printf("                                                        See You Again ...");
	}
}

// menu nhỏ Dec QInt
void menuQIntDec(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem1; i++)
	{
		gotoxy(5, line + i);
		cout << item1[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";


			deleteInput();
			deleteOutPut();

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem1 + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem1 - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					Frame_2();
					QInt_Dec();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Dec();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Dec();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Dec();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Dec();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Dec();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Dec();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Dec();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Dec();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 7);
						cout << item[i];
						Sleep(50);
					}
					exit = false;
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			gotoxy(3, line);
			cout << char(175);
		}
	}
	gotoxy(3, li);
	cout << char(175);
	gotoxy(3, 16);
	cout << " ";
}
// menu nhỏ Bin QInt
void menuQIntBin(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem2; i++)
	{
		gotoxy(5, line + i);
		cout << item2[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";

			deleteInput();
			deleteOutPut();

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem2 + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem2 - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					Frame_2();
					QInt_Bin();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Bin();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Bin();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Bin();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Bin();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Bin();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Bin();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Bin();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Bin();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 7);
						cout << item[i];
						Sleep(50);
					}
					exit = false;
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			gotoxy(3, line);
			cout << char(175);
		}
	}
	gotoxy(3, li);
	cout << char(175);
	gotoxy(3, 16);
	cout << " ";
}
// menu nhỏ Hex QInt
void menuQIntHex(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem3; i++)
	{
		gotoxy(5, line + i);
		cout << item3[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";

			deleteInput();
			deleteOutPut();

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem3 + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem3 - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					Frame_2();
					QInt_Hex();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Hex();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Hex();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Hex();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Hex();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Hex();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Hex();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Hex();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Hex();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 7);
						cout << item[i];
						Sleep(50);
					}
					exit = false;
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			gotoxy(3, line);
			cout << char(175);
		}
	}
	gotoxy(3, li);
	cout << char(175);
	gotoxy(3, 16);
	cout << " ";
}
// menu nhỏ QFloat
void menuQFLoat(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem4; i++)
	{
		gotoxy(5, line + i);
		cout << item4[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";

			deleteInput();
			deleteOutPut();

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem4 + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem4 - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					Frame_2();
					QFloat_Dec();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_3();
					QFloat_Bin();
					checkEnter();
					break;
				}
				case 9:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 7);
						cout << item[i];
						Sleep(50);
					}
					exit = false;
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			gotoxy(3, line);
			cout << char(175);
		}
	}
	gotoxy(3, li);
	cout << char(175);
	gotoxy(3, 9);
	cout << " ";
}

// đọc file QInt
void ReadFileQInt(string input)
{
	ifstream in1;
	in1.open(input);
	char buffer[GETTEST];
	int LineSize = 0;
	while (!in1.eof())
	{
		char temp[GETTEST];
		in1.getline(temp, GETTEST);
		LineSize++;
	}
	int* BlockSize = new int[LineSize];
	for (int i = 0; i < LineSize; i++)
	{
		BlockSize[i] = 0;
	}
	string** block = new string * [LineSize];
	ifstream in2;
	in2.open(input);
	int stt = 0;
	while (!in2.eof())
	{
		char temp[GETTEST];
		in2.getline(temp, GETTEST);
		string line = temp;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ' || i == line.size() - 1)
			{
				BlockSize[stt]++;
			}
		}
		block[stt] = new string[BlockSize[stt]];
		int blockstt = 0;
		int head = 0;
		for (int i = 0; i < line.size(); i++)
		{

			if (line[i] == ' ')
			{
				for (int j = head; j < i; j++)
				{
					block[stt][blockstt].push_back(line[j]);
				}
				blockstt++;
				head = i + 1;
			}
			if (i == line.size() - 1)
			{
				for (int j = head; j <= i; j++)
				{
					block[stt][blockstt].push_back(line[j]);
				}
				blockstt++;
			}
		}
		stt++;
	}
	ofstream of;
	of.open("D:\\output.txt");
	for (int i = 0; i < LineSize; i++)
	{
		if (BlockSize[i] == 4)
		{
			QInt a, b, kq;
			int compair = 0;
			if (block[i][0] == "2")
			{
				a.ScanQIntBin(block[i][1]);
				b.ScanQIntBin(block[i][3]);
			}
			else if (block[i][0] == "10")
			{
				a.ScanQIntDec(block[i][1]);
				b.ScanQIntDec(block[i][3]);
			}
			else if (block[i][0] == "16")
			{
				a.ScanQIntHex(block[i][1]);
				b.ScanQIntHex(block[i][3]);
			}
			if (block[i][2] == "+")
			{
				kq = a + b;
			}
			else if (block[i][2] == "-")
			{
				kq = a - b;
			}
			else if (block[i][2] == "*")
			{
				kq = a * b;
			}
			else if (block[i][2] == "/")
			{
				kq = a / b;
			}
			else if (block[i][2] == ">>")
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a >> nbit;
			}
			else if (block[i][2] == "<<")
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a << nbit;
			}
			else if (block[i][2] == "^")
			{
				kq = a ^ b;
			}
			else if (block[i][2] == "&")
			{
				kq = a & b;
			}
			else if (block[i][2] == "|")
			{
				kq = a | b;
			}
			else if (block[i][2] == "rol")
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a.rol(nbit);
			}
			else if (block[i][2] == "ror")
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a.ror(nbit);
			}
			else if (block[i][2] == "<")
			{
				compair = 1;
				if (a < b)
				{
					kq = "1";
				}
				else
				{
					kq = "0";
				}
			}
			else if (block[i][2] == ">")
			{
				compair = 1;
				if (a > b)
				{
					kq = "1";
				}
				else
				{
					kq = "0";
				}
			}
			else if (block[i][2] == "<=")
			{
				compair = 1;
				if (a <= b)
				{
					kq = "1";
				}
				else
				{
					kq = "0";
				}
			}
			else if (block[i][2] == ">=")
			{
				compair = 1;
				if (a >= b)
				{
					kq = "1";
				}
				else
				{
					kq = "0";
				}
			}
			else if (block[i][2] == "==")
			{
				compair = 1;
				if (a == b)
				{
					kq = "1";
				}
				else
				{
					kq = "0";
				}
			}
			if (compair == 0)
			{
				if (block[i][0] == "2")
				{
					of << kq.Print_QIntBin() << endl;
				}
				else if (block[i][0] == "10")
				{
					of << kq.Print_QIntDec() << endl;
				}
				else if (block[i][0] == "16")
				{
					of << kq.Print_QIntHex() << endl;
				}
			}
			else
			{
				if (kq.Print_QIntDec() == "1")
				{
					of << "true" << endl;
				}
				else
				{
					of << "false" << endl;
				}
			}
		}
		else
		{
			QInt kq;
			if (block[i][0] == "2")
			{
				kq.ScanQIntBin(block[i][2]);
				if (block[i][1] == "10")
				{
					of << kq.Print_QIntDec() << endl;
				}
				else if (block[i][1] == "16")
				{
					of << kq.Print_QIntHex() << endl;
				}
				else
				{
					QInt a = ~kq;
					of << a.Print_QIntBin() << endl;
				}
			}
			else if (block[i][0] == "10")
			{
				kq.ScanQIntDec(block[i][2]);
				if (block[i][1] == "2")
				{
					of << kq.Print_QIntBin() << endl;
				}
				else if (block[i][1] == "16")
				{
					of << kq.Print_QIntHex() << endl;
				}
				else
				{
					QInt a = ~kq;
					of << a.Print_QIntDec() << endl;
				}
			}
			else if (block[i][0] == "16")
			{
				kq.ScanQIntHex(block[i][2]);
				if (block[i][1] == "2")
				{
					of << kq.Print_QIntBin() << endl;
				}
				else if (block[i][1] == "10")
				{
					of << kq.Print_QIntDec() << endl;
				}
				else
				{
					QInt a = ~kq;
					of << a.Print_QIntHex() << endl;
				}
			}
		}
	}
	for (int i = 0; i < LineSize; i++)
	{
		delete[]block[i];
	}
	delete[] block;
	delete[] BlockSize;
	in1.clear();
	in2.clear();
	of.clear();
	ShellExecuteW(NULL, L"open", L"D:\\output.txt", L"", L"D:", SW_SHOW);
}
// đọc file QFloat
void ReadFileQFloat(string input)
{
	ifstream in1;
	in1.open(input);
	char buffer[GETTEST];
	int LineSize = 0;
	while (!in1.eof())
	{
		char temp[GETTEST];
		in1.getline(temp, GETTEST);
		LineSize++;
	}
	int* BlockSize = new int[LineSize];
	for (int i = 0; i < LineSize; i++)
	{
		BlockSize[i] = 0;
	}
	string** block = new string * [LineSize];
	ifstream in2;
	in2.open(input);
	int stt = 0;
	while (!in2.eof())
	{
		char temp[GETTEST];
		in2.getline(temp, GETTEST);
		string line = temp;
		for (int i = 0; i < line.size(); i++)
		{
			if (line[i] == ' ' || i == line.size() - 1)
			{
				BlockSize[stt]++;
			}
		}
		block[stt] = new string[BlockSize[stt]];
		int blockstt = 0;
		int head = 0;
		for (int i = 0; i < line.size(); i++)
		{

			if (line[i] == ' ')
			{
				for (int j = head; j < i; j++)
				{
					block[stt][blockstt].push_back(line[j]);
				}
				blockstt++;
				head = i + 1;
			}
			if (i == line.size() - 1)
			{
				for (int j = head; j <= i; j++)
				{
					block[stt][blockstt].push_back(line[j]);
				}
				blockstt++;
			}
		}
		stt++;
	}
	ofstream of;
	of.open("D:\\output.txt");
	for (int i = 0; i < LineSize; i++)
	{
		QFloat kq;
		if (block[i][0] == "2")
		{
			of << kq.BinToDec(block[i][2]) << endl;
		}
		else
		{
			of << kq.DecToBin(block[i][2]) << endl;
		}

	}
	for (int i = 0; i < LineSize; i++)
	{
		delete[]block[i];
	}
	delete[] block;
	delete[] BlockSize;
	in1.clear();
	in2.clear();
	of.clear();
	ShellExecuteW(NULL, L"open", L"D:\\output.txt", L"", L"D:", SW_SHOW);
}
//file QInt
void inputFileQInt()
{
	gotoxy(80, 7);
	cout << "***     Input FILE QInt   ***";
	string link = "D:\\";
	string filename;

	gotoxy(37, 11);	cin >> filename;

	link += filename;
	ReadFileQInt(link);
	gotoxy(64, 23); cout << "OK";
}
//file QFloat
void inputFileQFloat()
{
	gotoxy(80, 7);
	cout << "***     Input FILE QFloat  ***";
	string link = "D:\\";
	string filename;

	gotoxy(37, 11);	cin >> filename;

	link += filename;
	ReadFileQFloat(link);
	gotoxy(64, 23); cout << "OK";
}
// menu nhỏ nhập file
void menuFile(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem5; i++)
	{
		gotoxy(5, line + i);
		cout << item5[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";

			deleteInput();
			deleteOutPut();

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem5 + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem5 - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					Frame_4();
					inputFileQInt();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_4();
					inputFileQFloat();
					checkEnter();
					break;
				}
				case 9:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 7);
						cout << item[i];
						Sleep(50);
					}
					exit = false;
					break;
				}
				default:
					break;
				}
				break;
			}
			default:
				break;
			}
			gotoxy(3, line);
			cout << char(175);
		}
	}
	gotoxy(3, li);
	cout << char(175);
	gotoxy(3, 9);
	cout << " ";
}

int main()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	setColor(11);
	Nocursortype();

	bool exit = true;
	int line = 7;					// Vi tri dong menu
	int move;						// Nhan phim di chuyen

	BigFrame();

	for (int i = 0; i < NumberOfItem; i++)
	{
		gotoxy(5, i + 7);
		cout << item[i];
		Sleep(50);
	}
	gotoxy(3, 7);				// Tro menu
	cout << char(175);

	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(3, line);
			cout << " ";

			switch (move)
			{
			case 1:
			{
				line++;
				if (line >= NumberOfItem + 7)
				{
					line = 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 7)
				{
					line = NumberOfItem - 1 + 7;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 7:
				{
					menuQIntDec(line);
					break;
				}
				case 8:
				{
					menuQIntBin(line);
					break;
				}
				case 9:
				{
					menuQIntHex(line);
					break;
				}
				case 10:
				{
					menuQFLoat(line);
					break;
				}
				case 11:
				{
					menuFile(line);
					break;
				}
				case 12:
				{
					Exit();
					exit = false;
					break;
				}
				default:
					break;
				}
			}
			default:
				break;
			}
		}
	}
	return 0;
}