#include <stdio.h>

int main() {
    int num;
    printf("Enter a number: ");
    if (scanf("%d", &num) != 1) {
        printf("Invalid input!\n");
        return 1;
    }

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        int factorial = 1;
        for (int i = 1; i <= num; ++i) {
            factorial *= i;
        }
        printf("Factorial of %d is %d\n", num, factorial);
    }

    return 0;
}