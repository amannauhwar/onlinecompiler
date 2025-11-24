#include <stdio.h> [cite: 1133]

int len(char *s){ int i=0; while(s[i]) i++; return i; } [cite: 1134]

int main() [cite: 1135]
{ [cite: 1137]
    char a[]="hello", b[]="world!"; [cite: 1138]
    
    printf("Len a=%d b=%d\n", len(a), len(b)); [cite: 1139]
    printf("Equal length? %s\n", (len(a)==len(b)) ? "Yes" : "No"); [cite: 1140]
    return 0; [cite: 1141]
} [cite: 1136]