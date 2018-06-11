/**
 * @Author: lee
 * @Date:   2018-06-10T23:06:57+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-11T23:07:22+08:00
 */

// 二分

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// 定义类型LL表示long long，简化类型
typedef long long LL;

// long long的最大值2^63 - 1；long long型变量初始化值后必须加LL，否则编译错误。
LL inf = (1LL << 63) - 1;

// {0~9,a~z} => 对应十进制数
LL map[256];

// 初始化map数组，将字符转化为10进制数
void init()
{
    for (char c = '0'; c <= '9'; c ++) {
        map[c] = c - '0';
    }
    for (char c = 'a'; c <= 'z'; c ++) {
        map[c] = c - 'a' + 10;
    }
}

// a数组为待转化进制字符串数组；radix为进制数；t为进制数上界
LL converNumber10(char a[], LL radix, LL t)
{
    LL ans = 0;
    int len = strlen(a);

    for (int i = 0; i < len; i ++) {
        ans = ans * radix + map[a[i]];

        // ans溢出或者ans大于上界t，则返回-1
        if (ans < 0 || ans > t) {
            return -1;
        }
    }

    return ans;
}

// 获取n2中最大的数，然后加1作为进制下界。原因是，一个十进制数，将其转化为radix进制时，
// 每一位数字都会比radix小，所以将最大的数+1,作为进制下界。
int getLargestNumber(char n2[])
{
    int ans = -1, len = strlen(n2);

    for (int i = 0; i < len; i ++) {
        if (map[n2[i]] > ans) {
            ans = map[n2[i]];
        }
    }

    // 进制的底线为ans + 1
    return ans + 1;
}

// n2的十进制与t进行比较
// 1表示num > t；0表示num == t；-1表示num < t
int cmp(char n2[], LL radix, LL t)
{
    LL num = converNumber10(n2, radix, t);

    // 溢出，肯定n2 > t
    if (num < 0) {
        return 1;
    }
    if (t > num) {
        return -1;
    } else if (t == num) {
        return 0;
    } else {
        return 1;
    }
}

// 二分求解n2的进制
LL binarySearch(char n2[], LL left, LL right, LL t)
{
    LL mid;
    while (left <= right) {
        mid = (left + right) / 2;

        int flag = cmp(n2, mid, t);
        if (flag == 0) {
            return mid;
        } else if (flag == -1) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // 解不存在
    return -1;
}

char n1[20], n2[20], temp[20];
int tag, radix;

int main()
{
    // 初始化
    init();
    scanf("%s %s %d %d", n1, n2, &tag, &radix);

    // 将n1作为化为10进制的数字，n2的进制未确定，方便后面的计算
    if (tag == 2) {
        strcpy(temp, n1);
        strcpy(n1, n2);
        strcpy(n2, temp);
    }

    // 将n1转化为10进制，经测试，已给出进制的数转化为10进制时，不会溢出
    LL t = converNumber10(n1, radix, inf);
    // 获取n2中最大的数，然后加1，作为进制下界
    LL left = getLargestNumber(n2);
    // 进制上界可以选择 进制下界和n1的十进制数 中选择较大的一个数字，然后加1。原因是
    // 首先进制上界肯定不小于进制下界，要想n2十进制转化后等于n1的十进制，那么在n1十进制大于
    // 进制下界的时候，n2的进制最多选择n1的十进制；因为进制转化前，每一位数字最小为0，其次为1，
    // 0乘任何数=0，1乘任何数等于任何数本身，所以最多进制数等于n1十进制本身。所以选择
    // 进制下界和n1的十进制数 中较大的一个数字，然后加1，作为进制上界。
    LL right = max(left, t) + 1;
    LL ans = binarySearch(n2, left, right, t);
    if (ans == -1) {
        printf("Impossible\n");
    } else {
        printf("%lld\n", ans);
    }

    return 0;
}
