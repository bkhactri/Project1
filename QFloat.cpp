#include "QFloat.h"

QFloat::QFloat(string FloatStringdata, int He)
{
	if (He == 2)
	{
		ConvertBinStringtoFloat(FloatStringdata, data);
	}
	else
	{
		string bin = DecToBin(FloatStringdata);
		if (bin[0] != '0' && bin[0] != '1')
		{
			throw bin;
		}
		else
		{
			ConvertBinStringtoFloat(bin, data);
		}
	}
}
QFloat::QFloat(string FloatStringdata)
{
	int he(2);

	for (int i = 0; i < int(FloatStringdata.size()); ++i)
	{
		if (FloatStringdata[i] == '.' || (FloatStringdata[i] != '0' && FloatStringdata[i] != '1'))
		{
			he = 10;
		}
	}

	if (he == 2)
	{
		*this = QFloat(FloatStringdata, 2);
	}
	else
	{
		*this = QFloat(FloatStringdata, 10);
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
	cout << "Data: " << endl;

	fflush(stdin); getline(cin, datatmp);

	*this = QFloat(datatmp);
}
void QFloat::PrintQFloat()
{
	cout << BinToDec(ConvertFloattoBinString(data));
}
string QFloat::BinToDec(string binQfloat)
{
	// chuan hoa bit de co du 128 bit;
	while (binQfloat.size() < 128)
	{
		binQfloat.push_back('0');
	}
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

	if (exponentnumber == 1)
	{
		zero = false;
		denormalized = false;
	}
	if (exponentnumber == 0)
	{
		infinity = false;
		NaN = false;
	}

	for (int i = 0; i < significant.size(); i++)
	{
		if (significant[i] == '1')
		{
			zero = false;
			infinity = false;
		}
		if (significant[i] == '0')
		{
			denormalized = false;
			NaN = false;
		}
	}

	if (zero)
	{
		return "Zero";
	}
	if (denormalized)
	{
		return "Denormalized";
	}
	if (infinity)
	{
		return "Infinity";
	}
	if (NaN)
	{
		return "NaN - Not a Number";
	}
	//xu ly de co so thap phan

	significant = "0." + significant; // chuan hoa de chuoi co dang 0.11111111111111111010100000000->0.111111111111111110101
	StandardizedFractions(significant);
	significant = significant.substr(2, significant.size()); //cat de chuoi co dang 111111111111111110101

	string wholes;
	string fraction;
	if (exponentnumber <= 112 && exponentnumber > 0) //neu thoa dieu kien thi dich sang phai dau cham 1.F*2^E
	{
		wholes = '1' + significant.substr(0, exponentnumber);
		fraction = significant.substr(exponentnumber, exponentnumber);
	}
	else
	{
		if (exponentnumber > 112)
		{
			wholes = '1' + significant;
		}
		else
		{
			wholes = '0';
			fraction = '1' + fraction;
			for (int i = 1; i < exponentnumber; i++)
			{
				fraction = '0' + fraction;
			}
		}
	}
	if (sign[0] == '0')
	{
		wholes = WholesToDec(wholes);
	}
	else
	{
		wholes = '-' + WholesToDec(wholes);
	}

	fraction = FractionsToDec(fraction);

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
	StandardizedStringFloat(decQfloat);

	//xu ly dectobin
	//bien nhi phan
	if (decQfloat.size() == 1 && decQfloat[0] == '0')
	{
		return "Zero"; // xac dinh truong hop zero
	}

	int point = decQfloat.find('.');

	string binQfloat;
	if (point == -1)
	{
		binQfloat += WholesToBin(decQfloat); // không tim duoc dau cham co nghia la 123455
	else
	{
		string wholes = decQfloat.substr(0, point); //tim duoc thi tach lam hai phan 123456.1234567 -> 123456 & 0.1234567
		string fraction = '0' + decQfloat.substr(point, decQfloat.size());

		string wholesbin = WholesToBin(wholes);
		string fractionbin;
		if (wholesbin.size() > 1 || wholesbin[0] != '0') //abc. || 1.
		{
			fractionbin = FractionsToBin(fraction, 112 - (wholesbin.size() - 1));
		}
		else//0.abc
		{
			int bit1 = FindBitInFractions(fraction);
			if ((pow(2, 14) - 1) - bit1 <= 0)
			{
				return "Khong The Chuan Hoa!";
			}
			fractionbin = FractionsToBin(fraction, 112 + FindBitInFractions(fraction));
		}

		binQfloat = wholesbin + '.' + fractionbin;
	}
	// tim exponent nhi phan and significant
	point = binQfloat.find('.');
	int exponent = 0;
	string significant;
	if (point == -1)
	{
		exponent = binQfloat.size() - 1 + pow(2, 14) - 1;
		significant = binQfloat.substr(1, binQfloat.size());
		while (significant.size() < 112)
		{
			significant += '0';
		}
	}
	else
	{
		if (point > 1)
		{

			string wholes = binQfloat.substr(0, point);
			string fraction = binQfloat.substr(point + 1, binQfloat.size());
			exponent = wholes.size() - 1 + pow(2, 14) - 1;
			significant = wholes.substr(1, wholes.size()) + fraction;
			while (significant.size() < 112)
			{
				significant += '0';
			}
			significant = significant.substr(0, 112);
		}
		if (point == 1)
		{

		}
	}
	return bit;
}

/*void GetBit(int x, char bit[32])
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
}*/
void ConvertBinStringtoFloat(string bin, int data[4])
{
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
string ConvertFloattoBinString(int data[4])
{
	string b(128, 0);
	char* tmp = new char[32];
	int h = 0;

	for (int i = 0; i < 4; i++)
	{
		GetBit(data[i], tmp);

		for (int j = 0; j < 32; j++)
		{
			b[h++] = tmp[j];
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

	string a(slbit, '0');
	int c = 0;
	for (int i = 128 - slbit; i < 128; i++)
	{
		a[c++] = b[i] + 48;
	}
	return a;
}

string WholesToBin(string dec) // chuyen phan nguy sang nhi pahn
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


//Ham chua hoan thanh
string FractionsToDec(string bin) // ham chuyen thap phan sang dec bin dang 0000001010111101 cua phan thap phan
{
	return bin;
}