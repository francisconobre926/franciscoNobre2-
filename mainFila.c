#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Tamanho máximo da fila e pilha

// Estrutura para Fila
typedef struct {
    int itens[MAX];
    int frente, tras;
} Fila;

// Estrutura para Pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Função para inicializar a fila
void inicializarFila(Fila *f) {
    f->frente = 0;
    f->tras = -1;
}

// Função para enfileirar (inserir elemento na fila)
void enfileirar(Fila *f, int valor) {
    if (f->tras == MAX - 1) {
        printf("Fila cheia!\n");
    } else {
        f->itens[++f->tras] = valor;
    }
}

// Função para desenfileirar (remover elemento da fila)
int desenfileirar(Fila *f) {
    if (f->frente > f->tras) {
        printf("Fila vazia!\n");
        return -1;
    } else {
        return f->itens[f->frente++];
    }
}

// Função para inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Função para empilhar (inserir elemento na pilha)
void empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia!\n");
    } else {
        p->itens[++p->topo] = valor;
    }
}

// Função para mover dados da fila para a pilha
void moverFilaParaPilha(Fila *f, Pilha *p) {
    while (f->frente <= f->tras) {
        empilhar(p, desenfileirar(f));  // Passa o valor diretamente de desenfileirar para empilhar
    }
}

// Função para exibir a pilha
void exibirPilha(Pilha *p) {
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Fila fila;
    Pilha pilha;

    // Inicializar a fila e a pilha
    inicializarFila(&fila);
    inicializarPilha(&pilha);

    // Inserir elementos na fila
    enfileirar(&fila, 10);
    enfileirar(&fila, 20);
    enfileirar(&fila, 30);
    enfileirar(&fila, 40);

    printf("Movendo dados da fila para a pilha...\n");

    // Mover os elementos da fila para a pilha
    moverFilaParaPilha(&fila, &pilha);
    
    // Exibir a pilha resultante
    exibirPilha(&pilha);

    return 0;
}