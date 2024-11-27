/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
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