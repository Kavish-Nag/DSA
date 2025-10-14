#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];
int graph[MAX][MAX];
int n;  // make n global and assign in main

void enqueue(int vertex)
{
    if (rear == MAX - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue()
{
    int vertex;
   
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
       
        if (front > rear) front = rear = -1;
    }
    return vertex;
}

void bfs(int start)
{
    enqueue(start);
    visited[start] = 1;
   
    while (front != -1) {
        int i;
        int current = dequeue();
        printf("%d ", current);
       
        for (i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main()
{
    int edges, src, dest, i;
   
    printf("Enter number of vertices - ");
    scanf("%d", &n);
   
    // Initialize graph and visited arrays to zero
    for (i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
   
    printf("Enter number of edges - ");
    scanf("%d", &edges);
   
    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest) - ");
        scanf("%d %d", &src, &dest);
        if (src >= 0 && src < n && dest >= 0 && dest < n) {
            graph[src][dest] = graph[dest][src] = 1;
        } else {
            printf("Invalid edge! Try again.\n");
            i--;  // retry this iteration
        }
    }
   
    printf("BFS starting from vertex 0:\n");
    bfs(0);
   
    return 0;
}