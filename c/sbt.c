#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *l, *r;
} Node;

Node* newNode(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->val=v;
    n->l=n->r=NULL;
    return n;
}

void pre(Node* r){ if(!r) return; printf("%d ",r->val); pre(r->l); pre(r->r); }
void in (Node* r){ if(!r) return; in(r->l); printf("%d ",r->val); in(r->r); }
void post(Node* r){ if(!r) return; post(r->l); post(r->r); printf("%d ",r->val); }

int main(){
    Node *root = newNode(1);
    root->l = newNode(2);
    root->r = newNode(3);
    root->l->l = newNode(4);
    root->l->r = newNode(5);
    
    printf("Pre: "); pre(root); printf("\n");
    printf("In: "); in(root); printf("\n");
    printf("Post: "); post(root); printf("\n");
    return 0;
}