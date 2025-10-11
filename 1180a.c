#include <stdio.h>

int main() {
int n;
scanf("%d", &n);

int menor_valor, posicao;
int numero_atual;

// Lê o primeiro número
scanf("%d", &numero_atual);
menor_valor = numero_atual;
posicao = 0;

// Processa os números restantes
for (int i = 1; i < n; i++) {
    scanf("%d", &numero_atual);
    
    if (numero_atual < menor_valor) {
        menor_valor = numero_atual;
        posicao = i;
    }
}

printf("Menor valor: %d\n", menor_valor);
printf("Posicao: %d\n", posicao);

return 0;
}
