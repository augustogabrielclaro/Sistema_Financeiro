#include "funcoes.h"

void tela_movim_db_e_cd()
{
        tela();
        gotoxy(22, 3);
        printf("CADASTRAR MOVIMENTACOES BANCARIAS");
        gotoxy(5, 6);
        printf("Sequencia Movimentacao.: ");
        gotoxy(5, 7);
        printf("Codigo Conta...........: ");
        gotoxy(5, 8);
        printf("Banco..................: ");
        gotoxy(5, 9);
        printf("Agencia................: ");
        gotoxy(5, 10);
        printf("Numero da Conta........: ");
        gotoxy(5, 11);
        printf("Tipo Conta.............: ");
        gotoxy(5, 12);
        printf("Saldo..................: ");
        gotoxy(5, 13);
        printf("Limite.................: ");
        gotoxy(5, 14);
        printf("Total Saldo + Limite...: ");

        gotoxy(2, 15);
        printf("------------------------------------------------------------------------------|");

        gotoxy(5, 16);
        printf("1-Data Movimentacao....: ");
        gotoxy(5, 17);
        printf("2-Tipo Movimentacao....: ");
        gotoxy(5, 18);
        printf("3-Favorecido...........: ");
        gotoxy(5, 19);
        printf("4-Valor................: ");
        gotoxy(5, 20);
        printf("5-Novo Saldo...........: ");
}