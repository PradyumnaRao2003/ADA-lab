#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
    }
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    } else {
        int value = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return value;
    }
}

bool isEmpty() {
    return front == -1;
}

void bfs(int adjMatrix[MAX_NODES][MAX_NODES], int nodes, int startNode) {
    bool visited[MAX_NODES] = {false};

    enqueue(startNode);
    visited[startNode] = true;

    while (!isEmpty()) {
        int currentNode = dequeue();
        printf("%d ", currentNode);

        for (int i = 0; i < nodes; i++) {
            if (adjMatrix[currentNode][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = true;
            }
        }
    }
    printf("\n");
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

    int startNode;
    printf("Enter the starting node: ");
    scanf("%d", &startNode);

    printf("BFS traversal starting from node %d: ", startNode);
    bfs(adjMatrix, nodes, startNode);

    return 0;
}
