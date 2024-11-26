#include "funcoes.h"

void movim_db_e_cd(lista_contas *lista_contas, lista_movim *m)
{
    tipoApontador_conta aux;
    tipoApontador_movim movim;
    tipoApontador_movim movim2;
    int sequencial;
    reg_contas reg_contas;
    reg_movimentos reg_movim;
    int tipo_movim = 0;
    char *data_validada;
    int opc;
    int resp;

    tela();
    if (lista_contas->primeiro == NULL)
    {
        limpar();
        printf("Nao ha contas cadastradas para movimentar!");
        getch();
        return;
    }
    while (1)
    {
        do
        {
            sequencial = conta_movimentacao(m);
            tela_movim();
            gotoxy(30, 6);
            printf("%d", sequencial);

            limpar();
            printf("Digite o codigo da conta ou [0] para sair: ");

            gotoxy(30, 7);
            scanf("%d", &reg_contas.codigo_conta);
            fflush(stdin);

            if (reg_contas.codigo_conta == 0)
            {
                return;
            }
            aux = pesquisa_conta(lista_contas, reg_contas);
            if (aux == NULL)
            {
                limpar();
                printf("Codigo nao encontrado!");
                getch();
            }

            if (aux->conteudo.status == 2) {
                limpar();
                printf("Contas inativadas nao podem fazer movimentacoes!");
                getch();
                continue;
            }
        } while (aux == NULL || reg_contas.codigo_conta != 0);

        
        do
        {
            reg_movim.codigo_conta = reg_contas.codigo_conta;
            gotoxy(30, 8);
            printf("%s", aux->conteudo.banco);

            gotoxy(30, 9);
            printf("%s", aux->conteudo.agencia);

            gotoxy(30, 10);
            printf("%s", aux->conteudo.numero_conta);

            gotoxy(30, 11);
            printf("%s", aux->conteudo.tipo_conta);

            gotoxy(30, 12);
            printf("%.2f", aux->conteudo.valor_saldo);

            gotoxy(30, 13);
            printf("%.2f", aux->conteudo.valor_limite);

            gotoxy(30, 14);
            printf("%.2f", aux->conteudo.valor_saldo + aux->conteudo.valor_limite);

            do
            {
                data_validada = validar_dt(m, reg_movim.codigo_conta);
                if (data_validada != NULL)
                {
                    strncpy(reg_movim.dt_movimento, data_validada, 10);
                    reg_movim.dt_movimento[10] = '\0';
                    free(data_validada);
                    break;
                }
            } while (1);
            do
            {
                limpar();
                printf("1 - Debito  //  2 - Credito");
                gotoxy(30, 17);
                printf("                          ");
                gotoxy(30, 17);
                scanf("%d", &tipo_movim);
                fflush(stdin);

                if (tipo_movim == 1)
                {
                    strcpy(reg_movim.tp_movimentacao, "Debito");
                    break;
                }
                else if (tipo_movim == 2)
                {
                    strcpy(reg_movim.tp_movimentacao, "Credito");
                    break;
                }
                limpar();
                printf("Opcao invalida! Digite 1 para Debito ou 2 para Credito");
                getch();
            } while (1);

            gotoxy(32, 17);
            printf("- %s", reg_movim.tp_movimentacao);

            limpar();
            printf("Digite o favorecido: ");
            gotoxy(30, 18);
            printf("                                 ");
            gotoxy(30, 18);
            fflush(stdin);
            fgets(reg_movim.favorecido, 30, stdin);

            do
            {
                float saldo_disp = aux->conteudo.valor_limite + aux->conteudo.valor_saldo;
                float novo_saldo;
                float novo_limite;
                limpar();
                printf("Digite o valor da movimentacao: ");
                gotoxy(30, 19);
                printf("                                        ");
                gotoxy(30, 19);
                scanf("%f", &reg_movim.valor_movimento);
                fflush(stdin);

                if (tipo_movim == 1)
                {
                    if (reg_movim.valor_movimento <= 0)
                    {
                        limpar();
                        printf("Erro, valor invalido!");
                        getch();
                    }
                    else if (reg_movim.valor_movimento > saldo_disp)
                    {
                        limpar();
                        printf("Erro, valor da movimentacao maior que seu saldo!");
                        getch();
                    }
                    else
                    {
                        novo_saldo = aux->conteudo.valor_saldo - reg_movim.valor_movimento;
                        reg_movim.valor_saldo = novo_saldo;
                        break;
                    }
                }
                else
                {
                    novo_saldo = aux->conteudo.valor_saldo + reg_movim.valor_movimento;
                    reg_movim.valor_saldo = novo_saldo;
                    break;
                }
            } while (1);

            gotoxy(30, 20);
            printf("%.2f", reg_movim.valor_saldo);

            do
            {
                limpar();
                printf("Deseja gravar a movimentacao? [1] Sim [2] Nao: ");
                scanf("%d", &opc);
                fflush(stdin);

                switch (opc)
                {
                case 1:
                    movim = (tipoApontador_movim)malloc(sizeof(tipoItem_movim));
                    movim->conteudo = reg_movim;
                    movim->proximo = NULL;
                    movim->anterior = NULL;
                    aux->conteudo.valor_saldo = reg_movim.valor_saldo;

                    if (m->primeiro == NULL)
                    {
                        m->primeiro = movim;
                        m->ultimo = movim;
                    }
                    else
                    {
                        m->ultimo->proximo = movim;
                        movim->anterior = m->ultimo;
                        m->ultimo = movim;
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
                printf("Deseja cadastrar outra movimentacao? [1] Sim [2] Nao: ");
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
            if (resp == 1)
            {
                break;
            }
        } while (1);
    }
}