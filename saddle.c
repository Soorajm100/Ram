
#include <stdio.h>
     
      void saddle(int m[10][10],int n)
     {
          
      int i, j, k, min, max, pos[2][2];
     
        for (i = 0; i < n; i++) {
                min = m[i][0];
                for (j = 0; j < n; j++) {
                        if (min >= m[i][j]) {
                                min = m[i][j];
                                pos[0][0] = i;
                                pos[0][1] = j;
                        }
                }

                j = pos[0][1];
                max = m[0][j];
                for (k = 0; k < n; k++) {
                        if (max <= m[k][j]) {
                                max = m[i][j];
                                pos[1][0] = k;
                                pos[1][1] = j;
                        }
                }

               
                if (min == max) {
                        if (pos[0][0] == pos[1][0] &&
                                pos[0][1] == pos[1][1]) {
                                printf("Saddle point  at the location of (%d, %d)  is : %d\n",
                                                pos[0][0], pos[0][1], max);
                        }
                }
        }
      
  }


  int main() {
        int i, j, m[10][10],n;

     
        printf("enter the row of  the square matrix:");
        scanf("%d", &n);

        
        printf(" enter the elements of the square matrix:\n");
        for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                        scanf("%d", &m[i][j]);
                }
        }
        printf("********************************************************************\n\n");
        saddle(m,n);
          return 0;
  }
  
