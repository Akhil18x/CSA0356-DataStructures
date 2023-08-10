#include <stdio.h>

#define SIZE 10

// Hash function
int hash(int key) {
    return key % SIZE;
}

// Insert element into hash table using linear probing
void insert(int hashTable[], int key) {
    int index = hash(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % SIZE;
    }
    hashTable[index] = key;
}

// Display the hash table
void display(int hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        }
    }
}

int main() {
    int hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = -1;  // Initialize hash table with -1 (empty)
    }

    int elements[] = {34, 7, 23, 12, 45, 56, 78, 98, 32, 11};
    int numElements = sizeof(elements) / sizeof(elements[0]);

    for (int i = 0; i < numElements; i++) {
        insert(hashTable, elements[i]);
    }

    display(hashTable);

    return 0;
}
