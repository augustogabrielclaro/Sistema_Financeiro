/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void salvar_movim(lista_movim *m, const char *name) {
    FILE *MOVIM = fopen(name, "wb");
    tipoApontador_movim mov = m->primeiro;

    if (MOVIM == NULL) {
        limpar();
        printf("Erro ao salvar lista de movimentacoes!");
        getch();
        return;
    }
    while (mov != NULL) {
        fwrite(&mov->conteudo, sizeof(reg_movimentos), 1, MOVIM);
        mov = mov->proximo;
    }

    fclose(MOVIM);
    limpar();
    printf("Lista de movimentacoes salva com sucesso!");
    getch();
}