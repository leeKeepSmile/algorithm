#include <cstdio>
#include <set>

using namespace std;

const int N = 51;

// N个集合 
set<int> st[N];

// 比较集合st[x]与集合st[y] 
void compare(int x, int y)
{
	// totalNum为不同数的个数；sameNum为相同数的个数 
	int totalNum = st[y].size(), sameNum = 0;
	
	for (set<int>::iterator it = st[x].begin(); it != st[x].end(); it ++) {
		// 如果找到相同数 
		if (st[y].find(*it) != st[y].end()) {
			sameNum ++;
		} else {
			// 否则不同数个数++ 
			totalNum ++;
		}
	}
	
	// 输出比率 
	printf("%.1f%%\n", sameNum * 100.0 / totalNum);
} 

int main()
{
	int n, m, k, v, st1, st2;
	
	scanf("%d", &n);
	// 集合下标从1开始 
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &m);
		for (int j = 0; j < m; j ++) {
			scanf("%d", &v);
			// 将v插入集合 
			st[i].insert(v);
		}
	}
	
	scanf("%d", &k);
	for (int i = 0; i < k; i ++) {
		// 欲对比的集合编号 
		scanf("%d%d", &st1, &st2);
		compare(st1, st2); 
	}	
	
	return 0;
}
