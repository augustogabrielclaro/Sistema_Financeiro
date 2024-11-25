#include "funcoes.h"

int contar_movimentacao_conta(lista_movim *m, int codigo) {
    int cont = 0;
    tipoApontador_movim q;
    q = m->primeiro;

    while (q != NULL) {
        if (q->conteudo.codigo_conta == codigo) {
            cont++;
        }
        q = q->proximo;
    }

    return cont;
}