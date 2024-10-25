#include "funcoes.h"

void tela()
{
    system("cls");
    gotoxy(7, 23);
    printf("                                           ");
    int lin = 1;
    int col = 1;
    gotoxy(col, lin);
    printf("+");
    gotoxy(80, lin);
    printf("+");
    gotoxy(col, 25);
    printf("+");
    for (lin = 2; lin < 25; lin++)
    {
        gotoxy(col, lin);
        printf("|");
        gotoxy(80, lin);
        printf("|");
    }
    for (col = 2; col < 80; col++)
    {
        gotoxy(col, 1);
        printf("-");
        gotoxy(col, 25);
        printf("-");
        gotoxy(col, 22);
        printf("-");
        gotoxy(col, 4);
        printf("-");
        gotoxy(80, 25);
        printf("+");
    }

    gotoxy(3, 2);
    printf("UNICV");
    gotoxy(22, 3);
    printf("SISTEMA DE GERENCIAMENTO FINANCEIRO");
    gotoxy(60, 2);
    printf("AUGUSTO E PEDRO");
    gotoxy(2, 23);
    printf("MSG: ");
}