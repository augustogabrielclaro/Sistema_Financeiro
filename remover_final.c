#include "funcoes.h"

void remover_final(lista_contas *lista_contas, lista_movim m)
{
    tipoApontador_conta p;
    tipoApontador_conta aux;
    int resp = 0;

    gotoxy(20, 3);
    printf("                                                     ");
    gotoxy(28, 3);
    printf("REMOCAO NO FINAL DA LISTA");

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
            limpar();
            printf("Deseja realmente remover esta conta? [1] Sim [2] Nao: ");
            scanf("%d", &resp);

            switch (resp)
            {
            case 1:
                if (conta_movimentacao(m, p->conteudo.codigo_conta) != 0)
                {
                    limpar();
                    printf("A conta nao pode ser excluida!");
                    getch();
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
    // Mais de um
    aux = lista_contas->primeiro;
    p = aux->proximo;

    while (p->proximo != NULL)
    {
        p = p->proximo;
        aux = aux->proximo;
    }

    do
    {   
        exibir_unica_conta(p);
        limpar();
        printf("Deseja realmente remover esta conta? [1] Sim [2] Nao: ");
        scanf("%d", &resp);

        switch (resp)
        {
        case 1:
            if (conta_movimentacao(m, p->conteudo.codigo_conta) != 0)
            {
                limpar();
                printf("A conta nao pode ser excluida!");
                getch();
                return;
            }
            else
            {
                free(p);
                aux->proximo = NULL;
                lista_contas->ultimo = aux;
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