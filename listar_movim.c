#include "funcoes.h"

#define MAX_PAG 20

void listar_movim(lista_contas *lista_contas, lista_movim *m)
{
    tipoApontador_conta aux;
    tipoApontador_movim movim;
    reg_contas reg_conta;
    int linha = 9;
    int resp = 0;
    tela();
    if (m->primeiro == NULL)
    {
        limpar();
        printf("Nao ha movimentacoes para mostrar!");
        getch();
        return;
    }

    do
    {
        do
        {
            tela_consulta_movim();
            limpar();
            printf("Digite o codigo da conta ou [0] para sair: ");
            gotoxy(10, 5);
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

        } while (aux == NULL && reg_conta.codigo_conta != 0);

        movim = pesquisa_movim(m, aux->conteudo.codigo_conta);
        while (movim != NULL)
        {
            linha = 9;
            tela_consulta_movim();

            while (movim != NULL && linha < MAX_PAG)
            {
                if (movim->conteudo.codigo_conta == reg_conta.codigo_conta)
                {
                    gotoxy(2, linha);
                    printf("%s", movim->conteudo.dt_movimento);

                    gotoxy(13, linha);
                    printf("%s", movim->conteudo.favorecido);

                    gotoxy(45, linha);
                    printf("%s", movim->conteudo.tp_movimentacao);

                    gotoxy(59, linha);
                    printf("%.2f", movim->conteudo.valor_movimento);

                    gotoxy(71, linha);
                    printf("%.2f", movim->conteudo.valor_saldo);

                    linha++;
                }

                movim = movim->proximo;
            }

            if (movim != NULL)
            {
                limpar();
                printf("Pressione qualquer tecla para continuar...");
                getch();
            }
        }
        limpar();
        printf("Deseja consultar outras movimentacoes das contas? [1] Sim [2] Nao: ");
        scanf("%d", &resp);
        if (resp == 1) {
            continue;
        } else if (resp == 2) {
            return;
            break;
        } else {
            limpar();
            printf("Opcao invalida!");
            getch();
        }
    } while (1);
}