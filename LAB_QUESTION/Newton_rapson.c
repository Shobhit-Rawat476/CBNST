Source Code:
#include<stdio.h>
#include<math.h>
#define tol 0.001

double f(double x){
    return x*x*x*x-x-10;
}
double df(double x){
    return 4*x*x*x-1;
}

void newtonRaphson(double x){
    double h = f(x) / df(x);
    int i = 1;

    while(fabs(f(x)) >= tol){
        h = f(x) / df(x);
        printf("Iteration at %d = %lf\n",i++,x);
        x = x - h;
    }
    printf("the value of root : %lf",x);
}
int main(){
    newtonRaphson(1.5);
    return 0;
}
