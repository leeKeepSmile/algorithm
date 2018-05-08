/**
 * @Author: lee
 * @Date:   2018-05-08T22:53:01+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-08T23:24:28+08:00
 */

// 字符串处理

// 在user结构体中再定义一个bool型变量来判断账号是否已经改变可以少定义一个结构体数组。

#include <cstdio>
#include <cstring>

struct user{
    char name[11];
    char pwd[11];
}u[1000], res[1000];

int main()
{
    int n, m = 0;

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        getchar();
        scanf("%s%s", u[i].name, u[i].pwd);

        // 账号是否发生改变，0表示未改变，1表示改变
        int flag = 0;
        int len = strlen(u[i].pwd);
        for (int j = 0; j < len; j ++) {
            switch (u[i].pwd[j]) {
                case '1':
                    u[i].pwd[j] = '@';
                    flag = 1;
                    break;
                case '0':
                    u[i].pwd[j] = '%';
                    flag = 1;
                    break;
                case 'l':
                    u[i].pwd[j] = 'L';
                    flag = 1;
                    break;
                case 'O':
                    u[i].pwd[j] = 'o';
                    flag = 1;
                    break;
                default:
                    break;
            }
        }

        // 如果账号发生改变，记录改变后的账号
        if (flag == 1) {
            res[m ++] = u[i];
        }
    }

    // 输出结果
    if (m == 0) {
        if (n == 1) {
            printf("There is 1 account and no account is modified\n");
        } else {
            printf("There are %d accounts and no account is modified\n", n);
        }
    } else {
        printf("%d\n", m);
        for (int i = 0; i < m; i ++) {
            printf("%s %s\n", res[i].name, res[i].pwd);
        }
    }

    return 0;
}
