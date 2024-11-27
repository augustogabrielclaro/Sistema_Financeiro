/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void exibir_unica_conta(tipoApontador_conta p)
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
    printf("%d", p->conteudo.status);
}