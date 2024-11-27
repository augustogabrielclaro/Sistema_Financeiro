/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void remover_codigo(lista_contas *lista_contas, lista_movim *m)
{
    tipoApontador_conta p;
    tipoApontador_conta r;
    tipoApontador_conta aux;
    reg_contas reg_contas;
    int resp_i = 0;
    int resp = 0;   

    tela();
    gotoxy(20, 3);
    printf("                                                     ");
    gotoxy(28, 3);
    printf("REMOCAO POR CODIGO");

    // Caso não haja nenhuma conta
    if (lista_contas->primeiro == NULL)
    {
        limpar();
        printf("Nao ha nenhuma conta cadastrada!");
        getch();
        return;
    }

    // Caso haja somente uma
    if (lista_contas->primeiro->proximo == NULL)
    {

        do
        {
            p = lista_contas->primeiro;
            exibir_unica_conta(p);
            gotoxy(28, 3);
            printf("REMOCAO POR CODIGO");
            limpar();
            printf("Deseja realmente remover esta conta? [1] Sim [2] Nao: ");
            scanf("%d", &resp);

            switch (resp)
            {
            case 1:
                if (contar_movimentacao_conta(m, p->conteudo.codigo_conta) != 0)
                {
                    limpar();
                    printf("A conta nao pode ser excluida, pois tem movimentacoes!");
                    getch();
                    do {
                        limpar();
                        printf("Deseja deixar ela inativada? [1] Sim [2] Nao: ");
                        scanf("%d", &resp_i);
                        fflush(stdin);
                        if (resp_i == 1) {
                            p->conteudo.status = 2;
                            limpar();
                            printf("Conta inativada com Sucesso!");
                            getch();
                            break;
                        } else if (resp_i == 2) {
                            break;
                        } else {
                            limpar();
                            printf("Opcao invalida!");
                            getch();
                        }
                    } while (1);
                    return;
                }
                else
                {
                    free(lista_contas->primeiro);
                    lista_contas->primeiro = NULL;
                    lista_contas->ultimo = NULL;
                    limpar();
                    printf("Conta removida com sucesso!");
                    getch();
                    return;
                }
                break;
            case 2:
                return;
                break;
            default:
                sDefault();
                break;
            }
        } while (resp != 1 && resp != 2);
    }

    // Mais de uma conta
    do
    {
        limpar();
        printf("Digite o codigo a ser removido ou [0] para sair: ");
        scanf("%d", &reg_contas.codigo_conta);

        if (reg_contas.codigo_conta == 0)
        {
            return;
        }

        aux = pesquisa_conta(lista_contas, reg_contas);

        if (aux == NULL)
        {
            limpar();
            printf("Codigo nao encontrado!");
        }
    } while (aux == NULL);


    do
    {
        exibir_unica_conta(aux);
        gotoxy(28, 3);
        printf("REMOCAO POR CODIGO");
        limpar();
        printf("Deseja realmente remover esta conta? [1] Sim [2] Nao: ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                if (contar_movimentacao_conta(m, reg_contas.codigo_conta) > 0) {
                    limpar();
                    printf("A conta nao pode ser excluida, pois tem movimentacoes!");
                    getch();
                    do {
                        limpar();
                        printf("Deseja deixar ela inativada? [1] Sim [2] Nao: ");
                        scanf("%d", &resp_i);
                        fflush(stdin);
                        if (resp_i == 1) {
                            p->conteudo.status = 2;
                            limpar();
                            printf("Conta inativada com Sucesso!");
                            getch();
                            break;
                        } else if (resp_i == 2) {
                            break;
                        } else {
                            limpar();
                            printf("Opcao invalida!");
                            getch();
                        }
                    } while (1);
                    return;
                }

                if (aux == lista_contas->primeiro) {
                    lista_contas->primeiro = aux->proximo;
                    free(aux);
                    limpar();
                    printf("Conta removida com sucesso!");
                    getch();
                    return;
                }

                r = lista_contas->primeiro;
                while (r->proximo != aux) {
                    r = r->proximo;
                }
                p = aux->proximo;

                r->proximo = p;
                free(aux);
                limpar();
                printf("Conta removida com sucesso!");
                getch();
                return;
                break;
            case 2:
                return;
                break;
            default:
                sDefault();
                break;
        }
    } while (resp != 1 && resp != 2);
}