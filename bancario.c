/************************************************************************
Autores..: Augusto Claro e Pedro Gerhard
Data.....: 24/10/2024
Objetivo.: Criar um sistema de gerenciamento financeiro
************************************************************************/

// PARA COMPILAR: gcc -g .\include\funcoes.h .\src\*.c -o .\output\bancario

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

int main()
{
    // Declaração das variáveis
    lista_contas lista_contas;
    lista_contas.primeiro = NULL;
    lista_contas.ultimo = NULL;

    lista_movim m;
    m.primeiro = NULL;
    m.ultimo = NULL;

    int opc;

    system("color 0A");

    // Programa
    do
    {
        opc = 0;
        tela();
        gotoxy(25, 10);
        printf("1 - Cadastro de contas");
        gotoxy(25, 12);
        printf("2 - Movimentacao financeira");
        gotoxy(25, 14);
        printf("3 - Sair");

        gotoxy(7, 23);
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
        fflush(stdin); // Limpa o buffer para o programa não travar na proxima leitura 

        switch (opc) {
            case 1:
                menu_cadastro(&lista_contas, &m);
                break;
            case 2:
                menu_movim(&lista_contas, &m);
                break;
            case 3:
                limpar();
                gotoxy(7, 23);
                printf("Saindo...");
                Sleep(1000);
                return 0;
                break;
            default:
                sDefault();
                break;
        }
    } while (opc != 3);

    return 0;
}