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