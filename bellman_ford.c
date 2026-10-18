#include <stdio.h>
#define INF 999
#define V 5
#define E 6

struct Edge { int src, dest, wt; };

void bellmanFord(struct Edge edges[], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[src] = 0;

    for (int i = 1; i < V; i++)
        for (int j = 0; j < E; j++) {
            int u = edges[j].src, v = edges[j].dest, wt = edges[j].wt;
            if (dist[u] != INF && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }

    for (int i = 0; i < V; i++)
        printf("Vertex %d: %d\n", i, dist[i]);
}

int main() {
    struct Edge edges[E] = {
        {0, 1, 2}, {0, 2, 4}, {1, 2, -4}, {1, 4, -1}, {2, 3, 2}, {4, 3, -3}
    };
    bellmanFord(edges, 0);
    return 0;
}
