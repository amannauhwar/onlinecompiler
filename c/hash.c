#include <stdio.h> [cite: 1027]
#include <string.h> [cite: 1028]
#include <stdlib.h> [cite: 1029]

#define S 10 [cite: 1030]

typedef struct Node { char name [60]; char contact[20]; struct Node *next; } Node; [cite: 1031]
Node* table[S]; [cite: 1031]

int hash(char *s){ [cite: 1032]
    int sum = 0; [cite: 1034]
    for(int i=0;s[i];i++) sum += s[i]; [cite: 1034]
    return sum % S; [cite: 1035]
} [cite: 1033]

void add(char *fname, char *lname, char *contact){ [cite: 1036]
    char key[60]; [cite: 1038]
    sprintf(key, "%s%s", fname, lname); [cite: 1038]
    
    int h = hash(key); [cite: 1039]
    
    Node* n = malloc(sizeof(Node)); [cite: 1040]
    sprintf(n->name, "%s %s", fname, lname); [cite: 1040]
    strcpy(n->contact, contact); [cite: 1040]
    n->next = table[h]; [cite: 1040]
    table[h] = n; [cite: 1040]
} [cite: 1037]

void show(){ [cite: 1041]
    for(int i=0;i<S;i++){ [cite: 1042]
        printf("Bucket %d:\n",i); [cite: 1043, 1044]
        for(Node* p=table[i]; p; p=p->next) printf(" %s -> %s\n", p->name, p->contact); [cite: 1045]
    } [cite: 1046]
} [cite: 1047]

int main(){ [cite: 1048]
    add("Yash","Gupta", "9999999999"); [cite: 1049]
    add("Yash", "Gupta", "8888888888"); [cite: 1049]
    show(); [cite: 1050]
    return 0; [cite: 1051]
} [cite: 1052]