#include <stdio.h>
#include <string.h>

#define MAX 510
#define INF 1000000000

int g[MAX][MAX];

int main() {
    int N, E, primeiro = 1;
    
    while (scanf("%d %d", &N, &E), N || E) {
        memset(g, 0x3f, sizeof(g));
        for (int i = 1; i <= N; i++) g[i][i] = 0;
        
        while (E--) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            if (H < g[X][Y]) g[X][Y] = H;
        }
        
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                if (g[i][k] < INF)
                    for (int j = 1; j <= N; j++)
                        if (g[i][k] + g[k][j] < g[i][j])
                            g[i][j] = g[i][k] + g[k][j];
        
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (i != j && g[i][j] < INF && g[j][i] < INF)
                    g[i][j] = 0;
        
        for (int k = 1; k <= N; k++)
            for (int i = 1; i <= N; i++)
                if (g[i][k] < INF)
                    for (int j = 1; j <= N; j++)
                        if (g[i][k] + g[k][j] < g[i][j])
                            g[i][j] = g[i][k] + g[k][j];
        
        // Processar consultas
        int K;
        scanf("%d", &K);
        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);
            if (g[O][D] >= INF) 
                printf("Nao e possivel entregar a carta\n");
            else 
                printf("%d\n", g[O][D]);
        }
        
        // Linha em branco APÓS cada caso de teste
        printf("\n");
    }
    
    return 0;
}