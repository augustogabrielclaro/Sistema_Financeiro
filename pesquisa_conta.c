/*********************************************************************************
 Autores....: Augusto Gabriel Claro e Pedro Gerhard
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
*********************************************************************************/
#include "funcoes.h"


tipoApontador_conta pesquisa_conta(lista_contas *lista_contas, reg_contas reg_contas) {
    tipoApontador_conta aux;
    aux = lista_contas->primeiro;

    while (aux != NULL) {
        if (aux->conteudo.codigo_conta == reg_contas.codigo_conta) {
            return aux;
        }
        aux = aux->proximo;
    }

    return NULL;
}