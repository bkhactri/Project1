#include "QInt.h"
QInt::QInt()
{
	for (int i = 0; i < 4; i++)
	{
		data[i] = 0;
	}

}
QInt::~QInt(){}
void QInt::ScanQInt(QInt& x)
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
	
	
	int i = 0, checkslot = 0, step = 0,flag = 0;
	int pos = input.size() - 1;
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

void QInt::PrintQInt(QInt x)
{
	for (int i = x.index-1; i >=0; i--)
	{
		if (x.data[i] != NULL) 
		{ 
			cout << x.data[i];
		}
	}
}
int main()
{
	QInt x;
	x.ScanQInt(x);
	x.PrintQInt(x);
	//char t = '8';
	//int a = t - '0';
	return 0;
}
