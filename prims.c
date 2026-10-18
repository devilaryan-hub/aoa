#include <stdio.h>
#include <limits.h>
#define V 6

void primMST(int graph[V][V]) {
    int parent[V], key[V], mstSet[V] = {0}, total = 0;
    for (int i = 0; i < V; i++) key[i] = INT_MAX;
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < min) { min = key[v]; u = v; }
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u; key[v] = graph[u][v];
            }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
        total += graph[i][parent[i]];
    }
    printf("Total Cost = %d\n", total);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 0, 0, 4},
        {2, 0, 8, 0, 0, 3},
        {0, 8, 0, 6, 1, 0},
        {0, 0, 6, 0, 12, 0},
        {0, 0, 1, 12, 0, 2},
        {4, 3, 0, 0, 2, 0}
    };
    primMST(graph);
    return 0;
}
