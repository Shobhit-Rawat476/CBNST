#include <stdio.h>
#include <math.h>
int main() {

    double true_value, approx_value, absolute_error, relative_error, percentage_error;
    printf("Enter the true value (T): ");
    scanf("%lf", &true_value);
    printf("Enter the approximate value (A): ");
    scanf("%lf", &approx_value);
    // Absolute Error
    absolute_error = fabs(true_value - approx_value);
    // Relative Error
    relative_error = absolute_error / fabs(true_value);
    // Percentage Error
    percentage_error = relative_error * 100;
    printf("Absolute Error: %lf\n", absolute_error);
    printf("Relative Error: %lf\n", relative_error);
    printf("Percentage Error: %lf%%\n", percentage_error);
    return 0;
}
