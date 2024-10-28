#include <stdio.h>
void gauss_jordan(float a[10][10], int n) {
    int i, j, k;
    float ratio;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i != j) {
                ratio = a[j][i] / a[i][i];
                for (k = 0; k < n + 1; k++) {
                    a[j][k] = a[j][k] - ratio * a[i][k];
                }     }   }    }
    for (i = 0; i < n; i++) {
        a[i][n] = a[i][n] / a[i][i];
        a[i][i] = 1;   }    }
int main() {

    int i, j, n;
    float a[10][10];
    printf("Enter the number of equations: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n + 1; j++) {
            scanf("%f", &a[i][j]);        }     }
    gauss_jordan(a, n);
    printf("The solution is:\n");
    for (i = 0; i < n; i++) {
        printf("x%d = %f\n", i + 1, a[i][n]);    }
    return 0; }
