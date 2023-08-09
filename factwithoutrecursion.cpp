#include <stdio.h>

int main() {
    int num, factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else if (num == 0 || num == 1) {
        printf("Factorial of %d is 1\n", num);
    } else {
        for (int i = 2; i <= num; i++) {
            factorial *= i;
        }
        printf("Factorial of %d is %d\n", num, factorial);
    }

    return 0;
}
