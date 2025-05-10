#include "mover.h"

void inicializar(Fila *f){
    f->fim=0;
}

void inicializarPilha(Pilha *p){
    p->fim=0;
}

int inserirNoFim(Fila *fila, int dados){


    fila->vetor[fila->fim]=dados;
    fila->fim++;

    return dados;
}

int removerNoInicio(Fila *fila){
   
    int removido=fila->vetor[0];
    for(int i=0; i<fila->fim; i++){
        fila->vetor[i]=fila->vetor[i+1];
    }

    fila->fim--;
    return removido;
}

int push(Pilha *pilha, int dados){

    pilha->vetor[pilha->fim]=dados;
    pilha->fim++;

    return dados;
}

int pop(Pilha *pilha){
    
    int removido=pilha->vetor[pilha->fim];
    pilha->fim--;

    return removido;
}

int moverFilaParaPilha(Pilha *p, Fila *f){
    
    for(int i=f->fim; i>0; i--){
       
        push(p,removerNoInicio(f));
        
    }

        return 1;
}

void imprimir(Fila *f){
    for (int i=0; i<f->fim; i++){
        printf("%d | ", f->vetor[i]);
    }

    printf("\n\n");
}


void imprimirPilha(Pilha *p){

    for (int i=0; i<MAX; i++){
        printf("%d | ", p->vetor[i]);
    }

    printf("\n\n");
}
