#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

int findMinimumDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min)
            min = dist[v], minIndex = v;

    return minIndex;
}

void printShortestPath(int parent[], int j) {
    if (parent[j] == -1)
        return;

    printShortestPath(parent, parent[j]);
    printf(" %d", j);
}

void printResult(int dist[], int parent[]) {
    int src = 0;
    printf("Vertex\t Distance from Source\t Shortest Path\n");

    for (int i = 0; i < V; i++) {
        printf("%d -> %d \t\t %d\t\t%d", src, i, dist[i], src);
        printShortestPath(parent, i);
        printf("\n");
    }
}

void dijkstraAlgorithm(int graph[V][V], int src) {
    int dist[V], parent[V];
    bool sptSet[V];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = findMinimumDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }

    printResult(dist, parent);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 0, 0, 5},
        {2, 0, 4, 1, 0, 0},
        {0, 4, 0, 7, 0, 0},
        {0, 1, 7, 0, 3, 0},
        {0, 0, 0, 3, 0, 2},
        {5, 0, 0, 0, 2, 0}
    };

    dijkstraAlgorithm(graph, 0);

    return 0;
}
