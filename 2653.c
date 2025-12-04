#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 1000010  // 10^6 + margem

// Estrutura para um nó da BST
typedef struct Node {
    char* jewel;          // String da joia
    struct Node* left;
    struct Node* right;
} Node;

// Cria um novo nó
Node* createNode(char* jewel) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->jewel = strdup(jewel);  // Copia a string
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insere na BST se não existir, retorna 1 se inseriu, 0 se já existia
int insert(Node** root, char* jewel) {
    if (*root == NULL) {
        *root = createNode(jewel);
        return 1;  // Inseriu nova joia
    }
    
    int cmp = strcmp(jewel, (*root)->jewel);
    if (cmp < 0) {
        return insert(&((*root)->left), jewel);
    } else if (cmp > 0) {
        return insert(&((*root)->right), jewel);
    } else {
        return 0;  // Já existe
    }
}

// Libera memória da BST
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root->jewel);
    free(root);
}

int main() {
    char jewel[MAX_CHARS];
    Node* root = NULL;
    int count = 0;
    
    // Lê até EOF
    while (scanf("%s", jewel) != EOF) {
        if (insert(&root, jewel)) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    freeTree(root);
    return 0;
}