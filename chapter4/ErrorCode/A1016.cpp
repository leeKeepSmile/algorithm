/**
 * @Author: lee
 * @Date:   2018-05-23T21:20:51+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-26T23:23:48+08:00
 */

// 排序

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int RATE_LENGTH = 24;

// 收费标准（美分/分钟），rate[0]表示00:00~01:00之间的费用，以此类推。
int rate[RATE_LENGTH] = {0};

struct Phone {
    char name[25];
    int month, dd, hh, mm;
    // status=true表示on-line；status=false表示off-line
    bool status;
}p[1010], temp;

// 排序
bool cmp(Phone a, Phone b)
{
    int s = strcmp(a.name, b.name);

    // 按以下顺序排序：
    // 字母表顺序、时间升序
    if (s != 0) {
        return s < 0;
    } else if (a.month != b.month) {
        return a.month < b.month;
    } else if (a.dd != b.dd) {
        return a.dd < b.dd;
    } else if (a.hh != b.hh) {
        return a.hh < b.hh;
    } else {
        return a.mm < b.mm;
    }
}

// 获取一个记录所花的费用，以及通话总时间
void getOneRecordMoney(Phone start, Phone end, int &totalTime, int &money)
{
    temp = start;
    while (temp.dd < end.dd || temp.hh < end.hh || temp.mm < end.mm) {
        // 总时间 ++
        totalTime ++;
        // 钱 ++
        money += rate[temp.hh];
        // 分钟 ++
        temp.mm ++;

        // 分钟满60，小时 ++
        if (temp.mm >= 60) {
            temp.mm = 0;
            temp.hh ++;
        }

        // 小时满24，天数 ++
        if (temp.hh >= 24) {
            temp.hh = 0;
            temp.dd ++;
        }
    }
}

int main()
{
    int n;

    for (int i = 0; i < RATE_LENGTH; i ++) {
        scanf("%d", &rate[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        getchar();
        char tempStatus[9] = {'0'};
        // 录入数据
        scanf(
            "%s %d:%d:%d:%d %s",
            p[i].name, &p[i].month, &p[i].dd, &p[i].hh, &p[i].mm, tempStatus
         );
         // 将on-line和off-line转化为bool型变量，方便进行判断。
         if (strcmp(tempStatus, "on-line") == 0) {
             p[i].status = true;
         } else {
             p[i].status = false;
         }
    }

    // 排序电话记录
    sort(p, p + n, cmp);

    int tempTotalBills = 0;
    // 是否仍为某个用户的记录
    bool self = true;
    // 是否已经打印用户名和月份
    bool hasPrintNameMonth = false;
    for (int i = 0; i < n - 1; i ++) {
        if (strcmp(p[i].name, p[i + 1].name) != 0) {
            self = false;
            hasPrintNameMonth = false;
        } else {
            self = true;
        }

        // 如果当前记录状态为on-line
        if (p[i].status) {
            // 下条记录姓名相同并且状态为off-line
            if (self && p[i + 1].status == false) {
                // 该条记录总时间（单位：分钟）
                int totalTime = 0;
                // 该条记录花费金额（单位：美分）
                int money = 0;

                if (!hasPrintNameMonth) {
                    // 输出姓名，月份
                    printf("%s %02d\n", p[i].name, p[i].month);
                    hasPrintNameMonth = true;
                }

                // 输出开始时间
                printf("%02d:%02d:%02d ", p[i].dd, p[i].hh, p[i].mm);
                // 输出结束时间
                printf(
                    "%02d:%02d:%02d ",
                    p[i + 1].dd, p[i + 1].hh, p[i + 1].mm
                );

                // 计算总时间和总费用
                getOneRecordMoney(p[i], p[i + 1], totalTime, money);
                tempTotalBills += money;

                printf("%d $%.2f\n", totalTime, money / 100.0);
            }
        }

        // 如果开始下一个用户的记录或者遍历到最后一条记录时，若总费用不为0，则输出总费用。
        if ((!self || i == n - 2) && tempTotalBills != 0) {
            //输出总费用
            printf("Total amount: $%.2f\n", tempTotalBills / 100.0);
            tempTotalBills = 0;
        }
    }

    return 0;
}
