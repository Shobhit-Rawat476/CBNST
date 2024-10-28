#include<stdio.h>
#include<math.h>
#define MAX 10
int fact(int n){
    int factorial = 1;
    for(int  i = 2 ; i <= n ; i++){
        factorial *= i;
    }
    return factorial;
}
void Forward_diff_table(float x[], float y[][MAX], int n){
    for(int i = 1; i < n ;i++){
        for(int j = 0 ; j < n-1 ; j++){
            y[j][i] = y[j+1][i-1] - y[j][i-1];
        }
void print_table(float y[][MAX] , int n ){
    for(int i = 0 ; i < n ; i++){
        printf("%f",y[i][0]);
        for(int j=1 ; j<n-i;j++){
            printf("\t%f",y[i][j]);
        }
        printf("\n");
    }
float NewtonForwardInter(float x[], float y[][MAX], int n, float value){
    float sum = y[0][0];
    float u = (value - x[0])/(x[1] - x[0]);
    float u_term = u;
    for(int i = 1 ; i < n ; i++){
        sum += (u_term * y[0][i]) / fact(i);
        u_term *= (u-i);
    }
    return sum;
}
int main(){
    int n;
    float x[MAX],y[MAX][MAX],value;
    printf("Enter no of values : ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++){
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("y[%d] = ",i);
        scanf("%f",&y[i][0]);
    }
    printf("Enter the value to interpolate : ");
    scanf("%f",&value);
    Forward_diff_table(x,y,n);
    print_table(y, n );
    float result = NewtonForwardInter(x, y, n, value);
    printf("Interpolated value at %lf = %lf\n",value , result);
    return 0;
}
