/*********************************************************************************
 Autores....: Augusto Gabriel Claro e Pedro Gerhard
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
*********************************************************************************/
#include "funcoes.h"

void transf_entre_contas(lista_contas *lista_contas, lista_movim *m)
{
    tipoApontador_conta aux;
    tipoApontador_conta aux2;
    tipoApontador_movim movim;
    tipoApontador_movim movim2;
    reg_contas reg_conta;
    reg_contas reg_conta2;
    reg_movimentos reg_movim;
    reg_movimentos reg_movim2;
    char *data_validada;
    int opc;
    int resp;
    float valor = 0;
    float saldo_total = 0;
    float saldo_total2 = 0;
    float novo_saldo;
    float novo_saldo2;
    tela_transf();
    if (lista_contas->primeiro == NULL)
    {
        limpar();
        printf("Nao ha contas cadastradas!");
        getch();
        return;
    }
    else if (lista_contas->primeiro->proximo == NULL)
    {
        limpar();
        printf("Pelo menos duas contas necessitam ser cadastradas!");
        getch();
        return;
    }

    tela_transf();
    do
    {
        limpar();
        printf("Digite a conta de origem ou [0] para sair: ");
        gotoxy(20, 8);
        printf("            ");
        gotoxy(20, 8);
        scanf("%d", &reg_conta.codigo_conta);

        if (reg_conta.codigo_conta == 0)
        {
            return;
        }

        aux = pesquisa_conta(lista_contas, reg_conta);

        if (aux == NULL)
        {
            limpar();
            printf("Conta nao encontrada!");
            getch();
        }

        if (aux->conteudo.status == 2)
        {
            limpar();
            printf("Contas inativadas nao podem fazer movimentacoes!");
            getch();
            continue;
        }

        if (aux != NULL)
        {
            break;
        }
    } while (1);

    do
    {
        limpar();
        printf("Digite a conta de destino ou [0] para sair: ");
        gotoxy(59, 8);
        printf("            ");
        gotoxy(59, 8);
        scanf("%d", &reg_conta2.codigo_conta);

        if (reg_conta2.codigo_conta == 0)
        {
            return;
        }

        if (reg_conta2.codigo_conta == reg_conta.codigo_conta)
        {
            limpar();
            printf("A conta nao pode ser a mesma!");
            getch();
            continue;
        }

        aux2 = pesquisa_conta(lista_contas, reg_conta2);

        if (aux2 == NULL)
        {
            limpar();
            printf("Conta nao encontrada!");
            getch();
        }

        if (aux2->conteudo.status == 2)
        {
            limpar();
            printf("Contas inativadas nao podem fazer movimentacoes!");
            getch();
            continue;
        }

        if (aux2 != NULL)
        {
            break;
        }
    } while (1);


    reg_movim.codigo_conta = aux->conteudo.codigo_conta;
    reg_movim2.codigo_conta = aux2->conteudo.codigo_conta;
    // Conta origem
    gotoxy(20, 9);
    printf("%s", aux->conteudo.banco);
    gotoxy(20, 10);
    printf("%s", aux->conteudo.agencia);
    gotoxy(20, 11);
    printf("%s", aux->conteudo.numero_conta);
    gotoxy(20, 12);
    printf("%s", aux->conteudo.tipo_conta);
    gotoxy(20, 13);
    printf("%.2f", aux->conteudo.valor_saldo);
    gotoxy(20, 14);
    printf("%.2f", aux->conteudo.valor_limite);
    gotoxy(20, 15);
    printf("%.2f", aux->conteudo.valor_saldo + aux->conteudo.valor_limite);
    saldo_total = aux->conteudo.valor_saldo + aux->conteudo.valor_limite;
    // Conta destino
    gotoxy(59, 9);
    printf("%s", aux2->conteudo.banco);
    gotoxy(59, 10);
    printf("%s", aux2->conteudo.agencia);
    gotoxy(59, 11);
    printf("%s", aux2->conteudo.numero_conta);
    gotoxy(59, 12);
    printf("%s", aux2->conteudo.tipo_conta);
    gotoxy(59, 13);
    printf("%.2f", aux2->conteudo.valor_saldo);
    gotoxy(59, 14);
    printf("%.2f", aux2->conteudo.valor_limite);
    gotoxy(59, 15);
    printf("%.2f", aux2->conteudo.valor_saldo + aux2->conteudo.valor_limite);
    saldo_total2 = aux2->conteudo.valor_saldo + aux2->conteudo.valor_limite;

    do
    {
        novo_saldo = 0;
        novo_saldo2 = 0;
        limpar();
        printf("Digite o valor da transferencia ou [0] para sair: ");
        gotoxy(42, 18);
        printf("                 ");
        gotoxy(42, 18);
        scanf("%f", &valor);

        if (valor < 0)
        {
            limpar();
            printf("Digite um valor valido!");
            getch();
        } else if (valor == 0) {
            return;
        }
        else if (valor > saldo_total)
        {
            limpar();
            printf("O valor e maior que seu saldo total!");
            getch();
        }
        else
        {
            novo_saldo = aux->conteudo.valor_saldo - valor;
            reg_movim.valor_movimento = valor;
            reg_movim.valor_saldo = novo_saldo;

            reg_movim2.valor_movimento = valor;
            novo_saldo2 = reg_movim2.valor_movimento + aux2->conteudo.valor_saldo;
            reg_movim2.valor_saldo = novo_saldo2;
            gotoxy(20, 16);
            printf("%.2f", reg_movim.valor_saldo);

            gotoxy(59, 16);
            printf("%.2f", reg_movim2.valor_saldo);
            break;
        }
    } while (1);
    do
    {
        data_validada = validar_dt_transf(m, aux->conteudo.codigo_conta, aux2->conteudo.codigo_conta);
        if (data_validada != NULL)
        {
            strncpy(reg_movim.dt_movimento, data_validada, 10);
            reg_movim.dt_movimento[10] = '\0';

            strncpy(reg_movim2.dt_movimento, data_validada, 10);
            reg_movim2.dt_movimento[10] = '\0';

            free(data_validada);
            break;
        }
    } while (1);

    do
    {
        limpar();
        printf("Deseja gravar a movimentacao? [1] Sim [2] Nao: ");
        fflush(stdin);
        scanf("%d", &opc);

        if (opc == 1)
        {
            movim = (tipoApontador_movim)malloc(sizeof(tipoItem_movim));
            movim2 = (tipoApontador_movim)malloc(sizeof(tipoItem_movim));
            strcpy(reg_movim.tp_movimentacao, "Debito");
            strcpy(reg_movim2.tp_movimentacao, "Credito");

            strcpy(reg_movim.favorecido, "Transferencia");
            strcpy(reg_movim2.favorecido, "Transferencia");

            aux->conteudo.valor_saldo = novo_saldo;
            aux2->conteudo.valor_saldo = novo_saldo2;
            movim->conteudo = reg_movim;
            movim2->conteudo = reg_movim2;

            movim->anterior = NULL;
            movim->proximo = NULL;

            movim2->anterior = NULL;
            movim2->proximo = NULL;

            // Caso haja somente um
            if (m->primeiro == NULL)
            {
                m->primeiro = movim;
                movim->proximo = movim2;
                movim2->anterior = movim;
                m->ultimo = movim2;
            }
            else
            {
                m->ultimo->proximo = movim;
                movim->anterior = m->ultimo;
                movim->proximo = movim2;
                movim2->anterior = movim;
                m->ultimo = movim2;
            }
            break;
        }
        else if (opc == 2)
        {
            break;
        }
        else
        {
            limpar();
            printf("Opcao invalida!");
            getch();
        }
    } while (1);

    do
    {
        limpar();
        printf("Deseja cadastrar outra transferencia? [1] Sim [2] Nao: ");
        fflush(stdin);
        scanf("%d", &resp);
        if (resp == 1)
        {
            break;
        }
        else if (resp == 2)
        {
            return;
        }
        else
        {
            limpar();
            printf("Opcao invalida!");
            getch();
        }
    } while (1);
}