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
        
        int koef = l;
        int z = 0;
        for (int i = l; i<n - 1;i++){
            //int koef = i;
            for (int j = l; j < k ; j++ ){
                if (a[i+1][j]!=0 || z!=0){
                    z++;
                    //printf("<%0.2f - %0.2f>\n",a[i+1][j], a[koef][j]);
                    a[i+1][j] = a[i+1][j]  - a[koef][j];
                    //printf("<%0.2f - %0.2f>\n",a[i+1][j], a[koef][j]);
                }
            }
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
