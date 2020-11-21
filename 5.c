#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
int main(){
    int n, max_i = 0;
    float det = 1;
    int q = 0;
    scanf ("%d",&n);
    double** a= (double**)malloc(n * sizeof(double*));
    double* b = (double*)malloc(n * sizeof(double));
    for (int i = 0; i<n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j<n+1; j++)
        {
            if (j == n){
                scanf("%lf",&b[q]);
                q++;
                continue;
            }
            scanf("%lf", &a[i][j]);
        }
    }
    int n1 = 0;
    double max = 0;
    while (n1<n - 1){
        for (int i = n1; i<n; i++){
            if (fabs(a[i][n1])> fabs(max)){ // поиск максимума
                max = a[i][n1];
                max_i = i;
            }
        }
        if (max!=a[n1][n1]){  // замена двух строк местами && a[n1][n1] != 0
            double* t = a[n1];
            a[n1]= a[max_i];
            a[max_i] = t;
            det*= -1;
            double x = b[n1];
            b[n1] = b[max_i];
            b[max_i] = x;
        }
        //
        max = -1000000000;
        max_i = n1+1;
        for (int i = n1+1;i<n;i++){
            int l = 0;
            double v = a[i][n1];
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
    double** c = (double**)malloc(n * sizeof(double));
    for (int i = 0; i<n+1; i++)
    {
        c[i] = (double*)malloc((n+1) * sizeof(double));
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            c[i][j] = a[i][j];
        }
    }
    for (int i = 0;i<n;i++){
        c[i][n] = b[i];
    }
    double* d = (double*)malloc(n * sizeof(double));
    for (int i = n-1; i>=0;i--){
        double F = 0;
        for (int j = i+1;j<n;j++){
            F+= d[n-j-1] * c[i][j];
        }
        d[n-1-i] = (c[i][n] - F) / c[i][i];
    }
    int L = 1;
    for (int i = n-1; i>=0;i--){
        printf("x%d = %lf\n",L,d[i]);
        L++;
    }
    return 0;
}
