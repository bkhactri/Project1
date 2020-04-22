#include "QInt.h"
QInt::QInt()
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
	size = 0;
	index = 0;
}
QInt::~QInt(){}
void QInt::ScanQInt()
{
	string input;
	cout << "Input is: ";
	getline(cin, input);
	size = input.size();
	int count = 0;
	int type = 2; //He co so nhap vao cho mac dinh la 2

	while (count < size) //Kiem tra xem input la he 16 hay khong
	{
		if (input[count] >= 'A' && input[count] <= 'F')
		{
			type = 16;
			break;
		}
		count++;
	}

	count = 0;

	if (type != 16) //Kiem tra xem input co dung la he 2 khong
	{
		while (count < size)
		{
			if (input[count] != '1' && input[count] != '0')
			{
				type = 10;
				break;
			}
			count++;
		}
	}

	if (type == 10)//Bien doi he co so 10
	{
		int i = 0, checkslot = 0, step = 0, flag = 0; //checkslot kiem tra so chu so co trong 1 o nho,flag de kiem tra dau cua so
		int pos = size-1;// bien dem 
		index = 1;

		while (pos >= 0)
		{
			if (checkslot < one_slot)
			{
				data[i] += (input[pos] - '0') * pow(10.0, step);
				pos--;
				step++;
				checkslot++;
			}
			else
			{
				i++;
				index++;
				step = 0;
				checkslot = 0;
			}

			if (pos == 0 && input[pos] == '-')
			{
				data[0] *= -1;
			}
		}
	}
	else if (type == 16)//Bien doi he co so 16
	{
		
	}
}

void QInt::PrintQInt()
{
	for (int i = index - 1; i >= 0; i--)
	{
		cout <<data[i];
	}
	
}

bool* QInt::DecToBin(int &count)
{
	QInt div = *this;
	bool surplus = 0;
	bool* res = new bool[128];
	while (div.data[0] > 0)
	{
		div.Div2(surplus);
		res[count] = surplus;
		count++;
	}

	for (int i = 0; i <= count / 2; i++)
	{
		bool temp = res[i];
		res[i] = res[count - 1 - i];
		res[count - 1 - i] = temp;
	}

	return res;
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

bool* QInt::HexToBin(string num)
{
	return NULL;
}

QInt QInt::Div2(bool &sur)
{
	QInt res;
	res.index = index;
	bool flag = 0;
	for (int i = 0; i < 4; i++)
	{
		res.data[i] = data[i] / 2;
		if (i==0 && data[i] % 2 == 1)
		{
			sur = 1;
			flag = 1;
		}
		if (i > 0 && data[i] % 2 == 1)
		{
			res.data[i - 1] += 1000000000 / 2;
		}
		if (i > 0 && res.data[i - 1] > 1000000000)
		{
			res.data[i]++;
			res.data[i - 1] %= 1000000000;
		}
	}
	if (flag != 1)
	{
		sur = 0;
	}
	*this = res;
	return *this;
}

int main()
{
	QInt num16;
	num16.ScanQInt();
	num16.PrintQInt();
	
	cout << endl;

	int count = 0;
	bool* t = num16.DecToBin(count);

	for (int i = 0; i < count; i++)
	{
		cout << t[i];
	}

	return 0;
}
