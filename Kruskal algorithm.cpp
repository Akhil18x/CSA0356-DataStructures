#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Function to find the parent of a vertex using path compression
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
    struct Edge* edgeA = (struct Edge*)a;
    struct Edge* edgeB = (struct Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Function to construct the minimum signing tree using Kruskal's algorithm
void minSigningTree(struct Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compareEdges);

    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));
    for (int i = 0; i < V; ++i) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Minimum Signing Tree:\n");

    for (int i = 0; i < E; ++i) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int srcParent = find(subsets, src);
        int destParent = find(subsets, dest);

        if (srcParent != destParent) {
            printf("(%d,%d) ", src, dest);
            unionSets(subsets, srcParent, destParent);
        }
    }

    free(subsets);
}

int main() {
    int V = 4; // Number of vertices
    int E = 5; // Number of edges

    struct Edge edges[] = {
        {0, 1, 2},
        {0, 2, 4},
        {0, 3, 3},
        {1, 2, 1},
        {2, 3, 5}
    };

    minSigningTree(edges, V, E);

    return 0;
}
