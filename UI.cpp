#include"UI.h"

void gotoxy(int column, int line)
{
	COORD coord = { column,line };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
//Hàm xoá con trỏ
void Nocursortype()
{
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
// Ham di chuyen
int Move()
{
	char c = _getch();
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
}

// Tao khung
void BigFrame()
{
	// Khung lon
	for (int i = 20; i < 165; i++) // tao dong ngang
	{
		gotoxy(i, 5); cout << char(205); // dong ngang tren
		gotoxy(i, 27); cout << char(205);  // dong ngang duoi
	}

	for (int i = 49; i < 164; i++)		// dong ngang giua
	{
		gotoxy(i, 16); cout << char(205);
	}

	for (int i = 21; i < 49; i++)
	{
		gotoxy(i, 18); cout << char(205);
	}

	for (int i = 5; i <= 26; i++)  // dong ke thang dung
	{
		gotoxy(20, i); cout << char(186); // dong thang ben trai
		gotoxy(165, i); cout << char(186); // dong thang ben phai
	}

	for (int i = 6; i <= 26; i++)
	{
		gotoxy(48, i); cout << char(186); // dong thang o giua
	}

	for (int i = 17; i <= 26; i++)
	{
		gotoxy(88, i); cout << char(186);
		gotoxy(127, i); cout << char(186);
	}

	gotoxy(165, 5); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(165, 27); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(20, 5); cout << char(201); // cai moc cau ben trai tren
	gotoxy(20, 27); cout << char(200); // moc cau ben trai duoi

	gotoxy(24, 20);
	cout << "Huong dan su dung:";

	gotoxy(22, 22);
	cout << "Mui ten xuong : Di xuong";

	gotoxy(22, 23);
	cout << "Mui ten len : Di len";

	gotoxy(22, 24);
	cout << "Enter : Chon";

	gotoxy(49, 18);
	cout << " BIN : ";

	gotoxy(89, 18);
	cout << " DEC : ";

	gotoxy(128, 18);
	cout << " HEX : ";
}

// 2 khung nho ben trong
void Frame_1()
{
	gotoxy(55, 9);	cout << "Nhap so X :";
	gotoxy(55, 13); cout << "Nhap so Y :";
	// Khung tren
	for (int i = 75; i < 155; i++) // tao dong ngang
	{
		gotoxy(i, 8); cout << char(205); // dong ngang tren
		gotoxy(i, 10); cout << char(205);  // dong ngang duoi
	}

	gotoxy(75, 9); cout << char(186); // dong thang ben trai
	gotoxy(155, 9); cout << char(186); // dong thang ben phai

	gotoxy(155, 8); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 10); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 8); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 10); cout << char(200); // moc cau ben trai duoi

	// Khung duoi
	for (int i = 75; i < 155; i++) // tao dong ngang
	{
		gotoxy(i, 12); cout << char(205); // dong ngang tren
		gotoxy(i, 14); cout << char(205);  // dong ngang duoi
	}

	gotoxy(75, 13); cout << char(186); // dong thang ben trai
	gotoxy(155, 13); cout << char(186); // dong thang ben phai

	gotoxy(155, 12); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 14); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 12); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 14); cout << char(200); // moc cau ben trai duoi
}

void Frame_2()
{
	gotoxy(55, 11);	cout << "Nhap so X :";
	for (int i = 75; i < 155; i++)
	{
		gotoxy(i, 10); cout << char(205);
		gotoxy(i, 12); cout << char(205);
	}
	gotoxy(75, 11); cout << char(186); // dong thang ben trai
	gotoxy(155, 11); cout << char(186); // dong thang ben phai

	gotoxy(155, 10); cout << char(187); // cai moc cau ben phai ben tre^n
	gotoxy(155, 12); cout << char(188); // cai moc cau ben phai ben duoi
	gotoxy(75, 10); cout << char(201); // cai moc cau ben trai tren
	gotoxy(75, 12); cout << char(200); // moc cau ben trai duoi
}
// xoa 2 khung nho ben trong
//void deleteFrame_1()
//{
//	//clear input X Y
//	for (int i = 77; i < 134; i++)
//	{
//		gotoxy(i, 9); cout << " ";
//		gotoxy(i, 13); cout << " ";
//	}
//
//	// clear frame
//	gotoxy(55, 9);	cout << "                                       ";
//	gotoxy(55, 13); cout << "                                       ";
//	for (int i = 75; i < 135; i++) // tao dong ngang
//	{
//		gotoxy(i, 8); cout << " "; // dong ngang tren
//		gotoxy(i, 10); cout << " ";  // dong ngang duoi
//	}
//
//	gotoxy(75, 9); cout << " "; // dong thang ben trai
//	gotoxy(135, 9); cout << " "; // dong thang ben phai
//
//	gotoxy(135, 8); cout << " "; // cai moc cau ben phai ben tre^n
//	gotoxy(135, 10); cout << " "; // cai moc cau ben phai ben duoi
//	gotoxy(75, 8); cout << " "; // cai moc cau ben trai tren
//	gotoxy(75, 10); cout << " "; // moc cau ben trai duoi
//
//	// Khung duoi
//	for (int i = 75; i < 135; i++) // tao dong ngang
//	{
//		gotoxy(i, 12); cout << " "; // dong ngang tren
//		gotoxy(i, 14); cout << " ";  // dong ngang duoi
//	}
//
//	gotoxy(75, 13); cout << " "; // dong thang ben trai
//	gotoxy(135, 13); cout << " "; // dong thang ben phai
//
//	gotoxy(135, 12); cout << " "; // cai moc cau ben phai ben tre^n
//	gotoxy(135, 14); cout << " "; // cai moc cau ben phai ben duoi
//	gotoxy(75, 12); cout << " "; // cai moc cau ben trai tren
//	gotoxy(75, 14); cout << " "; // moc cau ben trai duoi
//}

//void deleteFrame_2()
//{
//	for (int i = 55; i < 134; i++)
//	{
//		gotoxy(i, 11); cout << " ";
//	}
//	// clear frame
//	gotoxy(55, 10);	cout << "                                       ";
//	gotoxy(55, 12); cout << "                                       ";
//	for (int i = 75; i < 135; i++) // tao dong ngang
//	{
//		gotoxy(i, 10); cout << " "; // dong ngang tren
//		gotoxy(i, 12); cout << " ";  // dong ngang duoi
//	}
//
//	gotoxy(75, 11); cout << " "; // dong thang ben trai
//	gotoxy(135, 11); cout << " "; // dong thang ben phai
//
//	gotoxy(135, 10); cout << " "; // cai moc cau ben phai ben tre^n
//	gotoxy(135, 12); cout << " "; // cai moc cau ben phai ben duoi
//	gotoxy(75, 10); cout << " "; // cai moc cau ben trai tren
//	gotoxy(75, 12); cout << " "; // moc cau ben trai duoi
//}
// xoa day bin dec hex

void deleteInput()
{
	for (int i = 7; i <= 14; i++)
	{
		for (int j = 55; j <= 159; j++)
		{
			gotoxy(j, i); cout << " ";
		}
	}
}

void deleteOutPut()
{
	// clear Bin
	for (int i = 20; i < 24; i++)
	{
		for (int j = 50; j < 88; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	// clear Dec
	for (int i = 20; i < 24; i++)
	{
		for (int j = 91; j < 126; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}

	//clear Hex
	for (int i = 20; i < 24; i++)
	{
		for (int j = 130; j < 163; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

void deleteMenu()
{

	for (int i = 7; i < 18; i++)
	{
		for (int j = 25; j < 48; j++)
		{
			gotoxy(j, i);
			cout << " ";
		}
	}
}

// xuat day bin dec hex
void OutPut(string s, string q, string p)
{
	if (s.size() != 0)
	{
		int k = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (i < 32)
			{
				gotoxy(50 + k, 20);
				cout << s[i];
			}
			else if (i < 64)
			{
				gotoxy(50 + k, 21);
				cout << s[i];
			}
			else if (i < 96)
			{
				gotoxy(50 + k, 22);
				cout << s[i];
			}
			else {
				gotoxy(50 + k, 23);
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
				gotoxy(91 + l, 20);
				cout << q[i];
			}
			else {
				gotoxy(91 + l, 21);
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
				gotoxy(130 + t, 20);
				cout << p[i];
			}
			else {
				gotoxy(130 + t, 21);
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

//void OutPutInvalid(string nbit1,string nbit2)
//{
//	if (nbit1.size() > 128 || nbit2.size() > 128)
//	{
//		gotoxy(50, 20); cout << "Invalid";
//		gotoxy(91, 20); cout << "Invalid";
//		gotoxy(130, 20); cout << "Invalid";
//	}
//}