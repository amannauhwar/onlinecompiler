#include <stdio.h> [cite: 964]
#include <string.h> [cite: 965]
#include <stdlib.h> [cite: 966]

#define MAX 100 [cite: 967]

typedef struct { char key [30]; char val[50]; } Item; [cite: 968]
Item dict[MAX]; [cite: 969]
int dsize = 0; [cite: 969]

void insertItem(char *k, char *v){ [cite: 970]
    strcpy(dict[dsize].key,k); [cite: 972]
    strcpy(dict[dsize].val,v); [cite: 972]
    dsize++; [cite: 972]
} [cite: 971]

int findIndex(char *k){ [cite: 973]
    for(int i=0;i<dsize;i++) if(strcmp(dict[i].key,k) == 0) return i; [cite: 975]
    return -1; [cite: 976]
} [cite: 974]

void delltem(char *k){ [cite: 977]
    int idx = findIndex(k); [cite: 979]
    if(idx==-1) { printf("Not found\n"); return; } [cite: 980]
    
    for(int i=idx;i<dsize-1;i++) dict[i]=dict[i+1]; [cite: 981]
    dsize--; [cite: 982]
} [cite: 978]

void show(){ for(int i=0;i<dsize;i++) printf("%s: %s\n", dict[i].key, dict[i].val); } [cite: 983]

int main(){ [cite: 984]
    insertItem("apple","fruit"); [cite: 986]
    insertItem("car", "vehicle"); [cite: 986]
    
    printf("Dict:\n"); show(); [cite: 987]
    
    delltem("apple"); [cite: 988]
    
    printf("After delete:\n"); show(); [cite: 989]
    return 0; [cite: 990]
} [cite: 985]