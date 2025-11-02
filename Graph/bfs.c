#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int src, int dest) {
    // Add src -> dest
    struct Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;

    // Add dest -> src (for undirected graph)
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = value;
    }
}

int dequeue() {
    int item;
    if (front == -1)
        return -1;
    item = queue[front++];
    if (front > rear) front = rear = -1;
    return item;
}

void BFS(int startVertex) {
    visited[startVertex] = 1;
    enqueue(startVertex);

    while (front != -1) {
        int currentVertex = dequeue();
        printf("%d ", currentVertex);

        struct Node* temp = adjList[currentVertex];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                enqueue(adjVertex);
            }
            temp = temp->next;
        }
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

    printf("BFS traversal starting from vertex 0:\n");
    BFS(0);

    return 0;
}
