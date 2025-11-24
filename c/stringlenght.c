#include <stdio.h> [cite: 1126]

int mylen(char *s){ int i=0; while(s[i]) i++; return i; } [cite: 1127]

int main(){ char s[]="Hello"; printf("Len=%d\n", mylen(s)); return 0; } [cite: 1128]