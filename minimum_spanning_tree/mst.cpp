#include <stdio.h>
#include <limits.h>
#include <cstdio>
#include <cassert>

#define N_MAX 10001
int graph[N_MAX][N_MAX];

int N, M;
int a, b, c;

int minKey(int key[], bool mstSet[]){
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < N; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
 
    return min_index;
}

void printMST(int parent[]){
    int pesi = 0;
    for (int i = 1; i < N; i++)
      pesi += graph[i][parent[i]];
    printf("%d\n", pesi);

    for (int i = 1; i < N; i++)
      printf("%d %d\n", parent[i]+1, i+1);
}
 
// Function to construct and print MST for a graph represented using adjacency matrix representation
void primMST(){
    int parent[N];  // Array to store constructed MST
    int key[N];     // Key values used to pick minimum weight edge in cut
    bool mstSet[N]; // To represent set of vertices not yet included in MST
 
    // Initialize all keys as INFINITE
    for (int i = 0; i < N; i++){
        key[i] = INT_MAX;
        mstSet[i] = false;
    }
 
    // Always include first 1st vertex in MST.
    key[0]    = 0;  // Make key 0 so that this vertex is picked as first vertex
    parent[0] = -1; // First node is always root of MST 
 
    // The MST will have V vertices
    for (int count = 0; count < N - 1; count++){
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet);
   
        // Add the picked vertex to the MST Set
        mstSet[u] = true;
   
        // Update key value and parent index of the adjacent vertices of the picked vertex. Consider only those vertices which are not yet included in MST
        for (int v = 0; v < N; v++){
            // graph[u][v] is non zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] <  key[v]){
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}


int main() {
#ifdef  EVAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &N); // nodi
    scanf("%d", &M); // archi

    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &a, &b, &c);
        graph[a-1][b-1] = c;
        graph[b-1][a-1] = c;
    }

    primMST();
 
    return 0;
}