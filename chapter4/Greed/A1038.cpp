/**
 * @Author: lee
 * @Date:   2018-06-09T21:38:30+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-09T22:31:13+08:00
 */

// 贪心

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAX_N = 10010;

// 字符串数组
string str[MAX_N];

// 如果a + b < b + a，那么a放在b之前
bool cmp(string a, string b)
{
    return a + b < b + a;
}

int main()
{
    int n;
    string ans;

    // 录入数据
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> str[i];
    }

    // 排序
    sort(str, str + n, cmp);
    // 拼接字符串
    for (int i = 0; i < n; i ++) {
        ans += str[i];
    }

    // 首位去0
    while (ans.size() != 0 && ans[0] == '0') {
        ans.erase(ans.begin());
    }

    // 如果字符串全为0，则输出0；否则输出结果
    if (ans.size() == 0) {
        cout << 0;
    } else {
        cout << ans;
    }

    return 0;
}
