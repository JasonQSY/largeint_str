#include <iostream>
#include "largeint.h"
using namespace std;

// the following deal with cin>>
istream& operator>>(istream& is, LargeInt& a)
{
	is >> a.largeint;
	return is;
}

// the following deal with cout<<
ostream& operator<<(ostream& os, LargeInt& a)
{
	os << a.largeint;
	return os;
}

int main()
{
	LargeInt a, b, c, d, e;

	cout << "Please enter two integers: " << endl;
	cout << "a = "; cin >> a;
	cout << "b = "; cin >> b;
	c = a + b;
	d = a - b;
	e = a * b;
	cout << "c = a + b = " << c << endl;
	cout << "d = a - b = " << d << endl;
	cout << "e = a * b = " << e << endl;
	getchar();
	getchar();
	return(0);
}