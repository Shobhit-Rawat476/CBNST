#include<stdio.h>
#define MAX 10
// Function to calculate factorial of a number
int fact(int n) {
    int factorial = 1;
    for(int i = 2; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}
// Function to calculate backward difference table
void Backward_diff_table(float y[][MAX], int n) {
    for(int i = 1; i < n; i++) {  // i denotes the order of difference
        for(int j = n - 1; j >= i; j--) {  // Calculate differences from the bottom
            y[j][i] = y[j][i - 1] - y[j - 1][i - 1];  // Backward differences
        }
    }
}
// Function to apply Newton's Backward Interpolation formula
float NewtonBackwardInter(float x[], float y[][MAX], int n, float value) {
    float sum = y[n - 1][0];  // Starting with the last y value
    float u = (value - x[n - 1]) / (x[1] - x[0]);  // Calculate u
    float u_term = u;  // First term in the u-expression

    // Loop to calculate the rest of the terms in the interpolation formula
    for(int i = 1; i < n; i++) {
        sum += (u_term * y[n - 1][i]) / fact(i);  // Add next term
        u_term *= (u + i);  // Update u-term as u(u+1)(u+2)...
    }

    return sum;
}

int main() {
    int n;
    float x[MAX], y[MAX][MAX], value;

    // Input number of values
    printf("Enter no of values: ");
    scanf("%d", &n);

    // Input x and y values
    for(int i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%f", &x[i]);
        printf("y[%d] = ", i);
        scanf("%f", &y[i][0]);
    }

    // Input the value to interpolate
    printf("Enter the value to interpolate: ");

AGRIM_CHAUHAN  /  2218245  /  5   /  E2
    scanf("%f", &value);

    // Compute backward difference table
    Backward_diff_table(y, n);

    // Print table headers
    printf("\nBackward Difference Table:\n");
    printf("x\t\t y\t\t ∆y\t\t ∆²y\t\t ∆³y\n");
    printf("------------------------------------------------------------\n");

    // Print the backward difference table
    for (int i = 0; i < n; i++) {
        printf("%f\t", x[i]);   // Print x values
        for (int j = 0; j <= i; j++) {
            printf("%f\t", y[i][j]);   // Print corresponding backward differences
        }
        printf("\n");
    }

    // Perform interpolation
    float result = NewtonBackwardInter(x, y, n, value);
    printf("\nInterpolated value at %f = %f\n", value, result);

    return 0;
}
