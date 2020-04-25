#include "QInt.h"
QInt::QInt()
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
	bitSize = 0;
}
QInt::QInt(string input)
{
	QInt temp;
	int index = 0;
	int size = input.size();
	int type = 2; // He co so nhap vao cho mac dinh la 2

	while (index < size) // Kiem tra xem input la he 16 hay khong
	{
		if ((input[index] >= 'A' && input[index] <= 'F') || (input[index] >= 'a' && input[index] <= 'f'))
		{
			type = 16;
			break;
		}
		index++;
	}
	index = 0;

	if (type != 16) // Kiem tra xem input co dung la he 2 khong
	{
		while (index < size)
		{
			if (input[index] != '1' && input[index] != '0')
			{
				type = 10;
				break;
			}
			index++;
		}
	}

}
QInt::~QInt() {}
void QInt::ScanQInt()
{
	string num16;
	cout << "Nhap vao so lon: "; 
	getline(cin, num16);
	QInt temp(num16);
	*this = temp;
}

void QInt::PrintQInt(bool *bit)
{

}

string QInt::DecToBin(string num)
{
	string bit_array;
	char bit;
	while (num != "")
	{
		num = Div2(num, bit);
		bit_array += (bit + '0');
	}
	reverse(bit_array.begin(), bit_array.end());
	return bit_array;
}

string QInt::HexToBin(string num)
{
	string bit_array;
	for (int i = 0; i < num.size(); i++)
	{
		if (num[i] == '0') { bit_array += "0000"; }
		else if (num[i] == '1') { bit_array += "0001"; }
		else if (num[i] == '2') { bit_array += "0010"; }
		else if (num[i] == '3') { bit_array += "0011"; }
		else if (num[i] == '4') { bit_array += "0100"; }
		else if (num[i] == '5') { bit_array += "0101"; }
		else if (num[i] == '6') { bit_array += "0110"; }
		else if (num[i] == '7') { bit_array += "0111"; }
		else if (num[i] == '8') { bit_array += "1000"; }
		else if (num[i] == '9') { bit_array += "1001"; }
		else if (num[i] == 'A' || num[i] == 'a') { bit_array += "1010"; }
		else if (num[i] == 'B' || num[i] == 'b') { bit_array += "1011"; }
		else if (num[i] == 'C' || num[i] == 'c') { bit_array += "1100"; }
		else if (num[i] == 'D' || num[i] == 'd') { bit_array += "1101"; }
		else if (num[i] == 'E' || num[i] == 'e') { bit_array += "1110"; }
		else if (num[i] == 'F' || num[i] == 'f') { bit_array += "1111"; }
	}
	StandardHex(bit_array);
	return bit_array;
}


string QInt::DecToHex()
{
	return NULL;
}


QInt QInt::BinToDec(bool* bit)
{
	QInt result;
	return result;
}

string QInt::BinToHex(bool* bit)
{
	return NULL;
}


string Div2(const string &num,char &bit)
{
	string res;
	int temp = 0;
	int size = num.size();
	for (int i = 0; i < size; i++)
	{
		temp = temp * 10 + (num[i] - '0');

		if (i > 0 || (i == 0 && temp >= 2))
		{
			res.push_back((temp / 2) + '0');
		}
		temp = temp % 2;
	}
	if (temp == 1)
	{
		bit = 1;
	}
	else bit = 0;
	return res;
}

bool* QInt::StringToBitArr(string input)
{
	bool* BitArr = new bool[max_bit];
	int i = 0;
	while (i < input.size())
	{
		BitArr[bitSize++] = input[i] -'0';
		i++;
	}
	return BitArr;
}
string QInt::BitArrToString(bool* bit)
{
	string res;
	for (int i = 0; i < bitSize; i++)
	{
		res += (bit[i] + '0');
	}
	return res;
}

void StandardHex(string &input)
{
	string res;
	int i = 0;
	int erase = 0;
	while (i < input.size())
	{
		if (input[i] == '0')
		{
			erase++;
		}
		if (input[i] == '1')
		{
			break;
		}
		i++;
	}
	input.erase(0, erase);
}

int main()
{
	QInt num16;
	//num16.ScanQInt();

	string t = num16.HexToBin("673A");
	cout << t << endl;
	bool* num = num16.StringToBitArr(t);
	for (int i = 0; i < num16.getSize(); i++)
	{
		cout << t[i];
	}
	cout << endl;
	string temp = num16.BitArrToString(num);
	cout << temp;

	return 0;
}