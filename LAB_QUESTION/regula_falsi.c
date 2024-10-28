#include <stdio.h>
#include <math.h>
#define e 0.001

float f(float x) {
    return x*x*x - 4*x - 9;
}
int main() {
    int i = 0;
    float x0, x1, x2;
    float f0, f1, f2;
    printf("Enter the value of x0: ");
    scanf("%f", &x0);
    printf("Enter the value of x1: ");
    scanf("%f", &x1);
    if (f(x0) * f(x1) >= 0) {
        printf("Invalid initial guesses. f(x0) and f(x1) should have opposite signs.\n");
        return 1;
    }
    do {
        f0 = f(x0);
        f1 = f(x1);

        x2 = (x0 * f1 - x1 * f0) / (f1 - f0);
        f2 = f(x2);

        if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }
        i++;
        printf("Iteration %d: Root = %f, Function Value = %f\n", i, x2, f2);
    } while (fabs(f2) > e);
    printf("Approximate Root = %f\n", x2);
    return 0;
}
