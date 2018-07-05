#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

// 分别建立标题、作者、关键字、出版社、出版年份与id的映射关系 
map<string, set<int> > mpTitle, mpAuthor, mpKey, mpPub, mpYear;

// 字符串以及map的参数传递速度较慢，如果需要作为函数的参数的话
// 需要尽可能加上引用 
void query(map<string, set<int> >& mp, string& str)
{
	// 未找到 
	if (mp.find(str) == mp.end()) {
		printf("Not Found\n");
	} else {
		set<int>::iterator it; 
		// 输出str对应的id 
		for (it = mp[str].begin(); it != mp[str].end(); it ++) {
			printf("%07d\n", *it);
		}
	}
}

int main()
{
	int n, m, id, type;
	string title, author, key, pub, year;
	
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf("%d", &id);
		// 接收换行 
		getchar();
		getline(cin, title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		// 输入关键字 
		while (cin >> key) {
			mpKey[key].insert(id); 
			// 接收key后的字符 
			char c = getchar(); 
			// 接收到换行符退出 
			if (c == '\n') {
				break;
			} 
		}
		getline(cin, pub);
		mpPub[pub].insert(id);
		getline(cin, year);
		mpYear[year].insert(id);
	}
	
	string temp;
	scanf("%d", &m);
	for (int i = 0; i < m; i ++) {
		scanf("%d: ", &type);
		getline(cin, temp);
		cout << type << ": " << temp << endl;
		if (type == 1) {
			query(mpTitle, temp);
		} else if (type == 2) {
			query(mpAuthor, temp);
		} else if (type == 3) {
			query(mpKey, temp);
		} else if (type == 4) {
			query(mpPub, temp);
		} else {
			query(mpYear, temp);
		}
	}
	
	return 0;
}