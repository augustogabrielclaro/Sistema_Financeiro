#include "funcoes.h"

tipoApontador_movim buscar_ultima_dt(lista_movim *m, int codigo) {
    tipoApontador_movim aux = m->primeiro;

    if (aux != NULL) {
        while (aux->anterior != NULL) {
            if (aux->conteudo.codigo_conta == codigo) {
                return aux;
            }
            aux = aux->anterior;
        }
    }
    return NULL;
}