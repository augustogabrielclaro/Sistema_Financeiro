/******************************************************************************************************
 Autor......: Augusto Gabriel Claro
 Dupla......: Augusto Gabriel Claro - RA 176029-2024, Pedro Gerhard - RA 175240-2024
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
******************************************************************************************************/
#include "funcoes.h"

char *validar_dt_transf(lista_movim *m, int codigo1, int codigo2)
{
    char *data_inserida = malloc(sizeof(char) * 11);
    char ultima_dt1[11];
    char ultima_dt2[11];
    char nova_data_ins[11];
    tipoApontador_movim aux;
    tipoApontador_movim aux2;

    if (data_inserida == NULL)
    {
        limpar();
        printf("Erro de alocação de memoria!\n");
        getch();
        return NULL;
    }
    limpar();
    printf("Digite a data da movimentacao: ");
    gotoxy(42, 19);
    printf("                ");
    gotoxy(42, 19);
    fflush(stdin);
    fgets(data_inserida, 11, stdin);

    if (strlen(data_inserida) < 10 || data_inserida[2] != '/' || data_inserida[5] != '/') {
        limpar();
        printf("Formato de data invalido! Use DD/MM/AAAA");
        getch();
        free(data_inserida);
        return NULL;
    }

    aux = buscar_ultima_dt(m, codigo1);

    if (aux != NULL) {
        strcpy(ultima_dt1, inverte_data(aux->conteudo.dt_movimento));
    } else
    {
        ultima_dt1[0] = '\0';
    }

    aux2 = buscar_ultima_dt(m, codigo2);

    if (aux2 != NULL) {
        strcpy(ultima_dt2, inverte_data(aux2->conteudo.dt_movimento));
    } else
    {
        ultima_dt2[0] = '\0';
    }


    strcpy(nova_data_ins, inverte_data(data_inserida));

    int ano = atoi(nova_data_ins);
    int mes = atoi(&nova_data_ins[5]);
    int dia = atoi(&nova_data_ins[8]);

    int ult_ano1 = atoi(ultima_dt1);
    int ult_mes1 = atoi(&ultima_dt1[5]);
    int ult_dia1 = atoi(&ultima_dt1[8]);

    int ult_ano2 = atoi(ultima_dt2);
    int ult_mes2 = atoi(&ultima_dt2[5]);
    int ult_dia2 = atoi(&ultima_dt2[8]);

    if (ano < ult_ano1 || (ano == ult_ano1 && mes < ult_mes1) || (ano == ult_ano1 && mes == ult_mes1 && dia < ult_dia1) 
    || (ano < ult_ano2) || (ano == ult_ano2 && mes < ult_mes2) || (ano == ult_ano2 && mes == ult_mes2 && dia < ult_dia2)) {
        limpar();
        printf("A data precisa ser maior que a ultima data registrada nas contas!");
        getch();
        free(data_inserida);
        return NULL;
    }

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12)
    {
        limpar();
        printf("Erro, data invalida!");
        getch();
        free(data_inserida);
        return NULL;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        limpar();
        printf("Erro, o mes digitado tem no maximo 30 dias!");
        getch();
        free(data_inserida);
        return NULL;
    }

    if (mes == 2)
    {
        int bissexto = 0;
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        {
            bissexto = 1;
        }

        if ((bissexto == 1 && dia > 29) || (bissexto == 0 && dia > 28))
        {
            limpar();
            printf("Fevereiro tem 28 dias em anos normais, e 29 em anos bissextos!");
            getch();
            free(data_inserida);
            return NULL;
        }
    }

    return data_inserida;
}