#include <iostream>
#include <string>
#include <map>

using namespace std;

// [0, 12]的火星文 
string unitDigit[13] = {
	"tret", "jan", "feb", "mar", "apr", "may", "jun",
	"jly", "aug", "sep", "oct", "nov", "dec"
};

// 13的[0, 12]倍火星文 
string tenDigit[13] = {
	"tret", "tam", "hel", "maa", "huh", "tou", 
	"kes", "hei", "elo", "syy", "lok", "mer", "jou"
};

// 数字 => 火星文 
string numToStr[170];
// 火星文 => 数字 
map<string, int> strToNum;

// 初始化数字和火星文的相互映射 
void init()
{
	for (int i = 0 ; i < 13; i ++) {
		// 个位不为0，十位为0的情况
		numToStr[i] = unitDigit[i];
		strToNum[unitDigit[i]] = i;
		
		// 个位为0，十位不为0的情况
		numToStr[i * 13] = tenDigit[i];
		strToNum[tenDigit[i]] = i * 13;
	}
	
	// 十位 
	for (int i = 1; i < 13; i ++) {
		// 个位 
		for (int j = 1; j < 13; j ++) {
			string str = tenDigit[i] + " " + unitDigit[j];
			numToStr[i * 13 + j] = str;
			strToNum[str] = i * 13 + j;
		}
	}
}

int main()
{
	// 初始化映射 
	init();
	
	int n;
	scanf("%d", &n);
	// 吸收回车 
	getchar();
	
	while (n --) {
		string str;
		getline(cin, str);
		
		// 如果为数字 
		if (str[0] >= '0' && str[0] <= '9') {
			int num = 0;
			// 将字符串转化为数字 
			for (int i = 0; i < str.length(); i ++) {
				num = num * 10 + (str[i] - '0');
			}
			
			cout << numToStr[num] << endl; 
		} else {
			cout << strToNum[str] << endl;
		}
	}
	
	return 0;
}