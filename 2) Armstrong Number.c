#include <stdio.h>
#include <math.h>
int powerSum(int n, int digits) {
    if (n == 0) {
        return 0;
    }
    int digit = n % 10;
    return pow(digit, digits) + powerSum(n / 10, digits);
}
int countDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return 1 + countDigits(n / 10);
}
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    int digits = countDigits(num);
    int sum = powerSum(num, digits);
    if (num == sum) {
        printf("%d is an Armstrong number.\n", num);
    } else {
        printf("%d is not an Armstrong number.\n", num);
    }
    return 0;
}
