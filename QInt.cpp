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
QInt::~QInt(){}


void QInt::ScanQIntDec(string nDec)
{
	string nBit=DecToBin(nDec);
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}
void QInt::ScanQIntBin(string nBit)
{
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}
void QInt::ScanQIntHex(string nHex)
{
	string nBit = HexToBin(nHex);
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}

void QInt::PrintQIntDec()
{
	if (IsZero(this->data) == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		string nDec = BinToDec(nBit);
		cout << nDec << endl;
	}
}
void QInt::PrintQIntBin()
{
	if (IsZero(this->data) == 0)
	{
		cout << "0" << endl;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		cout << nBit << endl;
	}
}
void QInt::PrintQIntHex()
{
	if (IsZero(this->data) == 0)
	{
		cout << "0" << endl;
	}
	else 
	{
		string nBit = ConvertInt4toString(this->data);
		string nHex = BinToHex(nBit);
		cout << nHex << endl;
	}
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
	if (num[0] == '0')
	{
		temp += '1';
	}
	else if (num[0] == '1')
	{
		temp += '0';
	}
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
string MultiBit(string num1, string num2)
{
	string res = "0";
	int step = 0;
	if (num1.size() < num2.size())
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}
	for (int i = num2.size() - 1; i >= 0; i--)
	{
		string temp = "0";//Khai báo để lưu kết quả nhân tạm
		if (num2[i] == '1')
		{
			temp = num1;
			for (int j = 0; j < step; j++)
			{
					temp += '0';
			}
		}
		step++;
		res = PlusBit(res, temp);
	}
	EraseZero(res);
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
	if (num1[0] == '-' && num2[0] == '-') // -num1 -num2 -> -(num1 + num2) (*)
	{
		sign = 1;
		num1.erase(0, 1);
		num2.erase(0, 1);
	};


	string res = ""; //chuỗi chứa kết quả cộng
	int carry = 0;//Biến này để nhớ phần mượn khi cộng quá 10 (8+3 --> carry = 11-10 = 1)
	if (num1.size() > num2.size())
	{
		FillZero(num2, num1.size());
	}
	else
	{
		FillZero(num1, num2.size());
	}
	for (int i = num1.size() - 1; i >= 0; i--)
	{
		int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
		res = char(temp % 10 + '0') + res;
		carry = temp / 10;
	}

	if (carry)
	{
		res = char(carry + '0') + res;
	}

	if (sign == 1) // (*) -(num1 + num2)
	{
		res = '-' + res;
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


	if (strcmp(num1.c_str(), num2.c_str()) < 0) //Kiểm tra a có lớn hơn b không nếu a không lớn hơn b thì đổi lại -> lúc này biết đc a-b < 0 (*)
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


//Ừng Văn Tuấn 
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
string ConvertInt4toString(const int bytes[4])
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
bool CheckSign(const int bytes[4])
{
	string a = ConvertInt4toString(bytes);
	if ((a[0] == '0' || a[0] == '1') && a.size() != 128)
	{
		return 1;
	}
	else if (a[0] == '1' && a.size() == 128)
	{
		return 0;
	}
}
bool IsZero(const int bytes[4])
{
	bool flag = 0;
	for (int i = 0; i < 4; i++)
	{
		if (bytes[i] != 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}




//Toán tử and
QInt QInt::operator&(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	string temp = "";
	if (n1.size() > n2.size())
	{
		FillZero(n2, n1.size());
	}
	else
	{
		FillZero(n1, n2.size());
	}
	
	for (int i = n1.size() - 1; i >= 0; i--)
	{
		if ((n1[i] == '0' && n2[i] == '0') || (n1[i] == '1' && n2[i] == '0') || (n1[i] == '0' && n2[i] == '1'))
		{
			temp = '0' + temp;
		}
		if (n1[i] == '1' && n2[i] == '1')
		{
			temp = '1' + temp;
		}
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử or
QInt QInt::operator|(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	string temp = "";
	if (n1.size() > n2.size())
	{
		FillZero(n2, n1.size());
	}
	else
	{
		FillZero(n1, n2.size());
	}

	for (int i = n1.size() - 1; i >= 0; i--)
	{
		if ((n1[i] == '1' && n2[i] == '1') || (n1[i] == '1' && n2[i] == '0') || (n1[i] == '0' && n2[i] == '1'))
		{
			temp = '1' + temp;
		}
		if (n1[i] == '0' && n2[i] == '0')
		{
			temp = '0' + temp;
		}
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử xor
QInt QInt::operator^(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	string temp = "";
	if (n1.size() > n2.size())
	{
		FillZero(n2, n1.size());
	}
	else
	{
		FillZero(n1, n2.size());
	}

	for (int i = n1.size() - 1; i >= 0; i--)
	{
		if ((n1[i] == '0' && n2[i] == '1') || (n1[i] == '1' && n2[i] == '0'))
		{
			temp = '1' + temp;
		}
		if ((n1[i] == '0' && n2[i] == '0') || (n1[i] == '1' && n2[i] == '1'))
		{
			temp = '0' + temp;
		}
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tủ not
QInt QInt::operator~()
{
	QInt res;
	string n = ConvertInt4toString(this->data);
	FillZero(n, 128);
	string temp;
	for (int i = 0; i < n.size(); i++)
	{
		if (n[i] == '0') temp += '1';
		else if (n[i] == '1') temp += '0';
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
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
	if (a[0] == '0')
	{
		for (int i = 0; i < nBitShifted + 128 - n; i++)
		{
			kq[i] = '0';
		}
	}
	else
	{
		for (int i = 0; i < nBitShifted + 128 - n; i++)
		{
			kq[i] = '1';
		}
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
//Toán tử cộng
QInt QInt::operator+(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	string temp = PlusBit(n1, n2);
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử -
QInt QInt::operator-(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	n2 = ConvertToOffetTwo(n2);
	string temp = PlusBit(n1, n2);
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử *
QInt QInt::operator*(const QInt& num)
{
	QInt res;
	bool sign = 0;//0 là dương , 1 là âm
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	if (CheckSign(this->data) == 0 && CheckSign(num.data) == 0)
	{
		n1 = ConvertToOffetTwo(n1);
		n2 = ConvertToOffetTwo(n2);
		EraseZero(n1);
		EraseZero(n2);
		sign = 0;
	}
	if (CheckSign(this->data) == 0 && CheckSign(num.data) != 0)
	{
		n1 = ConvertToOffetTwo(n1);
		EraseZero(n1);
		sign = 1;
	}
	if (CheckSign(this->data) != 0 && CheckSign(num.data) == 0)
	{
		n2 = ConvertToOffetTwo(n2);
		EraseZero(n2);
		sign = 1;
	}
	string temp = MultiBit(n1, n2);
	if (sign == 1)
	{
		temp = ConvertToOffetTwo(temp);
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử /
QInt QInt::operator/(const QInt& num)
{
	QInt res;

	return res;;
}

//Toán tử <
bool QInt::operator<(const QInt& num) const
{
	if (CheckSign(this->data) == 0 && CheckSign(num.data) == 1)
	{
		return true;
	}
	else if (CheckSign(this->data) == 1 && CheckSign(num.data) == 0)
	{
		return false;
	}

	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	if(n1.size() > n2.size())
	{
		FillZero(n2, n1.size());
	}
	else
	{
	FillZero(n1, n2.size());
	}
	for (int i = 0; i < n1.size(); i++)
	{
		if (n1[i] != n2[i])
		{
			return int(n1[i]) < int(n2[i]);
		}
	}
}

//Toán tử >
bool QInt::operator>(const QInt& num) const
{
	return num < *this;
}

//Toán tử >=
bool QInt::operator>=(const QInt& num) const
{
	if (*this > num || *this == num)
	{
		return true;
	}
	else return false;
}

//Toán tử <=
bool QInt::operator<=(const QInt& num) const
{
	if (*this < num || *this == num)
	{
		return true;
	}
	else return false;
}

//Toán tử ==
bool QInt::operator==(const QInt& num) const
{
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);

	if (n1.size() == n2.size())
	{
		for (int i = 0; i < n1.size(); i++)
		{
			if (n1[i] != n2[i])
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

int main()
{
	
	QInt a, b, c;

	a.ScanQIntDec("12456");
	b.ScanQIntDec("12456");

	if (a >= b)
	{
		cout << "a >= b " << endl;
	}
	else cout << "a <= b" << endl;
	
	
	return 0;
}