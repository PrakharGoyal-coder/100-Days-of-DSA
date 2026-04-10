/*Problem: Given weighted graph with non-negative edges, compute shortest path from 
source using priority queue.*/
#include <stdio.h>
#include <limits.h>

#define MAX 10

int main() {
    int n, src;
    int graph[MAX][MAX];
    int dist[MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter weighted adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &src);

    // Step 1: Initialize distances
    for (int i = 0; i < n; i++) 
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    // Step 2: Dijkstra main loop
    for (int count = 0; count < n - 1; count++) {

        // Find minimum distance unvisited node
        int min = INT_MAX, u;

        for (int i = 0; i < n; i++) 
        {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        // Update neighbors
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Step 3: Print result
    printf("\nVertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}