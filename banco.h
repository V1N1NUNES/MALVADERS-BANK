// adicionando as bibliotecas que seram utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>
#include <windows.h>
#include <unistd.h>

// protótipos de funções, variaveis globais, ....
void menu_principal();
// void menu_funcionario();
// void menu_cliente();
// void abertura_conta();
// void conte_corrente();
// void conta_poupanca();
// void encerramento_conta();
// void consultar_dados();
// void consultar_contas();
// void consultar_clientes();
// void consultar_funcionarios();
// void alterar_dados();
// void alterar_conta();
// void alterar_funcionarios();
// void alterar_clientes();
// void cadastro_funcionario();
// void gerar_relatorios();

#define tam 270
int senha_adm = 102938;
int senha_funcionario = 123456;
int senha_cliente = 123456;
int total_clientes = 0;
int total_funcionarios = 0;
int total_pessoas = total_clientes + total_funcionarios;

typedef struct
{
    char agencia[tam];
    int num;
    char nome[tam];
    int cpf;
    int nascimento;
    int telefone;
    char endereco[tam];
    int cep;
    char local[tam];
    int casa;
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int senha;
} poupanca;
poupanca cp[tam];
typedef struct
{
    char agencia[tam];
    int num;
    float limite;
    int vencimento;
    char nome[tam];
    long int cpf;
    long int nascimento;
    long int telefone;
    char endereco[tam];
    long int cep;
    char local[tam];
    int casa;
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int senha;
} corrente;
corrente cc[tam];

// 1- abertura de contas
void conta_poupanca()
{
    char resposta[5];
    do
    {
        printf("Digite qual a sua agencia:\n");
        fgets(cp[total_funcionarios].agencia, sizeof(cp[total_funcionarios].agencia), stdin);

        printf("Digite o numero da conta:\n");
        scanf("%d", &cp[total_funcionarios].num);
        getchar(); // Para consumir o newline deixado pelo scanf

        printf("Digite o nome do cliente:\n");
        fgets(cp[total_funcionarios].nome, sizeof(cp[total_funcionarios].nome), stdin);

        printf("Digite o CPF:\n");
        scanf("%d", &cp[total_funcionarios].cpf);
        getchar();

        printf("Digite a data de nascimento:\n");
        scanf("%d", &cp[total_funcionarios].nascimento);
        getchar();

        printf("Digite o telefone/celular:\n");
        scanf("%d", &cp[total_funcionarios].telefone);
        getchar();

        printf("Digite o endereco do cliente:\n");
        fgets(cp[total_funcionarios].endereco, sizeof(cp[total_funcionarios].endereco), stdin);

        printf("Digite o CEP:\n");
        scanf("%d", &cp[total_funcionarios].cep);
        getchar();

        printf("Digite o local:\n");
        fgets(cp[total_funcionarios].local, sizeof(cp[total_funcionarios].local), stdin);

        printf("Digite o numero da casa:\n");
        scanf("%d", &cp[total_funcionarios].casa);
        getchar();

        printf("Digite o bairro:\n");
        fgets(cp[total_funcionarios].bairro, sizeof(cp[total_funcionarios].bairro), stdin);

        printf("Digite a cidade:\n");
        fgets(cp[total_funcionarios].cidade, sizeof(cp[total_funcionarios].cidade), stdin);

        printf("Digite o estado:\n");
        fgets(cp[total_funcionarios].estado, sizeof(cp[total_funcionarios].estado), stdin);

        printf("Digite a senha do cliente:\n");
        scanf("%d", &cp[total_funcionarios].senha);
        getchar();

        total_funcionarios++; // Incrementa o contador de clientes ou funcionários

        printf("Deseja cadastrar mais um cliente/funcionario? (sim/nao)\n");
        scanf("%s", resposta);
        getchar(); // Para consumir o newline deixado pelo scanf
    } while (strcmp(resposta, "sim") == 0);
}
void conta_corrente() {
    char resposta[5];
    int total_contas = 0;

    do {
        printf("Digite qual a sua agencia:\n");
        scanf("%s", cc[total_contas].agencia);

        printf("Digite o numero da conta:\n");
        scanf("%d", &cc[total_contas].num);

        printf("Digite o limite da conta:\n");
        scanf("%f", &cc[total_contas].limite);

        printf("Digite o dia de vencimento:\n");
        scanf("%d", &cc[total_contas].vencimento);

        printf("Digite o nome do cliente:\n");
        getchar(); // Limpa o buffer de entrada
        fgets(cc[total_contas].nome, tam, stdin);

        printf("Digite o CPF:\n");
        scanf("%ld", &cc[total_contas].cpf);

        printf("Digite a data de nascimento:\n");
        scanf("%ld", &cc[total_contas].nascimento);

        printf("Digite o telefone/celular:\n");
        scanf("%ld", &cc[total_contas].telefone);

        printf("Digite o endereco do cliente:\n");
        getchar(); // Limpa o buffer de entrada
        fgets(cc[total_contas].endereco, tam, stdin);

        printf("Digite o CEP:\n");
        scanf("%ld", &cc[total_contas].cep);

        printf("Digite o local:\n");
        getchar(); // Limpa o buffer de entrada
        fgets(cc[total_contas].local, tam, stdin);

        printf("Digite o numero da casa:\n");
        scanf("%d", &cc[total_contas].casa);

        printf("Digite o bairro:\n");
        getchar(); // Limpa o buffer de entrada
        fgets(cc[total_contas].bairro, tam, stdin);

        printf("Digite a cidade:\n");
        fgets(cc[total_contas].cidade, tam, stdin);

        printf("Digite o estado:\n");
        fgets(cc[total_contas].estado, tam, stdin);

        printf("Digite a senha do cliente:\n");
        scanf("%d", &cc[total_contas].senha);

        total_contas++; // Incrementa o contador de contas

        printf("Deseja cadastrar mais um cliente/funcionario? (sim ou nao)\n");
        scanf("%s", resposta);
    } while (strcmp(resposta, "sim") == 0);
}
void abertura_conta()
{
    int opcao = 0;
    printf("ABERTURA DE CONTA\n\n");
    printf("1- Conta poupança\n2- Conta corrente\n3- Voltar\n");
    scanf("%d", &opcao);
    if (opcao <= 0 && opcao >= 4)
    {
        printf("numero informado invalido.\n");
        // menu_funcionario();
    }
    else if (opcao >= 1 && opcao <= 3)
    {
        switch (opcao)
        {
        case 1:
            // conta_poupanca();
            break;

        case 2:
            // conta_corrente();
            break;

        case 3:
            // menu_funcionario();
            break;
        }
    }
}

// 2- Encerramento de conta

//- MENU -
void menu_funcionario()
{
    int opcao;
    printf("MENU FUNCIONARIO\n\n");
    printf("1- Abertura de conta.\n2- Encerramento da conta.\n3- Consultar dados.\n4- Alterar dados.\n5- Cadastro de funcionario.\n6- Gerar relatoios.\n7- Voltar ao MENU PRINCIPAL.\n");
    scanf("%d", &opcao);

    // verificar se o numero digitado é inteiro//

    if (opcao > 0 && opcao < 8)
    {
        switch (opcao)
        {
        case 1:
            abertura_conta();
            break;

        case 2:
            // encerramento_conta();
            break;

        case 3:
            // consultar_dados();
            break;

        case 4:
            // alterar_dados();
            break;

        case 5:
            // cadastro_funcionario();
            break;

        case 6:
            // gerar_relatorios();
            break;

        case 7:
            menu_principal();
            break;
        }
    }
    else
    {
        printf("numero digitado invalido.\n");
        menu_principal();
    }
}
void menu_principal(){
    int opcao;
    int senha;

    do {
        printf("MENU PRINCIPAL\n\n");
        printf("1 - Menu funcionario\n");
        printf("2 - Menu cliente\n");
        printf("3 - Sair\n\n");

        scanf("%d", &opcao);
        getchar(); // Limpa o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite a senha:\n");
                scanf("%d", &senha);
                // menu_funcionario();
                break;

            case 2:
                // menu_cliente();
                break;

            case 3:
                printf("Até logo!\n");
                printf("AQUI O SEU DINHEIRO GANHA FORÇA\n");
                break;
        }

    } while (opcao != 3);

    return;
}