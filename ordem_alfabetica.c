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

#define MAX_PAG 19
void ordem_alfabetica(lista_contas *lista_contas)
{
    tipoApontador_conta aux;
    tipoApontador_conta aux2;
    int linha = 7;
    float saldo_total = 0;

    if (lista_contas->primeiro == NULL) {
        limpar();
        printf("Nao ha nenhuma conta cadastrada para listar!");
        getch();
        return;
    }

    aux = lista_contas->primeiro;
    while (aux->proximo != NULL)
    {
        aux2 = aux->proximo;
        while (aux2 != NULL)
        {
            if (strcmp(aux->conteudo.banco, aux2->conteudo.banco) > 0)
            {
                reg_contas temp = aux->conteudo;
                aux->conteudo = aux2->conteudo;
                aux2->conteudo = temp;
            }
            aux2 = aux2->proximo;
        }
        aux = aux->proximo;
    }

    aux = lista_contas->primeiro;
    while (aux != NULL)
    {
        tela();
        gotoxy(22, 3);
        printf("LISTA CONTAS BANCARIAS - ORDEM ALFABETICA");
        gotoxy(2, 5);
        printf("Cd Banco");
        gotoxy(2, 6);
        printf("-- ------------------- ----- -------- -------------- ----------- ----------- -");
        gotoxy(25, 5);
        printf("Agenc Conta");
        gotoxy(40, 5);
        printf("Tipo Conta");
        gotoxy(55, 5);
        printf("Saldo");
        gotoxy(67, 5);
        printf("Limite");
        gotoxy(78, 5);
        printf("St");
        gotoxy(20, 30);

        while (aux != NULL && linha < MAX_PAG)
        {
            gotoxy(2, linha);
            printf("%d", aux->conteudo.codigo_conta);
            gotoxy(4, linha);
            printf("%s", aux->conteudo.banco);
            gotoxy(25, linha);
            printf("%s", aux->conteudo.agencia);
            gotoxy(32, linha);
            printf("%s", aux->conteudo.numero_conta);
            gotoxy(40, linha);
            printf("%s", aux->conteudo.tipo_conta);
            gotoxy(55, linha);
            printf("R$ %.2f", aux->conteudo.valor_saldo);
            gotoxy(67, linha);
            printf("R$ %.2f", aux->conteudo.valor_limite);
            gotoxy(79, linha);
            printf("%d", aux->conteudo.status);

            linha++;
            saldo_total += aux->conteudo.valor_saldo;
            aux = aux->proximo;
        }

        if (linha == MAX_PAG)
        {
            limpar();
            printf("Pressione qualquer tecla para continuar...");
            getch();
            linha = 7;
        }
        gotoxy(42, linha + 1);
        printf("Saldo Total: R$ %.2f", saldo_total);
    }
    limpar();
    printf("Pressione qualquer tecla para continuar...");
    getch();
}