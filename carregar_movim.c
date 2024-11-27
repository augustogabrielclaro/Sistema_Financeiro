/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void carregar_movim(lista_movim *m, const char *name) {
    FILE *MOVIM = fopen(name, "rb");
    reg_movimentos reg_mov;
    tipoApontador_movim movim = NULL;
    tipoApontador_movim anterior = NULL;

    m->primeiro = NULL;
    m->ultimo = NULL;

    if (MOVIM == NULL) {
        limpar();
        printf("Erro ao abrir arquivo de movimentacoes!");
        getch();
        return;
    }

    while (fread(&reg_mov, sizeof(reg_movimentos), 1, MOVIM) == 1) {
        movim = (tipoApontador_movim) malloc (sizeof(tipoItem_movim));
        if (movim == NULL) {
            limpar();
            printf("Erro ao alocar memoria!");
            fclose(MOVIM);
            return;
        }

        movim->conteudo = reg_mov;
        movim->proximo = NULL;
        movim->anterior = NULL;

        if (m->primeiro == NULL) {
            m->primeiro = movim;
        } else {
            m->ultimo->proximo = movim;
            movim->anterior = m->ultimo;
        }

        m->ultimo = movim;
    }

    fclose(MOVIM);
    limpar();
    printf("Lista de movimentacoes carregada com sucesso!");
    getch();
}