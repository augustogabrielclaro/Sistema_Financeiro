/*********************************************************************************
 Autores....: Augusto Gabriel Claro e Pedro Gerhard
 Curso......: Analise e Desenvolvimento de Sistemas
 Turma......: 2º ADS
 Objetivo...: Fazer um sistema de gerenciamento financeiro
*********************************************************************************/

#include "funcoes.h"

tipoApontador_movim buscar_ultima_dt(lista_movim *m, int codigo) {
    tipoApontador_movim aux = m->ultimo;

    if (aux != NULL) {
        while (aux != NULL) {
            if (aux->conteudo.codigo_conta == codigo) {
                return aux;
            }
            aux = aux->anterior;
        }
    }
    return NULL;
}