#include "funcoes.h"

void exibir_unica_conta(tipoApontador_conta p)
{
    tela();
    tela_contas();
    gotoxy(25, 6);
    printf("%d", p->conteudo.codigo_conta);

    gotoxy(25, 8);
    printf("%s", p->conteudo.banco);

    gotoxy(25, 10);
    printf("%s", p->conteudo.agencia);

    gotoxy(25, 12);
    printf("%s", p->conteudo.numero_conta);

    gotoxy(25, 14);
    printf("%s", p->conteudo.tipo_conta);

    gotoxy(25, 16);
    printf("%.2f", p->conteudo.valor_saldo);

    gotoxy(25, 18);
    printf("%.2f", p->conteudo.valor_limite);

    gotoxy(25, 20);
    printf("%s", p->conteudo.status);
}