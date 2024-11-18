#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

void ordem_alfabetica(lista_contas *lista_contas) {
    tela();
    gotoxy(22,3);
    printf("LISTA CONTAS BANCARIAS - ORDEM ALFABETICA");
    gotoxy(2,5);
    printf("Cd Banco");
    gotoxy(2,6);
    printf("-- ------------------- ----- -------- -------------- ----------- ----------- -");
    gotoxy(25,5);
    printf("Agenc Conta");
    gotoxy(40,5);
    printf("Tipo Conta");
    gotoxy(55,5);
    printf("Saldo");
    gotoxy(67,5);
    printf("Limite");
    gotoxy(78,5);
    printf("St");
    gotoxy(20,30);
}