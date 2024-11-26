/*********************************************************************************
 Autores....: Augusto Gabriel Claro e Pedro Gerhard
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
*********************************************************************************/
#include "funcoes.h"

void carregar_contas(lista_contas *lista_contas, const char *name) {
    FILE *CONTAS = fopen(name, "rb");
    reg_contas reg_conta;
    tipoApontador_conta aux;

    if (CONTAS == NULL) {
        limpar();
        printf("Erro ao abrir lista de contas!");
        getch();
        return;
    }

    while (fread(&reg_conta, sizeof(reg_contas), 1, CONTAS) == 1) {
        aux = (tipoApontador_conta) malloc (sizeof(tipoItem_conta));

        aux->conteudo = reg_conta;
        aux->proximo = NULL;

        if (lista_contas->primeiro == NULL) {
            lista_contas->primeiro = aux;
            lista_contas->ultimo = aux;
        } else {
            lista_contas->ultimo->proximo = aux;
            lista_contas->ultimo = aux;
        }
    }

    fclose(CONTAS);
    limpar();
    printf("Lista de contas carregada com sucesso!");
    getch();
}