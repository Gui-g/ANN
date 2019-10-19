#include <stdio.h>
#include <math.h>

float func(float x){
    return pow(x,3) - (4*x) - 1;
}

float funcl(float x){
    return (3*pow(x,2)) - 4;
}

int main(){

    int i;

    printf("Q1\n");
    printf("Método de Newton\n");
    float xN = 1.465;
    for(i=0;i<4;i++){
        xN = xN - func(xN)/funcl(xN); 
    }
    printf("%.7f\n", xN);

    printf("Q2\n");
    printf("Método das Secantes\n");
    float xS[5] = {-0.681,0.211,0,0,0};
    for(i=2;i<6;i++){
        xS[i] = (xS[i-2]*func(xS[i-1]) - xS[i-1]*func(xS[i-2]))/(func(xS[i-1]) - func(xS[i-2]));
    }
    printf("%.7f\n", xS[4]);

    printf("Q3\n");
    printf("Método da Posição Falsa\n");
    float a = -0.6, b = 0.347;
    float xF;
    for(i=0;i<5;i++){
        xF = (a*func(b) - b*func(a))/(func(b) - func(a));
        if(func(xF)*func(a) < 0)
            b = xF;
        else
            a = xF;
    }
    printf("%.7f\n", xF);

    return 0;
}