#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void listar_contas(lista_contas *lista_contas)
{
    tipoApontador_conta p;
    p = lista_contas->primeiro;
    int resp;

    if (lista_contas->primeiro == NULL)
    {
        limpar();
        printf("Ainda nao ha nenhum cadastrado!");
        getch();
        return;
    }

    while (p != NULL)
    {

        tela();
        tela_contas();

        gotoxy(25, 6);
        printf("%d", p->conteudo.codigo_conta);

        gotoxy(25, 8);
        printf("%s", p->conteudo.banco);

        gotoxy(25, 10);
        printf("%s", p->conteudo.agencia);

        gotoxy(25, 12);
        printf("%s", p->conteudo.numero_conta);

        gotoxy(25, 14);
        printf("%s", p->conteudo.tipo_conta);

        gotoxy(25, 16);
        printf("%.2f", p->conteudo.valor_saldo);

        gotoxy(25, 18);
        printf("%.2f", p->conteudo.valor_limite);

        gotoxy(25, 20);
        printf("%s", p->conteudo.status);

        resp = 0;
        limpar();
        printf("Deseja ir para o proximo? [1] Sim [2] Nao: ");
        scanf("%d", &resp);
        fflush(stdin);

        switch (resp)
        {
        case 1:
            p = p->proximo;
            if (p == NULL)
            {
                limpar();
                printf("Nao ha mais para listar!");
                getch();
                return;
            }
            break;
        case 2:
            return;
        default:
            sDefault();
            break;
        }
    }
}