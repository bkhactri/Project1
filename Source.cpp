#include"QInt.h"
#include"UI.h"
#include"QFloat.h"

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

// chuyển đổi thập phân sang nhi phân, thập lục phân
void QInt_Dec()			//QInt Dec to ...
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt DEC'  ***";

	// To do here	
	string input, s, q, p;
	QInt a;
	gotoxy(77, 11);
	cin >> input;
	string nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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
void QInt_Bin()			//QInt  Bin to ...
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt BIN'  ***";

	//To do here
	string input, s, q, p;
	QInt a;
	gotoxy(77, 11);
	cin >> input;
	if (input.size() > 128 || checkBin(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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
void QInt_Hex()			//QInt  Hex to ...
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt HEX'  ***";

	// To do here
	string input, s, q, p;
	QInt a;
	gotoxy(77, 11);
	cin >> input;
	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;
	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
	}
	else {
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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
void Mul_Dec() // * Dec
{
	gotoxy(80, 7);
	cout << "***      '*' 'DEC'     ***";

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
	}
	else {
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
void Mul_Bin() // * Bin
{
	gotoxy(80, 7);
	cout << "***      '*' 'BIN'     ***";

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
	}
	else {
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0 || checkDiv(nbit2) == 1)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;
	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0 || checkDiv(y) == 1)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string l = a.HexToBin(x);
	string k = a.HexToBin(y);

	if (l.size() > 128 || k.size() > 128 || checkHex(l) == 0 || checkHex(k) == 0 || checkDiv(k) == 1)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
	}
	else {
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
	}
	else {
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.DecToBin(x);
	string nbit2 = b.DecToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkDec(x) == 0 || checkDec(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here	
	string input, s, q, p;
	QInt a, b;
	gotoxy(77, 11);
	cin >> input;
	string nbit = a.DecToBin(input);
	if (nbit.size() > 128 || checkDec(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	if (x.size() > 128 || y.size() > 128 || checkBin(x) == 0 || checkBin(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	//To do here
	string input, s, q, p;
	QInt a, b;
	gotoxy(77, 11);
	cin >> input;
	if (input.size() > 128 || checkBin(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here
	string input, x, y, s, q, p;
	QInt a, b, c;
	gotoxy(77, 9);
	cin >> x;
	gotoxy(77, 13);
	cin >> y;

	string nbit1 = a.HexToBin(x);
	string nbit2 = b.HexToBin(y);
	if (nbit1.size() > 128 || nbit2.size() > 128 || checkHex(x) == 0 || checkHex(y) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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

	// To do here	
	string input, s, q, p;
	QInt a, b;
	gotoxy(77, 11);
	cin >> input;
	string nbit = a.HexToBin(input);
	if (nbit.size() > 128 || checkHex(input) == 0)
	{
		gotoxy(50, 20); cout << "Invalid";
		gotoxy(91, 20); cout << "Invalid";
		gotoxy(130, 20); cout << "Invalid";
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
	string input, s, q = "", p = "";
	QFloat a;
	gotoxy(77, 11);

}
// chuyển đổi nhị phân sang thập phân (QFloat)
void QFloat_Bin()
{
	gotoxy(80, 7);
	cout << "*** Input 'QFloat BIN' ***";

	// To do here

}

//file
void inputFile()
{
	gotoxy(80, 7);
	cout << "***     Input 'FILE'   ***";

	// To do here

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
		gotoxy(25, line + i);
		cout << item1[i];
		Sleep(50);
	}
	gotoxy(23, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(23, line);
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
				gotoxy(23, line);
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
				gotoxy(23, line);
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
						gotoxy(25, i + 7);
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
			gotoxy(23, line);
			cout << char(175);
		}
	}
	gotoxy(23, li);
	cout << char(175);
	gotoxy(23, 16);
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
		gotoxy(25, line + i);
		cout << item2[i];
		Sleep(50);
	}
	gotoxy(23, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(23, line);
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
				gotoxy(23, line);
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
				gotoxy(23, line);
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
						gotoxy(25, i + 7);
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
			gotoxy(23, line);
			cout << char(175);
		}
	}
	gotoxy(23, li);
	cout << char(175);
	gotoxy(23, 16);
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
		gotoxy(25, line + i);
		cout << item3[i];
		Sleep(50);
	}
	gotoxy(23, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(23, line);
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
				gotoxy(23, line);
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
				gotoxy(23, line);
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
						gotoxy(25, i + 7);
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
			gotoxy(23, line);
			cout << char(175);
		}
	}
	gotoxy(23, li);
	cout << char(175);
	gotoxy(23, 16);
	cout << " ";
}
// menu nhỏ QFloat
void menuQFLoat(int li)
{
	deleteMenu();

	bool exit = true;
	int line = 7;

	for (int i = 0; i < NumberOfItem3; i++)
	{
		gotoxy(25, line + i);
		cout << item4[i];
		Sleep(50);
	}
	gotoxy(23, line);				// Tro menu
	cout << char(175);

	int move;
	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(23, line);
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
				gotoxy(23, line);
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
				gotoxy(23, line);
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
					Frame_2();
					QFloat_Bin();
					checkEnter();
					break;
				}
				case 9:
				{
					deleteMenu();
					for (int i = 0; i < NumberOfItem; i++)
					{
						gotoxy(25, i + 7);
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
			gotoxy(23, line);
			cout << char(175);
		}
	}
	gotoxy(23, li);
	cout << char(175);
	gotoxy(23, 9);
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
		gotoxy(25, i + 7);
		cout << item[i];
		Sleep(50);
	}
	gotoxy(23, line);				// Tro menu
	cout << char(175);

	while (exit == true)
	{

		if (_kbhit())
		{
			move = Move();
			gotoxy(23, line);
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
				gotoxy(23, line);
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
				gotoxy(23, line);
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
					Frame_2();
					inputFile();
					checkEnter();
					gotoxy(23, 11); cout << char(175);
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