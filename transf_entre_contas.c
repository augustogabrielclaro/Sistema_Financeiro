#include "funcoes.h"


void transf_entre_contas()
{
    tela();

    gotoxy(16,3);
    printf("TRANSFERENCIA DE VALORES ENTRE CONTAS BANCARIAS");

    gotoxy(2, 7);
    printf("-------C O N T A O R I G E M---------+-------C O N T A D E S T I N O----------|");
    gotoxy(3, 8);
    printf("Conta de Origem: ");
    gotoxy(3, 9);
    printf("Banco..........: ");
    gotoxy(3, 10);
    printf("Agencia........: ");
    gotoxy(3, 11);
    printf("Numero da Conta: ");
    gotoxy(3, 12);
    printf("Tipo da Conta..: ");
    gotoxy(3, 13);
    printf("Saldo..........: ");
    gotoxy(3, 14);
    printf("Limite.........: ");
    gotoxy(3, 15);
    printf("Saldo + Limite.: ");
    gotoxy(3, 16);
    printf("Novo Saldo.....: ");

    gotoxy(41, 8);
    printf("Conta de Destino: ");
    gotoxy(41, 9);
    printf("Banco...........: ");
    gotoxy(41, 10);
    printf("Agencia.........: ");
    gotoxy(41, 11);
    printf("Numero da Conta.: ");
    gotoxy(41, 12);
    printf("Tipo de Conta...: ");
    gotoxy(41, 13);
    printf("Saldo...........: ");
    gotoxy(41, 14);
    printf("Limite..........: ");
    gotoxy(41, 15);
    printf("Saldo + Limite..: ");
    gotoxy(41, 16);
    printf("Novo Saldo......: ");

    for (int i = 8; i <= 16; i++)
    {
        gotoxy(39, i);
        printf("|");
    }

    gotoxy(2, 17);
    printf("-------------------------------------+----------------------------------------|");

    gotoxy(16, 18);
    printf("Valor a Ser Transferido.: ");
    gotoxy(16, 19);
    printf("Data da Transferencia...: ");
}