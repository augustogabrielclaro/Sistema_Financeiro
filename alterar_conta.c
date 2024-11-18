#include "funcoes.h"

void alterar_conta(lista_contas *lista_contas)
{
    tipoApontador_conta aux;
    reg_contas reg_contas;
    int campo;
    int resp;
    int resp2;
    tela_contas();

    do
    {
        do
        {
            limpar();
            printf("Digite o codigo da conta ou [0] para sair: ");
            scanf("%d", &reg_contas.codigo_conta);

            if (reg_contas.codigo_conta == 0)
            {
                return;
            }

            aux = pesquisa_conta(lista_contas, reg_contas);

            if (aux == NULL)
            {
                limpar();
                printf("Conta nao encontrada!");
                getch();
            }
        } while (aux == NULL);

        do
        {
            exibir_unica_conta(aux);
            limpar();
            printf("Digite o campo a ser alterado ou [0] para sair: ");
            scanf("%d", &campo);

            switch (campo)
            {
            case 0:
                return;
                break;
            case 1:
                gotoxy(25, 8);
                printf("                                                    ");
                gotoxy(25, 8);
                fflush(stdin);
                fgets(reg_contas.banco, 50, stdin);
                break;
            case 2:
                gotoxy(25, 10);
                printf("                                                    ");
                gotoxy(25, 10);
                fflush(stdin);
                fgets(reg_contas.agencia, 10, stdin);
                break;
            case 3:
                gotoxy(25, 12);
                printf("                                                    ");
                gotoxy(25, 12);
                fflush(stdin);
                fgets(reg_contas.numero_conta, 20, stdin);
                break;
            case 4:
                gotoxy(25, 14);
                printf("                                                    ");
                gotoxy(25, 14);
                fflush(stdin);
                fgets(reg_contas.tipo_conta, 20, stdin);
                break;
            case 5:
                limpar();
                printf("Nao e possivel alterar o saldo diretamente!");
                getch();
                break;
            case 6:
                gotoxy(25, 18);
                printf("                                                    ");
                gotoxy(25, 18);
                scanf("%f", &reg_contas.valor_limite);
                getchar();
                break;
            case 7:
                gotoxy(25, 20);
                printf("                                                    ");
                gotoxy(25, 20);
                fflush(stdin);
                fgets(reg_contas.status, 10, stdin);
                break;
            default:
                limpar();
                printf("Campo invalido!");
                getch();
                break;
            }

        } while (campo != 0);

        do
        {
            limpar();
            printf("Deseja gravar as alteracoes?: [1] Sim [2] Nao: ");
            scanf("%d", &resp);

            switch (resp)
            {
            case 1:
                aux->conteudo = reg_contas;
                break;
            case 2:
                break;
            default:
                sDefault();
                break;
            }
        } while (resp != 1 && resp != 2);

        limpar();
        printf("Deseja alterar outra conta? [1] Sim [2] Nao: ");
        scanf("%d", &resp2);

        switch (resp2)
        {
            case 1:
                break;
            case 2:
                return;
                break;
            default:
                sDefault();
                break;
        }
    } while (resp2 != 2);
}