#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

// Estrutura das contas bancárias
typedef struct {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    float valor_saldo;
    float valor_limite;
    char status[10];
} reg_contas;

// Apontador do tipo item de conta
typedef struct tipoItem_conta *tipoApontador_conta;

// Tipo item conta
typedef struct tipoItem_conta {
    reg_contas conteudo;
    tipoApontador_conta proximo;
} tipoItem_conta;


// Lista das contas
typedef struct {
    tipoApontador_conta primeiro;
    tipoApontador_conta ultimo;
} lista_contas;

// Estrutura das movimentações
typedef struct {
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimentacao[15];
    float valor_movimento;
    float valor_saldo;
} reg_movimentos;

// Apontador do tipo item de movimentos
typedef struct tipoItem_movim *tipoApontador_movim;

// Tipo item dos movimentos
typedef struct {
    reg_movimentos conteudo;
    tipoApontador_movim anterior;
    tipoApontador_movim proximo;
} tipoItem_movim;

// Lista de movimentações
typedef struct {
    tipoApontador_movim primeiro;
    tipoApontador_movim ultimo;
} lista_movim;

void gotoxy();

void tela();

// void menu_movim();

void menu();

void limpar();

void menu_cadastro(lista_contas *lista_contas);

void cad_final(lista_contas *lista_contas);

void tela_contas();

void switchGravarOutro(int resp);

void listar_contas(lista_contas *lista_contas);