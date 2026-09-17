#include <stdio.h>

#define MAX 20
#define INF 99999

int main() {
    int cost[MAX][MAX];
    int selected[MAX] = {0};
    int n, i, j;
    int edges = 0;
    int min, x, y;
    int totalCost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    printf("Enter %d for no edge.\n", INF);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    selected[0] = 1;

    printf("\nEdges in MST:\n");

    while (edges < n - 1) {
        min = INF;
        x = y = -1;

        for (i = 0; i < n; i++) {
            if (selected[i]) {
                for (j = 0; j < n; j++) {
                    if (!selected[j] &&
                        cost[i][j] < min) {
                        min = cost[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (x == -1) {
            printf("Graph is not connected.\n");
            return 0;
        }

        printf("%d -- %d = %d\n", x, y, min);

        totalCost += min;
        selected[y] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", totalCost);

    return 0;
}