#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 260
#define INF INT_MAX

int grafo[MAX][MAX];
int dist[MAX];
int visitado[MAX];

int main() {
    int n, m, c, k;
    
    while (1) {
        scanf("%d %d %d %d", &n, &m, &c, &k);
        if (n == 0 && m == 0 && c == 0 && k == 0) break;
        
        // Inicializar grafo
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                grafo[i][j] = INF;
            }
        }
        
        // Ler arestas
        for (int i = 0; i < m; i++) {
            int u, v, p;
            scanf("%d %d %d", &u, &v, &p);
            if (p < grafo[u][v]) {
                grafo[u][v] = p;
                grafo[v][u] = p;
            }
        }
        
        // PRIMEIRO: Calcular custo acumulado da rota
        int custo_rota[MAX];
        custo_rota[c-1] = 0;
        for (int i = c-2; i >= 0; i--) {
            if (grafo[i][i+1] != INF) {
                custo_rota[i] = custo_rota[i+1] + grafo[i][i+1];
            } else {
                custo_rota[i] = INF;
            }
        }
        
        // SEGUNDO: Dijkstra normal de k até todas as cidades
        for (int i = 0; i < n; i++) {
            dist[i] = INF;
            visitado[i] = 0;
        }
        dist[k] = 0;
        
        for (int count = 0; count < n; count++) {
            // Encontrar mínimo
            int u = -1;
            int min_dist = INF;
            for (int i = 0; i < n; i++) {
                if (!visitado[i] && dist[i] < min_dist) {
                    min_dist = dist[i];
                    u = i;
                }
            }
            
            if (u == -1) break;
            visitado[u] = 1;
            
            // Relaxar arestas - MAS com restrição!
            for (int v = 0; v < n; v++) {
                if (grafo[u][v] == INF) continue;
                
                // RESTRIÇÃO IMPORTANTE:
                // Se u está na rota (0..c-2) e não é o próximo passo da rota
                if (u < c-1 && v != u+1) {
                    // Não pode usar esta aresta!
                    continue;
                }
                
                int nova_dist = dist[u] + grafo[u][v];
                if (nova_dist < dist[v]) {
                    dist[v] = nova_dist;
                }
            }
        }
        
        // TERCEIRO: Calcular resposta
        int resposta = INF;
        
        // Opção 1: Ir direto para c-1 (se possível)
        if (dist[c-1] < resposta) resposta = dist[c-1];
        
        // Opção 2: Ir para alguma cidade i da rota, depois seguir rota
        for (int i = 0; i < c; i++) {
            if (dist[i] != INF && custo_rota[i] != INF) {
                int total = dist[i] + custo_rota[i];
                if (total < resposta) resposta = total;
            }
        }
        
        printf("%d\n", resposta);
    }
    
    return 0;
}
