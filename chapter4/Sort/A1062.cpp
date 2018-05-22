/**
 * @Author: lee
 * @Date:   2018-05-22T22:33:15+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-22T22:33:31+08:00
 */

 // 排序

 #include <cstdio>
 #include <algorithm>

 using namespace std;

 struct Student {
     int number;
     int dScore;
     int cScore;
     // 1表示第一类，2表示第二类，3表示第三类，4表示第四类
     int kind;
 }stu[100000];

 int cmp(Student a, Student b)
 {
     // 总分不同按总分降序排序
     // 总分相同时，若徳分不相同，则按徳分降序排序；否则按准考证号升序排序
     if (a.dScore + a.cScore == b.dScore + b.cScore) {
         if (a.dScore == b.dScore) {
             return a.number < b.number;
         } else {
             return a.dScore > b.dScore;
         }
     } else {
         return a.dScore + a.cScore > b.dScore + b.cScore;
     }
 }

 int main()
 {
     int n, l, h, count = 0;
     scanf("%d%d%d", &n, &l, &h);

     for (int i = 0; i < n; i ++) {
         scanf("%d%d%d", &stu[i].number, &stu[i].dScore, &stu[i].cScore);

         // 分类
         if (stu[i].dScore >= h && stu[i].cScore >= h) {
             stu[i].kind = 1;
         } else if (
             stu[i].dScore >= h && stu[i].cScore < h
             && stu[i].cScore >= l
         ) {
             stu[i].kind = 2;
         } else if (
             stu[i].dScore < h && stu[i].cScore < h
             && stu[i].dScore >= l && stu[i].cScore >= l
             && stu[i].dScore >= stu[i].cScore
         ) {
             stu[i].kind = 3;
         } else if (stu[i].dScore >= l && stu[i].cScore >= l) {
             stu[i].kind = 4;
         } else {
             stu[i].kind = 0;
         }

         // 统计达到最低分数线的考生人数
         if (stu[i].kind != 0) {
             count ++;
         }
     }

     // 排序
     sort(stu, stu + n, cmp);
     printf("%d\n", count);
     for (int i = 1; i <= 4; i ++) {
         for (int j = 0; j < n; j ++) {
             if (stu[j].kind == i) {
                 printf("%d %d %d\n", stu[j].number, stu[j].dScore, stu[j].cScore);
             }
         }
     }

     return 0;
 }
