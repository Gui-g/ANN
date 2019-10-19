#include <stdio.h>
#include <math.h>

float func(float i){
    return pow(i,5) - (4*i) - 3;
}

int main(){

    int i;
    float a = 0.917, b = 2.756, p;

    printf("\nf(0.917) = %.2f e f(2.756) = %.2f, por Bolzano f(a)*f(b) < 0, logo, existe pelo menos uma raíz real no intervalo [0.917,2.756]\n\n", func(a), func(b));

    for(i=0;i<8;i++){
        p = (a+b)/2;
        if(func(a)*func(p) < 0)
            b = p;
        else if(func(b)*func(p) < 0)
            a = p;
        else if(func(p) == 0)
            break;
    }
    printf("Com n = 8, p ~= %.6f\n", p);

    printf("Quantidade n de vezes para 10^-8 = %.f\n", ceil((log(fabs(2.756-0.917))-log(pow(10,-8))/log(2))));

    return 0;
}