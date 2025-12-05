#include <stdio.h>
#include <stdlib.h>

#define MAX 50010

typedef struct {
    int u, v, peso;
} Aresta;

Aresta arestas[MAX];
int pai[MAX], tam[MAX];

// Função de comparação para qsort
int compara(const void* a, const void* b) {
    Aresta* a1 = (Aresta*)a;
    Aresta* a2 = (Aresta*)b;
    return a1->peso - a2->peso;
}

// Funções Union-Find (Disjoint Set Union)
int find(int x) {
    if (pai[x] != x) {
        pai[x] = find(pai[x]); // path compression
    }
    return pai[x];
}

void unionSets(int x, int y) {
    int raizX = find(x);
    int raizY = find(y);
    
    if (raizX == raizY) return;
    
    // Union by size
    if (tam[raizX] < tam[raizY]) {
        pai[raizX] = raizY;
        tam[raizY] += tam[raizX];
    } else {
        pai[raizY] = raizX;
        tam[raizX] += tam[raizY];
    }
}

int main() {
    int M, N;
    
    while (1) {
        scanf("%d %d", &M, &N);
        if (M == 0 && N == 0) break;
        
        // Ler todas as arestas
        for (int i = 0; i < N; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].peso);
        }
        
        // Ordenar arestas por peso (crescente)
        qsort(arestas, N, sizeof(Aresta), compara);
        
        // Inicializar Union-Find
        for (int i = 0; i < M; i++) {
            pai[i] = i;
            tam[i] = 1;
        }
        
        // Algoritmo de Kruskal
        int mst_peso = 0;
        int arestas_usadas = 0;
        
        for (int i = 0; i < N && arestas_usadas < M - 1; i++) {
            int u = arestas[i].u;
            int v = arestas[i].v;
            int peso = arestas[i].peso;
            
            // Se u e v estão em componentes diferentes, adiciona à MST
            if (find(u) != find(v)) {
                unionSets(u, v);
                mst_peso += peso;
                arestas_usadas++;
            }
        }
        
        printf("%d\n", mst_peso);
    }
    
    return 0;
}