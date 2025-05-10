#include "fila.h"


int main() {
    
    FILA f;

    int num1[] = {2, 3, 9, 2, 5};
    int num2[] = {1, 5, 9, 8, 5};
    int num3[] = {1, 3, 9, 2, 5};
    int num4[] = {1, 3, 9, 2, 5};

    // Inicializa a fila
    printf("chegou aqui\n");
    iniciliazar(&f);
    printf("Quantidade inicial na fila: %d\n", &f.qtd);

    // Insere os arrays na fila
    inserirNoFinal(&f, num1);
    inserirNoFinal(&f, num2);
    inserirNoFinal(&f, num3);
    inserirNoFinal(&f, num4);
    

    // Imprime os dados da fila
    imprimirDADOS(&f);

    // Libera a memória alocada para a fila
    free(&f);

    return 0;
}