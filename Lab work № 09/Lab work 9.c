// Find the sum of n fractions represented as an irreducible fraction. 
// The fraction should be expressed as a structure with two fields: numerator and denominator. 
// Use functions for input, output, reducing the fraction, and finding the sum of the fractions.

#include <stdio.h>

typedef struct {
    int numerator;
    int denominator;
} Fraction;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

Fraction reduceFraction(Fraction fraction) {
    int commonDivisor = gcd(fraction.numerator, fraction.denominator);
    fraction.numerator /= commonDivisor;
    fraction.denominator /= commonDivisor;
    return fraction;
}

Fraction addFractions(Fraction fractions[], int n) {
    Fraction result;
    result.numerator = 0;
    result.denominator = 1;

    for (int i = 0; i < n; i++) {
        result.numerator = result.numerator * fractions[i].denominator + fractions[i].numerator * result.denominator;
        result.denominator *= fractions[i].denominator;
    }

    return reduceFraction(result);
}

void displayFraction(Fraction fraction) {
    printf("%d/%d\n", fraction.numerator, fraction.denominator);
}

int main() {
    int n;
    printf("Enter the number of fractions: \n ");
    scanf("%d", &n);

    Fraction fractions[n];

    printf("Enter the fractions:\n");
    for (int i = 0; i < n; i++) {
        printf("Fraction %d:\n", i + 1);
        printf("Numerator: ");
        scanf("%d", &fractions[i].numerator);
        printf("Denominator: ");
        scanf("%d", &fractions[i].denominator);
    }

    Fraction sum = addFractions(fractions, n);

    printf("Sum of the fractions: ");
    displayFraction(sum);

    return 0;
}
