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
QInt::~QInt() {}

//Toán tử gán bằng QInt a,b;  a=b
QInt& QInt::operator=(const QInt& num)
{
	if (IsZero(this->data) == 0)
	{
		for (int i = 0; i < array_size; i++)
		{
			this->data[i] = 0;
		}
	}
	else
	{
		for (int i = 0; i < array_size; i++)
		{
			this->data[i] = num.data[i];
		}
	}
	return *this;
}
//Toán tử gán bằng QInt a;string b; a=b ;
QInt& QInt::operator=(const string nDec)
{
	string nBit = DecToBin(nDec);
	EraseZero(nBit);
	if (nBit.size() > 128)
	{
		cout << "Can't handle" << endl;
		exit(0);
	}
	ConvertStringtoInt4(nBit, this->data);
	return *this;
}


//Hàm trả về chuỗi để in ra giao diện (cho hệ 10)
string QInt::Print_QIntDec()
{
	if (IsZero(this->data) == 1)
	{
		string s = "0";
		return s;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		string nDec = BinToDec(nBit);
		return nDec;
	}
}
//Hàm trả về chuỗi để in ra giao diện (cho hệ 2)
string QInt::Print_QIntBin()
{
	if (IsZero(this->data) == 1)
	{
		string s = "0";
		return s;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		return nBit;
	}
}
//Hàm trả về chuỗi để in ra giao diện (cho hệ 16)
string QInt::Print_QIntHex()
{
	if (IsZero(this->data) == 1)
	{
		string s = "0";
		return s;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		string nHex = BinToHex(nBit);
		return nHex;
	}
}

//Hàm đọc chuỗi hệ 10 sau đó chuyển sang hệ 2 rồi lưu trữ vào data[4]
void QInt::ScanQIntDec(string nDec)
{
	string nBit = DecToBin(nDec);
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}
//Hàm đọc chuỗi  hệ 2 rồi lưu trữ vào data[4]
void QInt::ScanQIntBin(string nBit)
{
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}
//Hàm đọc chuỗi hệ 16 sau đó chuyển sang hệ 2 rồi lưu trữ vào data[4]
void QInt::ScanQIntHex(string nHex)
{
	string nBit = HexToBin(nHex);
	EraseZero(nBit);
	ConvertStringtoInt4(nBit, this->data);
}


//Hàm in ra console test sô thập phân (dạng chuỗi)
void QInt::PrintQIntDec()
{
	if (IsZero(this->data) == 1)
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
//àm in ra console test chuỗi số nhị phân
void QInt::PrintQIntBin()
{
	if (IsZero(this->data) == 1)
	{
		cout << "0" << endl;
	}
	else
	{
		string nBit = ConvertInt4toString(this->data);
		cout << nBit << endl;
	}
}
//àm in ra console test sô thập lục phân (dạng chuỗi)
void QInt::PrintQIntHex()
{
	if (IsZero(this->data) == 1)
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


//Chuyển từ hệ 10 sang hệ 2
string QInt::DecToBin(string nDec)
{
	int status = 1; //Nhớ dấu của số thập phân
	string bit_array; //Lưu trữ chuỗi bit
	char bit;
	if (nDec[0] == '-') //Kiểm tra số hệ 10 nhập vào âm hay dương
	{
		status = -1; // Âm
		nDec.erase(0, 1); //Xoá dấu trừ đầu dãy
	}
	while (nDec != "") //Bắt đầu chia 2 để được phân dư đưa vào chuỗi bit
	{
		nDec = Div2(nDec, bit); //Chia 2 - chuỗi ban đầu chia 2 trả ra chuỗi sau chia và bit  dư 1 hoặc 0
		bit_array += (bit + '0'); //Nối phần bit dư vào chuỗi bit
	}
	reverse(bit_array.begin(), bit_array.end()); //Đảo chuỗi bit để có kq đúng 

	//Đến đây đã có chuỗi bit nhị phân không dấu hoàn chỉnh

	if (status == -1) //Nếu số thập phân là số âm 
	{
		bit_array = ConvertToOffetTwo(bit_array); //đưa chuỗi bit vào hàm bù 2
	}
	return bit_array;
}
//Chuyển từ hệ 16 sang hệ 2
string QInt::HexToBin(string nHex)
{
	//Thuật toán của hàm là sử dung bảng chuyển đổi có sẵn giữa 2 hệ
	string bit_array; //Lưu trữ chuỗi bit
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
//Chuyển từ hệ 10 sang hệ 16
string QInt::DecToHex(string nDec)
{
	string temp = DecToBin(nDec); //Chuyển đổi số hệ thập phân sang chuỗi bit
	string res = BinToHex(temp); //Chuyển đổi chuỗi bit sang số hệ thập lục phân
	return res;
}
//Chuyển từ hệ 2 sang hệ 10
string QInt::BinToDec(string bit)
{
	//Nhóm chúng em sử dụng pp hệ cơ số q tổng quát cho hàm này(q = 2 )
	string nDec = "0"; //Khởi tạo số thập phân mặc định là 0
	int count = bit.size() - 1; //độ dài chuỗi bit
	for (int i = 0; i < bit.size(); i++)
	{
		string temp = "0"; //dùng để lưu trữ giá trị 2^k
		if (bit[i] == '1')
		{
			temp = Multi2(count); //tính giá trị 2^count và trả ra số thập phân dạng chuỗi
			if (i == 0 && count == 127) // nếu đây là số âm nó sẽ có 128 bit và bit đầu là 1
			{
				temp = '-' + temp; //thêm dấu trừ
			}
		}
		count--;// hạ count để cho nhưng lần mũ khác
		nDec = PlusDec(nDec, temp); //Cộng vào để tạo có kq thập phân đúng
	}
	return nDec;
}
//Chuyển từ hệ 2 sang hệ 16
string QInt::BinToHex(string bit)
{
	string nHex, temp;//nHex dùng để chứa sô thập lục phân kq,temp để chứa liên tiếp 4bit trong chuỗi bit 
	FillZero(bit, 4); //Thêm 0 vào đầu chuỗi bit đến khi nào bit.size() chia hết cho 4(*)
	int i = 0;
	//Thuật toán của hàm là sử dung bảng chuyển đổi có sẵn giữa 2 hệ 
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


//Toán tử and 
QInt QInt::operator&(const QInt& num)
{
	QInt res;
	string n1 = ConvertInt4toString(this->data);
	string n2 = ConvertInt4toString(num.data);
	string temp = "";
	//Biến đổi 2 chuỗi bit bằng nhau về kích thước
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
	//Biến đổi 2 chuỗi bit bằng nhau về kích thước
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
	//Biến đổi 2 chuỗi bit bằng nhau về kích thước
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
	//Đảo bit
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
	FillZero(a, 128);
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
	// a + b
	QInt res;
	string a = ConvertInt4toString(this->data); //chuỗi nhị phân a
	string b = ConvertInt4toString(num.data); //chuỗi nhị phân b
	string temp = PlusBit(a, b); //chuỗi nhị phân a+b
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử -
QInt QInt::operator-(const QInt& num)
{
	// a - b
	QInt res;
	string a = ConvertInt4toString(this->data); //chuỗi nhị phân a
	string b = ConvertInt4toString(num.data); //chuỗi nhị phân b 
	b = ConvertToOffetTwo(b); //b -> -b (nếu b âm thì -b->b)
	string temp = PlusBit(a, b);//a - b (nếu b âm thì a + --b)
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử *
QInt QInt::operator*(const QInt& num)
{
	// a * b
	QInt res;
	bool sign = 0;//0 là dương , 1 là âm
	bool aSign = CheckSign(this->data);
	bool bSign = CheckSign(num.data);
	string a = ConvertInt4toString(this->data); //chuỗi nhị phân a
	string b = ConvertInt4toString(num.data); //chuỗi nhị phân b
	string temp;//Lưu chuỗi nhị phân sau khi nhân
	if (IsZero(this->data) == 1 || IsZero(num.data) == 1)//1 trong 2 bằng 0 thì kq nhân =0
	{
		temp = "0";
	}
	else
	{
		if (aSign == 0 && bSign == 0) //cả 2 đều âm
		{
			a = ConvertToOffetTwo(a);//a-> -a
			b = ConvertToOffetTwo(b);//b-> -b
			EraseZero(a);
			EraseZero(b);
			sign = 0;//kết quả dương
		}
		//1 trong 2 âm đổi dấu thằng âm 
		if (aSign == 0 && bSign != 0)
		{
			a = ConvertToOffetTwo(a);
			EraseZero(a);
			sign = 1;//kq mang dấu trừ
		}
		if (aSign != 0 && bSign == 0)
		{
			b = ConvertToOffetTwo(b);
			EraseZero(b);
			sign = 1;
		}
		//nhân 2 chuỗi
		temp = MultiBit(a, b); //chuỗi nhị phân sau nhân
		if (sign == 1)//xét xem kq âm hay dương
		{
			temp = ConvertToOffetTwo(temp);
		}
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}
//Toán tử /
QInt QInt::operator/(const QInt& num)
{
	// a / b
	QInt res;
	bool sign = 0;//0 là dương , 1 là âm
	string a = ConvertInt4toString(this->data);//chuỗi bit tử
	string b = ConvertInt4toString(num.data);//chuỗi bit mẫu
	bool aSign = CheckSign(this->data);
	bool bSign = CheckSign(num.data);
	string temp;
	if (IsZero(this->data) == 1)//tử =0 kq =0
	{
		temp = "0";
	}
	if (IsZero(num.data) == 1)//mấu =0 -> không thể chia
	{
		cout << "Invalid ouput";
	}
	//Kiểm tra dấu như toán tử nhân
	if (aSign == 0 && bSign == 0)
	{
		a = ConvertToOffetTwo(a);
		b = ConvertToOffetTwo(b);
		EraseZero(a);
		EraseZero(b);
		sign = 0;
	}
	if (aSign == 0 && bSign != 0)
	{
		a = ConvertToOffetTwo(a);
		EraseZero(a);
		sign = 1;
	}
	if (aSign != 0 && bSign == 0)
	{
		b = ConvertToOffetTwo(b);
		EraseZero(b);
		sign = 1;
	}

	temp = DivBit(a, b); //Thực hiện phép chia

	if (sign == 1) //Xét điều kiện để thêm -
	{
		temp = ConvertToOffetTwo(temp);
	}
	ConvertStringtoInt4(temp, res.data);
	return res;
}


//Xoay trái
QInt QInt::rol(int nBitRotate)
{
	string a = ConvertInt4toString(this->data);
	int n = a.size();
	string kq;
	kq.resize(128);
	if (nBitRotate < 128 - n) 
	{
		int j = 0;
		for (int i = 0; i < 128 - n - nBitRotate; i++)
		{
			kq[j++] = '0';
		}
		for (int i = 0; i < n; i++)
		{
			kq[j++] = a[i];
		}
	}
	else 
	{
		int j = 128 - nBitRotate;
		int h = 0;
		for (int i = 0; i < 128 - n; i++)
		{
			kq[j++] = '0';
		}
		for (int i = 0; i < nBitRotate - 128 + n; i++)
		{
			kq[j++] = a[i];
		}
		for (int i = nBitRotate - 128 + n; i < n; i++)
		{
			kq[h++] = a[i];
		}
	}
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = 0;
	}
	ConvertStringtoInt4(kq, this->data);
	return *this;
}
//Xoay phải
QInt QInt::ror(int nBitRotate)
{
	string a = ConvertInt4toString(this->data);
	int n = a.size();
	string kq;
	kq.resize(128);
	if (nBitRotate < n)
	{
		int j = 0;
		for (int i = n - nBitRotate; i < n; i++)
		{
			kq[j++] = a[i];
		}
		for (int i = 0; i < 128 - n; i++)
		{
			kq[j++] = '0';
		}
		for (int i = 0; i < n - nBitRotate; i++)
		{
			kq[j++] = a[i];
		}
	}
	else
	{
		int j = 0;
		for (int i = 0; i < nBitRotate - n; i++)
		{
			kq[j++] = '0';
		}
		for (int i = 0; i < n; i++)
		{
			kq[j++] = a[i];
		}
		for (int i = 0; i < 128 - nBitRotate; i++)
		{
			kq[j++] = '0';
		}
	}
	for (int i = 0; i < 4; i++)
	{
		this->data[i] = 0;
	}
	ConvertStringtoInt4(kq, this->data);
	return *this;
}


//Toán tử <
bool QInt::operator<(const QInt& num) const
{
	//Kiểm tra dấu để kết luận nhanh
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
	return CompareBit(n1, n2);
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


//Hàm chia 1 chuỗi số thập phân(num) cho 2 và tìm phần dư của phép chia trả về bit
string Div2(const string num, char& bit)
{
	//Hàm này dùng thuật toán sơ đẳng của phép chia
	string res; //lưu trữ kết quả sau chia
	int temp = 0; //dùng để lưu số bị chia và cuối cùng sẽ nắm giữ phần dư
	int size = num.size();
	for (int i = 0; i < size; i++)
	{
		temp = temp * 10 + (num[i] - '0'); // tạo số bị chia 

		if (i > 0 || (i == 0 && temp >= 2)) //Nếu số bị chia < 2 thì không thể chia
		{
			res += ((temp / 2) + '0'); // đưa kết quả chia vào chuỗi sau chia
		}
		temp = temp % 2; //Tìm phần dư từ số bị chia với 2 để tiếp tục tạo số bị chia mới
	}
	if (temp == 1)//Đến cuối kết quả chia trả về bit 0 hoặc 1 tuỳ vào dư
	{
		bit = 1;
	}
	else bit = 0;
	return res;
}
//Hàm tính 2^(repeat) (tính theo số thập phân)
string Multi2(int repeat)
{
	string res = "1"; // tạo chuỗi kq gán mặc định là 1
	int temp = 0;
	int carry = 0; // phần dư khi nhân > 10 
	for (int i = 0; i < repeat; i++) //lặp lại số lần nhân 2 (tức 2^repeat)
	{
		string multi_temp = ""; //
		for (int j = res.size() - 1; j >= 0; j--) //nhân hết cả chuỗi số cho 2
		{
			temp = (res[j] - '0') * 2 + carry; //nhân phần tử cuối cùng cho 2
			multi_temp = char(temp % 10 + '0') + multi_temp; //nối vào chuỗi kq tạm
			carry = temp / 10; //tìm phần dư 
		}
		if (carry != 0) //nếu sau khi nhân xong dư khác 0 thì nối vào đằng trc
		{
			multi_temp = char(carry + '0') + multi_temp;
			carry = 0;
		}
		res = multi_temp; // gán chuỗi tạm cho chuỗi kq
		//tiếp dụng vòng lập nhân chuỗi res cho 2 đến khi đạt điều kiện dừng
	}
	return res;
}
//Hàm chuyển đồi số phù 2 (số dương -> bù 1 + 1 -> số âm , số ấm -> bù 1 + 1 -> số dương)
string ConvertToOffetTwo(string num)
{
	FillZero(num, 128);// Lắp đầy chuỗi bit bằng ký tự 0 cho đến khi đủ 128 bit
	//Chỉ xảy ra khi là số dương , nếu là số âm thì đã đủ 128 bit
	string temp;
	//Tạo bit dấu
	if (num[0] == '0') //Tức là số dương
	{
		temp += '1';
	}
	else if (num[0] == '1') //Tức là số âm
	{
		temp += '0';
	}
	for (int i = 1; i < num.size(); i++) //Đảo bit
	{
		if (num[i] == '0') temp += '1';
		else if (num[i] == '1') temp += '0';
	}
	//Đến đây đã có dãy bit bù 1
	temp = PlusBit(temp, "1"); // + 1 vào dãy bit bù 1 để có dãy bit bù 2
	return temp;
}
//Hàm cộng 2 chuỗi nhị phân num1 và num2 , handles cho phép cộng tràn
string PlusBit(string num1, string num2)//num1 + num2
{
	int carry = 0; // biến nhớ phần bit thừa mặc định là 0
	if (num1.size() > num2.size()) //Giúp 2 thg có kích thước bằng nhau
	{
		FillZero(num2, num1.size());
	}
	else
	{
		FillZero(num1, num2.size());
	}
	string res = num1;
	for (int i = num1.length() - 1; i >= 0; i--) //Bắt đầu cộng từ bit cuối đi lên
	{
		int temp = (num1[i] - '0') + (num2[i] - '0') + carry;
		if (temp == 3) // ghi bit thứ i là 1 và carry nhớ 1
		{
			res[i] = '1';
			carry = 1;
		}
		if (temp == 2) // ghi bit thứ i là 0 và carry nhớ 1
		{
			res[i] = '0';
			carry = 1;
		}
		else if (temp == 1)  // ghi bit thứ i là 0 và carry nhớ 0
		{
			res[i] = temp + '0';
			carry = 0;
		}
	}
	EraseZero(res);
	return res;
}
//Hàm nhân 2 chuỗi nhị phân num1 và num2
string MultiBit(string num1, string num2)
{
	//Sử dụng pp giống nhân số thập phân
	string res = "0";//chuỗi kết quả
	int step = 0; //biến nhớ lùi vào bao nhiêu số
	if (num1.size() < num2.size()) // đảm bảo num1 luôn lớn hơn num2 -> nhân bằng num2
	{
		string temp = num1;
		num1 = num2;
		num2 = temp;
	}
	for (int i = num2.size() - 1; i >= 0; i--)
	{
		string temp = "0"; //lưu trữ kq quả khi nhân cả bit thứ i của num2 vs num1
		if (num2[i] == '1') //chỉ quan tâm th bit=1 vì bit=0 nhân 0 thì ko có gì
		{
			temp = num1; // gán temp = num1 (vì nhân với 1 nên bằng chính nó)
			FillZero(temp, 128);
			for (int j = 0; j < step; j++) // đếm xem nên lùi bao nhiêu số
			{
				temp.erase(0, 1);
				temp.insert(temp.size(), "0");
			}
		}
		step++;
		res = PlusBit(res, temp); //cộng tạo kết quả sau mỗi lần nhân
		if (res == "") res = "0";
	}
	EraseZero(res);
	return res;
}
//Hàm chia 2 chuỗi nhị phân num1 và num2
string DivBit(string num1, string num2)
{
	string res;
	string negativeNum2 = ConvertToOffetTwo(num2);//chuyển num2 về số âm để trừ trong lúc chia
	if (num1.size() < num2.size())
	{
		res = "0";
	}
	else
	{
		string carry, temp; // carry nắm giữ chuỗi bit dư , temp dùng lưu trữ hiệu 2 chuỗi bit mỗi lần chia
		for (int i = 0; i < num1.size(); i++)
		{
			carry += num1[i];
			if (carry.size() < num2.size())
			{
				res += "0";
			}
			else if (carry.size() >= num2.size() && (CompareBit(carry, num2) == 0 || carry == num2)) //nếu dư >= số chia thì mới trừ
			{
				res += "1";
				temp = PlusBit(carry, negativeNum2); //carry - num2
				carry = temp;
				EraseZero(carry);
			}
			else res += "0";
		}
		if (carry.size() >= num2.size() && (CompareBit(carry, num2) == 0) || carry == num2) //nếu dư >= số chia thì mới lấy dư chia tiếp cho số chia
		{
			string temp = DivBit(carry, num2);
			res += temp;
		}
	}
	EraseZero(res);
	return res;
}
//Hàm cộng số thập phân num1 và num2
string PlusDec(string num1, string num2)
{
	bool sign = 0;//Biến xét dấu , 0 là + , 1 là -
	if (num1[0] != '-' && num2[0] == '-') // num1 - num2 -> Đưa vào hàm trừ thập phân
	{
		num2.erase(0, 1);
		return MinusDec(num1, num2);
	};
	if (num1[0] == '-' && num2[0] != '-') // -num1 + num2 -> Đưa vào hàm trừ thập phân num2 - num1
	{
		num1.erase(0, 1);
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
//Hàm trừ số thập phân num1 và num2
string MinusDec(string num1, string num2)
{
	string res = "";
	int carry = 0; //Biến này để nhớ phần mượn khi trừ 3-8 (mượn 1 -> kq trừ = 5, carry =1 )
	bool sign = 0; //Biến xét dấu , 0 là + , 1 là -

	if (num1.size() > num2.size()) //Giúp 2 thg có kích thước bằng nhau
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


//Hàm lấy bit từ số nguyên x ra mảng bit
void GetBit(int x, char bit[32])
{
	for (int i = 0; i < 32; i++)
	{
		bit[i] = (x >> 31 - i) & 1;
	}
}
//Hàm gán các bit trong mảng bit vào số nguyên x
void SetBit(char bit[32], int& x)
{
	for (int i = 0; i < 32; i++)
	{
		x = x | (bit[i] << 31 - i);
	}
}
//Hàm chuyển đổi chuỗi nhị phân(string) sang lưu vào mảng số nguyên 
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
//Hàm chuyển đổi mảng số nguyên sang chuỗi nhị phân(string)
string ConvertInt4toString(const int data[4])
{
	string a;
	if (IsZero(data) == 1)
	{
		a += "0";
	}
	else
	{
		char* b = new char[128];
		char* temp = new char[32];
		int h = 0;
		for (int i = 0; i < 4; i++)
		{
			GetBit(data[i], temp);
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
	}
	return a;
}


//Hàm thêm 0 vào đầu dãy đến khi nào input.size % nbit == 0 (num là 1 chuỗi nhị phân)
void FillZero(string& num, int nbit)
{
	while (num.size() % nbit != 0)
	{
		num.insert(0, "0");
	}
}
//Hàm xoá 0 tính từ đầu dãy (num là 1 chuỗi nhị phân) 00010101->10101
void EraseZero(string& num)
{
	while (num[0] == '0')
	{
		num.erase(0, 1);
	}
}
//Hàm kiểm tra dấu của data (true -> + , false -> -) //(chỉ so sánh được các số biểu diễn trong miền)
bool CheckSign(const int data[4])
{
	string a = ConvertInt4toString(data);
	if ((a[0] == '0' || a[0] == '1') && a.size() != 128)
	{
		return 1;
	}
	else if (a[0] == '1' && a.size() == 128)
	{
		return 0;
	}
}
//Hàm kiểm tra data có phải là số 0
bool IsZero(const int data[4])
{
	bool flag = 1;
	for (int i = 0; i < 4; i++)
	{
		if (data[i] != 0)
		{
			flag = 0;
			break;
		}
	}
	return flag;
}
//Hàm sao sánh 2 chuỗi bit num1 và num2 (num1 < num2 -> true else false)
bool CompareBit(string num1, string num2)
{
	if (num1.size() > num2.size())
	{
		FillZero(num2, num1.size());
	}
	else
	{
		FillZero(num1, num2.size());
	}
	if (num1 == num2)
	{
		return false;
	}
	for (int i = 0; i < num1.size(); i++)
	{
		if (num1[i] != num2[i])
		{
			return int(num1[i]) < int(num2[i]);
		}
	}
}

