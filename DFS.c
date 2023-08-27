#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

void dfs(int adjMatrix[MAX_NODES][MAX_NODES], bool visited[MAX_NODES], int nodes, int currentNode) {
    printf("%d ", currentNode);
    visited[currentNode] = true;

    for (int i = 0; i < nodes; i++) {
        if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
            dfs(adjMatrix, visited, nodes, i);
        }
    }
}

int main() {
    int nodes, edges;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int adjMatrix[MAX_NODES][MAX_NODES] = {0};

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    bool visited[MAX_NODES] = {false};

    printf("DFS traversal: ");
    for (int i = 0; i < nodes; i++) {
        if (!visited[i]) {
            dfs(adjMatrix, visited, nodes, i);
        }
    }
    
    printf("\n");

    return 0;
}

