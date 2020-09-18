


#include <stdio.h>

#include<stdio.h>

int main() {

   int a[ 10][10], i, j, n,m;
   int sm, p, large, f = 1;

   printf("Enter size of row of matrix:");
   scanf("%d", & m);
   
   printf("Enter size of row of matrix:");
   scanf("%d", & n);

   printf("Enter 2D array elements:");
   for (i = 0; i < m; i++) {
       for (j = 0; j < n; j++) {
           scanf("%d", & a[i][j]);
       }
   }

   printf("Elements of the 2D array is:");
   for (i = 0; i < m; i++) {
       printf("\n");
       for (j = 0; j < n; j++) {
           printf("%d ", a[i][j]);
       }
   }

   /* Logic start here */
   for (i = 0; i < m; i++) {
       p = 0;
       sm = a[i][0];
       for (j = 0; j < n; j++) {
           if (sm > a[i][j]) {
               sm = a[i][j];
               p = j;
           }
       }

       large = 0;
       for (j = 0; j < m; j++) {
           if (large < a[j][p]) {
               large = a[j][p];
           }
       }
       if (sm == large) {
           printf("\nValue of saddle point:%d", sm);
           f = 0;
       }
   }

   if (f > 0)
       printf("\nNo saddle point");

   return 0;
}
