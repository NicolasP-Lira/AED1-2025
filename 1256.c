#include <stdio.h>
#include <stdlib.h>

int funcaoHash(int chave, int TAM) {
  return chave % TAM;
}

typedef struct no {
  int chave;
  struct no* prox;
} No;

typedef struct Lista {
  No* inicio;
  int tam;
} Lista;

void iniciaLista(Lista* l) {
  l->inicio = NULL;
  l->tam = 0;
}

void inserirLista(Lista* l, int valor) {
  No* novoNo = (No*)malloc(sizeof(No));
  novoNo->chave = valor;
  novoNo->prox = NULL;

  if (l->inicio == NULL) {
    l->inicio = novoNo;
  } else {
    No* atual = l->inicio;
    while (atual->prox != NULL) {
      atual = atual->prox;
    }
    atual->prox = novoNo;
  }

  l->tam++;
}

void imprimirLista(Lista* l) {
  No* aux = l->inicio;
  while (aux != NULL) {
    printf("%d -> ", aux->chave);
    aux = aux->prox;
  }
  printf("\\\n");
}

void iniciaTabelaLista(Lista t[], int TAM) {
  int i;
  for (i = 0; i < TAM; i++) {
    iniciaLista(&t[i]); // posição vazia
  }
}

void inserirElementos(Lista t[], int TAM, int M) {
  int valor, i;
  for (i = 0; i < M; i++) {
    scanf("%d", &valor);
    int id = funcaoHash(valor, TAM);
    inserirLista(&t[id], valor);
  }
}

void imprimirTabela(Lista t[], int TAM) {
  int i;
  for (i = 0; i < TAM; i++) {
    printf("%d -> ", i);
    imprimirLista(&t[i]);
  }
}

int main() {
  int testes, C, M, i;

  scanf("%d", &testes);

  for (i = 0; i < testes; i++) {
    scanf("%d %d", &C, &M);

    Lista tabela[C];
    iniciaTabelaLista(tabela, C);
    inserirElementos(tabela, C, M);
    imprimirTabela(tabela, C);

    if (i < testes - 1) {
      printf("\n");
    }
  }

  return 0;
}
