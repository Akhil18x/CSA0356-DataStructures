#include <stdio.h>

void findFrequentNumbers(int arr[], int size) {
    int maxCount = 0;
    int frequentNum = 0;

    for (int i = 0; i < size; i++) {
        int count = 1;
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            frequentNum = arr[i];
        }
    }

    if (maxCount > 1) {
        printf("The most frequent number is %d, which appears %d times.\n", frequentNum, maxCount);
    } else {
        printf("No frequent numbers found.\n");
    }
}

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    findFrequentNumbers(arr, size);

    return 0;
}