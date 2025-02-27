/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void menu_movim(lista_contas *lista_contas, lista_movim *m) {
    int opc;

    do {
        tela();
        opc = 0;
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
        fflush(stdin);

        switch (opc) {
            case 1:
                // Movimentacao
                system("cls");
                movim_db_e_cd(lista_contas, m);
                break;
            case 2:
                // Transferencia
                system("cls");
                transf_entre_contas(lista_contas, m);
                break;
            case 3:
                // Listar
                listar_movim(lista_contas, m);
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