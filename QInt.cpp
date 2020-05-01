#include "QInt.h"
QInt::QInt()
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = 0;
	}
}
QInt::QInt(int _data[4])
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = _data[i];
	}
}
QInt::QInt(const QInt& int16)
{
	for (int i = 0; i < array_size; i++)
	{
		data[i] = int16.data[i];
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

	cout << bit_array << endl;
	/*ConvertStringtoInt4(bit_array, data);
	for (int i = 0; i < 4; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	string bit_array1 = ConvertInt4toString(data);
	cout << bit_array1 << endl;*/

}
QInt::~QInt(){}

void QInt::ScanQInt() //Nhap vo string
{
	string num16;
	cout << "Input : "; 
	getline(cin, num16);
	QInt temp(num16);
	*this = temp;
}



string QInt::DecToBin(string nDec)
{	
	int status = 1;
	string bit_array;
	char bit;
	if (nDec[0] == '-')
	{
		status = -1;
		nDec.erase(0, 1);
	}
	while (nDec != "")
	{
		nDec = Div2(nDec, bit);
		bit_array += (bit + '0');
	}
	reverse(bit_array.begin(), bit_array.end()); //Den day da bieu dien dc dang khong dau

	if (status == -1)
	{
		bit_array = ConvertToOffetTwo(bit_array);
	}
	return bit_array;
}
string QInt::HexToBin(string nHex)
{
	string bit_array;
	for (int i = 0; i < nHex.size(); i++)
	{
		if (nHex[i] == '0') { bit_array += "0000"; }
		else if (nHex[i] == '1') { bit_array += "0001"; }
		else if (nHex[i] == '2') { bit_array += "0010"; }
		else if (nHex[i] == '3') { bit_array += "0011"; }
		else if (nHex[i] == '4') { bit_array += "0100"; }
		else if (nHex[i] == '5') { bit_array += "0101"; }
		else if (nHex[i] == '6') { bit_array += "0110"; }
		else if (nHex[i] == '7') { bit_array += "0111"; }
		else if (nHex[i] == '8') { bit_array += "1000"; }
		else if (nHex[i] == '9') { bit_array += "1001"; }
		else if (nHex[i] == 'A' || nHex[i] == 'a') { bit_array += "1010"; }
		else if (nHex[i] == 'B' || nHex[i] == 'b') { bit_array += "1011"; }
		else if (nHex[i] == 'C' || nHex[i] == 'c') { bit_array += "1100"; }
		else if (nHex[i] == 'D' || nHex[i] == 'd') { bit_array += "1101"; }
		else if (nHex[i] == 'E' || nHex[i] == 'e') { bit_array += "1110"; }
		else if (nHex[i] == 'F' || nHex[i] == 'f') { bit_array += "1111"; }
	}
	return bit_array;
}

string QInt::DecToHex(string nDec)
{
	string Temp = DecToBin(nDec);
	string res = BinToHex(Temp);
	return res;
}

string QInt::BinToDec(string bit)
{
	string nDec = "0";
	int count = bit.size() - 1;
	for (int i = 0; i < bit.size(); i++)
	{
		string temp = "0";
		if (bit[i] == '1')
		{
			temp = Multi2(count);
			if (i == 0 && count == 127)
			{
				temp = '-' + temp;
			}
		}
		count--;
		nDec = PlusDec(nDec, temp);
	}
	return nDec;
}
string QInt::BinToHex(string bit)
{
	string nHex, temp;
	FillZero(bit, 4);
	int i = 0;

	while (i < bit.size() - 1)
	{
		for (int j = 0; j < 4; j++)
		{
			temp += bit[i];
			i++;	
		}
		if (temp == "0000") { nHex += "0"; }
		else if (temp == "0001") { nHex += "1"; }
		else if (temp == "0010") { nHex += "2"; }
		else if (temp == "0011") { nHex += "3"; }
		else if (temp == "0100") { nHex += "4"; }
		else if (temp == "0101") { nHex += "5"; }
		else if (temp == "0110") { nHex += "6"; }
		else if (temp == "0111") { nHex += "7"; }
		else if (temp == "1000") { nHex += "8"; }
		else if (temp == "1001") { nHex += "9"; }
		else if (temp == "1010") { nHex += "A"; }
		else if (temp == "1011") { nHex += "B"; }
		else if (temp == "1100") { nHex += "C"; }
		else if (temp == "1101") { nHex += "D"; }
		else if (temp == "1110") { nHex += "E"; }
		else if (temp == "1111") { nHex += "F"; }

		temp = "";
	}
	return nHex;
}


string Div2(const string num,char &bit)
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
string Multi2(int repeat)
{
	string res = "1";
	int temp = 0;
	int carry = 0;
	for (int i = 0; i < repeat; i++)
	{
		string multi_temp = "";
		for (int j = res.size() - 1; j >= 0; j--)
		{
			temp = (res[j] - '0') * 2 + carry;
			multi_temp = char(temp % 10 + '0') + multi_temp;
			carry = temp / 10;
		}
		if (carry != 0)
		{
			multi_temp = char(carry + '0') + multi_temp;
			carry = 0;
		}
		res = multi_temp;
	}
	return res;
}

string ConvertToOffetTwo(string num)
{
	FillZero(num, 128);
	string temp;
	temp += '1';
	for (int i = 1; i < num.size(); i++)
	{
		if (num[i] == '0') temp += '1';
		else if (num[i] == '1') temp += '0';
	}
	temp = PlusBit(temp, "1");
	return temp;
}

string PlusBit(string num1, string num2)//num1 + num2
{
	int sur_bit = 0;
	FillZero(num1, 128);
	FillZero(num2, 128);
	string res = num1;
	for (int i = num1.length() - 1; i >= 0; i--)
	{
		int temp = (num1[i] - '0') + (num2[i] - '0') + sur_bit;
		if (temp == 3)
		{
			res[i] = '1';
			sur_bit = 1;
		}
		if (temp == 2)
		{
			res[i] = '0';
			sur_bit = 1;
		}
		else if (temp == 1)
		{
			res[i] = temp + '0';
			sur_bit = 0;
		}
	}
	return res;
}


string MinusDec(string num1, string num2)
{
	string res = "";
	int carry = 0; //Biến này để nhớ phần mượn khi trừ 3-8 (mượn 1 -> kq trừ = 5, carry =1 )
	bool sign = 0; //Biến xét dấu , 0 là + , 1 là -

	if (num1.size() > num2.size())
	{
		FillZero(num2, num1.size());
	}
	else
	{
		FillZero(num1, num2.size());
	}


	if (strcmp(num1.c_str(), num2.c_str()) < 0) //Kiểm tra a có lớn hơn b không nếu a không lớn hơn thì đổi lại -> lúc này biết đc a-b < 0 (*)
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
		sign = 1; //(*) nên sẽ nhớ dấu - để gán vào kết quả sau cùng
	}

	for (int i = num1.size() - 1; i >= 0; i--)
	{
		if ((num1[i] - carry) < num2[i])
		{
			int temp = 10 + (num1[i] - '0') - (num2[i] - '0') - carry;
			res = char(temp % 10 + '0') + res;
			carry = 1;
		}
		else
		{
			int temp = (num1[i] - '0') - (num2[i] - '0') - carry;
			res = char(temp % 10 + '0') + res;
			carry = 0;
		}
	}
	EraseZero(res);//Xoá 0 thừa
	if (sign == 1)
	{
		res = '-' + res;
	}
	return res;
}
string PlusDec(string num1, string num2)
{
	bool sign = 0;//Biến xét dấu , 0 là + , 1 là -
	if (num1[0] != '-' && num2[0] == '-') // num1 - num2 -> Đưa vào hàm trừ thập phân
	{
		num2.erase(0, 1);
		//return SubtractDec(num1, num2);
		return MinusDec(num1, num2);
	};
	if (num1[0] == '-' && num2[0] != '-') // -num1 + num2 -> Đưa vào hàm trừ thập phân num2 - num1
	{
		num1.erase(0, 1);
		//return SubtractDec(num2, num1);
		return MinusDec(num2, num1);
	};
	if (num1[0] != '-' && num2[0] != '-') // num1 + num2 -> Dương
	{
		sign = 0;
	}
	if (num1[0] == '-' && num2[0] == '-') // -num1 - num2 -> -(num1 + num2) (*)
	{
		sign = 1;
		num1.erase(0, 1);
		num2.erase(0, 1);
	};

	if (num1.length() > num2.length())//Đôi vị trí để lấy chuỗi ngắn hơn
	{
		swap(num1, num2);
	}

	//Đảo chuỗi để dễ thực hiện tính toán
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	string res = ""; //chuỗi chứa kết quả cộng
	int carry = 0;//Biến này để nhớ phần mượn khi cộng quá 10 (8+3 --> carry = 11-10 = 1)

	for (int i = 0; i < num1.size(); i++)
	{
		int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
		res += char(temp % 10 + '0');
		carry = temp / 10;
	}
	//Đây bổ sung phần còn thiếu của chuỗi số dài hơn
	for (int i = num1.size(); i < num2.size(); i++)
	{

		int temp = (num2[i] - '0') + carry;
		res += char(temp % 10 + '0');
		carry = temp / 10;
	}
	//Kiểm tra dư một lần nữa nếu khác 0 thì cho vào sau
	if (carry)
	{
		res += char(carry + '0');
	}
	//Đảo chuỗi để nhận lại kết quả đúng
	reverse(res.begin(), res.end());

	if (sign == 1) // (*) -(num1 + num2)
	{
		res = '-' + res;
	}


	return res;

}

void FillZero(string& input, int nbit)
{
	while (input.size() % nbit != 0)
	{
		input.insert(0, "0");
	}
}
void EraseZero(string& num)
{
	while (num[0] == '0')
	{
		num.erase(0, 1);
	}
}


void GetBit(int x, char bit[32])
{
	for (int i = 0; i < 32; i++)
	{
		bit[i] = (x >> 31 - i) & 1;
	}
}
void SetBit(char bit[32], int& x)
{
	for (int i = 0; i < 32; i++)
	{
		x = x | (bit[i] << 31 - i);
	}
}

void ConvertStringtoInt4(string a, int data[4])
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
			SetBit(temp, data[z++]);
		}
	}
	delete[] temp;
	delete[] b;
}
string ConvertInt4toString(int bytes[4])
{
	string a;
	char* b = new char[128];
	char* temp = new char[32];
	int h = 0;
	for (int i = 0; i < 4; i++)
	{
		GetBit(bytes[i], temp);
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
bool CheckSign(int bytes[4])
{
	string a = ConvertInt4toString(bytes);
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

//operator

//Shift Left
QInt QInt::operator<<(int nBitShifted)
{
	string a = ConvertInt4toString(this->data);
	int n = a.size();
	string kq;
	kq.resize(128);
	for (int i = 128 - nBitShifted; i < 128; i++)
	{
		kq[i] = '0';
	}
	if (n + nBitShifted <= 128)
	{
		for (int i = 0; i < 128 - nBitShifted - n; i++)
		{
			kq[i] = '0';
		}
		int j = 0;
		for (int i = 128 - nBitShifted - n; i < 128 - nBitShifted; i++)
		{
			kq[i] = a[j++];
		}
	}
	else
	{
		int  j = n - 1;
		for (int i = 127 - nBitShifted; i >= 0; i--)
		{
			kq[i] = a[j--];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = 0;
	}
	ConvertStringtoInt4(kq, this->data);
	return *this;
}
//Shift Right
QInt QInt::operator>>(int nBitShifted)
{
	string a = ConvertInt4toString(this->data);
	int n = a.size();
	string kq;
	kq.resize(128);
	for (int i = 0; i < nBitShifted + 128 - n; i++)
	{
		kq[i] = '0';
	}
	int  j = 0;
	for (int i = nBitShifted + 128 - n; i < 128; i++)
	{
		kq[i] = a[j++];
	}
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = 0;
	}
	ConvertStringtoInt4(kq, this->data);
	return *this;
}


int main()
{
	QInt n;
	int data[4] = { 0,0,0,0 };
	string a = "-310586309";
	string temp = n.DecToBin(a);
	cout << temp << endl;
	
	ConvertStringtoInt4(temp,data);
	

	string n1 = ConvertInt4toString(data);
	cout << n1 << endl; 

	cout << n.BinToDec(n1) << endl;
	

	return 0;
}