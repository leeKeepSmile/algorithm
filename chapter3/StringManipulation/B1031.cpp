/**
 * @Author: lee
 * @Date:   2018-05-05T22:24:26+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-05T23:10:46+08:00
 */

// 字符串处理

#include <cstdio>
#include <cstring>

int main()
{
    int n, num = 0;
    char iden[100][19] = {'\0'};
    // 存储有问题的身份证号码
    char err[100][19] = {'\0'};
    bool hasAllPassed = 1;
    char m[12] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    // 权重
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s", iden[i]);

        int z, temp = 0, flag = 1;
        for (int j = 0; j < 17; j ++) {
            // 前17位只要有一位不是数字，就跳出循环，并记录有问题的身份证号码
            if (!(iden[i][j] >= '0' && iden[i][j] <= '9')) {
                strcpy(err[num ++], iden[i]);
                hasAllPassed = 0;
                flag = 0;
                break;
            }

            temp += (iden[i][j] - 48) * weight[j];
        }

        // 如果flag == 0，那么就继续下一个循环，不再执行下面的操作
        // 没有改判断语句，第三个测试点会不通过，注意细节！
        if (flag == 0) {
            continue;
        }

        z = temp % 11;

        if (m[z] != iden[i][17]) {
            strcpy(err[num ++], iden[i]);
            hasAllPassed = 0;
        }
    }

    // 输出结果
    if (hasAllPassed) {
        printf("All passed");
    } else {
        for (int i = 0; i < num; i ++) {
            printf("%s\n", err[i]);
        }
    }

    return 0;
}
