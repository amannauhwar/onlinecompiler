#include <stdio.h> [cite: 1083]
#include <stdlib.h> [cite: 1084]

#define N 6 [cite: 1085]

int adj[N][N] = {0}, visited[N]; [cite: 1086]

void addEdge(int u, int v){ adj[u] [v]=1; adj[v][u] = 1; } [cite: 1087]

void bfs(int s){ [cite: 1088]
    int q[100], f=0,r=0; [cite: 1089]
    q[r++]=s; [cite: 1090]
    visited[s] = 1; [cite: 1090, 1092]
    
    while(f<r){ [cite: 1091]
        int u=q[f++]; [cite: 1093]
        printf("%d ",u); [cite: 1093]
        
        for(int v=0; v<N; v++) if(adj[u] [v] && !visited[v]) { visited[v]=1; q[r++]=v; } [cite: 1094]
    } [cite: 1095]
} [cite: 1096]

int main(){ [cite: 1097]
    addEdge(0,1); [cite: 1099]
    addEdge(0,2); [cite: 1099]
    addEdge (1,3); [cite: 1099]
    addEdge(2,4); [cite: 1099]
    addEdge(2,5); [cite: 1099]
    
    printf("BFS: "); bfs(0); printf("\n"); [cite: 1100]
    return 0; [cite: 1101]
} [cite: 1098]