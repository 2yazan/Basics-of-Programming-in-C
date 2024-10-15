// Find the first n natural numbers that are equal to the sum of the factorials 
// of their digits. For example, 145 = 1! + 4! + 5!.

#include <stdio.h>

int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

void find_numbers(int n){
    int sum, num, digit, fact;
    for (int i = 1; i <= n; i++) {
        num = i;
        sum = 0;
        while (num > 0) {
            digit = num % 10;
            fact = factorial(digit);
            sum += fact;
            num /= 10;
        }
        if (sum == i) {
            printf("%d\n", i);
        }
    }
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    printf("%d natural numbers that are equal to the sum of their digit factorials:\n", n);
    find_numbers(n);
    return 0;
}
