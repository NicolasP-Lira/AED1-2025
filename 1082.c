#include <stdio.h>
#include <string.h>

#define MAX 26

int graph[MAX][MAX];
int visited[MAX];
int components[MAX][MAX];  // Para armazenar vértices de cada componente
int compSize[MAX];         // Tamanho de cada componente

void dfs(int vertex, int compIndex) {
    visited[vertex] = 1;
    components[compIndex][compSize[compIndex]++] = vertex;
    
    for (int i = 0; i < MAX; i++) {
        if (graph[vertex][i] && !visited[i]) {
            dfs(i, compIndex);
        }
    }
}

void sortComponent(int compIndex) {
    // Ordenação simples por inserção (máx 26 elementos)
    for (int i = 1; i < compSize[compIndex]; i++) {
        int key = components[compIndex][i];
        int j = i - 1;
        while (j >= 0 && components[compIndex][j] > key) {
            components[compIndex][j + 1] = components[compIndex][j];
            j--;
        }
        components[compIndex][j + 1] = key;
    }
}

int main() {
    int N, V, E;
    char u, v;
    
    scanf("%d", &N);
    
    for (int caso = 1; caso <= N; caso++) {
        scanf("%d %d", &V, &E);
        
        // Limpa grafo e estruturas
        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        memset(compSize, 0, sizeof(compSize));
        
        // Lê arestas
        for (int i = 0; i < E; i++) {
            scanf(" %c %c", &u, &v);
            int idx1 = u - 'a';
            int idx2 = v - 'a';
            graph[idx1][idx2] = 1;
            graph[idx2][idx1] = 1;
        }
        
        int compCount = 0;
        
        // Encontra componentes conexos
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, compCount);
                // Ordena o componente atual
                sortComponent(compCount);
                compCount++;
            }
        }
        
        printf("Case #%d:\n", caso);
        
        // Imprime componentes
        for (int i = 0; i < compCount; i++) {
            for (int j = 0; j < compSize[i]; j++) {
                printf("%c,", components[i][j] + 'a');
            }
            printf("\n");
        }
        
        printf("%d connected components\n\n", compCount);
    }
    
    return 0;
}