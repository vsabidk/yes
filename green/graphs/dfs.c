#include <stdio.h>

#define MAX 20

int adj[MAX][MAX];
int visited[MAX];
int n;

void dfs(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 1; i <= n; i = i + 1) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int i, j, flag = 1;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i = i + 1)
        for (j = 1; j <= n; j = j + 1)
            scanf("%d", &adj[i][j]);

    for (i = 1; i <= n; i = i + 1)
        visited[i] = 0;

    printf("DFS Traversal: ");
    dfs(1);
    printf("\n");

    for (i = 1; i <= n; i = i + 1) {
        if (visited[i] == 0) {
            flag = 0;
            break;
          //  dfs(i);
        }
    }

    if (flag == 1)
        printf("The graph is connected\n");
    else
        printf("The graph is not connected\n");

    return 0;
}