#include <stdio.h> [cite: 1164]

int mycmp(char *a, char *b){ [cite: 1165]
    int i=0; [cite: 1165]
    
    while(a[i] && b[i]){ [cite: 1167]
        if(a[i] != b[i]) return (a[i]<b[i]) ? -1: 1; [cite: 1169]
        i++; [cite: 1170]
    } [cite: 1168]
    
    if(a[i]==0 && b[i]==0) return 0; [cite: 1171]
    return (a[i] == 0) ? -1 : 1; [cite: 1172]
} [cite: 1166]

int main(){ [cite: 1173]
    char s1[]="test", s2[]="test"; [cite: 1174]
    
    int r=mycmp(s1,s2); [cite: 1176]
    
    if(r==0) printf("Equal\n"); [cite: 1177]
    else if(r<0) printf("s1<s2\n"); [cite: 1177]
    else printf("s1>s2\n"); [cite: 1177]
    return 0; [cite: 1177]
} [cite: 1175]