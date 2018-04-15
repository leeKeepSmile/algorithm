/**
 * @Author: lee
 * @Date:   2018-04-14T18:09:16+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-15T16:03:58+08:00
 */

// 公元年数可被4整除为闰年,但是整百（个位和十位均为0）的年数必须是可以被400整除的才是闰年
//（比如1900年不是闰年），其他都是平年。例如：1997年是平年，2002年是平年；1996年是闰年，
// 2000年是闰年。平年二月有28天，而闰年二月有29天。

// 日期处理

#include <cstdio>

int main()
{
    int date;

    // date = 20130101
    while (scanf("%d", &date) != EOF) {
        int year,mon,day;
        // 获取年月日
        year = date / 10000;
        mon = (date % 10000) / 100;
        day = (date % 100);



        printf("%d %d %d\n", year, mon, day);
    }

    return 0;
}
