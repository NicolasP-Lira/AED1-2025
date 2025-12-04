#include <stdio.h>
#include <stdlib.h>

#define MAX 200010

typedef struct {
    int u, v, w;
} Edge;

Edge edges[MAX];
int parent[MAX];
int rank[MAX];

int compare(const void* a, const void* b) {
    Edge* e1 = (Edge*)a;
    Edge* e2 = (Edge*)b;
    return e1->w - e2->w;
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

int unionSet(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX == rootY) return 0;
    
    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    return 1;
}

int main() {
    int m, n;
    
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        
        long long total = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            total += edges[i].w;
        }
        
        // Ordena arestas por peso
        qsort(edges, n, sizeof(Edge), compare);
        
        // Inicializa Union-Find
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        
        // Kruskal - encontra MST
        long long mstWeight = 0;
        int edgesUsed = 0;
        
        for (int i = 0; i < n && edgesUsed < m - 1; i++) {
            if (unionSet(edges[i].u, edges[i].v)) {
                mstWeight += edges[i].w;
                edgesUsed++;
            }
        }
        
        // Economia = total - MST
        printf("%lld\n", total - mstWeight);
    }
    
    return 0;
}