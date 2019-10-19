#include <stdio.h>

typedef struct Model{
    double x1, x2, x3, x4, x5, x6, x7;
} Jacobi;

int main()
{
    Jacobi X = {-1.3, -3.9, -4, -4.6, 0.7, 2, 1.6}, Y;
    int i;
   
    for(i=0;i<9;i++){
        Y.x1 = (2.5 - 0.5*X.x2 + 2*X.x3 - 0.9*X.x4 - 0.9*X.x5 + 2.4*X.x6 - 0.3*X.x7)/8.5;
        Y.x2 = (1.8 - 1.9*X.x1 - 2.5*X.x3 + 1.7*X.x4 + 1.1*X.x5 + 1.1*X.x6 - 2.6*X.x7)/13.5;
        Y.x3 = (-3.6 - 1.2*X.x1 + 3*X.x2 + 2.4*X.x4 + 1.4*X.x5 + 1.6*X.x6 + 1.1*X.x7)/12.9;
        Y.x4 = (1.6 + 0.8*X.x1 - 2*X.x2 - 1.3*X.x3 + 0.7*X.x5 - 2.6*X.x6 +1*X.x7)/10.9;
        Y.x5 = (-1.1 - 1.5*X.x1 + 2.8*X.x2 + 1.8*X.x3 + 1.5*X.x4 - 0.3*X.x6 - 1.5*X.x7)/15.1;
        Y.x6 = (0.4 - 1.4*X.x1 - 1.9*X.x2 + 1.1*X.x3 - 0*X.x4 + 2.5*X.x5 - 2.4*X.x7)/10.8;
        Y.x7 = (3.1 + 1.3*X.x1 + 1.9*X.x2 - 0.3*X.x3 - 0.7*X.x4 + 2.7*X.x5 - 1.9*X.x6)/11.5;
       
        X = Y;
    }
   
    printf("X(10) = [%.8lf, %.8lf, %.8lf, %.8lf, %.8lf, %.8lf, %.8lf]\n", X.x1, X.x2, X.x3, X.x4, X.x5, X.x6, X.x7);

    return 0;
}