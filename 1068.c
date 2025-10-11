#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    char expressao[MAX];
    
    while (fgets(expressao, MAX, stdin)) {
        int pilha = 0;
        int correto = 1; // 1 = correto, 0 = incorrect
        
        for (int i = 0; i < strlen(expressao); i++) {
            if (expressao[i] == '(') {
                pilha++; // Empilha '('
            }
            else if (expressao[i] == ')') {
                if (pilha > 0) {
                    pilha--; // Desempilha '('
                } else {
                    correto = 0; // Encontrou ')' sem '(' na pilha
                    break;
                }
            }
        }
        
        // No final, a pilha deve estar vazia
        if (pilha != 0) {
            correto = 0;
        }
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
