#include <stdio.h>

// Function to calculate GCD (Greatest Common Divisor)
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
    int N;  // Number of test cases
    scanf("%d", &N);  // Input number of test cases

    // Arrays to store numerators and denominators for all test cases
    int num1[N], den1[N], num2[N], den2[N];

    // Input all test cases
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d %d", &num1[i], &den1[i], &num2[i], &den2[i]);
    }

    // Process and output all results
    for (int i = 0; i < N; i++) {
        // Adding fractions (num1/den1 + num2/den2)
        int num = num1[i] * den2[i] + num2[i] * den1[i];  // Numerator of the result
        int den = den1[i] * den2[i];  // Denominator of the result

        // Simplify the fraction
        int divisor = gcd(num, den);  // Get the GCD to simplify the fraction
        num /= divisor;
        den /= divisor;

        // Handle improper fraction (whole number part)
        int whole = num / den;
        num = num % den;

        // Output result in the proper format
        printf("Case #%d: ", i + 1);
        if (whole != 0) {
            printf("%d", whole);  // Print whole number part if exists
            if (num != 0) {
                printf(", %d/%d\n", num, den);  // Print fractional part
            } else {
                printf("\n");  // No fractional part
            }
        } else {
            printf("%d/%d\n", num, den);  // Only print fraction if no whole number
        }
    }

    return 0;
}
