#include <stdio.h>
#include <limits.h>

#define SIZE 10 //max number of vertices
//excuse the new commit about the prog_8 file on this commit history on this file, i am sorry about my mistake
//function to find the vertex with minimum distance
int minDistance(int dist[], int visited[], int n) {
    int min = INT_MAX; //from limits.h
    int min_index = -1;

    for (int i = 0; i < n; i++){
        if(!visited[i] && dist[i] < min){
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}

//dijsktras algorithm
void dijsktra(int graph[SIZE][SIZE], int n, int source){
    int dist[SIZE];
    int visited[SIZE];

    //initializing distance and visited array
    for (int i = 0; i <n; i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    //distance from source to itself is 0
    dist[source] = 0;

    //the main implementation
    for (int count = 0; count < n - 1; count++){
        int u = minDistance(dist, visited, n);
        visited[u] = 1;

        //update distances of adjacent variables
        for (int v = 0; v <n;v++){
            if(!visited[v] &&
            graph[u][v] != 0 &&
            dist[u] != INT_MAX &&
            dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\t Distance from source\n");
    for (int i = 0; i < n; i++){
        printf("%d \t\t %d\n", i, dist[i]);
    }
}


int main(){
    int n = 5;
    int graph[SIZE][SIZE] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}};

    int source = 0;

    dijsktra(graph, n, source);

    return 0;
}
