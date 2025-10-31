#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX], top = -1;
int visited[MAX];
int graph[MAX][MAX];
int n;

// Function to push an element onto the stack
void push(int vertex) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = vertex;
    }
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}

// Depth First Search (DFS) function
void dfs(int start) {
    push(start);
    visited[start] = 1;

    printf("DFS Path: ");

    while (top != -1) {
        int i;
        int current = pop();
        printf("%d ", current);

        // Gather all unvisited adjacent vertices
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                push(i);          // Push unvisited adjacent vertex
                visited[i] = 1;   // Mark as visited
            }
        }
    }
}

// Main function
int main() {
    int edges, src, dest, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize graph and visited arrays
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    // Input edges
    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);
        graph[src][dest] = graph[dest][src] = 1;
    }

    printf("\nDFS starting from vertex 0:\n");
    dfs(0);

    return 0;
}

