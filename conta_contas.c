/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

int conta_contas(lista_contas *lista_contas) {
    tipoApontador_conta aux;
    int cont = 0;

    aux = lista_contas->primeiro;
    while (aux != NULL) {
        cont++;
        aux = aux->proximo;
    }

    return cont;
}