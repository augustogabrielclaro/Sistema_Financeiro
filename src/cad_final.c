#include "C:\Users\augus\Documents\Projeto\trabalho_final\include\funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void cad_final(lista_contas *lista_contas)
{
    reg_contas reg_contas;
    tipoApontador_conta p;
    int opc;
    int resp;
    do
    {
        opc = 0;

        tela();
        tela_contas();
        gotoxy(25, 3);
        printf("                                          ");
        gotoxy(33, 3);
        printf("CADASTRO NO FINAL");
        gotoxy(7, 23);
        printf("Digite o codigo 0 para sair!");

        // Leitura do codigo
        gotoxy(25, 6);
        scanf("%d", &reg_contas.codigo_conta);
        if (reg_contas.codigo_conta == 0)
        {
            return;
        }
        // Leitura do nome
        gotoxy(25, 8);
        fflush(stdin);
        fgets(reg_contas.banco, 50, stdin);

        // Leitura da agência
        gotoxy(25, 10);
        fflush(stdin);
        fgets(reg_contas.agencia, 10, stdin);

        // Leitura do numero da conta
        gotoxy(25, 12);
        fflush(stdin);
        fgets(reg_contas.numero_conta, 20, stdin);

        // Leitura do tipo da conta
        gotoxy(25, 14);
        fflush(stdin);
        fgets(reg_contas.tipo_conta, 20, stdin);

        // Leitura do saldo
        gotoxy(25, 16);
        scanf("%f", &reg_contas.valor_saldo);
        getchar();

        // Leitura do limite total
        gotoxy(25, 18);
        scanf("%f", &reg_contas.valor_limite);
        getchar();

        // Leitura do status da conta
        gotoxy(25, 20);
        fflush(stdin);
        fgets(reg_contas.status, 10, stdin);

        do
        {
            gotoxy(7, 23);
            printf("Deseja gravar no sistema? [1] Sim [2] Nao: ");
            scanf("%d", &opc);
            fflush(stdin);

            switch (opc)
            {
            case 1:
                p = (tipoApontador_conta)malloc(sizeof(tipoItem_conta));
                p->conteudo = reg_contas;
                p->proximo = NULL;

                if (lista_contas->primeiro == NULL)
                {
                    lista_contas->primeiro = p;
                    lista_contas->ultimo = p;
                }
                else
                {
                    lista_contas->ultimo->proximo = p;
                    lista_contas->ultimo = p;
                }
                break;

            case 2:
                break;
            default:
                sDefault();
                break;
            }

        } while (opc != 1 && opc != 2);

        do
        {
            limpar();
            printf("Deseja cadastrar outro? [1] Sim [2] Nao: ");
            scanf("%d", &resp);
            fflush(stdin);

            switch (resp) {
                case 1:
                    break;
                case 2:
                    return;
                    break;
                default:
                    sDefault();
                    break;
            }

        } while (resp != 1 && resp != 2);

    } while (resp != 2);
}