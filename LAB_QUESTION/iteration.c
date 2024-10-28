#include<stdio.h>
#include<math.h>
float g(float x) {
    return pow(2*x*x+4,1.0/3.0);
}
int main() {
    float x0, tol;
    int maxIter, iter = 0;
    printf("Enter initial guess: ");
    scanf("%f", &x0);
    printf("Enter tolerance: ");
    scanf("%f", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxIter);
    float x1;
    do {
        x1 = g(x0);
        iter++;
        if (fabs(x1 - x0) < tol) {  // Check if the result is within tolerance
            printf("\nThe root is: %f after %d iterations\n", x1, iter);
            return 0;
        }
        x0 = x1;
    } while (iter < maxIter);
    printf("\nThe method did not converge after %d iterations.\n", maxIter);
    return 0;
}
