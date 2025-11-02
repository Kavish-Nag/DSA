#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[100];
int visited[100];
int n;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    // Add edge src -> dest
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add edge dest -> src (for undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void DFS(int v) {
    struct Node* temp = adjList[v];
    visited[v] = 1;
    printf("%d ", v);

    while (temp != NULL) {
        int connectedVertex = temp->vertex;
        if (!visited[connectedVertex]) {
            DFS(connectedVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        addEdge(src, dest);
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);

    return 0;
}
