#include <stdio.h>

int ne = 1, min_cost = 0;

int main() {
    int n, i, j, min, a, u, b, v, cost[20][20], parent[20];

    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the cost matrix:\n");

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = 999; // Replace zero with a large value
            }
        }
    }

    for (i = 1; i <= n; i++) {
        parent[i] = 0;
    }

    printf("\nThe edges of the spanning tree are:\n");

    while (ne < n) {
        min = 999;
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                if (cost[i][j] < min) {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }

        while (parent[u]) {
            u = parent[u];
        }
        while (parent[v]) {
            v = parent[v];
        }

        if (u != v) {
            printf("Edge %d\t(%d->%d) = %d\n", ne++, a, b, min);
            min_cost += min;
            parent[v] = u;
        }

        cost[a][b] = cost[b][a] = 999; // Mark the edge as used
    }

    printf("\nMinimum cost = %d\n", min_cost);

    return 0;
}
