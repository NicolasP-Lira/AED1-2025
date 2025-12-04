#include <stdio.h>
#define MAX_ID 100001

int main() {
    int n, m, i, id;
    
    scanf("%d", &n);
    int fila[n];
    
    // Lê os identificadores da fila inicial
    for (i = 0; i < n; i++) {
        scanf("%d", &fila[i]);
    }
    
    // Cria um array de marcação (0 = presente, 1 = saiu)
    int saiu[MAX_ID] = {0};
    
    scanf("%d", &m);
    
    // Marca as pessoas que saíram
    for (i = 0; i < m; i++) {
        scanf("%d", &id);
        saiu[id] = 1;  // Marca que esta pessoa saiu
    }
    
    // Imprime as pessoas que permaneceram na fila
    int primeiro = 1;  // Para controlar os espaços
    for (i = 0; i < n; i++) {
        if (!saiu[fila[i]]) {  // Se não saiu
            if (!primeiro) {
                printf(" ");
            }
            printf("%d", fila[i]);
            primeiro = 0;
        }
    }
    printf("\n");
    
    return 0;
}