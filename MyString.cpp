#include "MyString.h"

MyString::MyString()	
{
	_len = 0;
	_capacity = CAPACITY;
	_str = new char[_capacity];
}

MyString::MyString(const MyString& mystring)	
{
	_len = mystring._len;
	_capacity = mystring._capacity;

	_str = new char[_capacity];
	for (int i = 0; i < _len; i++)
	{
		_str[i] = mystring._str[i];
	}
}

MyString::MyString(const MyString& mystring, int pos, int len)	
{
	try
	{
		if (pos < 0)
			throw "pos < 0";
		if (pos > mystring._len)
			throw "pos > mystring._len";
		if (len < 0)
			throw "len < 0";
		if (pos + len < mystring._len)
		{
			delete[] _str;

			_len = len;
			_capacity = CAPACITY;
			while (_len > _capacity)
			{
				_capacity += CAPACITY;
			}

			_str = new char[_capacity];
			for (int i = 0; i < len; i++)
			{
				_str[i] = mystring._str[i + pos];
			}
		}
		if (pos + len >= mystring._len)
		{
			delete[] _str;

			_len = mystring._len - pos;
			_capacity = CAPACITY;
			while (_len > _capacity)
			{
				_capacity += CAPACITY;
			}
			_str = new char[_capacity];
			for (int i = pos; i < mystring._len; i++)
			{
				_str[i - pos] = mystring._str[i];
			}
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString::MyString(const char* s)	
{
	if (s == NULL)
	{
		delete[] _str;

		_len = 0;
		_capacity = CAPACITY;
		_str = new char[_capacity];
	}
	else
	{
		delete[] _str;

		_len = strlen(s);
		_capacity = CAPACITY;
		while (_len > _capacity)
		{
			_capacity += CAPACITY;
		}

		_str = new char[_capacity];
		if (_str == NULL || _capacity > MAX_SIZE)
		{
			throw "Khong cap phat duoc bo nho";
		}
		else
		{
			for (int i = 0; i < _len; i++)
			{
				_str[i] = s[i];
			}
		}
	}
}

MyString::MyString(const char* s, int n)	
{
	try
	{
		if (n < 0)
			throw "n is not accepted (n < 0)";
		if (n > strlen(s) || s == NULL)
		{
			MyString temp(s, strlen(s));
		}
		if (n >= 0 && n <= strlen(s))
		{
			delete[] _str;
			_len = n;
			_capacity = CAPACITY;
			while (_len > _capacity)
				_capacity += CAPACITY;

			_str = new char[_capacity];
			if (_str == NULL)
				cerr << "Khong cap phat duoc bo nho";
			else
			{
				for (int i = 0; i < _len; i++)
					_str[i] = s[i];
			}
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

MyString::MyString(int n, char c)
{
	try
	{
		if (n < 0)
			throw "n is not accepted (n < 0)";
		else
		{
			delete[] _str;
			_len = n;
			_capacity = CAPACITY;
			while (_len > _capacity)
				_capacity += CAPACITY;

			_str = new char[_capacity];
			if (_str == NULL)
				cerr << "Khong cap phat duoc bo nho";
			else
			{
				for (int i = 0; i < _len; i++)
					_str[i] = c;
			}

		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString::~MyString()
{
	if(_str!=NULL)
		delete[] _str;
}

MyString& MyString::operator= (const MyString& mystring)
{
	try
	{
		if (_str == mystring._str)
			return *this;

		delete _str;
		_len = mystring._len;
		_capacity = mystring._capacity;
		_str = new char[_capacity];
		if (_str == NULL || _capacity > MAX_SIZE)
		{
			throw "Khong cap phat duoc bo nho";
		}
		else
		{
			for (int i = 0; i < _len; i++)
			{
				_str[i] = mystring._str[i];
			}
			return *this;
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

MyString& MyString::operator= (const char* s)
{
	try
	{
		if (s == NULL)
		{
			delete[] _str;

			_len = 0;
			_capacity = 0;
			_str = new char[_len];
		}
		else
		{
			delete[] _str;

			_len = strlen(s);
			_capacity = CAPACITY;
			while (_len > _capacity)
			{
				_capacity += CAPACITY;
			}

			_str = new char[_capacity];
			if (_str == NULL || _capacity > MAX_SIZE)
			{
				throw "Khong cap phat duoc bo nho";
			}
			else
			{
				for (int i = 0; i < _len; i++)
				{
					_str[i] = s[i];
				}
			}
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

MyString& MyString::operator= (char c)
{
	try
	{
		if (c == '\0')
		{
			delete[] _str;

			_len = 0;
			_capacity = 0;
			_str = new char[_len];
		}
		else
		{
			delete[] _str;

			_len = 1;
			
			

			_str = new char[_capacity];
			if (_str == NULL || _capacity > MAX_SIZE)
			{
				throw "Khong cap phat duoc bo nho";
			}
			else
			{
				_str[0] = c;
			}
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

istream& operator>> (istream& is, MyString& mystring)
{
	char* str = new char[100];
	cout << "\nNhap chuoi: ";
	is >> str;

	return is;
}

ostream& operator<< (ostream& os, const MyString& mystring)
{
	for (int i = 0; i < mystring._len; i++)
		os << mystring._str[i];

	return os;
}


/*************************CAPACITY*************************/
int MyString::size() const
{
	return _len;
}

int MyString::length() const
{
	return _len;
}

int MyString::max_size() const
{
	return MAX_SIZE;
}

void MyString::resize(int n)
{
	try
	{
		if (n < 0)
			throw "n < 0";
		if (n > _len)
		{
			_capacity = CAPACITY;
			while (_len > _capacity)
			{
				_len += CAPACITY;
			}
			for (int i = _len; i < n; i++)
			{
				this->push_back('\0');
			}
		}
		if (n < _len)
		{
			for (int i = n; i < _len; i++)
			{
				_str[i] = '\0';
			}
			_len = n;
		}
		if (n == _len)
			return;
	}
	catch (...)
	{
		cerr << "n is not accepted" << endl;
		exit(-2);
	}
}

void MyString::resize(int n, char c)
{
	try
	{
		if (n < 0)
			throw "n < 0";
		if (n == _len)
			return;
		if (n < _len)
			this->resize(n);
		if (n > _len)
		{
			for (int i = _len; i < n; i++)
				this->push_back(c);
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

int MyString::capacity() const
{
	return _capacity;
}

void MyString::reserve(int n)
{
	while (n > _capacity && _capacity < MAX_SIZE)
		_capacity += n;
}

void MyString::clear()
{
	for (int i = 0; i < _len; i++)
	{
		_str[i] = '\0';
	}
	_len = 0;
}

bool MyString::empty() const
{
	if (_len == 0)
		return true;
	else
		return false;
}


/*************************ELEMENT ACCESS*************************/
char& MyString::operator[] (int pos)
{
	try
	{
		if (_len == 0)
			throw "chuoi rong";
		if (pos < 0 || pos >= _len)
			throw "vi tri phan tu can tim nam ngoai chuoi";
		return _str[pos];
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

char& MyString::at(int pos)
{
	return this->operator[] (pos);
}

char& MyString::back()
{
	try
	{
		if (_len == 0)
			throw "chuoi rong";
		return _str[_len - 1];
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

char& MyString::front()
{
	try
	{
		if (_len == 0)
			throw "chuoi rong";
		return _str[0];
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}



/*************************MODIFIERS*************************/
void MyString::push_back(char c)
{
	try
	{
		if (_len < _capacity && _capacity < MAX_SIZE)
		{
			_len++;
			_str[_len - 1] = c;
		}
		else
		{
			char* temp;
			temp = new char[_len + 1];

			if (temp == NULL || _len + 1 > MAX_SIZE)	
			{
				throw "Khong cap phat duoc bo nho";
			}
			else
			{
				for (int i = 0; i < _len; i++)
				{
					temp[i] = _str[i];
				}
				delete[] _str;

				_capacity += CAPACITY;
				_str = new char[_capacity];
				if (_str == NULL || _capacity > MAX_SIZE)
				{
					throw "Khong cap phat duoc bo nho";	
				}
				_len++;
				for (int i = 0; i < _len - 1; i++)
				{
					_str[i] = temp[i];
				}
				_str[_len - 1] = c;
				delete[] temp;
			}
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

MyString& MyString::operator+= (const MyString& mystring)
{
	for (int i = 0; i < mystring._len; i++)
	{
		this->push_back(mystring._str[i]);
	}

	return *this;
}

MyString& MyString::operator+= (const char* s)
{
	for (int i = 0; i < strlen(s); i++)
	{
		this->push_back(s[i]);
	}

	return *this;
}

MyString& MyString::operator+= (const char c)
{
	this->push_back(c);

	return *this;
}

MyString& MyString::append(const MyString& mystring)
{
	*this += mystring;
	return *this;
}

MyString& MyString::append(const MyString& mystring, int subpos, int sublen)
{
	try
	{
		if (subpos < 0)
			throw "subpos < 0";
		if (subpos > mystring._len)
			throw "subpos > mystring._len";
		if ((subpos >= 0 && subpos < mystring._len) && (sublen < 0 || sublen > mystring._len))
		{
			for (int i = subpos; i < mystring._len; i++)
			{
				this->push_back(mystring._str[i]);
			}
		}
		if ((subpos >= 0 && subpos < mystring._len) && (sublen > 0 && sublen < mystring._len))
		{
			for (int i = subpos; i <= mystring._len - subpos; i++)
			{
				this->push_back(mystring._str[i]);
			}
		}
		if (subpos == 0 && sublen == mystring._len)
			*this += mystring;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString& MyString::append(const char* s)
{
	*this += s;
	return *this;
}

MyString& MyString::append(const char* s, int n)
{
	try
	{
		if (n < 0)
			throw "n < 0";
		if (n > strlen(s))
		{
			*this += s;
			return *this;	
		}
		if (n == 0)
			return *this;
		if (n > 0 && n <= strlen(s))
		{
			for (int i = 0; i < n; i++)
			{
				this->push_back(s[i]);
			}
			
			return *this;
		}
	}
	catch (const char* error)
	{
		cerr << error;
		exit(-2);
	}
}

MyString& MyString::append(int n, char c)
{
	try
	{
		if (n < 0)
			throw "n is not accepted (n < 0)";
		if (n == 0)
			return *this;
		if (n > 0)
		{
			for (int i = 0; i < n; i++)
			{
				this->push_back(c);
			}
			return *this;
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString& MyString::assign(const MyString& mystring)
{
	*this = mystring;
	return *this;
}

MyString& MyString::assign(const MyString& mystring, int subpos, int sublen)
{
	try
	{
		if (subpos < 0)
			throw "subpos < 0";
		if (subpos > mystring._len)
			throw "subpos > mystring._len";
		if ((subpos >= 0 && subpos < mystring._len) && (sublen < 0 || sublen > mystring._len))
		{
			MyString temp(mystring, subpos, mystring._len - subpos);
			*this = temp;
		}
		if ((subpos >= 0 && subpos < mystring._len) && (sublen > 0 && sublen < mystring._len))
		{
			MyString temp(mystring, subpos, sublen);
			*this = temp;
		}
		if (subpos == 0 && sublen == mystring._len)
			*this = mystring;
	}
	catch (const char* error)
	{
		cerr << error;
		exit(-2);
	}
}

MyString& MyString::assign(const char* s)
{
	MyString temp(s);
	*this = temp;
	return *this;
}

MyString& MyString::assign(const char* s, int n)
{
	MyString temp(s, n);
	*this = temp;
	return *this;
}

MyString& MyString::assign(int n, char c)
{
	MyString temp(n, c);
	*this = temp;
	return *this;
}

MyString& MyString::insert(int pos, const MyString& mystring)
{
	try
	{
		if (pos < 0)
			throw "pos < 0";
		if (pos > _len)
			throw "pos > _len";
		MyString temp1(*this, 0, pos);			
		MyString temp2(*this, pos, _len - pos);	
		temp1 += mystring;
		temp1 += temp2;
		*this = temp1;

		return *this;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString& MyString::insert(int pos, const MyString& mystring, int subpos, int sublen)
{
	if (sublen > mystring._len || sublen < 0)
		return this->insert(pos, mystring, subpos, mystring._len);

	MyString temp(mystring, subpos, sublen);
	this->insert(pos, temp);
	return *this;
}

MyString& MyString::insert(int pos, const char* s)
{
	MyString temp(s);
	this->insert(pos, temp);
	return *this;
}

MyString& MyString::insert(int pos, const char* s, int n)
{
	MyString temp(s, n);
	this->insert(pos, temp);
	return *this;
}

MyString& MyString::insert(int pos, int n, char c)
{
	MyString temp(n, c);
	this->insert(pos, temp);
	return *this;
}

MyString& MyString::erase(int pos, int len)
{
	try
	{
		if (pos<0 || pos>_len)
			throw "Vi tri bat dau xoa nam ngoai chuoi";
		MyString temp(*this, 0, pos);
		MyString temp1(*this, pos + len, _len - pos - len);
		temp += temp1;
		*this = temp;
		return *this;
	}
	catch (const char* error)
	{
		cerr << error << endl;
	}
}

MyString& MyString::replace(int pos, int len, const MyString& mystring)
{
	try
	{
		if (pos < 0)
			throw "pos < 0";
		if (pos > _len)
			throw "pos > _len";
		if (pos + len >= _len || len < 0)
		{
			MyString temp1(*this, 0, pos);
			temp1 += mystring;
			*this = temp1;
			return *this;
		}
		else
		{
			MyString temp(*this, 0, pos);
			temp += mystring;
			for (int i = pos + len; i < _len; i++)
			{
				temp.push_back(_str[i]);
			}
			*this = temp;
			return *this;
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

MyString& MyString::replace(int pos, int len, const MyString& mystring, int subpos, int sublen)
{
	MyString temp(mystring, subpos, sublen);
	this->replace(pos, len, temp);
	return *this;
}

MyString& MyString::replace(int pos, int len, const char* s)
{
	MyString temp(s);
	this->replace(pos, len, temp);
	return *this;
}

MyString& MyString::replace(int pos, int len, const char* s, int n)
{
	try
	{
		if (n > strlen(s))
			throw "n > strlen(s) (too long)";
			MyString temp(s, n);
		this->replace(pos, len, temp);
		return *this;
	}
	catch (const char* error)
	{
		cerr << error;
		exit(-2);
	}
}

MyString& MyString::replace(int pos, int len, int n, char c)
{
	MyString temp(n, c);
	this->replace(pos, len, temp);
	return *this;
}

void MyString::swap(MyString& mystring)
{
	*this = mystring;
}

void MyString::pop_back()
{
	try
	{
		if (_len == 0)
			throw "Chuoi rong, khong the pop_back";
		if (_len < _capacity && _capacity < MAX_SIZE)
			_len--;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}


/*************************STRING OPERATIONS*************************/
const char* MyString::c_str() const
{
	try
	{
		char* s = NULL;
		s = new char[_len + 1];
		if (s == NULL)
			throw "Khong cap phat duoc bo nho";
		else
		{
			for (int i = 0; i < _len; i++)
				s[i] = _str[i];
			s[_len] = '\0';
			return s;
		}
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-1);
	}
}

const char* MyString::data() const
{
	return c_str();
}

int MyString::copy(char* s, int len, int pos) const
{
	MyString temp(s);
	MyString temp1(temp, 0, len);
	temp = temp1;
	return temp._len;
}

int MyString::find(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return pos;
	int i = pos;
	int current_pos = 0;
	while (i < _len)
	{
		if (_len - i < mystring._len)
			return npos;
		if (_str[i] == mystring._str[current_pos])
			current_pos++;
		else
			current_pos = 0;
		if (current_pos == mystring._len)
			return i - mystring._len + 1;
		i++;
	}
	return npos;
}

int MyString::find(const char* s, int pos) const
{
	MyString temp(s);
	return find(temp, pos);
}

int MyString::find(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return find(temp, pos);
}

int MyString::find(char c, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	for (int i = pos; i < _len; i++)
	{
		if (c == _str[i])
			return i;
	}
	return npos;
}

void MyString::swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

MyString& MyString::reverse(MyString& mystring)
{
	for (int i = 0; i < mystring._len / 2; i++)
		swap(mystring._str[i], mystring._str[mystring._len - 1 - i]);
	return mystring;
}

int MyString::rfind(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return pos;

	MyString temp;
	temp = *this;
	MyString temp1;
	temp1 = mystring;

	temp = temp.reverse(temp);
	temp1 = temp1.reverse(temp1);
	int value = temp.find(temp1, temp._len - pos - 1);

	return temp._len - value - temp1._len;
}

int MyString::rfind(const char* s, int pos) const
{
	MyString temp(s);
	return rfind(temp, pos);
}

int MyString::rfind(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return rfind(temp, pos);
}

int MyString::rfind(char c, int pos) const
{
	MyString temp(1, c);
	return rfind(temp, pos);
}

int MyString::find_first_of(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return npos;
	for (int i = pos; i < _len; i++)
	{
		for (int j = 0; j < mystring._len; j++)
		{
			if (_str[i] == mystring._str[j])
				return i;
		}
	}
	return npos;
}

int MyString::find_first_of(const char* s, int pos) const
{
	MyString temp(s);
	return find_first_of(temp, pos);
}

int MyString::find_first_of(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return find_first_of(temp, pos);
}

int MyString::find_first_of(char c, int pos) const
{
	MyString temp(1, c);
	return find_first_of(temp, pos);
}

int MyString::find_last_of(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return npos;
	for (int i = pos; i >= 0; --i)
	{
		for (int j = 0; j < mystring._len; j++)
		{
			if (_str[i] == mystring._str[j])
				return i;
		}
	}
	return npos;
}

int MyString::find_last_of(const char* s, int pos) const
{
	MyString temp(s);
	return find_last_of(temp, pos);
}

int MyString::find_last_of(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return find_last_of(temp, pos);
}

int MyString::find_last_of(char c, int pos) const
{
	MyString temp(1, c);
	return find_last_of(temp, pos);
}

int MyString::find_first_not_of(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return pos;

	for (int i = pos; i < _len; i++)
	{
		if (mystring.find(_str[i], 0) == npos)
			return i;
	}

	return npos;
}

int MyString::find_first_not_of(const char* s, int pos) const
{
	MyString temp(s);
	return find_first_not_of(temp, pos);
}

int MyString::find_first_not_of(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return find_first_not_of(temp, pos);
}

int MyString::find_first_not_of(char c, int pos) const
{
	MyString temp(1, c);
	return find_first_not_of(temp, pos);
}

int MyString::find_last_not_of(const MyString& mystring, int pos) const
{
	if (pos < 0 || pos > _len)
		return npos;
	if (mystring._len == 0)
		return pos;

	for (int i = pos; i >= 0; i--)
	{
		if (mystring.find(_str[i], 0) == npos)
			return i;
	}

	return npos;
}

int MyString::find_last_not_of(const char* s, int pos) const
{
	MyString temp(s);
	return find_last_not_of(temp, pos);
}

int MyString::find_last_not_of(const char* s, int pos, int n) const
{
	MyString temp(s, n);
	return find_last_not_of(temp, pos);
}

int MyString::find_last_not_of(char c, int pos) const
{
	MyString temp(1, c);
	return find_last_not_of(temp, pos);
}

MyString MyString::substr(int pos, int len) const
{
	try
	{
		if (pos<0 || pos>_len)
			throw "vi tri bat dau cua substr khong nam trong chuoi";
		MyString temp(*this, pos, len);
		return temp;
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

int MyString::compare(const MyString& mystring) const
{
	if (*this > mystring)
		return 1;
	else if (*this < mystring)
		return -1;
	else
		return 0;
}

int MyString::compare(int pos, int len, const MyString& mystring) const
{
	try
	{
		if (pos < 0 || pos > _len)
			throw "Vi tri can so sanh nam ngoai chuoi";
		MyString temp(*this, pos, len);
		return temp.compare(mystring);
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

int MyString::compare(int pos, int len, const MyString& mystring, int subpos, int sublen) const
{
	try
	{
		if (subpos < 0 || subpos > mystring._len)
			throw "Vi tri can so sanh nam ngoai chuoi";
		MyString temp(*this, pos, len);
		MyString temp1(mystring, subpos, sublen);
		return temp.compare(temp1);
	}
	catch (const char* error)
	{
		cerr << error << endl;
		exit(-2);
	}
}

int MyString::compare(const char* s) const
{
	MyString temp(s);
	return compare(temp);
}

int MyString::compare(int pos, int len, const char* s) const
{
	MyString temp(*this, pos, len);
	return temp.compare(s);
}

int MyString::compare(int pos, int len, const char* s, int n) const
{
	MyString temp(*this, pos, len);
	MyString temp1(s, n);
	return temp.compare(temp1);
}


/*************************NON-MEMBER FUNCTION OVERLOADS*************************/
MyString operator+ (const MyString& lhs, const MyString& rhs)
{
	MyString temp = lhs;
	temp.append(rhs);
	return temp;
}

MyString operator+ (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs + temp;
}

MyString operator+ (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp + rhs;
}

MyString operator+ (const MyString& lhs, char rhs)
{
	MyString temp(1, rhs);
	return lhs + temp;
}

MyString operator+ (char lhs, const MyString& rhs)
{
	MyString temp(1, lhs);
	return temp + rhs;
}

bool operator== (const MyString& lhs, const MyString& rhs)
{
	if (lhs._len == 0 && rhs._len == 0)
		return true;
	for (int i = 0; i < lhs._len; i++)
	{
		if (lhs._len == rhs._len && lhs._str[i] == rhs._str[i])
			return true;
	}
	return false;
}

bool operator== (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp == rhs;
}

bool operator== (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs == temp;
}

bool operator!= (const MyString& lhs, const MyString& rhs)
{
	if (lhs._len == 0 && rhs._len == 0)
		return false;
	for (int i = 0; i < lhs._len; i++)
	{
		if (lhs._len == rhs._len && lhs._str[i] == rhs._str[i])
			return false;
	}
	return true;
}

bool operator!= (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp != rhs;
}

bool operator!= (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs != temp;
}

bool operator< (const MyString& lhs, const MyString& rhs)
{
	int i = 0;
	if (lhs._len == 0 && rhs._len == 0)
		return false;
	if (lhs == rhs)
		return false;
	do {
		if ((int)lhs._str[i] > (int)rhs._str[i])
			return false;
		if ((int)lhs._str[i] < (int)rhs._str[i])
			return true;
		i++;
	} while (i != lhs._len || i != rhs._len || lhs._str[i] == rhs._str[i]);

	if (lhs._len > rhs._len)
		return false;
	else if (lhs._len < rhs._len)
		return true;
}

bool operator< (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp < rhs;
}

bool operator< (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs < temp;
}

bool operator<= (const MyString& lhs, const MyString& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return true;
	else
		return false;
}

bool operator<= (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp <= rhs;
}

bool operator<= (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs <= temp;
}

bool operator> (const MyString& lhs, const MyString& rhs)
{
	if (lhs < rhs || lhs == rhs)
		return false;
	else
		return true;
}

bool operator> (const char* lhs, const MyString& rhs)
{
	MyString temp(lhs);
	return temp > rhs;
}

bool operator> (const MyString& lhs, const char* rhs)
{
	MyString temp(rhs);
	return lhs > temp;
}

void MyString::swap(MyString& x, MyString& y)
{
	MyString temp = x;
	x = y;
	y = x;
}

istream& getline(istream& is, MyString& mystring, char delim)
{
	char check;
	MyString temp;
	is.get(check);
	while (check != delim)
	{
		temp += check;
		is.get(check);
	}
	mystring = temp;
	return is;


}

istream& getline(istream& is, MyString& mystring)
{
	char delim;
	MyString temp;
	is.get(delim);
	while (delim != '\n')
	{
		temp += delim;
		is.get(delim);
	}
	mystring = temp;
	return is;
}
