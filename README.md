# Design and Analysis of Algorithms (DAA) Lab Experiments

## List of Experiments

1. Sort a given set of elements using the Quick Sort method and determine the time required to sort the elements. Repeat the experiment for different values of `n`, the number of elements in the list to be sorted. The elements can be read from a file or generated using a random number generator.

2. Implement a Merge Sort algorithm to sort a given set of elements and determine the time required to sort the elements. Repeat the experiment for different values of `n`, the number of elements in the list to be sorted. The elements can be read from a file or generated using a random number generator.

3. Compute the transitive closure of a given directed graph using Warshall's algorithm.

4. Implement the 0/1 Knapsack problem using Dynamic Programming.

5. From a given vertex in a weighted connected graph, find the shortest paths to other vertices using Dijkstra's algorithm.

6. Find the Minimum Cost Spanning Tree of a given undirected graph using Kruskal's algorithm.

7. Print all the nodes reachable from a given starting node in a digraph using the BFS method.

8. Check whether a given graph is connected or not using the DFS method.

9. Find a subset of a given set `S = {s1, s2, ..., sn}` of positive integers whose sum is equal to a given positive integer `d`. For example, if `S = {1, 2, 5, 6, 8}` and `d = 9`, there are two solutions: `{1, 2, 6}` and `{1, 8}`. A suitable message is to be displayed if the given problem instance doesn't have a solution.

10. Implement any scheme to find the optimal solution for the Travelling Salesperson Problem and then solve the same problem instance using any approximation algorithm and determine the error in the approximation.

11. Find the Minimum Cost Spanning Tree of a given undirected graph using Prim's algorithm.

12. Implement the N-Queens problem using Backtracking.

---

# Experiment 1: Quick Sort

## Aim

To sort a given set of elements using the Quick Sort method and determine the time required to sort the elements for different values of `n`.

## Algorithm

1. Read the number of elements `n`.
2. Read `n` elements into an array.
3. Select a pivot element.
4. Partition the array around the pivot.
5. Recursively apply Quick Sort to the left and right subarrays.
6. Measure and display the execution time.

## C Program

```c
#include <stdio.h>
#include <time.h>

#define MAX 100000

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = low - 1;
    int j, temp;

    for (j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;

            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

    temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;

    return i + 1;
}

void quickSort(int a[], int low, int high) {
    if (low < high) {
        int p = partition(a, low, high);

        quickSort(a, low, p - 1);
        quickSort(a, p + 1, high);
    }
}

int main() {
    int a[MAX], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    quickSort(a, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime required: %f seconds\n", time_taken);

    return 0;
}
```

## Complexity

- Best Case: `O(n log n)`
- Average Case: `O(n log n)`
- Worst Case: `O(n²)`
- Space Complexity: `O(log n)` average recursion stack

---

# Experiment 2: Merge Sort

## Aim

To implement Merge Sort and determine the time required to sort elements for different values of `n`.

## Algorithm

1. Divide the array into two halves.
2. Recursively sort both halves.
3. Merge the two sorted halves.
4. Repeat until the complete array is sorted.
5. Measure the execution time.

## C Program

```c
#include <stdio.h>
#include <time.h>

#define MAX 100000

void merge(int a[], int low, int mid, int high) {
    int temp[MAX];
    int i = low;
    int j = mid + 1;
    int k = low;

    while (i <= mid && j <= high) {
        if (a[i] <= a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= mid)
        temp[k++] = a[i++];

    while (j <= high)
        temp[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = temp[i];
}

void mergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

int main() {
    int a[MAX], n, i;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    start = clock();

    mergeSort(a, 0, n - 1);

    end = clock();

    time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nSorted elements:\n");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\nTime required: %f seconds\n", time_taken);

    return 0;
}
```

## Complexity

- Best Case: `O(n log n)`
- Average Case: `O(n log n)`
- Worst Case: `O(n log n)`
- Space Complexity: `O(n)`

---

# Experiment 3: Warshall's Algorithm

## Aim

To compute the transitive closure of a directed graph using Warshall's algorithm.

## Algorithm

1. Read the adjacency matrix of the graph.
2. For each intermediate vertex `k`, consider all pairs `(i, j)`.
3. Update:
   `reach[i][j] = reach[i][j] OR (reach[i][k] AND reach[k][j])`
4. Print the transitive closure matrix.

## C Program

```c
#include <stdio.h>

#define MAX 20

int main() {
    int reach[MAX][MAX];
    int n, i, j, k;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &reach[i][j]);

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                reach[i][j] =
                    reach[i][j] || (reach[i][k] && reach[k][j]);
            }
        }
    }

    printf("\nTransitive Closure:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", reach[i][j]);

        printf("\n");
    }

    return 0;
}
```

## Complexity

- Time Complexity: `O(V³)`
- Space Complexity: `O(V²)`

---

# Experiment 4: 0/1 Knapsack Using Dynamic Programming

## Aim

To implement the 0/1 Knapsack problem using Dynamic Programming.

## Algorithm

1. Read the number of items.
2. Read the weight and profit of each item.
3. Read the capacity of the knapsack.
4. Construct a DP table.
5. For each item, choose either:
   - Include the item, or
   - Exclude the item.
6. The maximum value is stored in `dp[n][capacity]`.

## C Program

```c
#include <stdio.h>

#define MAX 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, capacity;
    int weight[MAX], profit[MAX];
    int dp[MAX + 1][MAX + 1];
    int i, w;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    printf("Enter profits:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &profit[i]);

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    printf("Maximum profit = %d\n", dp[n][capacity]);

    return 0;
}
```

## Complexity

- Time Complexity: `O(nW)`
- Space Complexity: `O(nW)`

---

# Experiment 5: Dijkstra's Algorithm

## Aim

To find the shortest paths from a given source vertex to all other vertices in a weighted connected graph.

## Algorithm

1. Initialize the distance of the source vertex to `0`.
2. Initialize all other distances to infinity.
3. Select the unvisited vertex with minimum distance.
4. Update distances of its adjacent vertices.
5. Repeat until all vertices are processed.

## C Program

```c
#include <stdio.h>

#define MAX 20
#define INF 99999

int main() {
    int cost[MAX][MAX];
    int distance[MAX], visited[MAX];
    int n, source;
    int i, j, count, u, min;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");
    printf("Enter %d for no direct edge.\n", INF);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    for (i = 0; i < n; i++) {
        distance[i] = cost[source][i];
        visited[i] = 0;
    }

    distance[source] = 0;
    visited[source] = 1;

    for (count = 1; count < n; count++) {
        min = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && distance[i] < min) {
                min = distance[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        for (j = 0; j < n; j++) {
            if (!visited[j] &&
                distance[u] + cost[u][j] < distance[j]) {
                distance[j] = distance[u] + cost[u][j];
            }
        }
    }

    printf("\nShortest distances:\n");

    for (i = 0; i < n; i++)
        printf("From %d to %d = %d\n", source, i, distance[i]);

    return 0;
}
```

## Complexity

- Time Complexity: `O(V²)`
- Space Complexity: `O(V²)`

---

# Experiment 6: Kruskal's Algorithm

## Aim

To find the Minimum Cost Spanning Tree of an undirected graph using Kruskal's algorithm.

## Algorithm

1. Read all edges and their weights.
2. Sort the edges in ascending order of weight.
3. Select the smallest edge.
4. Add it if it does not form a cycle.
5. Repeat until `V - 1` edges are selected.

## C Program

```c
#include <stdio.h>

#define MAX 100

struct Edge {
    int u, v, weight;
};

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int u, int v) {
    parent[u] = v;
}

int main() {
    struct Edge edges[MAX], temp;
    int n, e, i, j;
    int count = 0, cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (u v weight):\n");

    for (i = 0; i < e; i++)
        scanf("%d %d %d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].weight);

    for (i = 0; i < n; i++)
        parent[i] = i;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("\nEdges in MST:\n");

    for (i = 0; i < e && count < n - 1; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            printf("%d -- %d = %d\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].weight);

            cost += edges[i].weight;
            unionSet(u, v);
            count++;
        }
    }

    printf("Minimum Cost = %d\n", cost);

    return 0;
}
```

## Complexity

- Time Complexity: `O(E²)` with bubble sort in this implementation
- Standard optimized complexity: `O(E log E)`
- Space Complexity: `O(V + E)`

---

# Experiment 7: Breadth First Search (BFS)

## Aim

To print all nodes reachable from a given starting node in a directed graph using BFS.

## Algorithm

1. Read the adjacency matrix.
2. Select the starting vertex.
3. Insert the starting vertex into a queue.
4. Remove a vertex from the queue.
5. Visit all its unvisited adjacent vertices.
6. Repeat until the queue becomes empty.

## C Program

```c
#include <stdio.h>

#define MAX 20

int main() {
    int graph[MAX][MAX];
    int visited[MAX] = {0};
    int queue[MAX];
    int n, start;
    int front = 0, rear = 0;
    int i, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (v = 0; v < n; v++)
            scanf("%d", &graph[i][v]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("Reachable vertices: ");

    while (front < rear) {
        int current = queue[front++];

        printf("%d ", current);

        for (i = 0; i < n; i++) {
            if (graph[current][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}
```

## Complexity

- Time Complexity: `O(V²)` using adjacency matrix
- Space Complexity: `O(V)`

---

# Experiment 8: Connectivity Using DFS

## Aim

To check whether a given graph is connected using the DFS method.

## Algorithm

1. Read the adjacency matrix.
2. Start DFS from vertex `0`.
3. Mark every visited vertex.
4. After DFS completes, check whether all vertices are visited.
5. If all are visited, the graph is connected.

## C Program

```c
#include <stdio.h>

#define MAX 20

int graph[MAX][MAX];
int visited[MAX];
int n;

void DFS(int v) {
    int i;

    visited[v] = 1;

    for (i = 0; i < n; i++) {
        if (graph[v][i] && !visited[i])
            DFS(i);
    }
}

int main() {
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    DFS(0);

    for (i = 0; i < n; i++) {
        if (!visited[i]) {
            printf("Graph is not connected.\n");
            return 0;
        }
    }

    printf("Graph is connected.\n");

    return 0;
}
```

## Complexity

- Time Complexity: `O(V²)` using adjacency matrix
- Space Complexity: `O(V)`

---

# Experiment 9: Subset Sum Problem

## Aim

To find all subsets of a given set of positive integers whose sum is equal to a given positive integer `d`.

## Algorithm

1. Read the set of positive integers.
2. Read the target sum.
3. Use recursion to include or exclude each element.
4. When the current sum equals the target, print the subset.
5. Display a suitable message if no subset exists.

## C Program

```c
#include <stdio.h>

#define MAX 20

int a[MAX], x[MAX];
int n, target;
int found = 0;

void subsetSum(int index, int sum) {
    int i;

    if (sum == target) {
        found = 1;

        printf("{ ");

        for (i = 0; i < index; i++) {
            if (x[i])
                printf("%d ", a[i]);
        }

        printf("}\n");
        return;
    }

    if (index == n || sum > target)
        return;

    x[index] = 1;
    subsetSum(index + 1, sum + a[index]);

    x[index] = 0;
    subsetSum(index + 1, sum);
}

int main() {
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter positive integers:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    printf("\nSubsets with sum %d:\n", target);

    subsetSum(0, 0);

    if (!found)
        printf("No solution exists.\n");

    return 0;
}
```

## Complexity

- Time Complexity: `O(2^n)`
- Space Complexity: `O(n)`

---

# Experiment 10: Travelling Salesperson Problem

## Aim

To find an optimal solution for the Travelling Salesperson Problem using an exact method and compare it with an approximation method.

## Exact Method: Brute Force

```c
#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];
int bestCost = INT_MAX;

void tsp(int current, int count, int totalCost) {
    int i;

    if (count == n) {
        if (cost[current][0] != 0 &&
            totalCost + cost[current][0] < bestCost) {
            bestCost = totalCost + cost[current][0];
        }

        return;
    }

    for (i = 0; i < n; i++) {
        if (!visited[i] && cost[current][i] != 0) {
            visited[i] = 1;

            tsp(i,
                count + 1,
                totalCost + cost[current][i]);

            visited[i] = 0;
        }
    }
}

int main() {
    int i, j;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Optimal tour cost = %d\n", bestCost);

    return 0;
}
```

## Approximation Method: Nearest Neighbor

```c
#include <stdio.h>

#define MAX 10

int main() {
    int cost[MAX][MAX];
    int visited[MAX] = {0};
    int n, current = 0;
    int totalCost = 0;
    int i, next, min;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    for (i = 1; i < n; i++) {
        min = 99999;
        next = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                cost[current][j] < min &&
                cost[current][j] != 0) {
                min = cost[current][j];
                next = j;
            }
        }

        visited[next] = 1;
        totalCost += min;
        current = next;
    }

    totalCost += cost[current][0];

    printf("Approximate tour cost = %d\n", totalCost);

    return 0;
}
```

## Error Calculation

```text
Error = Approximate Cost - Optimal Cost
```

Percentage error:

```text
Percentage Error =
((Approximate Cost - Optimal Cost) / Optimal Cost) × 100
```

## Complexity

- Brute Force: `O(n!)`
- Nearest Neighbor: `O(n²)`

---

# Experiment 11: Prim's Algorithm

## Aim

To find the Minimum Cost Spanning Tree of an undirected graph using Prim's algorithm.

## Algorithm

1. Start from any vertex.
2. Select the minimum weight edge connecting the selected set to an unselected vertex.
3. Add that edge to the MST.
4. Repeat until `V - 1` edges are selected.

## C Program

```c
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
```

## Complexity

- Time Complexity: `O(V²)`
- Space Complexity: `O(V²)`

---

# Experiment 12: N-Queens Using Backtracking

## Aim

To implement the N-Queens problem using Backtracking.

## Algorithm

1. Place one queen in each row.
2. Check whether the selected position is safe.
3. If safe, place the queen.
4. Recursively place queens in the next row.
5. If no safe position exists, backtrack.
6. Print all valid solutions.

## C Program

```c
#include <stdio.h>

#define MAX 20

int board[MAX][MAX];
int n;

int isSafe(int row, int col) {
    int i, j;

    for (i = 0; i < row; i++)
        if (board[i][col])
            return 0;

    for (i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--)
        if (board[i][j])
            return 0;

    for (i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++)
        if (board[i][j])
            return 0;

    return 1;
}

void solve(int row) {
    int col, i, j;

    if (row == n) {
        printf("\nSolution:\n");

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                printf("%d ", board[i][j]);

            printf("\n");
        }

        return;
    }

    for (col = 0; col < n; col++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;

            solve(row + 1);

            board[row][col] = 0;
        }
    }
}

int main() {
    printf("Enter number of queens: ");
    scanf("%d", &n);

    solve(0);

    return 0;
}
```

## Complexity

- Time Complexity: Approximately `O(N!)`
- Space Complexity: `O(N²)`

---

# General Conclusion

All the above algorithms were implemented successfully in C. The experiments demonstrate different algorithm design techniques, including:

- Divide and Conquer
- Dynamic Programming
- Greedy Algorithms
- Graph Traversal
- Backtracking
- Approximation Algorithms

The execution time and efficiency of each algorithm depend on the input size and the algorithm's time complexity.
