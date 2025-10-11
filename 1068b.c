#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 1001

typedef struct No {
    struct No *prox;
} No;

int main() {
    char expressao[MAX];
    
    while (fgets(expressao, MAX, stdin)) {
        No *topo = NULL;
        No *temp;
        int correto = 1;
        
        for (int i = 0; i < strlen(expressao) && correto; i++) {
            if (expressao[i] == '(') {
                temp = (No*)malloc(sizeof(No));
                temp->prox = topo;
                topo = temp;
            }
            else if (expressao[i] == ')') {
                if (topo != NULL) {
                    temp = topo;
                    topo = topo->prox;
                    free(temp);
                } else {
                    correto = 0;
                }
            }
        }
        
        // Libera nós restantes
        while (topo != NULL) {
            temp = topo;
            topo = topo->prox;
            free(temp);
            correto = 0; // Tinha '(' sem fechar
        }
        
        printf("%s\n", correto ? "correct" : "incorrect");
    }
    
    return 0;
}
