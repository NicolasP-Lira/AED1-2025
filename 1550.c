#include <stdio.h>
#include <string.h>

#define MAX 10000
#define INF 1000000000

int bfs(int start, int target) {
    int dist[MAX];
    int queue[MAX];
    int front = 0, rear = 0;
    
    for (int i = 0; i < MAX; i++) {
        dist[i] = INF;
    }
    
    dist[start] = 0;
    queue[rear++] = start;
    
    while (front < rear) {
        int current = queue[front++];
        
        if (current == target) {
            return dist[current];
        }
        
        // Botão 1: soma 1
        int next = current + 1;
        if (next < MAX && dist[next] > dist[current] + 1) {
            dist[next] = dist[current] + 1;
            queue[rear++] = next;
        }
        
        // Botão 2: inverte número
        int reversed = 0;
        int temp = current;
        while (temp > 0) {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }
        
        if (reversed < MAX && dist[reversed] > dist[current] + 1) {
            dist[reversed] = dist[current] + 1;
            queue[rear++] = reversed;
        }
    }
    
    return -1;  // Nunca deve chegar aqui
}

int main() {
    int T, A, B;
    
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &A, &B);
        printf("%d\n", bfs(A, B));
    }
    
    return 0;
}