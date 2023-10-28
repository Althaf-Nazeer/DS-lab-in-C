#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool visited[MAX_VERTICES];
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Depth-First Search traversal
void dfs(int vertex) {
    visited[vertex] = true;
    printf("%d ", vertex);

    for (int i = 0; i < numVertices; ++i) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i);
        }
    }
}
