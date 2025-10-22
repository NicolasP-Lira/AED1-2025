#include <stdio.h>
#include <stdlib.h>

// Função para merge (junção) do Merge Sort
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Arrays temporários
    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));
    
    // Copia dados para os arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Merge dos arrays temporários de volta para arr[left..right]
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid, right);
    }
}

// Função wrapper para facilitar o uso
void ordenar(int n, int v[]) {
    mergeSort(v, 0, n - 1);
}

int main() {
    int NC;
    
    scanf("%d", &NC);
    
    for (int caso = 0; caso < NC; caso++) {
        int N;
        scanf("%d", &N);
        
        int *alturas = malloc(N * sizeof(int));
        for (int i = 0; i < N; i++) {
            scanf("%d", &alturas[i]);
        }
        
        ordenar(N, alturas);
        
        for (int i = 0; i < N; i++) {
            printf("%d", alturas[i]);
            if (i < N - 1) printf(" ");
        }
        printf("\n");
        
        free(alturas);
    }
    
    return 0;
}
