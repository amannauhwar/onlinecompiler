#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
    int v;
    struct TNode *l, *r;
    int rthread; /* 1 if r is thread */
} TNode;

TNode* newT(int x) { TNode* n=malloc(sizeof(TNode)); n->v=x; n->l=n->r=NULL; n->rthread = 0; return n; }

TNode* insert(TNode* root, int x){
    if(!root) return newT(x);
    if(x < root->v) root->l = insert(root->l,x);
    else root->r = insert(root->r,x);
    return root;
}

/* Make simple threads by doing inorder traversal and linking predecessors */
void makeThreadsUtil (TNode* r, TNode** prev){
    if(!r) return;
    makeThreadsUtil(r->l, prev);
    
    if(*prev && (*prev)->r == NULL) {
        (*prev)->r = r;
        (*prev)->rthread = 1;
    }
    *prev = r;
    
    makeThreadsUtil(r->r, prev);
}

TNode* leftMost (TNode* n){ while(n && n->l) n=n->l; return n; }

void inorderThreaded (TNode* root){
    TNode* cur = leftMost(root);
    while(cur){
        printf("%d ", cur->v);
        if(cur->rthread) cur = cur->r;
        else cur = leftMost(cur->r);
    }
}

int main(){
    TNode* root=NULL;
    int a []={20,10,30,5,15,25,35}, i;
    for (i=0;i<7;i++) root = insert(root,a[i]);
    
    TNode* prev=NULL;
    makeThreadsUtil (root, &prev);
    
    printf("Threaded Inorder: "); inorderThreaded (root); printf("\n");
    return 0;
}