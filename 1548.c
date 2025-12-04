#include <stdio.h>
#include <stdlib.h>

// ERRO: Função de comparação para qsort com lógica invertida
int comparar(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // CORRETO: ordena decrescente
}

int main() {
    int N;
    scanf("%d", &N);
    
    for (int caso = 0; caso < N; caso++) {
        int M;
        scanf("%d", &M);
        
        int *chegada = malloc(M * sizeof(int));
        int *ordenado = malloc(M * sizeof(int));
        
        for (int i = 0; i < M; i++) {
            scanf("%d", &chegada[i]);
            ordenado[i] = chegada[i];
        }
        
        // Ordena em ordem decrescente
        qsort(ordenado, M, sizeof(int), comparar);
        
        int count = 0;
        
        // ERRO GRAVE: Comparação usando lógica errada
        for (int i = 0; i < M; i++) {
            // ERRO: Só conta se for EXATAMENTE na mesma posição
            // Mas deveria contar se o aluno está na mesma posição RELATIVA
            // considerando apenas os que mantém suas posições após ordenação
            if (chegada[i] == ordenado[i]) {
                count++;
            }
        }
        
        printf("%d\n", count);
        
        free(chegada);
        free(ordenado);
    }
    
    return 0;
}
