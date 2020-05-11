#include"UI.h"
#define GETTEST 1000
// dịch vị trí con trỏ
void gotoxy(int column, int line)
{
	COORD coord = { column,line };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// text color
void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// ẩn con trỏ console
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

// hàm di chuyển
int Move()
{
	int flag = 1;
	while (flag)
	{
		char c = _getch();
		if (int(c) == 80 || int(c) == 72 || int(c) == 13)
		{
			switch (int(c))
			{
			case 80:
				return 1;			// Xuong
			case 72:
				return 2;			// Len
			case 13:
				return 3;			// Enter
			default:
				break;
			}
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	}
}

// tạo khung lớn
void BigFrame()
{
	// Khung lon
	for (int i = 1; i <= 167; i++) // tao dong ngang
	{
		gotoxy(i, 1); cout << char(205); // dong ngang tren
		gotoxy(i, 27); cout << char(205);  // dong ngang duoi
	}
	for (int i = 2; i <= 166; i++)		// dong ngang giua
	{
		gotoxy(i, 18); cout << char(205);
	}
	for (int i = 1; i <= 26; i++)  // dong ke thang dung
	{
		gotoxy(1, i); cout << char(186); // dong thang ben trai
		gotoxy(167, i); cout << char(186); // dong thang ben phai
	}
	for (int i = 2; i <= 17; i++)
	{
		gotoxy(25, i); cout << char(186); // dong thang o giua
	}
	for (int i = 19; i <= 26; i++)
	{
		gotoxy(48, i); cout << char(186); // dong thang o giua
	}
	for (int i = 19; i <= 26; i++)
	{
		gotoxy(88, i); cout << char(186);
		gotoxy(127, i); cout << char(186);
	}
	gotoxy(167, 1); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(167, 27); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(1, 1); cout << char(201); // cai moc cau ben trai tren
	gotoxy(1, 27); cout << char(200); // moc cau ben trai duoi

	gotoxy(12, 20);	cout << "Directions for use:";
	gotoxy(10, 22);	cout << "Down Arrow : Down";
	gotoxy(10, 23);	cout << "Up Arrow : Up";
	gotoxy(10, 24);	cout << "Enter : Choose";
	gotoxy(49, 20);	cout << " BIN : ";
	gotoxy(89, 20);	cout << " DEC : ";
	gotoxy(128, 20); cout << " HEX : ";
}

// tạo 2 khung nhỏ bên trong
void Frame_1()
{
	gotoxy(28, 7);	cout << "Num X";
	gotoxy(28, 11); cout << "Num Y";
	// Khung tren
	for (int i = 28; i <= 165; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 9); cout << char(186); // dong thang ben trai
	gotoxy(165, 9); cout << char(186); // dong thang ben phai

	gotoxy(165, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 10); cout << char(200); // moc cau ben trai duoi

	// Khung duoi
	for (int i = 28; i < 165; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 13); cout << char(186); // dong thang ben trai
	gotoxy(165, 13); cout << char(186); // dong thang ben phai

	gotoxy(165, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 14); cout << char(200); // moc cau ben trai duoi
}

// tạo 1 khung nhỏ bên trong
void Frame_2()
{
	gotoxy(28, 9);	cout << "Num X";
	for (int i = 28; i <= 165; i++)
	{
		gotoxy(i, 10); cout << char(205);
		gotoxy(i, 12); cout << char(205);
	}
	gotoxy(28, 11); cout << char(186); // dong thang ben trai
	gotoxy(165, 11); cout << char(186); // dong thang ben phai

	gotoxy(165, 10); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 12); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 10); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 12); cout << char(200); // moc cau ben trai duoi
}

// tạo 2 khung nhỏ bên trong dành cho Qfloat Dec
void Frame_3()
{
	gotoxy(28, 7);	cout << "Num X";
	gotoxy(28, 11); cout << "Length Fraction";
	// Khung tren
	for (int i = 28; i <= 165; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 9); cout << char(186); // dong thang ben trai
	gotoxy(165, 9); cout << char(186); // dong thang ben phai

	gotoxy(165, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 10); cout << char(200); // moc cau ben trai duoi

	// Khung duoi
	for (int i = 28; i < 80; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 13); cout << char(186); // dong thang ben trai
	gotoxy(80, 13); cout << char(186); // dong thang ben phai

	gotoxy(80, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(80, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 14); cout << char(200); // moc cau ben trai duoi
}

// tạo 1 khung nhỏ bên trong file
void Frame_4()
{
	gotoxy(28, 7);	cout << "File";
	gotoxy(28, 11); cout << "Note: Save the File in drive D before using";
	for (int i = 28; i <= 165; i++)
	{
		gotoxy(i, 8); cout << char(205);
		gotoxy(i, 10); cout << char(205);
	}
	gotoxy(28, 9); cout << char(186); // dong thang ben trai
	gotoxy(165, 9); cout << char(186); // dong thang ben phai

	gotoxy(165, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 10); cout << char(200); // moc cau ben trai duoi
}

// tạo 2 khung nhỏ bên trong Shift
void Frame_5()
{
	gotoxy(28, 7);	cout << "Num X";
	gotoxy(28, 11); cout << "Count to Shift";
	// Khung tren
	for (int i = 28; i <= 165; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 9); cout << char(186); // dong thang ben trai
	gotoxy(165, 9); cout << char(186); // dong thang ben phai

	gotoxy(165, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 10); cout << char(200); // moc cau ben trai duoi
	// khung dưới
	// Khung duoi
	for (int i = 28; i < 80; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 13); cout << char(186); // dong thang ben trai
	gotoxy(80, 13); cout << char(186); // dong thang ben phai

	gotoxy(80, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(80, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 14); cout << char(200); // moc cau ben trai duoi
}

// tạo 2 khung nhỏ bên trong Shift Dec
void Frame_6()
{
	gotoxy(28, 7);	cout << "Num X";
	gotoxy(28, 11); cout << "Count to Rotate";
	// Khung tren
	for (int i = 28; i <= 165; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 9); cout << char(186); // dong thang ben trai
	gotoxy(165, 9); cout << char(186); // dong thang ben phai

	gotoxy(165, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 10); cout << char(200); // moc cau ben trai duoi
	// khung dưới
	// Khung duoi
	for (int i = 28; i < 80; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(28, 13); cout << char(186); // dong thang ben trai
	gotoxy(80, 13); cout << char(186); // dong thang ben phai

	gotoxy(80, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(80, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(28, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(28, 14); cout << char(200); // moc cau ben trai duoi
}

// xóa vị trí nhập vào
void deleteInput()
{
	for (int i = 2; i <= 14; i++)
	{
		for (int j = 27; j <= 165; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
}

// xóa vị trí xuất ra 
void deleteOutPut()
{
	// clear Bin
	for (int i = 22; i <= 25; i++)
	{
		for (int j = 50; j < 88; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	// clear Dec
	for (int i = 22; i <= 25; i++)
	{
		for (int j = 91; j < 126; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	//clear Hex
	for (int i = 22; i <= 25; i++)
	{
		for (int j = 130; j < 165; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

// xóa menu
void deleteMenu()
{

	for (int i = 2; i <= 17; i++)
	{
		for (int j = 2; j <= 24; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

// xuất kết quả
void OutPut(string s, string q, string p)
{
	if (s.size() != 0)
	{
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(52 + k, 22);
				cout << s[i];
			}
			else if (i < 64)
			{
				gotoxy(52 + k, 23);
				cout << s[i];
			}
			else if (i < 96)
			{
				gotoxy(52 + k, 24);
				cout << s[i];
			}
			else {
				gotoxy(52 + k, 25);
				cout << s[i];
			}
			k++;
			if (k == 32)
			{
				k = 0;
			}
		}
	}

	if (q.size() != 0)
	{
		int l = 0;
		for (int i = 0; i < q.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(92 + l, 22);
				cout << q[i];
			}
			else {
				gotoxy(92 + l, 23);
				cout << q[i];
			}
			l++;
			if (l == 32)
			{
				l = 0;
			}
		}
	}

	if (p.size() != 0)
	{
		int t = 0;
		for (int i = 0; i < p.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(132 + t, 22);
				cout << p[i];
			}
			else {
				gotoxy(132 + t, 23);
				cout << p[i];
			}
			t++;
			if (t == 32)
			{
				t = 0;
			}
		}
	}
}

// kiểm tra enter, esc
void checkEnter()
{
	int flag = 1;
	while (flag)
	{
		char c = _getch();
		if (int(c) == 13 || int(c) == 27)
		{
			flag = 0;
			deleteInput();
			deleteOutPut();
		}
		else flag = 1;
	}
}

// kiểm tra nhập thập phân
int checkDec(string s)
{
	int flag = 1;
	if (s.size() == 1 && (s == "-" || s < "0" || s > "9"))
	{
		return 0;
	}
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9' && (s[0] = '-' || (s[0] >= '0' && s[0] <= '9')))
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra nhập nhị phân
int checkBin(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0' || s[i] == '1')
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra nhập thập lục phân
int checkHex(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if ((s[i] >= 'a' && s[i] <= 'f' || (s[i] >= '0' && s[i] <= '9')) || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= '0' && s[i] <= '9'))
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra chia
int checkDiv(string s)
{
	int flag = 1;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '0')
		{
			flag = 1;
		}
		else {
			flag = 0;
			break;
		}
	}
	return flag;
}

// kiểm tra nhập QFloat thập phân
int checkQFloatDec(string s)
{
	int flag = 1;
	int count = 0;
	if (s.size() == 1 && (s == "-" || s < "0" || s > "9"))
	{
		return 0;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '.')
		{
			count++;
		}
	}
	if (count == 1 || count == 0)
	{
		for (int i = 1; i < s.size(); i++)
		{
			if ((s[i] >= '0' && s[i] <= '9' && (s[0] = '-' || (s[0] >= '0' && s[0] <= '9'))) || s[i] == '.')
			{
				flag = 1;
			}
			else {
				flag = 0;
				break;
			}
		}
	}
	else return 0;
	return flag;
}

// xuất Invalid QInt
void outputInvalidQInt()
{
	gotoxy(64, 23); cout << "Invalid";
	gotoxy(104, 23); cout << "Invalid";
	gotoxy(144, 23); cout << "Invalid";
}

// xuất Invalid QFloat
void outputInvalidQFloat()
{
	gotoxy(64, 23); cout << "Invalid";
	gotoxy(104, 23); cout << "Invalid";
}

// chuyển string sang int
int convertStringtoInt(string n)
{
	int kq = 0;
	for (int i = 0; i < n.size(); i++)
	{
		kq = kq * 10 + (n[i] - 48);
	}
	return kq;
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
			int checkError = 0;
			if (block[i][0] == "2")
			{
				if (block[i][1].size() > 128 || block[i][3].size() > 128)
				{
					checkError = 1;
				}
				else
				{
					a.ScanQIntBin(block[i][1]);
					b.ScanQIntBin(block[i][3]);
				}
			}
			else if (block[i][0] == "10")
			{
				string temp1, temp2;
				temp1 = a.DecToBin(block[i][1]);
				temp2 = b.DecToBin(block[i][3]);
				if (temp1.size() > 128 || temp2.size() > 128)
				{
					checkError = 1;
				}
				else
				{
					a.ScanQIntDec(block[i][1]);
					b.ScanQIntDec(block[i][3]);
				}
			}
			else if (block[i][0] == "16")
			{
				string temp1, temp2;
				temp1 = a.HexToBin(block[i][1]);
				temp2 = b.HexToBin(block[i][3]);
				if (temp1.size() > 128 || temp2.size() > 128)
				{
					checkError = 1;
				}
				else
				{
					a.ScanQIntHex(block[i][1]);
					b.ScanQIntHex(block[i][3]);
				}
			}
			if (block[i][2] == "+" && checkError == 0)
			{
				kq = a + b;
			}
			else if (block[i][2] == "-" && checkError == 0)
			{
				kq = a - b;
			}
			else if (block[i][2] == "*" && checkError == 0)
			{
				kq = a * b;
			}
			else if (block[i][2] == "/" && checkError == 0)
			{
				kq = a / b;
			}
			else if (block[i][2] == ">>" && checkError == 0)
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a >> nbit;
			}
			else if (block[i][2] == "<<" && checkError == 0)
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a << nbit;
			}
			else if (block[i][2] == "^" && checkError == 0)
			{
				kq = a ^ b;
			}
			else if (block[i][2] == "&" && checkError == 0)
			{
				kq = a & b;
			}
			else if (block[i][2] == "|" && checkError == 0)
			{
				kq = a | b;
			}
			else if (block[i][2] == "rol" && checkError == 0)
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a.rol(nbit);
			}
			else if (block[i][2] == "ror" && checkError == 0)
			{
				int nbit = convertStringtoInt(block[i][3]);
				kq = a.ror(nbit);
			}
			else if (block[i][2] == "<" && checkError == 0)
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
			else if (block[i][2] == ">" && checkError == 0)
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
			else if (block[i][2] == "<=" && checkError == 0)
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
			else if (block[i][2] == ">=" && checkError == 0)
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
			else if (block[i][2] == "==" && checkError == 0)
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
			if (compair == 0 && checkError == 0)
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
			else if (compair == 1 && checkError == 0)
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
			else
			{
				of << "Invalid" << endl;
			}
		}
		else
		{
			QInt kq;
			if (block[i][0] == "2")
			{
				if (block[i][2].size() > 128)
				{
					of << "Invalid" << endl;
				}
				else
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
			}
			else if (block[i][0] == "10")
			{
				string temp1 = kq.DecToBin(block[i][2]);
				if (temp1.size() > 128)
				{
					of << "Invalid" << endl;
				}
				else
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
			}
			else if (block[i][0] == "16")
			{
				string temp1 = kq.HexToBin(block[i][2]);
				if (temp1.size() > 128)
				{
					of << "Invalid" << endl;
				}
				else
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