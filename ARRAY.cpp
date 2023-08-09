 #include<stdio.h>
 #define MAX_SIZE 100

// Function to insert an element at a specified position
int insertElement(int arr[], int size, int pos, int value) {
    if (size >= MAX_SIZE || pos < 0 || pos > size)
        return -1;

    for (int i = size; i > pos; i--)
        arr[i] = arr[i - 1];

    arr[pos] = value;

    return size + 1;
}

// Function to delete an element from a specified position
int deleteElement(int arr[], int size, int pos) {
    if (size <= 0 || pos < 0 || pos >= size)
        return -1;

    for (int i = pos; i < size - 1; i++)
        arr[i] = arr[i + 1];

    return size - 1;
}

// Function to search for an element in the array
int searchElement(int arr[], int size, int value) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == value)
            return i;
    }

    return -1;
}

int main() {
    int arr[MAX_SIZE];
    int size = 0;

    // Insertion
    size = insertElement(arr, size, 0, 5);
    size = insertElement(arr, size, 1, 10);
    size = insertElement(arr, size, 1, 7);

    // Display array after insertion
    printf("Array after insertion: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Deletion
    size = deleteElement(arr, size, 1);

    // Display array after deletion
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Searching
    int searchValue = 5;
    int searchIndex = searchElement(arr, size, searchValue);

    if (searchIndex != -1)
        printf("%d found at index %d\n", searchValue, searchIndex);
    else
        printf("%d not found in the array\n", searchValue);

    return 0;
}
