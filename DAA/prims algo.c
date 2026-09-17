#include <stdio.h>

#define INF 999

int main()
{
    int n, cost[10][10], visited[10] = {0};
    int i, j, edges = 0, min, u = 0, v = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;   // Start from vertex 0

    printf("\nEdges in Minimum Spanning Tree:\n");

    while(edges < n - 1)
    {
        min = INF;

        for(i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);

        total += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", total);

    return 0;
}
