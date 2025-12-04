#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Cria novo nó
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insere na BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }
    
    return root;
}

// BFS (percurso por nível)
void levelOrder(Node* root, int caseNumber) {
    if (root == NULL) return;
    
    // Fila para BFS
    Node* queue[505];
    int front = 0, rear = 0;
    
    printf("Case %d:\n", caseNumber);
    
    queue[rear++] = root;
    
    int first = 1;
    while (front < rear) {
        Node* current = queue[front++];
        
        // Imprime o nó
        if (first) {
            printf("%d", current->data);
            first = 0;
        } else {
            printf(" %d", current->data);
        }
        
        // Adiciona filhos à fila
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
    printf("\n\n");
}

// Libera memória da árvore
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    int C, N, value;
    
    scanf("%d", &C);
    
    for (int caso = 1; caso <= C; caso++) {
        scanf("%d", &N);
        
        Node* root = NULL;
        
        // Lê e insere valores
        for (int i = 0; i < N; i++) {
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        // Imprime percurso por nível
        levelOrder(root, caso);
        
        // Libera memória
        freeTree(root);
    }
    
    return 0;
}