#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double funcg(double x){
    return 2 + 5.45/(pow(x,2)+6);
}

double funcdgdx(double x){
    return -(5.45*x)/(pow((pow(x,2)+6),2));
}

int main(){
    
    int i;
    double p = 2.48;

    printf("g(x) possui um único ponto fixo?\n");
    printf("|g'(x)| < L < 1\n");
    printf("|g'(3)| < |g'(x)| < |g'(2)|\n");
    printf("%.4lf < |g'(x)| < %.4lf\n", fabs(funcdgdx(3)), fabs(funcdgdx(2)));
    printf("|g'(x)| < 1 em [2,3]\n\n");

    printf("Ponto fixo x de g(x) é raiz de f(x)?\n");
    printf("g(x) = x\n");
    printf("2 + 5.45/(x²+6) = x\n");
    printf("2x² + 12 + 5.45 = x³ + 6\n");
    printf("x³ - 2x² + 6x - 17.45 = 0\n");
    printf("f(x) = 0\n");
    printf("logo ponto fixo x de g(x) é a raiz de f(x)\n\n");

    printf("Sendo p1 = 2.48\n");
    for(i=0;i<7;i++){
        p = funcg(p);
    }
    printf("p8 = %.7lf\n", p);

    return 0;
}