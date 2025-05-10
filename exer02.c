#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Tamanho máximo da pilha

// Estrutura da Pilha
typedef struct {
    int itens[MAX];
    int topo;
} Pilha;

// Inicializar a pilha
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// Verificar se a pilha está vazia
int estaVazia(Pilha *p) {
    return p->topo == -1;
}

// Inserir elemento na pilha (empilhar)
void empilhar(Pilha *p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia!\n");
    } else {
        p->itens[++p->topo] = valor;
    }
}

// Remover elemento do topo da pilha (desempilhar)
int desempilhar(Pilha *p) {
    if (estaVazia(p)) {
        printf("Pilha vazia!\n");
        return -1;  // Retorno de erro
    } else {
        return p->itens[p->topo--];
    }
}

// Função para remover o valor máximo da pilha
void removerMaximo(Pilha *p) {
    if (estaVazia(p)) {
        printf("A pilha está vazia, nada a remover.\n");
        return;
    }

    // Encontrar o valor máximo e sua posição
    int maxValor = p->itens[p->topo];
    int posicaoMax = p->topo;
    
    for (int i = p->topo; i >= 0; i--) {
        if (p->itens[i] > maxValor) {
            maxValor = p->itens[i];
            posicaoMax = i;
        }
    }

    // Remover o valor máximo mantendo os outros elementos
    Pilha temp;
    inicializarPilha(&temp);

    // Desempilha até chegar à posição do valor máximo e salva em uma pilha temporária
    while (p->topo >= posicaoMax) {
        empilhar(&temp, desempilhar(p));
    }

    // Desempilhar o valor máximo (não será colocado de volta)
    desempilhar(p);

    // Recolocar os elementos na pilha original, exceto o máximo removido
    while (!estaVazia(&temp)) {
        empilhar(p, desempilhar(&temp));
    }

    printf("O valor máximo %d foi removido.\n", maxValor);
}

// Exibir elementos da pilha
void exibirPilha(Pilha *p) {
    printf("Pilha: ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->itens[i]);
    }
    printf("\n");
}

int main() {
    Pilha pilha;
    inicializarPilha(&pilha);

    // Inserir elementos na pilha
    empilhar(&pilha, 10);
    empilhar(&pilha, 25);
    empilhar(&pilha, 100);
    empilhar(&pilha, 40);
    empilhar(&pilha, 15);

    printf("Pilha antes de remover o maximo:\n");
    exibirPilha(&pilha);

    // Remover o valor máximo da pilha
    removerMaximo(&pilha);

    printf("Pilha apos remover o maximo:\n");
    exibirPilha(&pilha);

    return 0;
}
