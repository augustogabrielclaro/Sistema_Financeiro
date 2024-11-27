/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

char *inverte_data(char *dt_data) {
    if (dt_data == NULL || strlen(dt_data) != 10) {
        limpar();
        printf("Erro: Data inválida.\n");
        return NULL;
    }

    char *dt_data_inv;
    dt_data_inv = malloc(sizeof(char) * 11);

    char dia[3], mes[3], ano[5];

    strncpy(dia, dt_data, 2);
    dia[2] = '\0';

    strncpy(mes, dt_data + 3, 2);
    mes[2] = '\0';

    strncpy(ano, dt_data + 6, 4);
    ano[4] = '\0';

    sprintf(dt_data_inv, "%s/%s/%s", ano, mes, dia);

    return dt_data_inv;

}