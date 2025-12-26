#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;
int front = 1, rear = 1;

void bfs(int start) {
    int i, v;

    queue[rear] = start;
    rear = rear + 1;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (front < rear) {
        v = queue[front];
        front = front + 1;
        printf("%d ", v);

        for (i = 1; i <= n; i = i + 1) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear] = i;
                rear = rear + 1;
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i = i + 1)
        for (j = 1; j <= n; j = j + 1)
            scanf("%d", &adj[i][j]);

    for (i = 1; i <= n; i = i + 1)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    bfs(start);

    return 0;
}
