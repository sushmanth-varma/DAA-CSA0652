#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n, int i) {
    if (n <= 1) {
    	return false;
    }
    if (i == n) {
    	return true;
    }
    if (n % i == 0) {
    	return false;
    }
    return isPrime(n, i + 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    bool prime = isPrime(num, 2);
    if (prime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}
