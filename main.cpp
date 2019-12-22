#include "MyString.h"
#include <string>
#include <vector>

void printS(const MyString& S)
{
	cout << S << endl;
	cout << S.size() << endl;
	cout << S.capacity() << endl;
}

void printS(const string& S)
{
	cout << S << endl;
	cout << S.size() << endl;
	cout << S.capacity() << endl;
}

int main()
{
	string s("ahiyerh");
	string s1("iy");
	cout << s.find_last_not_of(s1, 2) << endl;

	MyString S("ahiyerh");
	MyString S1("iy");
	cout << S.find_last_not_of(S1, 2) << endl;

	system("pause");
	return 0;

}