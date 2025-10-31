#include <stdio.h>
#include <stdbool.h>

// Define constants for maximum vertices and infinity
#define MAX 10
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX];
    int i, count, v, nextNode, minDist;

    // Initialize distances and visited arrays
    for (i = 0; i < n; i++) {
        dist[i] = INF;        // Set initial distances to infinity
        visited[i] = false;       // Mark all nodes as unvisited
    }
    dist[start] = 0;          // Distance from start to itself is 0

    // Main algorithm loop - runs n-1 times
    for (count = 0; count < n - 1; count++) {
        minDist = INF;
        // Find the unvisited vertex with the minimum known distance
        for (v = 0; v < n; v++) {
            if (!visited[v] && dist[v] < minDist) {
                minDist = dist[v];
                nextNode = v;
            }
        }
        // If no reachable unvisited vertex remains, break early
        if (minDist == INF) {
            break;
        }

        // Mark the selected vertex as visited
        visited[nextNode] = true;

        // Relaxation step, update distances to adjacent unvisited vertices
        // If path of nextNode has a shorter route, update distance
        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[nextNode][v] != INF &&
                dist[nextNode] + graph[nextNode][v] < dist[v]) {
                dist[v] = dist[nextNode] + graph[nextNode][v];
            }
        }
    }

    // Display results
    printf("\nVertex\tDistance from Source\n");
    for (i = 0; i < n; i++) {
        // If a vertex is unreachable from the source, distance[i] will remain INF
        if (dist[i] == INF) {
            printf("%d\t\tINF\n", i);
        } else {
            printf("%d\t\t%d\n", i, dist[i]);
        }
    }
}

int main() {
    int graph[MAX][MAX], n, i, j, start, edges, src, dest, weight;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize graph adjacency matrix with INF (no direct edges)
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Read each edge and populate the adjacency matrix
    for (i = 0; i < edges; i++) {
        printf("Enter edge (src dest weight): ");
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight; // For undirected graphs
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &start);

    // Run from the chosen start vertex
    dijkstra(graph, n, start);
    return 0;
}