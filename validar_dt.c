#include "funcoes.h"

char *validar_dt(lista_movim *m, int codigo)
{
    char *dt_inserida = malloc(sizeof(char) * 11);
    char ultima_dt[11];
    char nova_data[11];

    if (dt_inserida == NULL)
    {
        limpar();
        printf("Erro de alocação de memoria!\n");
        getch();
        return NULL;
    }

    
    limpar();
    printf("Digite a data: DD/MM/AAAA");
    gotoxy(30, 16);
    printf("                             ");
    gotoxy(30, 16);
    fflush(stdin);
    fgets(dt_inserida, 11, stdin);

    if (strlen(dt_inserida) < 10 || dt_inserida[2] != '/' || dt_inserida[5] != '/') {
        limpar();
        printf("Formato de data invalido! Use DD/MM/AAAA");
        getch();
        free(dt_inserida);
        return NULL;
    }

    tipoApontador_movim aux = buscar_ultima_dt(m, codigo);

    if (aux != NULL)
    {
        strcpy(ultima_dt, inverte_data(aux->conteudo.dt_movimento));
        limpar();
    }
    else
    {
        ultima_dt[0] = '\0';
    }

    strcpy(nova_data, inverte_data(dt_inserida));

    
    int ano = atoi(nova_data);
    int mes = atoi(&nova_data[5]);
    int dia = atoi(&nova_data[8]);

    int ult_ano = atoi(ultima_dt);
    int ult_mes = atoi(&ultima_dt[5]);
    int ult_dia = atoi(&ultima_dt[8]);

    if (ano < ult_ano || (ano == ult_ano && mes < ult_mes) || (ano == ult_ano && mes == ult_mes && dia < ult_dia))
    {
        limpar();
        printf("Erro, a data inserida e menor que a ultima data registrada!");
        getch();
        free(dt_inserida);
        return NULL;
    }

    if (dia < 1 || dia > 31 || mes < 1 || mes > 12)
    {
        limpar();
        printf("Erro, data invalida!");
        getch();
        free(dt_inserida);
        return NULL;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
    {
        limpar();
        printf("Erro, o mes digitado tem no maximo 30 dias!");
        getch();
        free(dt_inserida);
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
            free(dt_inserida);
            return NULL;
        }
    }

    return dt_inserida;
}