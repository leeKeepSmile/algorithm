#include <cstdio>
#include <stack>

using namespace std;

const int MAX_N = 1010;

// 保留题目中的出栈顺序
int arr[MAX_N];
// 定义栈
stack<int> st;

int main()
{
	// m为栈的最大容量；n为插入队列的长度；
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);

	while (k --) {
		// 清空栈
		while (!st.empty()) {
			st.pop();
		}

		// 读入数据
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &arr[i]);
		}

		// 指向待出栈元素
		int current = 1;
		bool flag = true;

		for (int i = 1; i <= n; i ++) {
			// 入栈
			st.push(i);
			if (st.size() > m) {
				flag = false;
				break;
			}

			while (!st.empty() && st.top() == arr[current]) {
				// 反复出栈
				st.pop();
				current ++;
			}
		}

		if (st.empty() == true && flag == true) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}