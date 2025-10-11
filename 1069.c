#include <stdio.h>
#include <string.h>

#define MAX 1001

int main() {
    int n;
    char linha[MAX];
    char pilha[MAX];
    int topo;
    
    scanf("%d", &n);
    getchar(); // Consome o \n
    
    for (int i = 0; i < n; i++) {
        fgets(linha, MAX, stdin);
        
        topo = -1; // Pilha vazia
        int diamantes = 0;
        
        for (int j = 0; j < strlen(linha); j++) {
            if (linha[j] == '<') {
                // Empilha o '<'
                topo++;
                pilha[topo] = '<';
            }
            else if (linha[j] == '>') {
                // Verifica se pode formar diamante
                if (topo >= 0 && pilha[topo] == '<') {
                    diamantes++;
                    topo--; // Desempilha
                }
            }
        }
        
        printf("%d\n", diamantes);
    }
    
    return 0;
}
