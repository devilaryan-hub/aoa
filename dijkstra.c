#include <stdio.h>
#define INF 999
#define V 5

void dijkstra(int cost[V][V], int src) {
    int dist[V], visited[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = cost[src][i];
    dist[src] = 0; visited[src] = 1;

    for (int count = 1; count < V; count++) {
        int min = INF, u = -1;
        for (int i = 0; i < V; i++)
            if (!visited[i] && dist[i] < min) { min = dist[i]; u = i; }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[u] + cost[u][v] < dist[v])
                dist[v] = dist[u] + cost[u][v];
    }
    for (int i = 0; i < V; i++) printf("%d -> %d = %d\n", src, i, dist[i]);
}

int main() {
    int cost[V][V] = {
        {0, 10, INF, 30, 100},
        {10, 0, 50, INF, INF},
        {INF, 50, 0, 20, 10},
        {30, INF, 20, 0, 60},
        {100, INF, 10, 60, 0}
    };
    dijkstra(cost, 0);
    return 0;
}
