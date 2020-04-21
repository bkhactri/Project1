#include "QInt.h"
QInt::QInt()
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
	size = 0;
	index=0;
}
QInt::~QInt(){}
void QInt::ScanQInt(QInt& num)
{
	string input;
	cout << "Input is: ";
	getline(cin, input);
	int size = input.size();
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
		int i = 0, checkslot = 0, flag = 0; //checkslot kiem tra so chu so co trong 1 o nho,flag de kiem tra dau cua so
		int pos = 0;// bien dem 
		index = 1;

		while (pos <= size - 1)
		{
			if (pos == 0 && input[pos] == '-')
			{
				flag = -1;
				pos++;
			}
			if (checkslot < one_slot)
			{
				data[i] = data[i] * 10 + (input[pos] - '0');
				pos++;
				checkslot++;
			}
			else
			{
				i++;
				index++;
				checkslot = 0;
			}
		}
		if (flag == -1)
		{
			data[0] *= -1;
		}
	}
	else if (type == 2)//Bien doi he co so 2
	{
		int pos = 0;
		bool* bin = new bool[size - 1];
		while (pos <= size - 1)
		{
			bin[pos] = input[pos] - '0';
			pos++;
		}
		num.BinToDec(bin);
	}
	else//Bien doi he co so 16
	{

	}
}


void QInt::PrintQInt(QInt num)
{
	for (int i = 0; i < num.index; i++)
	{
		cout << num.data[i];
	}
}

bool* QInt::DecToBin(QInt num)
{
	return NULL;
}

char* QInt::DecToHex(QInt num)
{
	return NULL;
}

QInt QInt::BinToDec(bool* bit)
{
	QInt result;

	

	return result;
}

char* QInt::BinToHex(bool* bit)
{
	return NULL;
}
int main()
{
	QInt num16;
	num16.ScanQInt(num16);
	num16.PrintQInt(num16);
	return 0;
}
