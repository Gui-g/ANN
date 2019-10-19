#include <stdio.h>
#include <math.h>

int main(){

    int i, j, k;
    double X[] = {-2.5,-2,-1.5,-1,-0.5,0,0.5,1,1.5,2,2.5,3,3.5,4,4.5},
            Y[] = {3.78, 5.81, 1.03, 1.4, 0.26, 5.1, 1.12, 5.62, 0.37, 2.05, 0.39, 5.26, 3.95, 4.17, 4.36},
            M[15][16], pivot, R[15], sum;
    
    //escrever matriz
    for(i=0;i<15;i++){
        for(j=0;j<15;j++)
          M[i][j] = pow(X[i],j);
    }

    for(i=0;i<15;i++)
        M[i][15] = Y[i];

    //escalonar
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            if(i>j){
                pivot = M[i][j]/M[j][j];
                for(k=0;k<16;k++)
                    M[i][k] -= pivot*M[j][k];
            }            
        }
    }

    //solução
    R[14] = M[14][15]/M[14][14];
    for(i=13; i>=0; i--){
        sum=0;
        for(j=i+1; j<15; j++)
            sum += M[i][j]*R[j];
        R[i] = (M[i][15]-sum)/M[i][i];
    }

    for(i=0; i<15; i++)
        printf("\na[%d]=%lf\n",i,R[i]);

    return 0;
}