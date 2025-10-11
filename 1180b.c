#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x[n];
    int menor_valor, posicao;
    
    // Lê todos os números
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }
    
    // Encontra o menor valor
    menor_valor = x[0];
    posicao = 0;
    
    for (int i = 1; i < n; i++) {
        if (x[i] < menor_valor) {
            menor_valor = x[i];
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}
