#include <stdio.h>

typedef struct Model{
    float x1, x2, x3, x4, x5;
} Gauss;

int main(){

    Gauss X = {2.2, 3.8, 3.7, -2.7, 2.4};
    int i;

    for(i=0;i<9;i++){
        X.x1 = (-4.1 -0*X.x2 + 1.4*X.x3 + 1.9*X.x4 - 2.7*X.x5)/6.7;
        X.x2 = (4.4 - 2.8*X.x1 - 1.4*X.x3 - 2.2*X.x4 + 2.4*X.x5)/11.4;
        X.x3 = (-1.8 + 1.2*X.x1 + 2.1*X.x2 + 2.8*X.x4 + 1.8*X.x5)/14.5;
        X.x4 = (2.4 + 0.2*X.x1 - 1.2*X.x2 + 0.2*X.x3 - 1.4*X.x5)/5.6;
        X.x5 = (0.9 - 1*X.x1 - 1.2*X.x2 - 0.2*X.x3 - 1.8*X.x4)/6.5;
    }

    printf("X(10) = [%.8f, %.8f, %.8f, %.8f, %.8f]\n", X.x1, X.x2, X.x3, X.x4, X.x5);

    return 0;
}