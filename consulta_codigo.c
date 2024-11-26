/*********************************************************************************
 Autores....: Augusto Gabriel Claro e Pedro Gerhard
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
*********************************************************************************/
#include "funcoes.h"

void consulta_codigo(lista_contas *lista_contas) {
    reg_contas reg_contas;
    tipoApontador_conta aux;

    
    if (lista_contas->primeiro == NULL) {
        limpar();
        printf("Ainda nao ha contas para consultar!");
        getch();
        return;
    }

    do {
        tela();
        limpar();
        printf("Digite o codigo da conta ou [0] para sair: ");
        scanf("%d", &reg_contas.codigo_conta);
        fflush(stdin);

        if (reg_contas.codigo_conta == 0) {
            return;
        }
        aux = pesquisa_conta(lista_contas, reg_contas);

        if (aux != NULL) {
            exibir_unica_conta(aux);
            getch();
        } else {
            limpar();
            printf("Codigo nao encontrado!");
            getch();
        }
    } while (reg_contas.codigo_conta != 0);

}