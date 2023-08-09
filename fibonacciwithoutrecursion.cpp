#include <stdio.h>

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    int first = 0, second = 1, next;

    printf("Fibonacci Series: ");
    printf("%d", first);  // Display the first term

    for (int i = 1; i < n; ++i) {
        printf(", %d", second);  // Display the current term

        next = first + second;
        first = second;
        second = next;
    }

    return 0;
}