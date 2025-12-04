#include <stdio.h>

int main() {
    int v, t;
    
    // Lê até EOF
    while (scanf("%d %d", &v, &t) != EOF) {
        // Deslocamento = 2 * v * t
        printf("%d\n", 2 * v * t);
    }
    
    return 0;
}