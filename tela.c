#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

// Função da tela

void tela()
{
    system("cls");
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
    gotoxy(60, 2);
    printf("AUGUSTO E PEDRO");
    gotoxy(22, 2);
    printf("SISTEMA DE GERENCIAMENTO FINANCEIRO");
    gotoxy(2, 23);
    printf("MSG: ");
}

// Pra que serve?
// Tantos códigos?
// Se a vida
// Não é programada
// E as melhores coisas
// Não têm lógica.