#include <stdio.h> [cite: 941]
#include <stdlib.h> [cite: 942]

typedef struct Node{ int v; struct Node *l, *r; } Node; [cite: 943]

Node* newN(int x) { Node* n=malloc(sizeof(Node)); n->v=x; n->l=n->r=NULL; return n; } [cite: 944]

void inorderIter(Node* root){ [cite: 945]
    Node* stack[100]; [cite: 946]
    int top = 0; [cite: 946]
    Node* cur = root; [cite: 947]

    while(cur || top){ [cite: 948]
        while(cur){ stack[top++]=cur; cur=cur->l; } [cite: 949]
        cur = stack[--top]; [cite: 950]
        printf("%d ", cur->v); [cite: 951]
        cur = cur->r; [cite: 952]
    } [cite: 953]
} [cite: 954]

int main(){ [cite: 955]
    Node *r = newN(4); [cite: 956]
    r->l=newN(2); [cite: 956]
    r->r=newN(6); [cite: 956]
    r->l->l=newN(1); [cite: 957]
    r->l->r=newN(3); [cite: 957]
    r->r->l=newN(5); [cite: 957]
    r->r->r=newN(7); [cite: 957]

    printf("Iter Inorder: "); inorderIter(r); printf("\n"); [cite: 958]
    return 0; [cite: 959]
} [cite: 960]