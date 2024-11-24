#include "funcoes.h"

int conta_movimentacao(lista_movim *m) {
    tipoApontador_movim aux;
    int cont = 0;

    aux = m->primeiro;

    while (aux != NULL) {
        cont++;
        aux = aux->proximo;
    }

    return cont + 1;
}