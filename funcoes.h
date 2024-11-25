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
    int status;
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
    char favorecido[30];
} reg_movimentos;

// Apontador do tipo item de movimentos
typedef struct tipoItem_movim *tipoApontador_movim;

// Tipo item dos movimentos
typedef struct tipoItem_movim{
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

void menu_movim(lista_contas *lista_contas, lista_movim *m);

void menu();

void limpar();

void menu_cadastro(lista_contas *lista_contas, lista_movim *m);

void cad_final(lista_contas *lista_contas);

void tela_contas();

void sDefault();

void listar_contas(lista_contas *lista_contas);

void cad_inicio(lista_contas *lista_contas);

void cad_posicao(lista_contas *lista_contas);

tipoApontador_conta pesquisa_conta(lista_contas *lista_contas, reg_contas reg_contas);

int conta_contas(lista_contas *lista_contas);

void remover_final(lista_contas *lista_contas, lista_movim *m);

void exibir_unica_conta(tipoApontador_conta p);

int contar_movimentacao_conta(lista_movim *m, int codigo);

void ordem_alfabetica(lista_contas *lista_contas);

void remover_inicio(lista_contas *lista_contas, lista_movim *m);

void remover_codigo(lista_contas *lista_contas, lista_movim *m);

void movim_db_e_cd(lista_contas *lista_contas, lista_movim *m);

void alterar_conta(lista_contas *lista_contas);

void transf_entre_contas();

void menu_listagem(lista_contas *lista_contas, lista_movim *m);

void consulta_codigo(lista_contas *lista_contas);

int conta_movimentacao(lista_movim *m);

void tela_movim();

char *inverte_data(char *dt_data);

tipoApontador_movim buscar_ultima_dt(lista_movim *m, int codigo);

char *validar_dt(lista_movim *m, int codigo);

void salvar_movim(lista_movim *m, const char *name);

void salvar_contas(lista_contas *lista_contas, const char *name);

void carregar_movim(lista_movim *m, const char *name);

void carregar_contas(lista_contas *lista_contas, const char *name);

void ordem_codigo(lista_contas *lista_contas);