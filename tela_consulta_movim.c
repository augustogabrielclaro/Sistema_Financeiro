/******************************************************************************************************
 Autor......: Pedro Augusto Gerhard de Carvalho
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

void tela_consulta_movim() {
    tela();
    gotoxy(25, 3);
    printf("LISTA MOVIMENTACOES BANCARIAS ");

    gotoxy(2, 5);
    printf("Codigo: ");
    gotoxy(2, 6);
    printf("------------------------------------------------------------------------------| ");

    gotoxy(2, 7);
    printf("Dt.Movim ");
    gotoxy(2, 8);
    printf("---------- ");

    gotoxy(13, 7);
    printf("Favorecido ");
    gotoxy(13, 8);
    printf("------------------------------- ");

    gotoxy(45, 7);
    printf("TpMovim ");
    gotoxy(45, 8);
    printf("------------- ");

    gotoxy(59, 7);
    printf("Vl.Movim ");
    gotoxy(59, 8);
    printf("----------- ");

    gotoxy(71, 7);
    printf("Saldo ");
    gotoxy(71, 8);
    printf("---------| ");
}