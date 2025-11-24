#include <stdio.h> [cite: 1146]

void mycat(char *a, char *b){ [cite: 1147]
    int i=0,j =0; [cite: 1148]
    
    while(a[i]) i++; /* go to end of a */ [cite: 1149]
    
    while(b[j]) {a[i++]=b[j++];} [cite: 1150, 1151]
    
    a[i] = 0; [cite: 1152]
} [cite: 1153]

int main(){ [cite: 1154]
    char a[50] = "Hello"; [cite: 1155]
    char b[] = "World!"; [cite: 1155]
    
    mycat(a,b); [cite: 1156]
    
    printf("%s\n", a); [cite: 1157]
    return 0; [cite: 1158]
} [cite: 1159]