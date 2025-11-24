#include <stdio.h> [cite: 1106]

int findSub(char *text, char *pat){ [cite: 1107]
    for(int i=0; text[i]; i++){ [cite: 1108, 1109]
        int j=0; [cite: 1110]
        while(pat[j] && text[i+j] && text[i+j]==pat[j]) j++; [cite: 1111]
        if(!pat[j]) return i; /* found at i */ [cite: 1112]
    } [cite: 1113]
    return -1; [cite: 1114]
} [cite: 1115]

int main(){ [cite: 1116]
    char txt[] = "This is a sample paragraph for testing."; [cite: 1117]
    char pat[] = "sample"; [cite: 1118]
    int pos = findSub(txt, pat); [cite: 1119]
    
    if(pos>=0) printf("Found at %d\n", pos); else printf("Not found\n"); [cite: 1120]
    return 0; [cite: 1121]
} [cite: 1122]