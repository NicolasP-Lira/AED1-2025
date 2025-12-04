#include <stdio.h>

#define MAX 1000  // Espaço suficiente para todas as operações

int main() {
    int n, i, queue[MAX], inicio, fim;
    
    while (scanf("%d", &n) && n != 0) {
        if (n == 1) {
            printf("Discarded cards:\nRemaining card: 1\n");
            continue;
        }
        
        for (i = 1; i <= n; i++) 
            queue[i-1] = i;
        
        printf("Discarded cards: ");
        inicio = 0; 
        fim = n;
        
        while (fim - inicio > 1) {
            printf("%d", queue[inicio++]);
            if (fim - inicio > 1) 
                printf(", ");
            queue[fim++] = queue[inicio++];
        }
        
        printf("\nRemaining card: %d\n", queue[inicio]);
    }
    
    return 0;
}