#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void menu_movim(lista_contas *lista_contas, lista_movim m) {
    int opc;

    do {
        gotoxy(20, 10);
        printf("1 - Movimentacao de Debito e Credito");

        gotoxy(20, 12);
        printf("2 - Transferencia entre Contas Bancarias");

        gotoxy(20, 14);
        printf("3 - Consulta Movimentacoes Bancarias");

        gotoxy(20, 16);
        printf("4 - Retornar ao Menu Anterior");

        limpar();
        printf("Digite sua opcao: ");
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                // Movimentacao
                break;
            case 2:
                // Transferencia
                break;
            case 3:
                // Consulta de movimentacoes
                break;
            case 4:
                return;
                break;
            default:
                sDefault();
                break;
        }
    } while (opc != 4);
}