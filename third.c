#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int n,k, l = 0, max_i = 0, N = 0;
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
    
    int max = -1000000000;
    while (l<k && N<n){
        int g = 0;
        for (int j = l;j<k; j++){
            for (int i =N ;i< n; i++){
                if (a[i][j] == 0){
                    g++;
                }
            }
        }
        if (g == n){
            if (l+1 <k ){
                l++;
            }
            printf("_%d_%d_",l,N);
            // N++;
        }
        for (int i = l; i<n; i++){
            //int x = i;
            int y = l;
            //printf("(%d)-(%d)\n", a[i][y], max);
            if (a[i][y]> max){ // поиск максимума
                max = a[i][l];
                max_i = i;
            }
            
        }
        if (max!=a[l][l]){  // замена двух строк местами
            //for (int m = 0; m<k;m++){
            float* t = a[l];
            a[l]= a[max_i];
            a[max_i] = t;
            //}
        }
        for (int i = l;i<n;i++){ // приведение к единичке
            float v = a[i][l];
            if (v!=0){
                //printf("<%d>",a[i][l]);
                for (int j = l; j < k ; j++ ){
                    a[i][j] = a[i][j] / v;
                    //printf("<%f>",a[i][j]);
                }
            }
        }
        for (int i = 0;i<n;i++){
            for (int j = 0;j<k;j++){
                printf("%0.2f ",a[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        int koef = N;
        int z = l+1;
        for (int i = l; i<n-1 ;i++){ // вычитание
            //int koef = i;
            printf("<%d>", z);
            if (a[z][l] != 0){
                for (int j = l; j < k ; j++ ){
                    
                    //z++;
                    printf("<%0.2f - %0.2f>\n",a[z][j], a[koef][j]);
                    a[z][j] = a[z][j]  - a[koef][j];
                    //printf("<%0.2f - %0.2f>\n",a[i+1][j], a[koef][j]);
                }
            }
            z++;
        }
        /*
         for (int i = 0;i<n;i++){
         for (int j = 0;j<k;j++){
         printf("%0.2f ",a[i][j]);
         }
         printf("\n");
         }
         printf("\n");*/
        max = 0;
        l++;
        N++;
    }
    /*
     for (int i = 0;i<n;i++){
     for (int j = 0;j<k;j++){
     printf("%0.2f ",a[i][j]);
     }
     printf("\n");
     }
     */
    int dim = n;
    for (int i = 0;i<n;i++){
        int l = 0;
        for (int j = 0;j<k;j++){
            if (a[i][j] == 0){
                l++;
            }
        }
        if (l == k ){
            dim-=1;
        }
    }
    printf("dim = %d\n",dim);
    if (dim == n){
        printf("Lin. nez\n");
    }else{
        printf("Lin. Zav\n");
    }
    return 0;
}
