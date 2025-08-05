#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    int from;
    int to;
    float weight;
} Edge;

float prims(int n, float graph[][n]) {
    bool visited[n];
    float mst = 0;
    int edges = 0;

    Edge mstEdges[n - 1]; // Store MST edges

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[0] = true;

    while (edges < n - 1) {
        float min = 99999;
        int u = -1, v = -1;

        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && graph[i][j] != 0 && graph[i][j] < min) {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if (u != -1 && v != -1) {
            mst += min;
            visited[v] = true;
            mstEdges[edges].from = u;
            mstEdges[edges].to = v;
            mstEdges[edges].weight = min;
            edges++;
        }
    }

    // Print MST path
    printf("\nEdges in the MST:\n");
    for (int i = 0; i < n - 1; i++) {
        printf("Freckle %d Freckle %d : Distance = %.2f\n",
               mstEdges[i].from + 1, mstEdges[i].to + 1, mstEdges[i].weight);
    }

    return mst;
}

int main() {
    int nodes;
    printf("Enter number of Freckles: ");
    scanf("%d", &nodes);

    int locations[nodes][2];
    for (int i = 0; i < nodes; i++) {
        printf("Enter coordinates of freckle %d: ", i + 1);
        scanf("%d %d", &locations[i][0], &locations[i][1]);
    }

    float distance[nodes][nodes];
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            distance[i][j] = sqrt(pow(locations[i][0] - locations[j][0], 2) +
                                  pow(locations[i][1] - locations[j][1], 2));
        }
    }

    printf("\nDistance Matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            printf("%6.2f ", distance[i][j]);
        }
        printf("\n");
    }

    printf("\nMinimum spanning distance is: %.2f\n", prims(nodes, distance));

    return 0;
}


