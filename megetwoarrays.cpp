#include <stdio.h>

int main() {
    int arr1[100], arr2[100], mergedArray[200];
    int size1, size2, mergedSize;

    printf("Enter the size of the first array: ");
    scanf("%d", &size1);

    printf("Enter elements of the first array:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    printf("Enter the size of the second array: ");
    scanf("%d", &size2);

    printf("Enter elements of the second array:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    mergedSize = size1 + size2;

    for (int i = 0; i < size1; i++) {
        mergedArray[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        mergedArray[size1 + i] = arr2[i];
    }

    printf("Merged array:\n");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", mergedArray[i]);
    }

    return 0;
}