#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("Enter the element to search for: ");
    scanf("%d", &target);

    int *address = NULL;
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            address = &arr[i];
            break;
        }
    }

    if (address != NULL) {
        int location = address - arr;
        printf("Element %d found at location %d with address %p\n", target, location, address);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    return 0;
}