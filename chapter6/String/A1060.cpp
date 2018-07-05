#include <iostream>
#include <string>

using namespace std;

// 有效位数 
int n;

// e为指数 
string deal(string s, int& e)
{
	// s的下标 
	int k = 0;
	
	// 去除s的前导零 
	while (s.length() > 0 && s[0] == '0') {
		s.erase(s.begin());
	}
	
	//去除s前导零后第一位是小数点，说明s小于0 
	if (s[0] == '.') {
		// 去除小数点 
		s.erase(s.begin()); 
		while (s.length() > 0 && s[0] == '0') {
			// 去除非零位前的所有0 
			s.erase(s.begin());
			// 每去掉一位0，指数e减1 
			e --;
		}
	} else {
		// 去除前导零后的第一位不是小数点时，则找到后面的小数点删除 
		while (k < s.length() && s[k] != '.') {
			// 寻找小数点
			k ++;
			// 只要不碰到小数点就让指数e++ 
			e ++; 
		}
		
		// while结束后，k小于字符串的长度，说明碰到了小数点 
		if (k < s.length()) {
			// 删除小数点 
			s.erase(s.begin() + k);
		}
	}
		
	// 如果去除前导零后s长度为0，说明这个数就是0 
	if (s.length() == 0) {
		e = 0; 
	}
	
	// 精度 
	int num = 0;
	k = 0;
	string res;
	
	while (num < n) {
		if (k < s.length()) {
			res += s[k ++];
		} else {
			res += '0';
		}
		// 精度++ 
		num ++;
	} 
	
	return res;  
}

int main()
{
	string s1, s2, s3, s4;
	cin >> n >> s1 >> s2;
		//e1、e2分别为s1、s2的指数 
	int e1 = 0, e2 = 0;
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	
	// 主体相同并且指数相同，则为YES 
	if (s3 == s4 && e1 == e2) {
		cout << "YES 0." << s3 << "*10^" << e1 << endl; 
	} else {
		cout << "NO 0." << s3 << "*10^" << e1 << " 0." << s4 << "*10^" << e2 << endl; 
	}
		
	return 0;	
}