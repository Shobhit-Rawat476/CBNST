#include <stdio.h>
#include <math.h>
#define e 0.001

float f(float x) {
   return x*x*x - 4*x - 9;
}

int main() {
    float x0, x1, x2;
    float f0, f1, f2;
    int i = 0;
    printf("Enter the values of x0 and x1: ");
    scanf("%f %f", &x0, &x1);
    if (f(x0) * f(x1) > 0) {
        printf("Invalid initial guesses. f(x0) and f(x1) should have opposite signs.\n");
        return 1; // Exit if the initial guesses are incorrect
    }
    do {
        f0 = f(x0);
        f1 = f(x1);
        x2 = (x0 + x1) / 2;
        f2 = f(x2);
        if (f0 * f2 < 0) {
            x1 = x2;
        } else {
            x0 = x2;
        }
        i++;
        printf("Iteration %d: Root = %f, Function Value = %f\n", i, x2, f2);
    } while (fabs(f2) > e);
    printf("Approximate Root = %f\n", x2);
    return 0;
}
