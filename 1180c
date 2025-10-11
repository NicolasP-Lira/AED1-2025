#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int x[1000]; // Array com tamanho máximo
    int *ptr = x; // Ponteiro apontando para o array
    int menor_valor, posicao;
    
    // Lê todos os números usando ponteiro
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr + i); // ptr + i é equivalente a &x[i]
    }
    
    // Encontra o menor valor usando ponteiro
    menor_valor = *ptr; // Primeiro elemento (ptr aponta para x[0])
    posicao = 0;
    
    for (int i = 1; i < n; i++) {
        if (*(ptr + i) < menor_valor) { // Acessa o elemento na posição i
            menor_valor = *(ptr + i);
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor_valor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}
