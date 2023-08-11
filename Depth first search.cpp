#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Adjacency list representation of the graph
struct Graph {
    int V; // Number of vertices
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
};

// Initialize the graph
void initGraph(struct Graph *graph, int vertices) {
    graph->V = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adj[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adj[src][dest] = 1;
    graph->adj[dest][src] = 1; // For undirected graphs
}

// Depth-First Search traversal
void DFS(struct Graph *graph, int vertex, bool visited[]) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < graph->V; i++) {
        if (graph->adj[vertex][i] && !visited[i]) {
            DFS(graph, i, visited);
        }
    }
}

int main() {
    struct Graph graph;
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);

    initGraph(&graph, vertices);

    printf("Enter the edges (src dest):\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest);
    }

    bool visited[MAX_VERTICES] = {false};
    
    printf("DFS traversal starting from vertex 0:\n");
    DFS(&graph, 0, visited);

    return 0;

