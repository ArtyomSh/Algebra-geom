#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
// создание копии матрицы
double**  copy (double ** a,int n){
    double** b= (double**)malloc(n * sizeof(double*));
    for (int i = 0; i<n; i++)
    {
        b[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            b[i][j] = a[i][j];
        }
    }
    return b;
}
// подсчет детерминанта матрицы
float determinant(double** a, int n){
    double det = 1;
    int  Wh=0,quantity=0,t=0,I_n=0;
    double f=0;
    for (int j = 0; j < n; j++ ){
            for ( int i = 0; i < n; i++ ){
                if (a[i][j]==0){
                    quantity++;
                }
            }
            if (quantity == n) {
                det=0;
                return det;
            }
            quantity=0;
        }
    for (int n1=0; n1<n; n1++){
        if (a[n1][n1]==0){
            for (int j=n1; j<n; j++){
                if (a[j][n1]!=0){
                    Wh = 1;
                    I_n=j;
                    break;
                }
            }
            if (Wh==1){
                for (int j=0; j<n; j++){
                    t=a[n1][j];
                    a[n1][j]=a[I_n][j];
                    a[I_n][j]=t;
                }
            }
        }
        if (a[n1][n1]!=0){
            if (Wh){
                t++;
                Wh=0;
            }
            for (int n2=n1+1; n2<n; n2++){
                f = a[n2][n1] / a[n1][n1];
                for (int J=n1; J<n; J++){ // вычитание
                    a[n2][J] -= a[n1][J] * f;
                }
            }
        }
    }
    
    for(int i=0; i<n; i++){
        det*=a[i][i];
    }
    
    if(t%2!=0)(det*=(-1));
//    if(det==-0){det=0;}
//    return (0);
    return det ;
}
// транспонирование матрицы
double** tran(double** a, int n){
    double** tran= (double**)malloc(n * sizeof(double*));
    for (int i = 0; i<n; i++)
    {
        tran[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i = 0;i<n;i++){
        for (int j = 0; j<n;j++){
            tran[i][j] = a[j][i];
        }
    }
    return tran;
}
// создание матрицы с одной удаленной строкой и одним удаленным столбцом
double** del(double** a,int n, int x,int y){
    double** del= (double**)malloc((n-1) * sizeof(double*));
    for (int i = 0; i<n-1; i++)
    {
        del[i] = (double*)malloc((n-1) * sizeof(double));
    }
    for (int i = 0; i<n;i++){
        if (i == x){
            continue;
        }
        for (int j = 0; j<n;j++){
            if (j == y){
                continue;
            }
            int kx = 0, ky = 0;
            if (i>x) kx=1;
            if (j>y) ky = 1;
            del[i-kx][j-ky] = a[i][j];
        }
    }
    return del;
}

int main(){
    int n;
    scanf ("%d",&n);
    double** a= (double**)malloc(n * sizeof(double*));
    for (int i = 0; i<n; i++)
    {
        a[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j<n; j++)
        {
            scanf("%lf", &a[i][j]);
        }
    }
    
    double** b = copy(a,n);
    double wow = determinant(b,n);
    if (wow == 0){
        printf("NO");
        return 0;
    }
    //    float** m = tran (a,n);
    //    printf("<%f>", wow);
    //    float D = 1/wow;
    double** A = copy (a,n);
    double ** T = tran(a,n);
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            double** q = del(T,n,i,j);
            A[i][j] =  (determinant (q,n-1) * pow((-1),(i+j)))/wow;
        
            //printf("%lf",determinant(q,n-1));
        }
    }
    //float** z = del(a,n,2,2);
    for (int i = 0;i<n;i++){
        for (int j = 0;j<n;j++){
            printf("%.5lf ",A[i][j]);
        }
        printf("\n");
    }
    //    printf("%f",c);
    return 0;
}
