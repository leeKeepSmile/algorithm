/*
 * @Author: lee 
 * @Date: 2018-09-07 15:19:41 
 * @Last Modified by: lee
 * @Last Modified time: 2018-09-07 20:25:53
 */

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// maxFacSum记录最大底数之和
int n, k, p, maxFacSum = -1;
// fac记录0^p,1^p...i^p，使得i^p为不超过n的最大数
// ans存放最优底数序列，temp存放递归中的临时底数序列
vector<int> fac, ans, temp;

// 计算x^p
int power(int x)
{
    int ans = 1;
    for (int i = 0; i < p; i ++) {
        ans *= x;
    }

    return ans;
}

// 预处理fac数组，注意把0也存入数组
void init()
{
    int i = 0, temp = 0;
    while (temp <= n) {
        fac.push_back(temp);
        temp = power(++ i);
    }
}

// DFS函数，当前访问fac[index],nowK为当前选中个数
// sum为当前选中的数之和，
void DFS(int index, int nowK, int sum, int facSum)
{
    // 找到一个满足的序列
    if (sum == n && nowK == k) {
        // 底数之和更优
        if (facSum > maxFacSum) {
            // 更新最优底数序列
            ans = temp;
            maxFacSum = facSum;
        }

        return;
    }

    // 这种情况不会产生答案，直接返回
    if (sum > n || nowK > k) {
        return;
    }

    // fac[0]不需要选择
    if (index - 1 >= 0) {
        // 底数index加入临时序列temp
        temp.push_back(index);
        // 选的分支
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        temp.pop_back();
        // 不选的分支
        DFS(index - 1, nowK, sum, facSum);
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    // 初始化fac数组
    init();
    // 从fac的最后一位开始往前搜索
    DFS(fac.size() - 1, 0, 0, 0);
    // 没有找到满足的序列
    if (maxFacSum == -1) {
        printf("Impossible\n");
    } else {
        printf("%d = %d^%d", n, ans[0], p);
        for (int i = 1; i < ans.size(); i ++) {
            printf(" + %d^%d", ans[i], p);
        }
    }

    return 0;
}
