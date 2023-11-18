#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Breadth-First Search traversal
void bfs(int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;

    queue[rear++] = start;
    visited[start] = true;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < numVertices; ++i) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = true;
            }
        }
    }
}
