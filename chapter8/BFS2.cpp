/*
 * @Author: lee 
 * @Date: 2018-09-06 22:01:09 
 * @Last Modified by: lee
 * @Last Modified time: 2018-09-06 22:19:52
 */

// P279 广度优先-迷宫从起点到终点最少步数问题

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int maxn = 100;

struct node {
    // 位置（x,y）
    int x, y;
    // step为从起点S到达改位置的最少步数（即层数）
    int step;
} S, T, Node; // S为起点，T为终点，Node为临时结点

int n, m;
// 迷宫信息
char maze[maxn][maxn];
// 记录（x,y）是否已入过队
bool inq[maxn][maxn] = {false};
// 增量数组
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

// 检测位置（x，y）是否有效
bool judge(int x, int y)
{
    // 超过边界
    if (x > n || x < 0 || y > m || y < 0) {
        return false;
    }

    // 墙壁*
    if (maze[x][y] == '*') {
        return false;
    }

    // 已入过队
    if (inq[x][y] == true) {
        return false;
    }

    return true;
}

int BFS()
{
    // 定义队列
    queue<node> q;
    // 起点S入队
    q.push(S);
    while (!q.empty()) {
        // 取队首元素
        node top = q.front();
        // 队首元素出队
        q.pop();
        // 终点，直接返回最少步数
        if (top.x == T.x && top.y == T.y) {
            return top.step;
        }

        for (int i = 0; i < 4; i ++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            // 位置（newX,newY）有效
            if (judge(newX, newY)) {
                Node.x = newX, Node.y = newY;
                // Node层数为top的层数+1
                Node.step = top.step + 1;
                q.push(Node);
                // 设置（newX,newY）已入过队
                inq[newX][newY] = true;
            }
        }
    }

    // 无法到达终点T时返回-1
    return -1;
}

int main()
{
    // nxm阶矩阵
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i ++) {
        // 过滤掉每行后面的空格
        getchar();
        for (int j = 0; j < m; j ++) {
            maze[i][j] = getchar();
        }

        maze[i][m] = '\0';
    }

    // 起点和终点的坐标
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    // 初始化起点的层数为0
    S.step = 0;
    printf("%d\n", BFS());

    return 0;
}
