#include <stdio.h>
#include <stdlib.h>

#define N 5

char vertices[N] = {'A', 'B', 'C', 'D', 'E'};
int adj[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
};

int visited[N];

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%c ", vertices[vertex]);

    for (int neighbor = 0; neighbor < N; ++neighbor) {
        if (adj[vertex][neighbor] == 1 && visited[neighbor] == 0) {
            dfs(neighbor);
        }
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        visited[i] = 0;
    }

    dfs(0);

    return 0;
}
/*#include <stdio.h>
#include <stdlib.h>

#define N 5

int adj[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 0},
    {1, 1, 0, 1, 1},
    {0, 1, 1, 0, 1},
    {0, 0, 1, 1, 0}
};

int visited[N];

void dfs(int vertex) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int neighbor = 0; neighbor < N; ++neighbor) {
        if (adj[vertex][neighbor] == 1 && visited[neighbor] == 0) {
            dfs(neighbor);
        }
    }
}

int main() {
    for (int i = 0; i < N; ++i) {
        visited[i] = 0;
    }

    dfs(0);

    return 0;
}
*/