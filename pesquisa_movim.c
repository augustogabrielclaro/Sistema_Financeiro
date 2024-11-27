/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
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