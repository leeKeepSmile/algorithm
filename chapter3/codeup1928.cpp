/**
 * @Author: lee
 * @Date:   2018-04-14T18:09:16+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-16T20:22:23+08:00
 */

// 公元年数可被4整除为闰年,但是整百（个位和十位均为0）的年数必须是可以被400整除的才是闰年
//（比如1900年不是闰年），其他都是平年。例如：1997年是平年，2002年是平年；1996年是闰年，
// 2000年是闰年。平年二月有28天，而闰年二月有29天。

// 解题思路：假设输入两个数据a,b。a和b均为YYYYMMDD形式。
// （1）先求出a年到b年（不包含b年）之间的天数 - （a年总天数 减去 该年1月1日到a月日的天数 再加 1）
// （2）算出来的天数再加上b年1月1日到b月日的天数。
// （3）需要分别讨论 （同年/不同年） 以及 （同年同月/同年不同月）

// 注意点：输入的两个日期不区分大小，第一个日期可以比第二个日期大，为此，写代码时，不要默许第一个
// 日期比第二个日期小。


// 日期处理

#include <cstdio>

struct dateInfo {
    int year;
    int mon;
    int day;

    // 构造函数
    dateInfo() {};
    dateInfo(int _year, int _mon, int _day) : year(_year), mon(_mon), day(_day) {};
};

// 获取年
int getYear(int date)
{
    return (date / 10000);
}

// 获取月
int getMon(int date)
{
    return ((date % 10000) / 100);
}

// 获取日
int getDay(int date)
{
    return (date % 100);
}

// 判断是否为闰年，1表示是，0表示不是
int isLeapYear(int year)
{
    if ((year % 100 != 0 && year % 4 == 0) || year % 400 == 0) {
        return 1;
    }

    return 0;
}

// 获取该月的总天数
int getDaysOfMon(int year, int mon)
{
    // 该月总天数
    int days = 0;

    if (mon == 2) {
        days = isLeapYear(year) ? 29 : 28;
    } else {
        // 1 3 5 7 8 10 12 月有31天
        days = (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 ||
            mon == 10 || mon == 12) ? 31 : 30;
    }

    return days;
}

int main()
{
    int date1, date2;

    // date = 20130101
    while (scanf("%d%d", &date1, &date2) != EOF) {
        // 两个日期相差的总天数
        int diffDays = 0;
        dateInfo d1, d2, temp;
        d1 = dateInfo(getYear(date1), getMon(date1), getDay(date1));
        d2 = dateInfo(getYear(date2), getMon(date2), getDay(date2));

        // 如果d1 > d2 那么交换两个结构体
        if (d1.year > d2.year) {
            temp = d1;
            d1 = d2;
            d2 = temp;
        }

        // 计算d1.year 和 d2.year差的天数，不包含d2.year年的天数。
        for (int y = d1.year; y < d2.year; y ++) {
            // 如果是闰年
            if (isLeapYear(y)) {
                diffDays += 366;
            } else {
                diffDays += 365;
            }
        }

        // 如果跨年，（1）d1.year一年的天数减去1月1日到(d1.mon)月(d1.day)日的天数，不包括
        // (d1.mon)月(d1.day)日；（2）加上d2.year 1月1日到(d2.mon)月(d2.day)日的天数。
        if (d2.year > d1.year) {
            // 减去d1.year中多算的天数
            for (int m = 1; m < d1.mon; m ++) {
                diffDays -= getDaysOfMon(d1.year, m);
            }
            diffDays = diffDays - d1.day + 1;

            // 加上d2.year中少算的天数
            for (int m = 1; m < d2.mon; m ++) {
                diffDays += getDaysOfMon(d2.year, m);
            }
            diffDays += d2.day;
        }

        // 如果不跨年
        if (d1.year == d2.year) {
            // 如果同年同月
            if (d1.mon == d2.mon) {
                diffDays = d2.day - d1.day + 1;
            } else {
                // 如果同年不同月
                for (int m = d1.mon; m < d2.mon; m ++) {
                    diffDays += getDaysOfMon(d1.year, m);
                }
                diffDays = diffDays - d1.day + 1;
                diffDays += d2.day;
            }
        }

        printf("%d\n", diffDays);
    }

    return 0;
}
