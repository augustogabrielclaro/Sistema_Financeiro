#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double valor_saldo;
    double valor_limite;
    char status[10];
} conta_bancaria;

typedef struct tipoItem_conta *tipoApontador_conta;

typedef struct {
    conta_bancaria conteudo;
    tipoApontador_conta proximo;
} tipoItem_conta;

typedef struct {
    tipoApontador_conta primeiro;
    tipoApontador_conta ultimo;
} lista_contas;

typedef struct {
    int sequencial;
    int codigo_conta;

} reg_movimentos;

typedef struct tipoItem_movim *tipoApontador_movim;


typedef struct {
    reg_movimentos conteudo;
    tipoApontador_movim anterior;
    tipoApontador_movim proximo;
} tipoItem_movim;

void gotoxy();

void tela();

void menu();

void menu_cadastro();



#endif;