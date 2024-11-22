#include "funcoes.h"

void menu_listagem(lista_contas *lista_contas, lista_movim m)
{
    int opc;

    do
    {
        

        tela();
        gotoxy(15, 9);
        printf("1 - Consulta Geral de Contas Bancarias");
        gotoxy(15, 11);
        printf("2 - Consulta por Codigo da Conta Bancaria");
        gotoxy(15, 13);
        printf("3 - Consulta por Ordem de Codigo das Contas Bancarias");
        gotoxy(15, 15);
        printf("4 - Consulta por Ordem Alfabetica das Contas Bancarias");
        gotoxy(15, 17);
        printf("5 - Retornar ao Menu Anterior");


            opc = 0;
            limpar();
            printf("Digite sua opcao: ");
            scanf("%d", &opc);
            fflush(stdin);

            switch (opc)
            {
            case 1:
                listar_contas(lista_contas);
                break;
            case 2:
                consulta_codigo(lista_contas);
                break;
            case 3:
                // Ordem de codigo
                break;
            case 4:
                // Consulta ordem alfabetica
                break;
            case 5:
                return;
                break;
            default:
                sDefault();
                break;
            }

    } while (opc != 5);
}