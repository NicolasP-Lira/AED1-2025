#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da árvore
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;

// Função para criar um novo nó
Node* createNode(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um valor na árvore
Node* insert(Node* root, char value) {
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

// Função para buscar um valor na árvore
int search(Node* root, char value) {
    if (root == NULL) {
        return 0;
    }
    
    if (value == root->data) {
        return 1;
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return search(root->right, value);
    }
}

// Função para percurso infixo
void infixTraversal(Node* root, int* first) {
    if (root == NULL) return;
    
    infixTraversal(root->left, first);
    
    if (*first) {
        printf("%c", root->data);
        *first = 0;
    } else {
        printf(" %c", root->data);
    }
    
    infixTraversal(root->right, first);
}

// Função para percurso prefixo
void prefixTraversal(Node* root, int* first) {
    if (root == NULL) return;
    
    if (*first) {
        printf("%c", root->data);
        *first = 0;
    } else {
        printf(" %c", root->data);
    }
    
    prefixTraversal(root->left, first);
    prefixTraversal(root->right, first);
}

// Função para percurso posfixo
void postfixTraversal(Node* root, int* first) {
    if (root == NULL) return;
    
    postfixTraversal(root->left, first);
    postfixTraversal(root->right, first);
    
    if (*first) {
        printf("%c", root->data);
        *first = 0;
    } else {
        printf(" %c", root->data);
    }
}

// Função principal
int main() {
    Node* root = NULL;
    char command[10];
    char value;
    
    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "I") == 0) {
            scanf(" %c", &value);
            root = insert(root, value);
        }
        else if (strcmp(command, "P") == 0) {
            scanf(" %c", &value);
            if (search(root, value)) {
                printf("%c existe\n", value);
            } else {
                printf("%c nao existe\n", value);
            }
        }
        else if (strcmp(command, "INFIXA") == 0) {
            int first = 1;
            infixTraversal(root, &first);
            printf("\n");
        }
        else if (strcmp(command, "PREFIXA") == 0) {
            int first = 1;
            prefixTraversal(root, &first);
            printf("\n");
        }
        else if (strcmp(command, "POSFIXA") == 0) {
            int first = 1;
            postfixTraversal(root, &first);
            printf("\n");
        }
    }
    
    return 0;
}