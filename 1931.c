#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10010
#define INF 1000000000

typedef struct {
    int to, cost;
} Edge;

Edge* adj[MAX];
int adjSize[MAX];
int dist[MAX][2];
int heapSize;

typedef struct {
    int cost, city, parity;
} Node;

Node* heap;

void push(int cost, int city, int parity) {
    int i = ++heapSize;
    while (i > 1 && cost < heap[i/2].cost) {
        heap[i] = heap[i/2];
        i /= 2;
    }
    heap[i].cost = cost;
    heap[i].city = city;
    heap[i].parity = parity;
}

void pop(int *cost, int *city, int *parity) {
    *cost = heap[1].cost;
    *city = heap[1].city;
    *parity = heap[1].parity;
    
    Node last = heap[heapSize--];
    int i = 1;
    while (i * 2 <= heapSize) {
        int child = i * 2;
        if (child < heapSize && heap[child+1].cost < heap[child].cost) child++;
        if (last.cost <= heap[child].cost) break;
        heap[i] = heap[child];
        i = child;
    }
    heap[i] = last;
}

int main() {
    int C, V;
    
    while (scanf("%d %d", &C, &V) != EOF) {
        // Inicializa listas de adjacência
        for (int i = 1; i <= C; i++) {
            adj[i] = (Edge*)malloc(sizeof(Edge) * 50); // Máximo 50 vizinhos por cidade
            adjSize[i] = 0;
            dist[i][0] = dist[i][1] = INF;
        }
        
        // Aloca heap
        heap = (Node*)malloc(sizeof(Node) * (C * 4 + 10));
        
        // Lê arestas
        for (int i = 0; i < V; i++) {
            int c1, c2, g;
            scanf("%d %d %d", &c1, &c2, &g);
            
            adj[c1][adjSize[c1]].to = c2;
            adj[c1][adjSize[c1]].cost = g;
            adjSize[c1]++;
            
            adj[c2][adjSize[c2]].to = c1;
            adj[c2][adjSize[c2]].cost = g;
            adjSize[c2]++;
        }
        
        // Dijkstra
        heapSize = 0;
        dist[1][0] = 0;
        push(0, 1, 0);
        
        while (heapSize > 0) {
            int cost, city, parity;
            pop(&cost, &city, &parity);
            
            if (cost > dist[city][parity]) continue;
            
            for (int i = 0; i < adjSize[city]; i++) {
                int nextCity = adj[city][i].to;
                int edgeCost = adj[city][i].cost;
                int nextParity = 1 - parity;
                int newCost = cost + edgeCost;
                
                if (newCost < dist[nextCity][nextParity]) {
                    dist[nextCity][nextParity] = newCost;
                    push(newCost, nextCity, nextParity);
                }
            }
        }
        
        // Resposta
        if (dist[C][0] == INF) {
            printf("-1\n");
        } else {
            printf("%d\n", dist[C][0]);
        }
        
        // Libera memória
        for (int i = 1; i <= C; i++) {
            free(adj[i]);
        }
        free(heap);
    }
    
    return 0;
}