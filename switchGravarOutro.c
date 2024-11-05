#include "funcoes.h"

void switchGravarOutro(int resp) {
    switch (resp) {
        case 1:
            break;
        case 2:
            return;
            break;
        default:
            limpar();
            printf("Opcao invalida!");
            getch();
            break;
    }
}