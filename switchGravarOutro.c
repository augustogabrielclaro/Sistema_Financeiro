#include "funcoes.h"

void switchGravarOutro(int resp) {
    switch (resp) {
        case 1:
            break;
        case 2:
            return;
        default:
            limpar();
            printf("Opcao invalida!");
            getch();
            break;
    }
}