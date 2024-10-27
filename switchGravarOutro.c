#include "funcoes.h"

void switchGravarOutro(int resp) {
    switch (resp) {
        case 1:
            break;
        case 2:
            return;
        default:
            limpar();
            gotoxy(7, 23);
            printf("Opcao invalida!");
            getch();
            break;
    }
}