#ifndef LISTA_H
#define LISTA_H
#include <stdlib.h>
#include <stdio.h>
#define MAX 5

typedef struct {

    int vetor [MAX];
    int inicio;
    int fim;

}Fila;

typedef struct {

    int vetor [MAX]; 
    int fim;

}Pilha;


int pop(Pilha *pilha);
int push(Pilha *pilha, int dados);
int removerNoInicio(Fila *fila);
int inserirNoFim(Fila *fila, int dados);
void inicializarPilha(Pilha *p);
void inicializar(Fila *f);
int moverFilaParaPilha(Pilha *p, Fila *f);
void imprimirPilha(Pilha *p);


void imprimir(Fila *f);

#endif