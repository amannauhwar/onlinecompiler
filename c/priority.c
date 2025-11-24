#include <stdio.h> [cite: 998]
#include <stdlib.h> [cite: 999]

int heap[100], hsize = 0; [cite: 1000]

void push(int x){ [cite: 1001]
    int i = ++hsize; [cite: 1003]
    heap[i] = x; [cite: 1004]
    
    // Upward heapify
    while( i>1 && heap[i/2] < heap[i]) { int t=heap[i/2]; heap[i/2]=heap[i]; heap[i]=t; i/=2; } [cite: 1005]
} [cite: 1002]

int pop(){ [cite: 1006]
    if(hsize==0) return -1; [cite: 1006]
    
    int ret=heap[1]; [cite: 1007]
    heap[1]=heap[hsize--]; [cite: 1007]
    
    // Downward heapify
    int i=1; [cite: 1008]
    while(1){ [cite: 1009]
        int l=2*i, r=2*i+1, m=i; [cite: 1012]
        if(l <= hsize && heap[l]>heap[m]) m=l; [cite: 1013]
        if(r <= hsize && heap[r]>heap[m]) m=r; [cite: 1014]
        
        if(m==i) break; [cite: 1015]
        
        int t=heap[i]; heap[i]=heap[m]; heap[m] = t; i=m; [cite: 1016]
    } [cite: 1010, 1011]
    return ret; [cite: 1017]
} [cite: 1006]

int main(){ [cite: 1018]
    push(10); [cite: 1019]
    push(30); [cite: 1019]
    push(20); [cite: 1019]
    push(40); [cite: 1019]
    
    printf("Pop: %d\n", pop()); [cite: 1020]
    printf("Pop: %d\n", pop()); [cite: 1020]
    return 0; [cite: 1021]
} [cite: 1022]