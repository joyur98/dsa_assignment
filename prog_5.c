#include <stdio.h>
#include <stdlib.h>

#define SIZE 10 //size of the matrix

int adj[SIZE][SIZE]; //the adjacency matrix
int visited[SIZE]; //array to store the visited nodes
int queue[SIZE]; //queue for BFS
int front = 0, rear = -1;

//function to add edge
void addEdge(int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

//BFS function
void BFS(int start, int n){
    for (int i = 0; i < n;i++){
        visited[i] = 0; //we first mark all the nodes as not visited
    }

    front = 0;
    rear = -1;

    queue[++rear] = start; //insert the start node into queue
    visited[start] = 1; // mark the start node as visited

    printf("BFS Traversal: ");

    while(front <= rear){ //while queue is not empty
        int node = queue[front++];
        printf("%d", node);

        for (int j = 0; j < n; j++){
            if(adj[node][j] == 1 && visited[j] == 0){ //checks if there is an edge and not visited
                queue[++rear] = j; //adds the neighbors to the queue
                visited[j] = 1; //marking as visited so it wont add it twice
            }
        }
    }
    printf("\n");
}

//DFS function
void DFS(int start, int n){
    printf("%d", start);
    visited[start] = 1;

    for (int j = 0; j < n ; j++){
        if(adj[start][j] == 1 && visited[j] == 0){
            DSF(j, n);
        }
    }
}


//DFS driver which starts the DFS function
void DFS_Start(int start, int n){
    for (int i = 0; i < n;i++){
        visited[i] = 0; //marking the nodes as unvisited
    }

    print("DFS Traversal: ");
    DFS(start,n);
    printf("\n");
}
