#include "funcoes.h"

tipoApontador_movim pesquisa_movim(lista_movim *m, int codigo) {
    tipoApontador_movim aux = m->primeiro;

    while (aux != NULL) {
        if (aux->conteudo.codigo_conta == codigo) {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}