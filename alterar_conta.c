#include "funcoes.h"

void alterar_conta(lista_contas *lista_contas)
{
    tipoApontador_conta aux;
    reg_contas reg_conta;
    reg_contas copia;
    int campo;
    int resp;
    int resp2;
    int tipo;
    tela_contas();
    gotoxy(28, 3);
    printf("ALTERACAO DE CADASTRADOS");
    do
    {
        do
        {
            limpar();
            printf("Digite o codigo da conta ou [0] para sair: ");
            scanf("%d", &reg_conta.codigo_conta);

            if (reg_conta.codigo_conta == 0)
            {
                return;
            }

            aux = pesquisa_conta(lista_contas, reg_conta);

            if (aux == NULL)
            {
                limpar();
                printf("Conta nao encontrada!");
                getch();
            }
        } while (aux == NULL);

        copia = aux->conteudo;
        exibir_unica_conta(aux);
        do
        {
            gotoxy(28, 3);
            printf("ALTERACAO DE CADASTRADOS");
            limpar();
            printf("Digite o campo a ser alterado ou [0] para sair: ");
            scanf("%d", &campo);

            switch (campo)
            {
            case 0:
                break;
            case 1:
                gotoxy(25, 8);
                printf("                                                    ");
                gotoxy(25, 8);
                fflush(stdin);
                fgets(aux->conteudo.banco, 50, stdin);
                break;
            case 2:
                gotoxy(25, 10);
                printf("                                                    ");
                gotoxy(25, 10);
                fflush(stdin);
                fgets(aux->conteudo.agencia, 10, stdin);
                break;
            case 3:
                gotoxy(25, 12);
                printf("                                                    ");
                gotoxy(25, 12);
                fflush(stdin);
                fgets(aux->conteudo.numero_conta, 20, stdin);
                break;
            case 4:
                do
                {
                    limpar();
                    printf("[1] Poupanca  [2] Corrente  [3] Cartao de Credito");
                    gotoxy(25, 14);
                    printf("                                            ");
                    gotoxy(25, 14);
                    scanf("%d", &tipo);
                    fflush(stdin);

                    if (tipo == 1)
                    {
                        strcpy(aux->conteudo.tipo_conta, "Poupanca");
                        break;
                    }
                    else if (tipo == 2)
                    {
                        strcpy(aux->conteudo.tipo_conta, "Corrente");
                        break;
                    }
                    else if (tipo == 3)
                    {
                        strcpy(aux->conteudo.tipo_conta, "Cartao Credito");
                        break;
                    }
                    else
                    {
                        limpar();
                        printf("Opcao invalida!");
                        getch();
                    }
                } while (1);
                gotoxy(25,14);
                printf("%s", aux->conteudo.tipo_conta);
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
                scanf("%f", &aux->conteudo.valor_limite);
                getchar();
                break;
            case 7:
                gotoxy(25, 20);
                printf("                                                    ");
                do
                {
                    limpar();
                    printf("[1] Ativa  [2] Inativa");
                    gotoxy(25, 20);
                    scanf("%d", &aux->conteudo.status);
                    fflush(stdin);
                } while (aux->conteudo.status != 1 && aux->conteudo.status != 2);
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
            fflush(stdin);
            scanf("%d", &resp);

            switch (resp)
            {
            case 1:
                break;
            case 2:
                aux->conteudo = copia;
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