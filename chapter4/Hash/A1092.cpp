/**
 * @Author: lee
 * @Date:   2018-06-05T22:34:36+08:00
 * @Last modified by:   lee
 * @Last modified time: 2018-06-05T22:34:39+08:00
 */

 // 散列

 #include <cstdio>
 #include <cstring>

 int main()
 {
     char a[1001], b[1001];
     // ASCII => 需要珠子个数
     int hashTable[128] = {0};
     scanf("%s%s", a, b);

     int lenA = strlen(a);
     int lenB = strlen(b);

     // 小红需要的珠子种类及个数
     for (int i = 0; i < lenB; i ++) {
         hashTable[b[i]] ++;
     }

     // 摊主珠串中有几颗满足小红的需求
     int count = 0;
     for (int i = 0; i < lenA; i ++) {
         if (hashTable[a[i]] != 0) {
             hashTable[a[i]] --;
             count ++;
         }

         if (count == lenB) {
             break;
         }
     }

     // 输出结果
     if (count == lenB) {
         printf("Yes %d", lenA - lenB);
     } else {
         printf("No %d", lenB - count);
     }

     return 0;
 }
