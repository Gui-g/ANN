#include <stdio.h>
#include <math.h>

double func1(double x1, double x2){
    return pow(x1,2) - 3*pow(x2,2) + 5;
}

double func2(double x1, double x2){
    return pow(x1,2) + 2*pow(x2,2) - 5;
}

double func1dfdx1(double x1){
    return 2*x1;
}

double func1dfdx2(double x2){
    return -6*x2;
}

double func2dfdx1(double x1){
    return 2*x1;
}

double func2dfdx2(double x2){
    return 4*x2;
}

double det(double x1, double x2){
    return func1dfdx1(x1)*func2dfdx2(x2) - func1dfdx2(x2)*func2dfdx1(x1);
}

int main(){

    double X[2][1], F[2][1], Fl[2][2], R[2][1], d;
    int i, i2, i3, i4;

    X[0][0] = 1.57;
    X[1][0] = 1.84;

    for(i=0;i<3;i++){
    
        R[0][0] = 0;
        R[1][0] = 0;

        F[0][0] = func1(X[0][0], X[1][0]);
        F[1][0] = func2(X[0][0], X[1][0]);

        Fl[0][0] = func2dfdx2(X[1][0]);
        Fl[0][1] = -func1dfdx2(X[1][0]);
        Fl[1][0] = -func2dfdx1(X[0][0]);
        Fl[1][1] = func1dfdx1(X[0][0]);

        d = det(X[0][0],X[1][0]);

        for(i2=0;i2<2;i2++){
            for(i3=0;i3<1;i3++){
                for(i4=0;i4<2;i4++)
                    R[i2][i3] += Fl[i2][i4]*F[i4][i3];
            }
        }

        X[0][0] = X[0][0] - (1/d)*R[0][0];
        X[1][0] = X[1][0] - (1/d)*R[1][0]; 
    }

    printf("X(4) = %.8lf, %.8lf\n", X[0][0], X[1][0]);

    return 0;
}