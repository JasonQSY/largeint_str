#ifndef __LARGEINT_H__
#define __LARGEINT_H__

#include <vector>
#include <string>
#include <cmath>
using namespace std;

class LargeInt
{
public:
	string largeint; // large integer stored as string

	LargeInt() { largeint = ""; } // constructor
	LargeInt(string str) { largeint = str; } // constructor

	const LargeInt& operator=(const LargeInt& b) { largeint = b.largeint; return(*this); }
	LargeInt operator+(const LargeInt& b);
	LargeInt operator-(const LargeInt& b);
	LargeInt operator*(const LargeInt& b);
private:
	vector<char> add(string s1, string s2); 
	vector<char> minus(string s1, string s2);
	LargeInt times(string s1, string s2);
	string digittimes(string s1, char ch1);
};

#endif