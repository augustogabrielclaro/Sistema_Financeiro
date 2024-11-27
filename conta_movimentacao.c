/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
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