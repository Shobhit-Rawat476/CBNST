#include <stdio.h>
void gauss_elimination(float a[10][10], float x[], int n) {
    int i, j, k;
    float ratio;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k < n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
    x[n - 1] = a[n - 1][n] / a[n - 1][n - 1];
    for (i = n - 2; i >= 0; i--) {
        x[i] = a[i][n];
        for (j = i + 1; j < n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
}

int main() {
==
    int i, j, n;
    float a[10][10], x[10];

    printf("Enter the number of equations: ");
    scanf("%d", &n);

    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);
        }
    }
    gauss_elimination(a, x, n);
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, x[i]);
    }

    return 0;
}
