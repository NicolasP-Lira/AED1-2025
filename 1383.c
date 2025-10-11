#include <stdio.h>

int main() {
    int n, instancia;
    scanf("%d", &n);
    
    for (instancia = 1; instancia <= n; instancia++) {
        int sudoku[9][9];
        int valido = 1;
        
        // Leitura rápida
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }
        
        // Verifica linhas
        for (int i = 0; i < 9 && valido; i++) {
            int mask = 0;
            for (int j = 0; j < 9; j++) {
                int num = sudoku[i][j];
                if (num < 1 || num > 9 || (mask & (1 << num))) {
                    valido = 0;
                    break;
                }
                mask |= (1 << num);
            }
        }
        
        // Verifica colunas
        for (int j = 0; j < 9 && valido; j++) {
            int mask = 0;
            for (int i = 0; i < 9; i++) {
                int num = sudoku[i][j];
                if (num < 1 || num > 9 || (mask & (1 << num))) {
                    valido = 0;
                    break;
                }
                mask |= (1 << num);
            }
        }
        
        // Verifica blocos 3x3
        for (int bloco = 0; bloco < 9 && valido; bloco++) {
            int mask = 0;
            int start_i = (bloco / 3) * 3;
            int start_j = (bloco % 3) * 3;
            
            for (int i = start_i; i < start_i + 3; i++) {
                for (int j = start_j; j < start_j + 3; j++) {
                    int num = sudoku[i][j];
                    if (num < 1 || num > 9 || (mask & (1 << num))) {
                        valido = 0;
                        break;
                    }
                    mask |= (1 << num);
                }
                if (!valido) break;
            }
        }
        
        printf("Instancia %d\n", instancia);
        printf(valido ? "SIM\n\n" : "NAO\n\n");
    }
    
    return 0;
}
