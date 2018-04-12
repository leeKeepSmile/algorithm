//
// Created by 李云飞 on 2018/4/12.
//

#include <stdio.h>

int main()
{
    int n;
    int step = 0;

    scanf("%d", &n);

    do {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = (3 * n + 1) / 2;
        }
        step ++;
    } while (n == 1);

    printf("%d", step);

    return 0;
}
