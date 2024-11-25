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