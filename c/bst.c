#include <stdio.h>
#include <stdlib.h>

typedef struct Node{ int v; struct Node *l, *r; } Node;

Node* newN(int x) { Node* n=malloc(sizeof(Node)); n->v=x; n->l=n->r=NULL; return n; }

Node* insert(Node* r,int x){
    if(!r) return newN(x);
    if(x<r->v) r->l = insert(r->l,x);
    else r->r = insert(r->r,x);
    return r;
}

void inorder(Node* r){ if(!r) return; inorder(r->l); printf("%d ",r->v); inorder(r->r); }

int search (Node* r,int x) {
    if(!r) return 0;
    if(r->v==x) return 1;
    return (x < r->v) ? search(r->l,x): search(r->r,x);
}

int main(){
    Node* root=NULL;
    int a[] = {50,30,70,20,40,60,80}, n=7, i;
    for( i=0;i<n;i++) root = insert(root,a[i]);
    
    printf("BST inorder: "); inorder(root); printf("\n");
    printf("Search 60: %s\n", search (root, 60) ? "Found":"Not Found");
    return 0;
}