#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int adj[SIZE][SIZE]; //the adjacency matrix
int visited[SIZE]; //array to store the visited nodes
int queue[SIZE]; //queue for BFS
int front = 0, rear = -1;

//function to add edge
void addEdge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}


