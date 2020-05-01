#include "QInt.h"
void getBit(int x, char temp[32])
{
	//int bit[32];
	for (int i = 0; i < 32; i++)
	{
		temp[i] = (x >> 31 - i) & 1;
		//cout << int(temp[i]);
		//if ((i + 1) % 8 == 0)
		//{
		//	cout << " ";
		//}
	}
}
void setBit(char bit[32], int& x)
{
	for (int i = 0; i < 32; i++)
	{
		x = x | (bit[i] << 31 - i);
	}
}
void convertStringtoInt4(string a, int bytes[4])
{
	QInt c;
	char* b = new char[128];
	for (int i = 0; i < 128; i++)
	{
		b[i] = 0;
	}
	int k = 127;
	for (int i = a.size() - 1; i >= 0; i--)
	{
		if (a[i] == '0' || a[i] == '1')
		{
			b[k--] = a[i] - 48;
		}
	}
	char* temp = new char[32];
	int y = 0;
	int z = 0;
	for (int i = 0; i < 128; i++)
	{
		temp[y++] = b[i];
		if (y % 32 == 0)
		{
			y = 0;
			setBit(temp, bytes[z++]);
		}
	}
	delete[] temp;
	delete[] b;
}
string convertInt4toString(int bytes[4])
{
	string a;
	char* b = new char[128];
	char* temp = new char[32];
	int h = 0;
	for (int i = 0; i < 4; i++)
	{
		getBit(bytes[i], temp);
		for (int j = 0; j < 32; j++)
		{
			b[h++] = temp[j];
		}
	}
	int slbit = 0;
	int flag = 0;
	for (int i = 0; i < 128; i++)
	{
		if (b[i] == 1)
		{
			flag = 1;
			slbit = 128 - i;
			break;
		}
	}
	a.resize(slbit);
	int c = 0;
	for (int i = 128 - slbit; i < 128; i++)
	{
		a[c++] = b[i] + 48;
	}
	return a;
}
void ShiftLeft(int bytes[4], int k)
{
	string a = convertInt4toString(bytes);
	int n = a.size();
	string kq;
	kq.resize(128);
	for (int i = 128 - k; i < 128; i++)
	{
		kq[i] = '0';
	}
	if (n + k <= 128)
	{
		for (int i = 0; i < 128 - k - n; i++)
		{
			kq[i] = '0';
		}
		int j = 0;
		for (int i = 128 - k - n; i < 128 - k; i++)
		{
			kq[i] = a[j++];
		}
	}
	else
	{
		int  j = n - 1;
		for (int i = 127 - k; i >= 0; i--)
		{
			kq[i] = a[j--];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		bytes[i] = 0;
	}
	convertStringtoInt4(kq, bytes);
}
void ShiftRight(int bytes[4], int k)
{
	string a = convertInt4toString(bytes);
	int n = a.size();
	string kq;
	kq.resize(128);
	for (int i = 0; i < k + 128 - n; i++)
	{
		kq[i] = '0';
	}
	int  j = 0;
	for (int i = k + 128 - n; i < 128; i++)
	{
		kq[i] = a[j++];
	}
	for (int i = 0; i < 4; i++)
	{
		bytes[i] = 0;
	}
	convertStringtoInt4(kq, bytes);
}
bool CheckSign(int bytes[4])
{
	string a = convertInt4toString(bytes);
	int n = a.size();
	string temp;
	temp.resize(128);
	for (int i = 0; i < 128 - n; i++)
	{
		temp[i] = '0';
	}
	int j = 0;
	for (int i = 128 - n; i < 128; i++)
	{
		temp[i] = a[j++];
	}
	if (temp[0] == '0')
		return 1;
	else
		return 0;
}
QInt::QInt()
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
}

QInt::QInt(string input)
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
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
	string bit_array;
	if (type == 10)
	{
		bit_array = DecToBin(input);
	}
	else if (type == 16)
	{
		bit_array = HexToBin(input);
	}
	else if (type == 2)
	{
		bit_array = input;
	}

	cout << bit_array;
	//bit_array ... mang bit -> int[] ok
	convertStringtoInt4(bit_array, data);
	//string -> int[] ok
	string bit_array1 = convertInt4toString(data);

}

QInt::~QInt(){}
void QInt::ScanQInt() //Nhap vo string
{
	string num16;
	cout << "Nhap vao so lon: "; 
	getline(cin, num16);
	QInt temp(num16);
	*this = temp;
}


string QInt::DecToBin(string num)
{
	int status = 1;
	string bit_array;
	char bit;
	if (num[0] == '-')
	{
		status = -1;
		num.erase(0, 1);
	}
	while (num != "")
	{
		num = Div2(num, bit);
		bit_array += (bit + '0');
	}
	reverse(bit_array.begin(), bit_array.end());
	if (status == 1)
	{
		StandardPrintBit(bit_array);
	}
	else if (status == -1)
	{
		StandardCalcBit(bit_array);
		string temp;
		temp += '1';
		for (int i = 1; i < bit_array.size(); i++)
		{
			if (bit_array[i] == '0') temp += '1';
			else if (bit_array[i] == '1') temp += '0';
		}
		Plus1(temp);
		return temp;
	}
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
	StandardPrintBit(bit_array);
	return bit_array;
}
string QInt::DecToHex(string num)
{

	return NULL;
}
string QInt::BinToDec(string bit)
{
	string dec;
	StandardCalcBit(bit);
	int size = bit.size();



	return dec;
}
string QInt::BinToHex(string bit)
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
void StandardPrintBit(string& input)
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
	if (erase == input.size())
	{
		input = "0";
	}
	else
	{
		input.erase(0, erase);
	}
}
void StandardCalcBit(string& input)
{
	while (input.size() % 32 != 0)
	{
		input.insert(0, "0");
	}
}
void Plus1(string& num)
{
	int sur_bit = 1;
	for (int i = num.length() - 1; i >= 1; i--)
	{
		int temp = (num[i] - '0') + sur_bit;
		if (temp == 3)
		{
			num[i] = '1';
			sur_bit = 1;
		}
		if (temp == 2)
		{
			num[i] = '0';
			sur_bit = 1;
		}
		else if (temp == 1)
		{
			num[i] = temp + '0';
			sur_bit = 0;
		}
		if (sur_bit == 0) break;
	}
}



int main()
{
	QInt num16;
	num16.ScanQInt();
	
	


	return 0;
}