/************************************************************************
Autores..: Augusto Claro e Pedro Gerhard
Data.....: 24/10/2024
Objetivo.: Criar um sistema de gerenciamento financeiro
************************************************************************/

// PARA COMPILAR: gcc -g *.c -o .output\bancario

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#include "funcoes.h"


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    tela();
    getch();
    return 0;
}