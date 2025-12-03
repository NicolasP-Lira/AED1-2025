#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = v;
    n->left = n->right = NULL;
    return n;
}

Node* insert(Node* r, int v) {
    if (!r) return create(v);
    if (v < r->data) r->left = insert(r->left, v);
    else if (v > r->data) r->right = insert(r->right, v);
    return r;
}

void print(Node* r, int* f, int type) {
    if (!r) return;
    
    if (type == 1) { // pré-ordem
        printf(*f ? "%d" : " %d", r->data);
        *f = 0;
        print(r->left, f, type);
        print(r->right, f, type);
    } else if (type == 2) { // em-ordem
        print(r->left, f, type);
        printf(*f ? "%d" : " %d", r->data);
        *f = 0;
        print(r->right, f, type);
    } else { // pós-ordem
        print(r->left, f, type);
        print(r->right, f, type);
        printf(*f ? "%d" : " %d", r->data);
        *f = 0;
    }
}

void freeTree(Node* r) {
    if (!r) return;
    freeTree(r->left);
    freeTree(r->right);
    free(r);
}

int main() {
    int C, N, v;
    scanf("%d", &C);
    
    for (int i = 1; i <= C; i++) {
        scanf("%d", &N);
        Node* root = NULL;
        
        for (int j = 0; j < N; j++) {
            scanf("%d", &v);
            root = insert(root, v);
        }
        
        printf("Case %d:\n", i);
        
        printf("Pre.: ");
        int first = 1;
        print(root, &first, 1);
        
        printf("\nIn..: ");
        first = 1;
        print(root, &first, 2);
        
        printf("\nPost: ");
        first = 1;
        print(root, &first, 3);
        
        printf("\n\n");
        freeTree(root);
    }
    
    return 0;
}
