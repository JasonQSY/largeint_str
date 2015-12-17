#include "largeint.h"

LargeInt LargeInt::operator+(const LargeInt& b){
	long len1 = largeint.length(), len2 = b.largeint.length();
	int i;
	bool nega = false, negb = false;
	string rep1, rep2;
	vector<char> temp;
	LargeInt result;

	if (largeint[0] == '-'){
		nega = true;
		rep1 = largeint.substr(1, len1 - 1);
	}
	else{
		nega = false;
		rep1 = largeint;
	}
	if (b.largeint[0] == '-'){
		negb = true;
		rep2 = b.largeint.substr(1, len2 - 1);
	}
	else{
		negb = false;
		rep2 = b.largeint;
	}
	len1 = rep1.length();
	len2 = rep2.length();
	if (nega == false && negb == false){
		temp = add(rep1, rep2);
	}
	else if (nega == false && negb == true){
		if (len1>len2 || (len1 == len2 && rep1.compare(rep2)>0)){
			temp = minus(rep1, rep2);
		}
		else if(rep1.compare(rep2) == 0){
			temp.push_back('0');
		}
		else{
			temp = minus(rep2, rep1);
			temp.push_back('-');
		}
	}
	else if (nega == true && negb == false){
		if (len1>len2 || (len1 == len2 && rep1.compare(rep2)>0)){
			temp = minus(rep2, rep1);
			temp.push_back('-');
		}
		else if (rep1.compare(rep2) == 0){
			temp.push_back('0');
		}
		else{
			temp = minus(rep2, rep1);
		}
	}
	else{//nega==true && negb==true
		temp = add(rep1, rep2);
		temp.push_back('-');
	}

	for (i = (int)temp.size(); i >= 1; i--){
		result.largeint.push_back(temp[i - 1]);
	}
	return result;
}

LargeInt LargeInt::operator-(const LargeInt& b){
	string temp;
	LargeInt result;

	if (b.largeint[0] == '-'){
		temp = b.largeint.substr(1, (b.largeint.length() - 1));
		result = (*this) + temp;
	}
	else{
		temp = "-";
		temp += b.largeint;
		result = (*this) + temp;
	}
	return result;
}

LargeInt LargeInt::operator*(const LargeInt& b){
	bool nega = false, negb = false;
	string rep1, rep2;
	LargeInt unsiresult, result;

	if (largeint[0] == '-'){
		nega = true;
		rep1 = largeint.substr(1, largeint.length() - 1);
	}
	else{
		nega = false;
		rep1 = largeint;
	}
	if (b.largeint[0] == '-'){
		negb = true;
		rep2 = b.largeint.substr(1, b.largeint.length() - 1);
	}
	else{
		negb = false;
		rep2 = b.largeint;
	}
	unsiresult = times(rep1, rep2);
	if ((nega == true && negb == false) || (nega == false && negb == true)) {
		result.largeint = "-";
		result.largeint += unsiresult.largeint;
	}
	else {
		result.largeint = unsiresult.largeint;
	}
	return result;
}

vector<char> LargeInt::add(string s1, string s2){
	long len1 = s1.length(), len2 = s2.length(), len = (len1>len2) ? (len1 + 1) : (len2 + 1);
	int i, add = 0;
	char para1, para2;
	vector<char> temp;

	for (i = 1; i <= len; i++){
		if (i>len1){ para1 = '0'; }
		else{ para1 = s1[len1 - i]; }
		if (i>len2){ para2 = '0'; }
		else{ para2 = s2[len2 - i]; }
		if (i != len || add != 0){
			temp.push_back((para1 - '0' + para2 - '0' + add) % 10 + '0');
			add = (para1 - '0' + para2 - '0' + add) / 10;
		}
	}
	return temp;
}
vector<char> LargeInt::minus(string s1, string s2){
	long len1 = s1.length(), len2 = s2.length(), len = (len1>len2) ? len1 : len2;
	int i, minus = 0, res;
	char para1, para2;
	vector<char> temp;

	for (i = 1; i <= len; i++){
		if (i>len1){ para1 = '0'; }
		else{ para1 = s1[len1 - i]; }
		if (i>len2){ para2 = '0'; }
		else{ para2 = s2[len2 - i]; }
		res = para1 - para2 - minus;
		if (res<0) {
			res += 10;
			minus = 1;
		}
		else{ minus = 0; }
		if (i != len || res != 0) {
			temp.push_back(res + '0');
		}
	}
	for (i = temp.size()-1; i >= 0; i--){
		if (temp[i] == '0'){
			temp.pop_back();
		}
		else{
			break;
		}
	}
	return temp;
}
LargeInt LargeInt::times(string s1, string s2){
	vector<LargeInt> vec;
	LargeInt sum("0"), temp;
	int i, j;

	for (i = 0; i < s2.length(); i++){
		vec.push_back(digittimes(s1, s2[i]));
	}
	for (i = 0; i < s2.length(); i++){
		for (j = 1; j < s2.length() - i; j++){
			vec[i].largeint.push_back('0');
		}
		sum = sum + vec[i];
	}
	return sum;
}
string LargeInt::digittimes(string s1, char ch1){
	long len1 = s1.length(), len = len1 + 1;
	char para;
	int i, times = 0;
	string str, strop;

	for (i = 1; i <= len + 1; i++){
		if (i > len1){ para = '0'; }
		else{ para = s1[len1 - i]; }
		str.push_back(((para - '0') * (ch1 - '0') + times % 10) % 10 + '0');
		times = times / 10 + ((para - '0') * (ch1 - '0') + times % 10) / 10;
	}

	for (i = len; i >= 1; i--){
		if (str[i] == '0'){
			str.pop_back();
		}
		else{ break; }
	}
	for (i = str.length() - 1; i >= 0; i--){
		strop.push_back(str[i]);
	}
	return strop;
}