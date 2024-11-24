#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void menu_cadastro(lista_contas *lista_contas, lista_movim *m)
{
    int opc2;
    do
    {
        tela();
        gotoxy(20, 3);
        printf("MENU DE CADASTRO / REMOCAO DE CONTAS");
        gotoxy(17, 5);
        printf("[1] Cadastrar no final da lista das contas");
        gotoxy(17, 7);
        printf("[2] Cadastrar no inicio da lista das contas");
        gotoxy(17, 9);
        printf("[3] Cadastrar em uma posicao da lista de contas");
        gotoxy(17, 11);
        printf("[4] Remover do final da lista das contas");
        gotoxy(17, 13);
        printf("[5] Remover do inicio da lista das contas ");
        gotoxy(17, 15);
        printf("[6] Remover de uma posicao da lista das contas ");
        gotoxy(17, 17);
        printf("[7] Alterar contas cadastradas ");
        gotoxy(17, 19);
        printf("[8] Listar contas cadastradas ");
        gotoxy(17, 21);
        printf("[9] Voltar ao menu principal ");
        gotoxy(7, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opc2);
        fflush(stdin);

        switch (opc2)
        {
        case 1:
            cad_final(lista_contas);
            break;
        case 2:
            cad_inicio(lista_contas);
            break;
        case 3:
            cad_posicao(lista_contas);
            break;
        case 4:
            remover_final(lista_contas, m);
            break;
        case 5:
            remover_inicio(lista_contas, m);
            break;
        case 6:
            remover_codigo(lista_contas, m);
            break;
        case 8:
            menu_listagem(lista_contas, m);
            break;
        case 9:
            return;
            break;
        default:
            sDefault();
            break;
        }
    } while (opc2 != 9);
}