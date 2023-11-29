#include <stdio.h>

#define V 4
#define INF 99999

void printSolution(int dist[][V], int pred[][V]);
void printPath(int start, int end, int pred[][V]);
void floydWarshall(int dist[][V]);

void floydWarshall(int dist[][V]) {
    int i, j, k;
    int pred[V][V]; //matrix to store predecessors

    //initialize predecessor matrix
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            pred[i][j] = -1; // case of no predecessor
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pred[i][j] = k; 
                }
            }
        }
    }

    //check for negative cycles
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            printf("Graph has a negative cycle.\n");
            return;
        }
    }

    //print the shortest distance matrix and paths
    printSolution(dist, pred);
}

/* A utility function to print solution */
void printSolution(int dist[][V], int pred[][V]) {
    //print distance matrix
    printf("Shortest distances:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == INF)
                printf("%7s", "INF");
            else
                printf("%7d", dist[i][j]);
        }
        printf("\n");
    }

    //print paths
    printf("\nPaths:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i != j && dist[i][j] != INF) {
                printf("Shortest path from %d to %d: %d", i, j, i);
                printPath(i, j, pred);
                printf(" %d\n", j);
            }
        }
    }
}

void printPath(int start, int end, int pred[][V]) {
    if (pred[start][end] == -1)
        return;
    
    printPath(start, pred[start][end], pred);
    printf(" %d", pred[start][end]);
}

int main() {
    int graph[V][V] = { {0, 5, INF, 10},
                        {INF, 0, 3, INF},
                        {INF, INF, 0, 1},
                        {INF, INF, INF, 0} };

    floydWarshall(graph);

    return 0;
}

//auxilary space required will be O(n^2) where n is the number of vertices in the graph


