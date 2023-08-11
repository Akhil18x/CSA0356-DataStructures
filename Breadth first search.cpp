#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int node) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = node;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        int node = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return node;
    }
}

void bfs(int start, int n) {
    enqueue(start);
    visited[start] = 1;

    while (front != -1) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int n, start;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Breadth First Traversal starting from node %d: ", start);
    bfs(start, n);
    
    return 0;
}
