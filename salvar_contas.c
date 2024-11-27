/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void salvar_contas(lista_contas *lista_contas, const char *name) {
    FILE *CONTAS = fopen(name, "wb");
    tipoApontador_conta aux = lista_contas->primeiro;

    if (CONTAS == NULL) {
        limpar();
        printf("Erro ao salvar lista de contas!");
        getch();
        return;
    }

    while (aux != NULL) {
        fwrite(&aux->conteudo, sizeof(reg_contas), 1, CONTAS);
        aux = aux->proximo;
    }

    fclose(CONTAS);
    limpar();
    printf("Lista de contas salva com sucesso!");
    getch();
}