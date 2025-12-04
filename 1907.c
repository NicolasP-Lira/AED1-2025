#include <stdio.h>
#include <string.h>

#define MAX 1030

char grid[MAX][MAX];
int visited[MAX][MAX];
int N, M;

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// Estrutura para coordenadas
typedef struct {
    int x, y;
} Point;

Point queue[MAX * MAX];
int front, rear;

void bfs(int startX, int startY) {
    front = rear = 0;
    queue[rear++] = (Point){startX, startY};
    visited[startX][startY] = 1;
    
    while (front < rear) {
        Point current = queue[front++];
        
        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && 
                grid[nx][ny] == '.' && !visited[nx][ny]) {
                visited[nx][ny] = 1;
                queue[rear++] = (Point){nx, ny};
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++) {
        scanf("%s", grid[i]);
    }
    
    int clicks = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                clicks++;
                bfs(i, j);
            }
        }
    }
    
    printf("%d\n", clicks);
    
    return 0;
}