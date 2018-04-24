/**
 * @Author: lee
 * @Date:   2018-04-24T17:46:37+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-04-24T19:39:30+08:00
 */

// 查找元素

// 注意点，注意有效生日个数为0,1的情况，此时存在最年轻的人和最年长的人是否存在,若未考虑，
// 测试点会出现格式错误。

#include <cstdio>
#include <cstring>

// 将yyyy/mm/dd转化为整数
int changeToInt(int year, int month, int day)
{
    return year * 10000 + month * 100 + day;
}

struct people{
    char name[6];
    int year;
    int month;
    int day;

    people() {};
    people(int _year, int _month, int _day)
        : year(_year), month(_month), day(_day) {};
    people(char _name[], int _year, int _month, int _day) {
        strcpy(name, _name);
        year = _year;
        month = _month;
        day = _day;
    };
}y, o, temp;

int main()
{
    int n, year, month, day, temp, count = 0;
    char name[6];
    // 最年轻的人是否存在，最年长的人是否存在
    bool yExists, oExists;
    yExists = oExists = 0;

    // 初始化最年轻的人
    y = people(1814, 9, 5);
    // 初始化最年长的人
    o = people(2014, 9, 7);

    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s%d/%d/%d", name, &year, &month, &day);
        temp = changeToInt(year, month, day);

        if (temp >= 18140906 && temp <= 20140906) {
            // 有效生日个数+1
            count ++;

            if (temp > changeToInt(y.year, y.month, y.day)) {
                y = people(name, year, month, day);
                yExists = 1;
            }

            if (temp < changeToInt(o.year, o.month, o.day)) {
                o = people(name, year, month, day);
                oExists = 1;
            }
        }
    }

    printf("%d", count);
    if (oExists) {
        printf(" %s", o.name);
    }
    if (yExists) {
        printf(" %s", y.name);
    }

    return 0;
}
