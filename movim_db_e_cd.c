#include "funcoes.h"

void movim_db_e_cd(lista_contas *lista_contas, lista_movim *m)
{
    tipoApontador_conta aux;
    tipoApontador_movim movim;
    int sequencial;
    reg_contas reg_contas;
    reg_movimentos reg_movim;
    int tipo_movim;

    tela();
    if (lista_contas->primeiro == NULL)
    {
        limpar();
        printf("Nao ha contas cadastradas para movimentar!");
        getch();
        return;
    }

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

    } while (aux == NULL || reg_contas.codigo_conta == 0);

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

        
        validar_dt(m, reg_movim.codigo_conta);
        do
        {
            limpar();
            printf("1 - Debito  //  2 - Credito");
            gotoxy(30, 17);
            scanf("%d", tipo_movim);
        } while (tipo_movim != 1 && tipo_movim != 2);
        if (tipo_movim == 1)
        {
            strcpy(reg_movim.tp_movimentacao, "Debito");
        }
        else if (tipo_movim == 2)
        {
            strcpy(reg_movim.tp_movimentacao, "Credito");
        }

        gotoxy(30, 18);
        printf("- %s", reg_movim.tp_movimentacao);
    } while (1);
}