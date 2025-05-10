#ifndef FILA_H
#define FILA_H

#include <stdlib.h>
#include <stdio.h>

#define MAX 5

// Estrutura para armazenar os registros da fila


// Estrutura da fila
typedef struct fila {
    int qtd;               // Quantidade de elementos na fila
    int inicio;            // Índice do início da fila
    int final;             // Índice do final da fila
    int dados[MAX];    // Array de registros
} FILA;


// Protótipos das funções
int fila_cheia(FILA *f);
int fila_vazia(FILA *f);
FILA* inserirNoFinal(FILA *f, int num[]);
FILA* removerNoInicio(FILA *f);
int tamanho(FILA *f);
void imprimirDADOS(FILA *f);
int iniciliazar(FILA *f);

#endif