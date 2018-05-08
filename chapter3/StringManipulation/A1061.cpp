/**
 * @Author: lee
 * @Date:   2018-05-08T22:00:19+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-05-08T22:00:43+08:00
 */

 // 字符串处理

 #include <cstdio>

 int main()
 {
     char s1[61], s2[61], s3[61], s4[61];
     char week[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

     scanf("%s%s%s%s", s1, s2, s3, s4);

     // 计数器，用于判断是否跳出循环
     int num = 0;
     for (int i = 0; ; i ++) {
         // 第一个相同的大写字母对应星期
         if (num == 0 && s1[i] == s2[i] && s1[i] >= 'A' && s1[i] <= 'G') {
             printf("%s ", week[s1[i] - 65]);
             num ++;
             continue;
         }

         // 第二个相同的字符表示 时
         if (num == 1 && s1[i] == s2[i]) {
             if (s1[i] >= '0' && s1[i] <= '9') {
                 printf("%02d:", s1[i] - '0');
                 num ++;
             }

             if (s1[i] >= 'A' && s1[i] <= 'N') {
                 printf("%02d:", s1[i] - 'A' + 10);
                 num ++;
             }
         }

         if (num == 2) {
             break;
         }
     }

     // 后面两个字符串相同的字母对应的位置为 分钟
     for (int i = 0; ; i ++) {
         if (s3[i] == s4[i]) {
             if ((s3[i] >= 'A' && s3[i] <= 'Z') || (s3[i] >= 'a' && s3[i] <= 'z')) {
                 printf("%02d", i);
                 break;
             }
         }
     }

     return 0;
 }
