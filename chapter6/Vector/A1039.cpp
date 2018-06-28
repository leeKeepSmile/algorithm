/**
 * @Author: lee
 * @Date:   2018-06-28T17:53:10+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-28T20:48:08+08:00
 */

// vector

#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

// 由姓名散列成数字上界
const int M = 26 * 26 * 26 * 10 + 1;
vector<int> selectCourse[M];

// hash函数，将姓名字符串转化为数字
int getId(char name[])
{
    int id = 0;
    for (int i = 0; i < 3; i ++) {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');

    return id;
}

int main()
{
    char name[5];
    int n, k;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i ++) {
        // 课程编号；选课人数
        int course, x;

        scanf("%d%d", &course, &x);
        for (int i = 0; i < x; i ++) {
            scanf("%s", name);

            int id = getId(name);
            selectCourse[id].push_back(course);
        }
    }

    for (int i = 0; i < n; i ++) {
        scanf("%s", name);

        int id = getId(name);
        // 从小打到排序
        sort(selectCourse[id].begin(), selectCourse[id].end());
        printf("%s %lu", name, selectCourse[id].size());
        for (int j = 0; j < selectCourse[id].size(); j ++) {
            printf(" %d", selectCourse[id][j]);
        }

        printf("\n");
    }

    return 0;
}
