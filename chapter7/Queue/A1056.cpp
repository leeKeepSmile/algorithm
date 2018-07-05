#include <cstdio>
#include <queue>

using namespace std;

const int MAX_N = 1010;

struct mouse {
	int weight;
	int rank;
}mouse[MAX_N];

int main()
{
	int np, ng, order;
	scanf("%d%d", &np, &ng);

	// 录入重量
	for (int i = 0; i < np; i ++) {
		scanf("%d", &mouse[i].weight);
	}

	// 定义一个队列
	queue<int> q;
	for (int i = 0;i < np; i ++) {
		scanf("%d", &order);
		// 按顺序把老鼠们入队列
		q.push(order);
	}

	// temp为当前轮比赛老鼠的个数；group为组数
	int temp = np, group;
	while (q.size() != 1) {
		// 计算组数
		if (temp % ng == 0) {
			group = temp / ng;
		} else {
			group = temp / ng + 1;
		}

		// 枚举每一组，找出最重的老鼠
		for (int i = 0; i < group; i ++) {
			// k存放最重老鼠的编号
			int k = q.front();
			for (int j = 0; j < ng; j ++) {
				// 最后一组不足ng时退出循环
				if (i * ng + j >= temp) {
					break;
				}

				int front = q.front();
				if (mouse[front].weight > mouse[k].weight) {
					k = front;
				}
				// 当前轮的老鼠排名为group + 1
				mouse[front].rank = group + 1;
				// 出队列
				q.pop();
			}

			// 晋级老鼠入队列
			q.push(k);
		}

		// group只老鼠晋级
		temp = group;
	}

	mouse[q.front()].rank = 1;

	for (int i = 0; i < np; i ++) {
		printf("%d", mouse[i].rank);

		if (i != np - 1) {
			printf(" ");
		}
	}

	return 0;
}
