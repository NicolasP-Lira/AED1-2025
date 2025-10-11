#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    char expressao[MAX];
    char pilha[MAX];
    int topo;
    
    while (fgets(expressao, MAX, stdin)) {
        topo = -1;
        int correto = 1;
        
        for (int i = 0; i < strlen(expressao) && correto; i++) {
            if (expressao[i] == '(') {
                pilha[++topo] = '(';
            }
            else if (expressao[i] == ')') {
                if (topo >= 0) {
                    topo--;
                } else {
                    correto = 0;
                }
            }
        }
        
        printf("%s\n", (correto && topo == -1) ? "correct" : "incorrect");
    }
    
    return 0;
}
