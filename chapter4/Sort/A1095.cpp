/**
 * @Author: lee
 * @Date:   2018-06-01T18:30:26+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T17:03:01+08:00
 */

// 排序

// 思路及要点
//（1）利用map<string, int>来存储对应车牌号停留的总时间；
//（2）时间全部转化为秒，有利于简化操作；
//（3）定义两个结构体数组，record[10000]和valid[10000]，record数组存储所有记录；
// valid数组存储匹配正确的记录，这样就可以分段循环；因为查询时间是按时间的升序排序，
// 利用这点可以进行分段排序，valid内的数据同样按时间顺序排序，所以只要在每一个时间段内
// 累加累减停车数量即可求出每个时间段内的停车总数。
//（4）要求最长停车时间和对应的车牌号，停车时间最长的车辆不止一辆时，所有停车时间最长的
// 车牌号都需要输出；方法如下：先求出最长停车时间，然后遍历map，找出时间等于改最长停车
// 时间的车牌号，一次输出；题目还要求按车牌号的字母表顺序输出，所以一开始需要将record按
// 字母表排序，此时得出的map，自然就是按车牌的字母表排序的。

#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;

int n, k;
// map: 车牌号 => 总停车时间
map<string, int> parkTime;

// 车辆记录
// valid记录配对的停车记录，将无效停车记录排除
struct Record {
    // 车牌号
    char plateNumber[8];
    // 时间，单位s(秒)
    int time;
    // 状态，1表示in，0表示out
    bool status;
} record[10000], valid[10000];

// 有效记录总数
int num = 0;

// 按车牌号字母表顺序排序；按时间降序排序
bool cmpNumberParkTime(Record a, Record b)
{
    if (strcmp(a.plateNumber, b.plateNumber) != 0) {
        return strcmp(a.plateNumber, b.plateNumber) < 0;
    } else {
        return a.time < b.time;
    }
}

// 按时间降序排序
bool cmpParkTime(Record a, Record b)
{
    return a.time < b.time;
}

// 将时间转化为秒
int convertTimeToSecond(int hh, int mm, int ss)
{
    return hh * 3600 + mm * 60 + ss;
}

int main()
{
    scanf("%d%d", &n, &k);
    // 录入车辆记录
    for (int i = 0; i < n; i ++) {
        int hh, mm, ss;
        char charStatus[4];
        scanf("%s %d:%d:%d %s",record[i].plateNumber, &hh, &mm, &ss, charStatus);

        // 将时间转化为秒
        record[i].time = convertTimeToSecond(hh, mm, ss);
        if (strcmp(charStatus, "in") == 0) {
            record[i].status = 1;
        } else {
            record[i].status = 0;
        }
    }

    // 最长停留时间
    int maxTime = -1;
    // 按车牌号字母表顺序排序；按时间降序排序
    sort(record, record + n, cmpNumberParkTime);
    for (int i = 0; i < n - 1; i ++) {
        // 车牌号相等；in out匹配，则记录停车时间
        if (
            strcmp(record[i].plateNumber, record[i + 1].plateNumber) == 0 &&
            record[i].status == 1 && record[i + 1].status == 0
        ) {
            // 若map中没有该车牌号的记录，则初始化停车时间
            if (parkTime.count(record[i].plateNumber) == 0) {
                // 初始化停车时间
                parkTime[record[i].plateNumber] = 0;
            }
            // 计算总停车时间
            parkTime[record[i].plateNumber] += record[i + 1].time - record[i].time;
            // 更新最长停车时间
            maxTime = max(maxTime, parkTime[record[i].plateNumber]);
            // 记录配对正确的停车记录
            valid[num ++] = record[i];
            valid[num ++] = record[i + 1];
        }
    }

    // 按停车记录时间排序
    sort(valid, valid + num, cmpParkTime);
    // amount:停车数量；now表示不超过当前查询时间的记录。
    int amount = 0, now = 0;
    // 录入查询信息
    for (int i = 0; i < k; i ++) {
        int hh, mm, ss;
        int seconds;
        scanf("%d:%d:%d", &hh, &mm, &ss);

        seconds = convertTimeToSecond(hh, mm, ss);
        // 计算停车数量
        while (now < num && valid[now].time <= seconds) {
            if (valid[now].status == 1) {
                amount ++;
            } else {
                amount --;
            }

            now ++;
        }

        printf("%d\n", amount);
    }

    // 输出停车时间最长的车牌号
    map<string, int>::iterator it;
    for (it = parkTime.begin(); it != parkTime.end(); it ++) {
        if (it->second == maxTime) {
            printf("%s ", it->first.c_str());
        }
    }

    // 输出停车最长时间
    printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);

    return 0;
}
