#include"UI.h"

#define NumberOfItem 6
string item[NumberOfItem] = { "QInt 'DEC'","QInt 'BIN'","QInt 'HEX'","QFloat 'DEC' 'BIN'","INPUT 'FILE'","EXIT" };
#define NumberOfItem1 14
string item1[NumberOfItem1] = { "Convert QInt 'DEC'","+ 'DEC'","- 'DEC'","* 'DEC'","/ 'DEC'","&(and) 'DEC'","|(or) 'DEC'","^(xor) 'DEC'","~(not) 'DEC'",">> 'DEC'","<< 'DEC'","rol 'DEC'","ror 'DEC'","BACK" };
#define NumberOfItem2 14
string item2[NumberOfItem2] = { "Convert QInt 'BIN'","+ 'BIN'","- 'BIN'","* 'BIN'","/ 'BIN'","&(and) 'BIN'","|(or) 'BIN'","^(xor) 'BIN'","~(not) 'BIN'",">> 'BIN'","<< 'BIN'","rol 'BIN'","ror 'BIN'","BACK" };
#define NumberOfItem3 14
string item3[NumberOfItem3] = { "Convert QInt 'HEX'","+ 'HEX'","- 'HEX'","* 'HEX'","/ 'HEX'","&(and) 'HEX'","|(or) 'HEX'","^(xor) 'HEX'","~(not) 'HEX'",">> 'HEX'","<< 'HEX'","rol 'HEX'","ror 'HEX'","BACK" };
#define NumberOfItem4 3
string item4[NumberOfItem4] = { "Convert QFloat 'DEC'","Convert QFloat 'BIN'","BACK" };
#define NumberOfItem5 3
string item5[NumberOfItem5] = { "Input File QInt","Input File QFloat", "BACK" };

// chuyển đổi thập phân sang nhi phân, thập lục phân
void QInt_Dec()
{
	gotoxy(80, 5);
	cout << "***  Input 'QInt DEC'  ***";
	QInt a;
	string input, s, q, p, nbit;

	gotoxy(30, 11);	cin >> input;

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
	gotoxy(80, 5);
	cout << "***  Input 'QInt BIN'  ***";
	QInt a;
	string input, s, q, p;

	gotoxy(30, 11);	cin >> input;

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
	gotoxy(80, 5);
	cout << "***  Input 'QInt HEX'  ***";
	QInt a;
	string input, s, q, p;

	gotoxy(30, 11);	cin >> input;

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
	gotoxy(80, 5);
	cout << "***      '+' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '+' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '+' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '-' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '-' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '-' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '*' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '*' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '*' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '/' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '/' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '/' 'HEX'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '&' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '|' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '^' 'DEC'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '~' 'DEC'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(30, 11);	cin >> input;

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
// >> dec QInt
void ShiftRight_Dec()
{
	gotoxy(80, 5);
	cout << "***      Shift Right 'DEC'     ***";
	QInt a, b;
	string input, s, q, p, nbit;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		b = a >> count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// << dec QInt
void ShiftLeft_Dec()
{
	gotoxy(80, 5);
	cout << "***      Shift Left 'DEC'     ***";
	QInt a, b;
	string input, s, q, p, nbit;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		b = a << count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay trái Dec
void Rol_Dec()
{
	gotoxy(80, 5);
	cout << "***      rol 'DEC'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	string nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		b = a.rol(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay trái Dec
void Ror_Dec()
{
	gotoxy(80, 5);
	cout << "***      ror 'DEC'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	string nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntDec(input);
		b = a.ror(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// and bin QInt
void And_Bin()
{
	gotoxy(80, 5);
	cout << "***      '&' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '|' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '^' 'BIN'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '~' 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(30, 11);	cin >> input;

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
// >> bin QInt
void ShiftRight_Bin()
{
	gotoxy(80, 5);
	cout << "***      Shift Right 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		b = a >> count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// << bin QInt
void ShiftLeft_Bin()
{
	gotoxy(80, 5);
	cout << "***      Shift Left 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		b = a << count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay trái Bin
void Rol_Bin()
{
	gotoxy(80, 5);
	cout << "***      rol 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		b = a.rol(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay trái Bin
void Ror_Bin()
{
	gotoxy(80, 5);
	cout << "***      ror 'BIN'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	if (input.size() > 128 || checkBin(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntBin(input);
		b = a.ror(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// and bin QInt
void And_Hex()
{
	gotoxy(80, 5);
	cout << "***      '&' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '|' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '^' 'Hex'     ***";
	QInt a, b, c;
	string input, x, y, s, q, p;

	gotoxy(30, 9);	cin >> x;
	gotoxy(30, 13);	cin >> y;

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
	gotoxy(80, 5);
	cout << "***      '~' 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;

	gotoxy(30, 11);	cin >> input;

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
// >> hex QInt
void ShiftRight_Hex()
{
	gotoxy(80, 5);
	cout << "***      Shift Right 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		b = a >> count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// << hex QInt
void ShiftLeft_Hex()
{
	gotoxy(80, 5);
	cout << "***      Shift Left 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13); cin >> count;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		b = a << count;
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay trái Hex
void Rol_Hex()
{
	gotoxy(80, 5);
	cout << "***      rol 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		b = a.rol(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}
// xoay tráiHex
void Ror_Hex()
{
	gotoxy(80, 5);
	cout << "***      ror 'Hex'     ***";
	QInt a, b;
	string input, s, q, p;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		outputInvalidQInt();
	}
	else
	{
		a.ScanQIntHex(input);
		b = a.ror(count);
		s = b.Print_QIntBin();
		q = b.Print_QIntDec();
		p = b.Print_QIntHex();
		OutPut(s, q, p);
	}
}

// chuyển đổi thập phân sang nhị phân (QFloat)
void QFloat_Dec()
{
	gotoxy(80, 5);
	cout << "*** Input 'QFloat DEC' ***";
	// To do here
	string input, temp, s, q, p = "";
	QFloat a;

	gotoxy(30, 11);	cin >> input;

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
	gotoxy(80, 5);
	cout << "*** Input 'QFloat BIN' ***";

	// To do here
	string input, temp, s, q, p = "";
	QFloat a;
	int count;

	gotoxy(30, 9);	cin >> input;
	gotoxy(30, 13);	cin >> count;

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
	int line = 3;

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
				if (line >= NumberOfItem1 + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 3)
				{
					line = NumberOfItem1 - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					Frame_2();
					QInt_Dec();
					checkEnter();
					break;
				}
				case 4:
				{
					Frame_1();
					Plus_Dec();
					checkEnter();
					break;
				}
				case 5:
				{
					Frame_1();
					Minus_Dec();
					checkEnter();
					break;
				}
				case 6:
				{
					Frame_1();
					Mul_Dec();
					checkEnter();
					break;
				}
				case 7:
				{
					Frame_1();
					Div_Dec();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					And_Dec();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Or_Dec();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Xor_Dec();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_2();
					Not_Dec();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_5();
					ShiftRight_Dec();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_5();
					ShiftLeft_Dec();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_6();
					Rol_Dec();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_6();
					Ror_Dec();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 3);
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
	int line = 3;

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
				if (line >= NumberOfItem2 + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 3)
				{
					line = NumberOfItem2 - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					Frame_2();
					QInt_Bin();
					checkEnter();
					break;
				}
				case 4:
				{
					Frame_1();
					Plus_Bin();
					checkEnter();
					break;
				}
				case 5:
				{
					Frame_1();
					Minus_Bin();
					checkEnter();
					break;
				}
				case 6:
				{
					Frame_1();
					Mul_Bin();
					checkEnter();
					break;
				}
				case 7:
				{
					Frame_1();
					Div_Bin();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					And_Bin();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Or_Bin();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Xor_Bin();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_2();
					Not_Bin();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_5();
					ShiftRight_Bin();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_5();
					ShiftLeft_Bin();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_6();
					Rol_Bin();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_6();
					Ror_Bin();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 3);
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
	int line = 3;

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
				if (line >= NumberOfItem3 + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 3)
				{
					line = NumberOfItem3 - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					Frame_2();
					QInt_Hex();
					checkEnter();
					break;
				}
				case 4:
				{
					Frame_1();
					Plus_Hex();
					checkEnter();
					break;
				}
				case 5:
				{
					Frame_1();
					Minus_Hex();
					checkEnter();
					break;
				}
				case 6:
				{
					Frame_1();
					Mul_Hex();
					checkEnter();
					break;
				}
				case 7:
				{
					Frame_1();
					Div_Hex();
					checkEnter();
					break;
				}
				case 8:
				{
					Frame_1();
					And_Hex();
					checkEnter();
					break;
				}
				case 9:
				{
					Frame_1();
					Or_Hex();
					checkEnter();
					break;
				}
				case 10:
				{
					Frame_1();
					Xor_Hex();
					checkEnter();
					break;
				}
				case 11:
				{
					Frame_2();
					Not_Hex();
					checkEnter();
					break;
				}
				case 12:
				{
					Frame_5();
					ShiftRight_Hex();
					checkEnter();
					break;
				}
				case 13:
				{
					Frame_5();
					ShiftLeft_Hex();
					checkEnter();
					break;
				}
				case 14:
				{
					Frame_6();
					Rol_Hex();
					checkEnter();
					break;
				}
				case 15:
				{
					Frame_6();
					Ror_Hex();
					checkEnter();
					break;
				}
				case 16:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 3);
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
	int line = 3;

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
				if (line >= NumberOfItem4 + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 5)
				{
					line = NumberOfItem4 - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					Frame_2();
					QFloat_Dec();
					checkEnter();
					break;
				}
				case 4:
				{
					Frame_3();
					QFloat_Bin();
					checkEnter();
					break;
				}
				case 5:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 3);
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
	gotoxy(3, 5);
	cout << " ";
}

//file QInt
void inputFileQInt()
{
	gotoxy(80, 5);
	cout << "***     Input FILE QInt   ***";
	string link = "D:\\";
	string filename;

	gotoxy(30, 9);	cin >> filename;

	link += filename;
	ReadFileQInt(link);
	gotoxy(64, 23); cout << "OK";
}
//file QFloat
void inputFileQFloat()
{
	gotoxy(80, 5);
	cout << "***     Input FILE QFloat  ***";
	string link = "D:\\";
	string filename;

	gotoxy(30, 9);	cin >> filename;

	link += filename;
	ReadFileQFloat(link);
	gotoxy(64, 23); cout << "OK";
}
// menu nhỏ nhập file
void menuFile(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 3;

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
				if (line >= NumberOfItem5 + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 3)
				{
					line = NumberOfItem5 - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					Frame_4();
					inputFileQInt();
					checkEnter();
					break;
				}
				case 4:
				{
					Frame_4();
					inputFileQFloat();
					checkEnter();
					break;
				}
				case 5:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(5, i + 3);
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
	gotoxy(3, 5);
	cout << " ";
}

int main()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	setColor(11);
	Nocursortype();

	bool exit = true;
	int line = 3;					// Vi tri dong menu
	int move;						// Nhan phim di chuyen

	BigFrame();

	for (int i = 0; i < NumberOfItem; i++)
	{
		gotoxy(5, i + 3);
		cout << item[i];
		Sleep(50);
	}
	gotoxy(3, line);				// Tro menu
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
				if (line >= NumberOfItem + 3)
				{
					line = 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 2:
			{
				line--;
				if (line < 3)
				{
					line = NumberOfItem - 1 + 3;
				}
				gotoxy(3, line);
				cout << char(175);
				break;
			}
			case 3:
			{
				switch (line)
				{
				case 3:
				{
					menuQIntDec(line);
					break;
				}
				case 4:
				{
					menuQIntBin(line);
					break;
				}
				case 5:
				{
					menuQIntHex(line);
					break;
				}
				case 6:
				{
					menuQFLoat(line);
					break;
				}
				case 7:
				{
					menuFile(line);
					break;
				}
				case 8:
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