#include"QInt.h"
#include"UI.h"
#include"QFloat.h"

#define NumberOfItem 5
string item[NumberOfItem] = { "QInt 'DEC'","QInt 'BIN'","QInt 'HEX'","INPUT 'FILE'","EXIT" };

#define NumberOfItem1 10
string item1[NumberOfItem1] = { "Convert QInt 'DEC'","+ 'DEC'","- 'DEC'","* 'DEC'","/ 'DEC'","&(and) 'DEC'","|(or) 'DEC'","^(xor) 'DEC'","~(not) 'DEC'","BACK" };
#define NumberOfItem2 10
string item2[NumberOfItem2] = { "Convert QInt 'BIN'","+ 'BIN'","- 'BIN'","* 'BIN'","/ 'BIN'","&(and) 'BIN'","|(or) 'BIN'","^(xor) 'BIN'","~(not) 'BIN'","BACK" };
#define NumberOfItem3 10
string item3[NumberOfItem3] = { "Convert QInt 'HEX'","+ 'HEX'","- 'HEX'","* 'HEX'","/ 'HEX'","&(and) 'HEX'","|(or) 'HEX'","^(xor) 'HEX'","~(not) 'HEX'","BACK" };

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
	if (nbit.size() > 128)
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

void QInt_Bin()			//QInt  Bin to ...
{
	gotoxy(80, 7);
	cout << "***  Input 'QInt BIN'  ***";

	//To do here
	string input, s, q, p;
	QInt a;
	gotoxy(77, 11);
	cin >> input;
	if (input.size() > 128)
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
	if (nbit.size() > 128)
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

/*void QFloat_Dec()		//QFloat Dec to ...
{
	gotoxy(80, 7);
	cout << "*** Input 'QFloat DEC' ***";
	// To do here

	string input, s, q = "", p = "";
	QFloat a;
	gotoxy(77, 11);
	cin >> input;
	a.ScanQFloat(input);

	s = a.Print_QFloat();
	OutPut(s, q, p);
}*/

//void QFloat_Bin()			//QFloat Bin to ...
//{
//	gotoxy(80, 7);
//	cout << "*** Input 'QFloat BIN' ***";
//
//	// To do here
//
//}

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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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

	if (l.size() > 128 || k.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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

	if (x.size() > 128 || y.size() > 128)
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

void Not_Bin()
{
	gotoxy(80, 7);
	cout << "***      '~' 'BIN'     ***";

	//To do here
	string input, s, q, p;
	QInt a, b;
	gotoxy(77, 11);
	cin >> input;
	if (input.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit1.size() > 128 || nbit2.size() > 128)
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
	if (nbit.size() > 128)
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

void inputFile()		// File 
{
	gotoxy(80, 7);
	cout << "***     Input 'FILE'   ***";

	// To do here

}

void Exit()				// Thoat
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

// menu nho
void menuQIntDec()
{
	deleteMenu();		// delete menu truoc

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
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Dec();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Dec();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Dec();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Dec();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Dec();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Dec();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Dec();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Dec();
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
		}
	}
}

void menuQIntBin()
{
	deleteMenu();		// delete menu truoc

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
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Bin();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Bin();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Bin();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Bin();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Bin();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Bin();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Bin();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Bin();
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
		}
	}
}

void menuQIntHex()
{
	deleteMenu();		// delete menu truoc

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
					break;
				}
				case 8:
				{
					Frame_1();
					Plus_Hex();
					break;
				}
				case 9:
				{
					Frame_1();
					Minus_Hex();
					break;
				}
				case 10:
				{
					Frame_1();
					Mul_Hex();
					break;
				}
				case 11:
				{
					Frame_1();
					Div_Hex();
					break;
				}
				case 12:
				{
					Frame_1();
					And_Hex();
					break;
				}
				case 13:
				{
					Frame_1();
					Or_Hex();
					break;
				}
				case 14:
				{
					Frame_1();
					Xor_Hex();
					break;
				}
				case 15:
				{
					Frame_2();
					Not_Hex();
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
		}
	}
}

int main()
{
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
	setColor(11);

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
					menuQIntDec();
					break;
				}
				case 8:
				{
					menuQIntBin();
					break;
				}
				case 9:
				{
					menuQIntHex();
					break;
				}
				/*case 23:
				{
					Frame_2();
					QFloat_Bin();
					break;
				*/
				/*case 10:
				{
					Frame_2();
					inputFile();
					break;
				}*/
				case 11:
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