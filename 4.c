#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n,k, l = 0, max_i = 0;
    float det = 1;
    scanf ("%d %d",&k, &n);
    float** a= (float**)malloc(n * sizeof(float*));
    for (int i = 0; i<n; i++)
    {
        a[i] = (float*)malloc(k * sizeof(float));
        for (int j = 0; j<k; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    for (int i = 0;i<n;i++){
        int l = 0;
        for (int j = 0;j<n;j++){
            if (a[i][j] == 0){
                l++;
                if (l == n){
                    printf("determinant raven 0");
                    return 0;
                }
                
            }
        }
    }
    int n1 = 0;
    float max = -1000000000;
    //printf("%d",l);
    while (n1<n-1){
        for (int i = n1; i<n; i++){
            //int x = i;
            //printf("(%d)-(%d)\n", a[i][y], max);
            if (a[i][n1]> max){ // поиск максимума
                max = a[i][n1];
                max_i = i;
            }
        }
        if (max!=a[n1][n1]){  // замена двух строк местами
            //for (int m = 0; m<k;m++){
            float* t = a[n1];
            a[n1]= a[max_i];
            a[max_i] = t;
            det*= -1;
            //}
        }
        for (int i = n1+1;i<n;i++){
            int l = 0;
            float v = a[i][n1];
            for (int j = n1; j<n;j++){
                if (a[i][n1]!=0 || l ==1){
                    l = 1;
                    //printf("xx%fxx\n",v);
                    //printf("<%f>\n",a[i][n1]);
                    a[i][j]-= a[n1][j]*( v / a[n1][n1]);
                   
                }
            }
        }
        n1++;
    }
    for (int i = 0; i<n;i++){
        det *= a[i][i];
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<k;j++){
            printf("%0.2f ",a[i][j]);
        }
        printf("\n");
    }
    printf("%0.2f",det);
    return 0;
}
