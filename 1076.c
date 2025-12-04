#include <stdio.h>
#include <string.h>

#define MAX 50

int main() {
    int T, N, V, A, u, v;
    int i;
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &N);
        scanf("%d %d", &V, &A);
        
        // Matriz de adjacência para até 50 vértices
        int adj[MAX][MAX] = {0};
        int contador = 0;
        
        for (i = 0; i < A; i++) {
            scanf("%d %d", &u, &v);
            
            // Se a aresta ainda não foi marcada
            if (!adj[u][v]) {
                adj[u][v] = 1;
                adj[v][u] = 1;  // Marca bidirecional
                contador++;
            }
        }
        
        // Número de movimentos = 2 * número de arestas únicas
        printf("%d\n", 2 * contador);
    }
    
    return 0;
}