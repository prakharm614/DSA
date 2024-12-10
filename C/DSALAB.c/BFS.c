#include <stdio.h>
#include <stdlib.h>
#define N 5
int adj[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};
int visited[N];
 char vertices[5]={'A','B','C','D','E'};
void dfs(int v) {
    visited[v] = 1;
   // printf("%d ", v);
    printf("%c ", vertices[v]);

    for (int i = 0; i < N; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    };
}

int main() {
    for (int i = 0; i < N; ++i) {
        visited[i] = 0;
    }

    dfs(0);

    return 0;
}

