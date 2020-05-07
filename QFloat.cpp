#include "QFloat.h"

QFloat::QFloat(string FloatStringdata, int He)
{
	for (int i = 0; i < arraysize; i++)
	{
		data[i] = 0;
	}
	if (He == 2)
	{
		ConvertBinStringtoFloat(FloatStringdata, data);
	}
	else
	{
		string bin = DecToBin(FloatStringdata);
		if (bin[0] != '0' && bin[0] != '1' || (bin.size() == 1 && bin[0] == '0'))
		{
			cout << bin << endl;
		}
		else
		{
			ConvertBinStringtoFloat(bin, data);
		}
	}
}
QFloat::QFloat()
{
	for (int i = 0; i < arraysize; i++)
	{
		data[i] = 0;
	}
}
QFloat::QFloat(int datatmp[4])
{
	for (int i = 0; i < arraysize; ++i)
	{
		data[i] = datatmp[i];
	}
}
QFloat::QFloat(const QFloat& datatmp)
{
	for (int i = 0; i < arraysize; i++)
	{
		data[i] = datatmp.data[i];
	}
}
void QFloat::ScanQFloat()
{
	string datatmp;
	int he(2);
	cout << "He: "; cin >> he;
	cout << "Data: ";
	fflush(stdin); getline(cin, datatmp);
	*this = QFloat(datatmp, he); // khoi tao qfloat
}
string QFloat::PrintQFloat(int fraction) // xuat qfloat
{
	string tmp = ConvertFloattoBinString(data); //chuyen day nhi phan trong data thanh chuoi nhi phan
	return BinToDec(tmp, fraction); //tra ve gia tri bien doi nhi phan -> dec
}
string QFloat::BinToDec(string binQfloat, int numofele) // binqfloat day nhi phan, nummofele soluong phan tu duoc in ra man hinh
{
	// chuan hoa bit de co du 128 bit;
	while (binQfloat.size() < 128)
	{
		binQfloat.push_back('0');
	}
	binQfloat = binQfloat.substr(0, 128);

	//tach ra thanh 3 phan
	string sign = binQfloat.substr(0, 1);
	string exponent = binQfloat.substr(1, 15);
	string significant = binQfloat.substr(16, binQfloat.size());

	// kiem tra zero // KiemTraKhongTheChuanHoa // SoVoCung // SoBaoLoi
	bool zero = true;
	bool denormalized = true;
	bool infinity = true;
	bool NaN = true;
	int exponentnumber(0); // lay gia tri so mu

	for (int i = exponent.size() - 1; i >= 0; i--)
	{
		if (exponent[i] == '1')
		{
			exponentnumber += pow(2, exponent.size() - 1 - i);
		}
	}
	exponentnumber -= (pow(2, 14) - 1);
	//kiem tra dieu kien
	for (int i = 0; i < exponent.size(); i++)
	{
		if (exponent[i] == '0')
		{
			NaN = false;
			infinity = false;
		}
		if (exponent[i] == '1')
		{
			zero = false;
			denormalized = false;
		}
	}
	bool flag = false;
	for (int i = 0; i < significant.size(); i++)
	{
		if (significant[i] == '1')
		{
			zero = false;
			infinity = false;
			flag = true;
		}
	}
	if (zero)
	{
		return "0";
	}
	if (denormalized && flag)
	{
		return "Denormalized";
	}
	if (infinity)
	{
		return "Infinity";
	}
	if (NaN && flag)
	{
		return "NaN - Not a Number";
	}

	//xu ly de co so thap phan
	string wholes;
	string fraction = "0";

	if (exponentnumber < 112 && exponentnumber > 0) //neu thoa dieu kien thi dich sang phai dau cham 1.F*2^E
	{
		wholes = '1' + significant.substr(0, exponentnumber);
		fraction = significant.substr(exponentnumber, significant.size());
	}
	else
	{
		if (exponentnumber >= 112) //so E > so bit luu phan significant
		{
			wholes = '1' + significant;
		}
		else
		{
			if (exponentnumber == 0) // truong hop 1.10101011010011
			{
				wholes = '1';
				fraction = significant;
			}
			else // truong hop 0.010011
			{
				wholes = '0';
				exponentnumber = -exponentnumber;
				fraction = '1' + significant;
				for (int i = 1; i < exponentnumber; i++)
				{
					fraction = '0' + fraction;
				}
			}
		}
	}
	// chuyen phan nguyen sang dec
	if (sign[0] == '0')
	{
		wholes = WholesToDec(wholes);
	}
	else
	{
		wholes = '-' + WholesToDec(wholes);
	}
	// chuyen phan thap phan sang dec
	fraction = FractionsToDec(fraction);
	//lam tron toi da toi 34 ki tu 34 = so chu so phan nguyen + so chu so phan thap phan

	if (numofele)
	{
		while (fraction.size() < numofele)
		{
			fraction = fraction + '0';
		}

		bool flag = false; // phan nguyen co bi tang len hay khong
		if (fraction[numofele] >= '5')
		{
			for (int i = numofele - 1; i >= 0; i--)
			{
				if (fraction[i] >= '0' && fraction[i] <= '9')
				{
					if (fraction[i] == '9') // cong so nguyen
					{
						if (i == 0)
						{
							flag = true;
						}
						fraction[i] = '0';
					}
					else
					{
						fraction[i] = char(fraction[i] + 1);
						break;
					}
				}
			}
		}
		if (flag)
		{
			bool flagtmp = false;
			for (int i = wholes.size() - 1; i >= 0; i--)
			{
				if (wholes[i] >= '0' && wholes[i] <= '9')
				{
					if (wholes[i] == '9')
					{
						if (i == 0)
						{
							flagtmp = true;
						}
						wholes[i] = '0';
					}
					else
					{
						wholes[i] = char(wholes[i] + 1);
						break;
					}
				}
			}
			if (flagtmp)
			{
				wholes = '1' + wholes;
			}

		}
		fraction = fraction.substr(0, numofele);
	}
	else
	{
		numofele = 34 - wholes.size();
		if (fraction.size() > numofele)
		{
			bool flag = false;
			if (fraction[numofele] >= '5')
			{
				for (int i = numofele - 1; i >= 0; i--)
				{
					if (fraction[i] >= '0' && fraction[i] <= '9')
					{
						if (fraction[i] == '9')
						{
							if (i == 0)
							{
								flag = true;
							}
							fraction[i] = '0';
						}
						else
						{
							fraction[i] = char(fraction[i] + 1);
							break;
						}
					}
				}
			}
			if (flag)
			{
				bool flagtmp = false;
				for (int i = wholes.size() - 1; i >= 0; i--)
				{
					if (wholes[i] >= '0' && wholes[i] <= '9')
					{
						if (wholes[i] == '9')
						{
							if (i == 0)
							{
								flagtmp = true;
							}
							wholes[i] = '0';
						}
						else
						{
							wholes[i] = char(wholes[i] + 1);
							break;
						}
					}
				}
				if (flagtmp)
				{
					wholes = '1' + wholes;
				}

			}
			fraction = fraction.substr(0, numofele);
		}
		for (int i = fraction.size() - 1; i >= 1; i--)
		{
			if (fraction[i] == '0')
			{
				fraction.pop_back();
			}
			if (fraction[i] == '.')
			{
				fraction.pop_back();
				break;
			}
			if (fraction[i] >= '1' && fraction[i] <= '9')
			{
				break;
			}
		}
	}

	return wholes + '.' + fraction;
}
string QFloat::DecToBin(string decQfloat)
{
	string bit;
	if (decQfloat[0] == '-') // xu ly bit dấu
	{
		decQfloat = decQfloat.substr(1, decQfloat.size());
		bit = '1';
	}
	else
	{
		bit = '0';
	}

	//chuan hoa string
	StandardizedStringFloat(decQfloat);//0000125.25220000 -> 125.

	//xu ly dectobin
	//bien nhi phan
	if (decQfloat.size() == 1 && decQfloat[0] == '0')
	{
		string zero;
		while (zero.size() < 128)
		{
			zero += '0';
		}
		return zero; // xác định trường hợp zero
	}

	int point = decQfloat.find('.');

	string binQfloat;
	if (point == -1)//123552
	{
		binQfloat += WholesToBin(decQfloat); // không tìm được dâu chấm tức có dạng 123456485
	}
	else
	{
		string wholes = decQfloat.substr(0, point); // tìm được thì tách làm 2 phần 123456.1234567 -> 123456 & 0.1234567
		string fraction = '0' + decQfloat.substr(point, decQfloat.size());

		string wholesbin = WholesToBin(wholes);
		string fractionbin;
		if (wholesbin.size() > 1 || wholesbin[0] != '0') //abc. || 1.
		{
			fractionbin = FractionsToBin(fraction, 113 - (wholesbin.size() - 1));
		}
		else//0.abc
		{
			int bit1 = FindBitInFractions(fraction);
			if ((pow(2, 14) - 1) - bit1 <= 0)
			{
				return "Denormalized";
			}
			fractionbin = FractionsToBin(fraction, 113 + bit1);//00000000000000000000000000000000001111101010
		}

		binQfloat = wholesbin + '.' + fractionbin;
	}
	// tim exponent nhi phan and significant

	point = binQfloat.find('.'); // 123123 -> 1010001010.010101
	int exponent = 0;
	string significant;

	if (point == -1)
	{
		exponent = binQfloat.size() - 1 + pow(2, 14) - 1;
		significant = binQfloat.substr(1, binQfloat.size());
	}
	else
	{
		if (point > 1)//101101011.010101111001
		{
			string wholes = binQfloat.substr(0, point);
			string fraction = binQfloat.substr(point + 1, binQfloat.size());

			exponent = wholes.size() - 1 + pow(2, 14) - 1;
			significant = wholes.substr(1, wholes.size()) + fraction;
		}
		if (point == 1) //0.101010111111111 || 1.00000101011111
		{
			if (binQfloat[0] == '0')
			{
				for (int i = 2; i < binQfloat.size(); i++)
				{
					if (binQfloat[i] == '1')
					{
						exponent = -(i - 1) + pow(2, 14) - 1;
						significant = binQfloat.substr(i + 1, binQfloat.size());
						break;
					}
				}
			}
			else
			{
				exponent = pow(2, 14) - 1;
				significant = binQfloat.substr(2, binQfloat.size());
			}
		}
	}

	while (significant.size() < 112)
	{
		significant += '0';
	}
	// Lam tron len
	if (significant.size() > 112)
	{
		if (significant[112] == '1')
		{
			int find0 = significant.find('0');
			if (find0 != -1)
			{
				for (int i = 111; i >= 0; i--)
				{
					if (significant[i] == '1')
					{
						significant[i] = '0';
					}
					else
					{
						significant[i] = '1';
						break;
					}
				}
			}
			else
			{
				string tmp(112, '0');
				significant = tmp;
				exponent++;
			}
		}
	}
	//xac dinh cac truong hop loi
	significant = significant.substr(0, 112);
	if (exponent < 0)
	{
		exponent = 0;
		return "Denormalized";
	}

	bool flag = false;
	if (exponent >= 32767)
	{
		flag = true;
	}
	for (int i = 0; i < significant.size(); i++)
	{
		if (!flag)
		{
			break;
		}
		else
		{
			if (significant[i] == '1')
			{
				return "NaN - Not a Number";
			}
		}
	}
	if (flag)
	{
		return "Infinity";
	}

	string exp;
	while (exponent > 0)
	{
		exp = char((exponent % 10) + 48) + exp;
		exponent /= 10;
	}

	exp = WholesToBin(exp); // chuyen mu sang bin luu vao day bit

	while (exp.size() < 15) // dam bao my co 15bit
	{
		exp = '0' + exp;
	}

	exp += significant;
	bit += exp;
	return bit;
}

void ConvertBinStringtoFloat(string bin, int data[4]) // dua du lieu vao data
{
	while (bin.size() < 128)
	{
		bin += '0';
	}
	string b(128, '0');
	int k = 127;

	for (int i = bin.size() - 1; i >= 0; i--)
	{
		b[k--] = bin[i] - 48;
	}

	char* tmp = new char[32];
	int y = 0;
	int z = 0;

	for (int i = 0; i < 128; i++)
	{
		tmp[y++] = b[i];
		if (y % 32 == 0)
		{
			y = 0;
			SetBit(tmp, data[z++]);
		}
	}

	delete[] tmp;
}
string ConvertFloattoBinString(int data[4]) // lay du lieu tu data chuyen sang day bit
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
	while (a.size() < 128)
	{
		a = '0' + a;
	}

	return a;
}
string WholesToBin(string dec) // chuyen phan nguyen sang nhi phan
{
	for (int i = 0; i < dec.size(); i++)
	{
		if (i == dec.size() - 1 && i == 0 && dec[0] == '0')
		{
			break;
		}

		if (dec[i] != '0')
		{
			break;
		}
		else
		{
			dec = dec.substr(1, dec.size());
			i--;
		}
	}

	int status = 1;
	string bit_array;
	char bit;
	if (dec[0] == '-')
	{
		status = -1;
		dec.erase(0, 1);
	}
	while (dec != "")
	{
		dec = Div2(dec, bit);
		bit_array += (bit + '0');
	}
	reverse(bit_array.begin(), bit_array.end()); //Den day da bieu dien dc dang khong dau

	if (status == -1)
	{
		bit_array = ConvertToOffetTwo(bit_array);
	}
	return bit_array;
}
string FractionsToBin(string frac, int numoffractions) // a.cdef frac co dang 0.101010 numoffractions so phan tu bin lay. tra ve day bit 01010101
{
	string bit;

	while (bit.size() < numoffractions)
	{
		if (frac == "0.0" || frac == "1.0")
		{
			if (frac == "0.0")	bit += '0';
			else
			{
				bit += '1';
				frac == "0.0";
			}
		}
		int memo = 0;

		for (int i = frac.size() - 1; i >= 0; i--)
		{
			int mul2 = (int(frac[i]) - 48) * 2 + memo;

			if (frac[i] != '.')
			{
				if (mul2 >= 10)
				{
					memo = 1;
					frac[i] = char((mul2 - 10) + 48);
				}
				else
				{
					frac[i] = char(mul2 + 48);
					memo = 0;
				}
			}
		}

		bool flag = false;

		for (int i = frac.size() - 1; i > 2; i--)
		{
			if (frac[i] == '0' && !flag)
			{
				frac.pop_back();
			}
			else
			{
				flag = true;
			}

			if (flag)
			{
				break;
			}
		}

		if (frac[0] == '1')
		{
			bit.push_back('1');
			frac[0] = '0';
		}
		else
		{
			bit.push_back('0');
		}
	}

	return bit;
}
void StandardizedStringFloat(string& decQfloat) // chuan hoa chuoi QFloat(dec) 000001525.12350000000 --> 1525.1235
{
	int point = decQfloat.find('.');
	if (point == -1)
	{
		StandardizedWholes(decQfloat);
	}
	else
	{
		if (point == 0)
		{
			decQfloat = '0' + decQfloat;
		}
		string tmp = "0.";
		string fraction(decQfloat, point + 1, decQfloat.size()); fraction = tmp + fraction;
		string wholes(decQfloat, 0, point);

		StandardizedWholes(wholes);
		StandardizedFractions(fraction);

		if (fraction.size() == 1)
		{
			decQfloat = wholes;
		}
		else
		{
			decQfloat = wholes + fraction.substr(1, fraction.size());
		}
	}
}
void StandardizedWholes(string& wholes) //whole co dang 000000125782 hoac 215241 chuan hoa phan nguyen
{
	for (int i = 0; i < wholes.size(); i++)
	{
		if (wholes[i] == '0' && wholes.size() > 1)
		{
			wholes = wholes.substr(1, wholes.size());
			i--;
		}
		else
		{
			break;
		}
	}
}
void StandardizedFractions(string& fractions) // 0.abcd chuan hoa phan thuc co the cho ra 0 hoac 0.12345152
{
	for (int i = fractions.size() - 1; i >= 1; i--)
	{
		if (fractions[i] == '0' || fractions[i] == '.')
		{
			fractions.pop_back();
		}
		else
		{
			break;
		}
	}
}
int FindBitInFractions(string frac) // tim vi tri bit 1 trong chuoi thap phan bien doi
{
	int vitri = 0;
	while (true)
	{
		if (vitri > pow(2, 14) - 1)
		{
			break;
		}
		if (frac == "0.0" || frac == "1.0")
		{
			if (frac == "0.0")	break;
			else
			{
				return vitri + 1;
				frac == "0.0";
			}
		}
		int memo = 0;

		for (int i = frac.size() - 1; i >= 0; i--)
		{
			int mul2 = (int(frac[i]) - 48) * 2 + memo;

			if (frac[i] != '.')
			{
				if (mul2 >= 10)
				{
					memo = 1;
					frac[i] = char((mul2 - 10) + 48);
				}
				else
				{
					frac[i] = char(mul2 + 48);
					memo = 0;
				}
			}
		}

		bool flag = false;
		for (int i = frac.size() - 1; i > 2; i--)
		{
			if (frac[i] == '0' && !flag)
			{
				frac.pop_back();
			}
			else
			{
				flag = true;
			}

			if (flag)
			{
				break;
			}
		}

		if (frac[0] == '1')
		{
			return vitri + 1;
		}
		else
		{
			vitri++;
		}
		if (vitri >= pow(2, 14) - 1)
			return vitri;
	}
	return vitri;
}
string WholesToDec(string bit) //phan nguyen tu nhi phan sang thap phan
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
string FractionsToDec(string bin) // hàm chuyển đổi phần thập phân dạng bin sang dec
{
	string dec = "0";
	for (int i = 0; i < bin.size(); i++)
	{
		if (bin[i] == '1')
		{
			string temp = PowNegative(i + 1);
			if (dec.size() > temp.size())
			{
				FillZeroLast(temp, dec.size());
			}
			else
			{
				FillZeroLast(dec, temp.size());
			}
			dec = PlusDec(dec, temp);
		}
	}
	return dec;
}
string PowNegative(int repeat)
{
	string res = "1";
	int temp = 0;
	int carry = 0;
	for (int i = 0; i < repeat; i++)
	{
		string multi_temp = "";
		for (int j = res.size() - 1; j >= 0; j--)
		{
			temp = (res[j] - '0') * 5 + carry;
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
	if (res.size() < repeat)
	{
		FillZero(res, repeat);
	}
	return res;
}
//Hàm thêm 0 vào đầu dãy đến khi nào input.size % nbit == 0 (num là 1 chuỗi nhị phân)
void FillZeroLast(string& num, int nbit)
{
	while (num.size() % nbit != 0)
	{
		num.insert(num.size(), "0");
	}
}