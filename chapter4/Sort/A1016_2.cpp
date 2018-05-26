/**
 * @Author: lee
 * @Date:   2018-05-23T21:20:51+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-26T23:21:39+08:00
 */

// 排序

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

// 收费标准（美分/分钟），rate[0]表示00:00~01:00之间的费用，以此类推。
int rate[25];

struct Phone {
    char name[25];
    int month, dd, hh, mm;
    // status=true表示on-line；status=false表示off-line
    bool status;
} p[1010], temp;

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
void getOneRecordMoney(int on, int off, int& totalTime, int& money)
{
    temp = p[on];
    while (temp.dd < p[off].dd || temp.hh < p[off].hh || temp.mm < p[off].mm) {
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

    for (int i = 0; i < 24; i ++) {
        scanf("%d", &rate[i]);
    }
    scanf("%d", &n);
    char tempStatus[10];
    for (int i = 0; i < n; i ++) {
        // 录入数据
        scanf("%s", p[i].name);
        scanf("%d:%d:%d:%d", &p[i].month, &p[i].dd, &p[i].hh, &p[i].mm);
        scanf("%s", tempStatus);
         // 将on-line和off-line转化为bool型变量，方便进行判断。
         if (strcmp(tempStatus, "on-line") == 0) {
             p[i].status = true;
         } else {
             p[i].status = false;
         }
    }

    // 排序电话记录
    sort(p, p + n, cmp);
    int on = 0, off, next;

    while (on < n) {
        // needPrint == 2 表示有配对
        int needPrint = 0;
        next = on;

        while (next < n && strcmp(p[next].name, p[on].name) == 0) {
            if (needPrint == 0 && p[next].status == true) {
                needPrint = 1;
            } else if (needPrint == 1 && p[next].status == false) {
                needPrint = 2;
            }
            next ++;
        }

        // 当前用户没有配对记录，则继续判断下一个用户是否有配对
        if (needPrint < 2) {
            on = next;
            continue;
        }

        int AllMoney = 0;
        printf("%s %02d\n", p[on].name, p[on].month);
        while (on < next) {
            while (
                on < next - 1 &&
                !(p[on].status == true && p[on + 1].status == false)
            ) {
                on ++;
            }
            off = on + 1;
            if (off == next) {
                on = next;
                break;
            }

            // 输出开始时间
            printf("%02d:%02d:%02d ", p[on].dd, p[on].hh, p[on].mm);
            // 输出结束时间
            printf("%02d:%02d:%02d ", p[off].dd, p[off].hh, p[off].mm);

            int totalTime = 0, money = 0;
            getOneRecordMoney(on, off, totalTime, money);
            AllMoney += money;
            printf("%d $%.2f\n", totalTime, money / 100.0);
            on = off + 1;
        }

        printf("Total amount: $%.2f\n", AllMoney / 100.0);
    }

    return 0;
}
