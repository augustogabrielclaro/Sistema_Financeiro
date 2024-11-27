/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void cad_inicio(lista_contas *lista_contas)
{
    reg_contas reg_contas;
    tipoApontador_conta p;
    tipoApontador_conta aux;
    int opc;
    int resp;
    int tipo;
    do
    {
        opc = 0;

        do
        {
            tela();
            tela_contas();
            gotoxy(25, 3);
            printf("                                          ");
            gotoxy(33, 3);
            printf("CADASTRO NO INICIO");
            gotoxy(7, 23);
            printf("Digite o codigo 0 para sair!");

            // Leitura do codigo
            gotoxy(25, 6);
            scanf("%d", &reg_contas.codigo_conta);

            aux = pesquisa_conta(lista_contas, reg_contas);

            if (aux != NULL)
            {
                limpar();
                printf("Codigo %d ja cadastrado! Digite outro codigo!", reg_contas.codigo_conta);
                getch();
            }
            if (reg_contas.codigo_conta == 0)
            {
                return;
            }
        } while (aux != NULL && reg_contas.codigo_conta != 0);
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
        do {
            limpar();
            printf("[1] Poupanca  [2] Corrente  [3] Cartao de Credito");
            gotoxy(25, 14);
            scanf("%d", &tipo);
            fflush(stdin);

            if (tipo == 1) {
                strcpy(reg_contas.tipo_conta, "Poupanca");
                break;
            } else if (tipo == 2) {
                strcpy(reg_contas.tipo_conta, "Corrente");
                break;
            } else if (tipo == 3) {
                strcpy(reg_contas.tipo_conta, "Cartao Credito");
                break;
            } else {
                limpar();
                printf("Opcao invalida!");
                getch();
            }
        } while (1);
        
        gotoxy(27, 14);
        printf("- %s", reg_contas.tipo_conta);
        
        limpar();
        // Leitura do saldo
        gotoxy(25, 16);
        scanf("%f", &reg_contas.valor_saldo);
        getchar();

        // Leitura do limite total
        gotoxy(25, 18);
        scanf("%f", &reg_contas.valor_limite);
        getchar();

        // Leitura do status da conta
        do {
            limpar();
            printf("[1] Ativa  [2] Inativa");
            gotoxy(25, 20);
            scanf("%d", &reg_contas.status);
            fflush(stdin);
        } while (reg_contas.status != 1 && reg_contas.status != 2);

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
                    p->proximo = lista_contas->primeiro;
                    lista_contas->primeiro = p;
                    if (lista_contas->ultimo == NULL)
                    {
                        lista_contas->ultimo = lista_contas->primeiro;
                    }
                }
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

            switch (resp)
            {
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