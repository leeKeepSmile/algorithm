/*
 * @Author: lee 
 * @Date: 2018-09-06 21:33:54 
 * @Last Modified by: lee
 * @Last Modified time: 2018-09-06 21:59:42
 */

// P276 广度优先例子

#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 100;

struct node {
    int x, y;
} Node;

// mxn阶矩阵
int n, m;
// 01矩阵
int matrix[maxn][maxn];
// 记录位置（x,y）是否已入过队
bool inq[maxn][maxn] = {false};
// 增量数组
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

// 判断坐标（x,y）是否需要访问
bool judge(int x, int y) {
    // 越界返回false
    if (x >= n || x < 0 || y >= m || y < 0) {
        return false;
    }

    // 如果当前位置为0，或者（x,y）已经入过队，返回false
    if (matrix[x][y] == 0 || inq[x][y] == true) {
        return false;
    }

    return true;
}

// BFS函数访问位置（x,y）所在的块，将该块中所有"1"的inq都设置为true
void BFS(int x, int y)
{
    // 定义队列
    queue<node> Q;
    // 当前坐标伟（x,y）
    Node.x = x, Node.y = y;
    // 将结点Node入队列
    Q.push(Node);
    inq[x][y] = true;
    while (!Q.empty()) {
        // 取出队首元素
        node top = Q.front();
        // 队首元素出队
        Q.pop();
        for (int i = 0; i < 4; i ++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            // 如果新位置（newX, newY）需要访问
            if (judge(newX, newY)) {
                // 设置Node的坐标为（newX,newY）
                Node.x = newX, Node.y = newY;
                Q.push(Node);
                inq[newX][newY] = true;
            }
        }
    }
}

int main()
{
    scanf("%d%d", &m, &n);
    for (int x = 0; x < n; x ++) {
        for (int y = 0; y < m; y ++) {
            // 读入01矩阵
            scanf("%d", &matrix[x][y]);
        }
    }

    // 存放块数
    int ans = 0;
    // 枚举每一个位置
    for (int x = 0; x < n; x ++) {
        for (int y = 0; y < m; y ++) {
            if (matrix[x][y] == 1 && inq[x][y] == false) {
                ans ++;
                // 访问整个块，将该块所有"1"的inq都标记为true
                BFS(x, y);
            }
        }
    }

    printf("%d\n", ans);

    return 0;
}
