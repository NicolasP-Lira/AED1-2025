#include <stdio.h>
#include <stdlib.h>

#define MAX 1005

int main() {
    int N;
    int alvo[MAX];
    int pilha[MAX];
    int topo;
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        while (1) {
            scanf("%d", &alvo[0]);
            if (alvo[0] == 0) {
                printf("\n");
                break;
            }
            
            for (int i = 1; i < N; i++) {
                scanf("%d", &alvo[i]);
            }
            
            topo = -1;
            int vagao = 1;
            int pos = 0;
            int possivel = 1;
            
            while (pos < N && possivel) {
                // ERRO 1: Só empilha se o vagão for menor ou igual ao alvo atual
                // Isso falha quando precisa empilhar números maiores temporariamente
                if (vagao <= N && vagao <= alvo[pos]) {
                    pilha[++topo] = vagao++;
                }
                // ERRO 2: Desempilha se o topo for igual ao alvo
                else if (topo >= 0 && pilha[topo] == alvo[pos]) {
                    topo--;
                    pos++;
                }
                // ERRO 3: Condição de impossibilidade muito restritiva
                else if (vagao > N && topo >= 0 && pilha[topo] != alvo[pos]) {
                    possivel = 0;
                }
                // ERRO 4: Falta um caso - quando precisa empilhar um número maior que o alvo atual
                // mas isso é necessário para alcançar o alvo depois
                else {
                    // Tenta empilhar mesmo assim, mas com lógica errada
                    if (vagao <= N) {
                        pilha[++topo] = vagao++;
                    } else {
                        possivel = 0;
                    }
                }
            }
            
            // ERRO 5: Não verifica se todos os elementos foram processados
            if (possivel && pos >= N - 1) { // Deveria ser pos == N
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }
    
    return 0;
}
