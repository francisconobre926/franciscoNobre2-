#include "mover.h"


int main(){
    
    Pilha p;
    Fila f;
    inicializar(&f);
    inicializarPilha(&p);

    printf("==============inserindo no fim============\n");
    inserirNoFim(&f, 2);
    inserirNoFim(&f, 9);
    inserirNoFim(&f, 6);
    inserirNoFim(&f, 1);

    imprimir(&f);

    printf("==============removendo no inicio============\n");
    removerNoInicio(&f);
    imprimir(&f);



    // printf("==============movendo fila para pilha ============\n");
    // moverFilaParaPilha(&p,&f);
    
    push(&p,3);
    push(&p,4);
    push(&p,9);
    push(&p,1);
    push(&p,8);

    pop(&p);
    pop(&p);
    // pop(&p);
    // pop(&p);
    
    imprimirPilha(&p);
    printf("fim pilha: %d\n", p.fim);
    printf("fim fila: %d\n", f.fim);


    return 0;
}
