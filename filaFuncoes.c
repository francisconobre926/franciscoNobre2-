#include "fila.h"

int tamanho(FILA *f){
    return f->qtd;
}

void inicializar(FILA *fila) {
    if (fila == NULL) {  // Verificar se o ponteiro é nulo
        printf("Fila nula!\n");
        exit(1);     // Retornar código de erro
    }
    fila->inicio=0;    // Inicializar o índice de início
    fila->final=0;     // Inicializar o índice de final
    fila->qtd = 0;       // Inicializar a fila com quantidade zero
    printf("Fila inicializada com sucesso. Quantidade: %d\n", fila->qtd);

               // Retorno 0 para indicar sucesso
}


int fila_cheia(FILA *F){

    if (F==NULL)
        return -1;
    if(F->qtd==MAX){
         return 1;
    }else{
        return 0;
    }

}

int fila_vazia(FILA *f){
    if(f==NULL)
        return -1;
    
    if(f->qtd==0){
        return 1;
    }
    return 0;
}

FILA* inserirNoFinal(FILA *f, int num[]) {
    if (f == NULL) {
        return NULL; // Retorna NULL para indicar erro
    }

    if (fila_cheia(f) == 1) {
        return NULL; // Retorna NULL se a fila estiver cheia
    }

    // Copia os elementos do array num para a posição final da fila
    for (int i = 0; i < MAX; i++) {
        f->dados[f->final+1]= num[i];
    }

    f->final = (f->final + 1) % MAX; // Atualiza o índice final
    f->qtd++; // Incrementa a quantidade de elementos na fila
    return f; // Retorna a fila atualizada
}


FILA* removerNoInicio(FILA *f){
    
    if(fila_vazia(f) || f==NULL){
        return NULL;
    }

    f->dados[f->inicio]=f->dados[f->inicio+1]; 
    f->qtd--;

    return f->dados[f->inicio];

}



void imprimirDADOS(FILA *f) {
    if (f == NULL || fila_vazia(f)) {
        printf("Fila vazia ou inexistente.\n");
        return;
    }
        for(int i=0; i<f->qtd; i++){
            printf(" %d | \n",f->dados[i]);
        }        
}