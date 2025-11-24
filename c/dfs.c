#include <stdio.h> [cite: 1066]
#include <stdlib.h> [cite: 1067]

#define N 6 [cite: 1068]

int adj[N][N] = {0}; [cite: 1069]
int visited[N]; [cite: 1069]

void addEdge(int u,int v){ adj[u] [v] = 1; adj[v][u] = 1; } [cite: 1070]

void dfs(int u){ [cite: 1071]
    visited[u] = 1; [cite: 1073]
    printf("%d ", u); [cite: 1073]
    for(int v=0; v<N; v++) if(adj[u] [v] && !visited[v]) dfs(v); [cite: 1074]
} [cite: 1072]

int main(){ [cite: 1075]
    addEdge(0,1); [cite: 1076]
    addEdge(0,2); [cite: 1076]
    addEdge(1,3); [cite: 1076]
    addEdge (2,4); [cite: 1076]
    addEdge(2,5); [cite: 1076]
    
    printf("DFS: "); dfs(0); printf("\n"); [cite: 1077]
    return 0; [cite: 1078]
} [cite: 1079]