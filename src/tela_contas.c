#include "funcoes.h"

void tela_contas() {
    tela();
    gotoxy(5, 6);
    printf("Codigo da conta...:                                      ");
    gotoxy(5, 8);
    printf("1-Banco...........:                                      ");
    gotoxy(5, 10);
    printf("2-Agencia.........:                                      ");
    gotoxy(5, 12);
    printf("3-Numero da conta.:                                      ");
    gotoxy(5, 14);
    printf("4-Tipo de conta...:                                      ");
    gotoxy(5, 16);
    printf("5-Saldo...........:                                      ");
    gotoxy(5, 18);
    printf("6-Valor de limite.:                                      ");
    gotoxy(5, 20);
    printf("7-Status..........:                                      ");
}