#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n, l = 0, max_i = 0;
    float det = 1;
    int q = 0;
    scanf ("%d",&n);
    float** a= (float**)malloc(n * sizeof(float*));
    float* b = (float*)malloc(n * sizeof(float));
    for (int i = 0; i<n; i++)
    {
        a[i] = (float*)malloc(n * sizeof(float));
        for (int j = 0; j<n+1; j++)
        {
            if (j == n){
                scanf("%f",&b[q]);
                q++;
                continue;
            }
            scanf("%f", &a[i][j]);
        }
    }
    while (l<n){
        int m = 0;
        for (int i = 0;i<n;i++){
            //printf("xx%fxx",a[l][i]);
            if (a[i][l] == 0){
                m++;
                //printf("<%d>\n",i);
                if (m == n){
                    printf("infinity");
                    return 0;
                }
            }
        }
        l++;
    }
    int n1 = 0;
    float max = 0;
    while (n1<n - 1){
        for (int i = n1; i<n; i++){
            if (fabs(a[i][n1])> fabs(max)){ // поиск максимума
                max = a[i][n1];
                max_i = i;
            }
        }
        if (max!=a[n1][n1]){  // замена двух строк местами && a[n1][n1] != 0
            float* t = a[n1];
            a[n1]= a[max_i];
            a[max_i] = t;
            det*= -1;
            float x = b[n1];
            b[n1] = b[max_i];
            b[max_i] = x;
        }
        //
        max = -1000000000;
        max_i = n1+1;
        for (int i = n1+1;i<n;i++){
            int l = 0;
            float v = a[i][n1];
            b[i] = b[i] - b[n1]*( v / a[n1][n1]);
            for (int j = n1; j<n;j++){
                if ((a[i][n1]!=0 || l ==1) ){
                    l = 1;
                    a[i][j]-= a[n1][j]*( v / a[n1][n1]);
                    
                }
            }
            
        }
        n1++;
    }
    float** c = (float**)malloc(n * sizeof(float));
    for (int i = 0; i<n+1; i++)
    {
        c[i] = (float*)malloc((n+1) * sizeof(float));
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            c[i][j] = a[i][j];
        }
    }
    for (int i = 0;i<n;i++){
        c[i][n] = b[i];
    }
    float* d = (float*)malloc(n * sizeof(float));
    for (int i = n-1; i>=0;i--){
        float F = 0;
        for (int j = i+1;j<n;j++){
            F+= d[n-j-1] * c[i][j];
        }
        d[n-1-i] = (c[i][n] - F) / c[i][i];
    }
    int L = 1;
    for (int i = n-1; i>=0;i--){
        printf("x%d = %f\n",L,d[i]);
        L++;
    }
    return 0;
}
