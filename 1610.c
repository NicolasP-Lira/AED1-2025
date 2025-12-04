#include <stdio.h>
#include <stdlib.h>

#define MAXN 10010

int adj[MAXN][300];  // Lista de adjacência (máximo de ~300 arestas por nó, ajustável)
int adjSize[MAXN];
int inDegree[MAXN];

int fila[MAXN];
int inicio, fim;

void bfs_init() {
    inicio = 0;
    fim = 0;
}

void enfileirar(int x) {
    fila[fim++] = x;
}

int desenfileirar() {
    return fila[inicio++];
}

int fila_vazia() {
    return inicio == fim;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        // Inicialização
        for (int i = 1; i <= N; i++) {
            adjSize[i] = 0;
            inDegree[i] = 0;
        }
        bfs_init();

        // Construir grafo
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            // B -> A (A depende de B)
            adj[B][adjSize[B]++] = A;
            inDegree[A]++;
        }

        // Colocar na fila todos com grau de entrada zero
        for (int i = 1; i <= N; i++) {
            if (inDegree[i] == 0) {
                enfileirar(i);
            }
        }

        int count = 0;
        // BFS
        while (!fila_vazia()) {
            int u = desenfileirar();
            count++;

            for (int j = 0; j < adjSize[u]; j++) {
                int v = adj[u][j];
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    enfileirar(v);
                }
            }
        }

        // Verificar ciclo
        if (count < N) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
