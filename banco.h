// adicionando as bibliotecas que seram utilizadas
#ifndef  BANCO_H
#define BANCO_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

#define tam 270
int senha_adm= 102938;
int senha_funcionario= 123456;
int senha_cliente= 654321;
int total_funcionarios=0;
int total_clientes=0;
int total_pessoas = total_funcionarios + total_clientes;

// protótipos de funções, variaveis globais, ....
void menu_principal();
void menu_funcionario();
void menu_cliente();
void abertura_conta();
void conte_corrente();
void conta_poupanca();
void criarArquivoClientes();
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



struct Cliente {
    float saldo;
    char agencia[tam];
    int num;
    float limite; // Alterado para float para representar limite de conta corrente
    int vencimento;
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
};
struct Poupanca{
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
};

struct ContaCorrente {
    char agencia[tam];
    int num;
    float limite; // Alterado para float para representar limite de conta corrente
    int vencimento;
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
};

Poupanca cp[tam];
ContaCorrente cc[tam];

void conta_poupanca() {
    char resposta[10]; 
    do {
        for (int i = 0; i < 1; i++) {
            printf("Digite qual a sua agencia:\n");
            scanf("%s", cp[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%d", &cp[i].num);
            getchar(); 

            printf("Digite o nome do cliente:\n");
            getchar(); 
            fgets(cp[i].nome, tam, stdin);

            printf("Digite o CPF:\n");
            scanf("%d", &cp[i].cpf);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &cp[i].nascimento);

            printf("Digite o telefone/celular:\n");
            scanf("%d", &cp[i].telefone);
            getchar(); // 

            printf("Digite o endereco do cliente:\n");
            fgets(cp[i].endereco, tam, stdin);

            printf("Digite o CEP:\n");
            scanf("%d", &cp[i].cep);

            printf("Digite o local:\n");
            fgets(cp[i].local, tam, stdin);

            printf("Digite o numero da casa:\n");
            scanf("%d", &cp[i].casa);
            getchar(); 

            printf("Digite o bairro:\n");
            fgets(cp[i].bairro, tam, stdin);

            printf("Digite a cidade:\n");
            fgets(cp[i].cidade, tam, stdin);

            printf("Digite o estado:\n");
            fgets(cp[i].estado, tam, stdin);

            printf("Digite a senha do cliente:\n");
            scanf("%d", &cp[i].senha);
        }
        total_funcionarios++; // Incrementa o contador de funcionários/clientes

        printf("Deseja cadastrar mais um cliente/funcionario? (sim/nao)\n");
        scanf("%s", resposta);
        getchar(); 
    } while (strcmp(resposta, "sim") == 0);
}

void conta_corrente() {
    char resposta[10]; 
    do {
        for (int i = 0; i < 1; i++) {
            printf("Digite qual a sua agencia:\n");
            scanf("%s", cc[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%d", &cc[i].num);
            getchar(); 

            printf("Digite o limite da conta:\n");
            scanf("%f", &cc[i].limite);
            getchar(); 

            printf("Digite a data de vencimento:\n");
            scanf("%d", &cc[i].vencimento);

            printf("Digite o nome do cliente:\n");
            getchar(); 
            fgets(cc[i].nome, tam, stdin);

            printf("Digite o CPF:\n");
            scanf("%d", &cc[i].cpf);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &cc[i].nascimento);

            printf("Digite o telefone/celular:\n");
            scanf("%d", &cc[i].telefone);
            getchar(); 

            printf("Digite o endereco do cliente:\n");
            fgets(cc[i].endereco, tam, stdin);

            printf("Digite o CEP:\n");
            scanf("%d", &cc[i].cep);

            printf("Digite o local:\n");
            fgets(cc[i].local, tam, stdin);

            printf("Digite o numero da casa:\n");
            scanf("%d", &cc[i].casa);
            getchar(); 

            printf("Digite o bairro:\n");
            fgets(cc[i].bairro, tam, stdin);

            printf("Digite a cidade:\n");
            fgets(cc[i].cidade, tam, stdin);

            printf("Digite o estado:\n");
            fgets(cc[i].estado, tam, stdin);

            printf("Digite a senha do cliente:\n");
            scanf("%d", &cc[i].senha);
        }
        total_funcionarios++; 

        printf("Deseja cadastrar mais um cliente/funcionario? (sim/nao)\n");
        scanf("%s", resposta);
        getchar();
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
        menu_funcionario();
    }
    else if (opcao >= 1 && opcao <= 3)
    {
        switch (opcao)
        {
        case 1:
            conta_poupanca();
            break;

        case 2:
            conta_corrente();
            break;

        case 3:
            menu_funcionario();
            break;
        }
    }
}

void criarArquivoClientes(const char *nomeArquivo, struct Cliente clientes[], int numClientes) {
    // Abre o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo, "w");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        fprintf(stderr, "Erro ao abrir o arquivo %s\n", nomeArquivo);
        return;
    }

    // Escreve os dados dos clientes no arquivo
    for (int i = 0; i < numClientes; ++i) {
        fprintf(arquivo, "Nome: %s\n", clientes[i].nome);
        fprintf(arquivo, "Agencia: %s\n", clientes[i].agencia);
        fprintf(arquivo, "Num: %d\n", clientes[i].num);
        fprintf(arquivo, "Saldo: %f\n", clientes[i].saldo);
        fprintf(arquivo, "Limite: %f\n", clientes[i].limite);
        fprintf(arquivo, "Vencimento: %d\n", clientes[i].vencimento);
        fprintf(arquivo, "CPF: %d\n", clientes[i].cpf);
        fprintf(arquivo, "Nascimento: %d\n", clientes[i].nascimento);
        fprintf(arquivo, "Telefone: %d\n", clientes[i].telefone);
        fprintf(arquivo, "Endereço: %s\n", clientes[i].endereco);
        fprintf(arquivo, "CEP: %d\n", clientes[i].cep);
        fprintf(arquivo, "Local: %s\n", clientes[i].local);
        fprintf(arquivo, "Casa: %d\n", clientes[i].casa);
        fprintf(arquivo, "Bairro: %s\n", clientes[i].bairro);
        fprintf(arquivo, "Cidade: %s\n", clientes[i].cidade);
        fprintf(arquivo, "Estado: %s\n", clientes[i].estado);
        fprintf(arquivo, "Senha: %d\n", clientes[i].senha);
        fprintf(arquivo, "\n"); // Linha em branco para separar os registros
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("Arquivo %s criado com sucesso!\n", nomeArquivo);
}

//void encerramento_de_conta()

//- MENU -
void menu_funcionario(void)
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
            break;

        case 3:
            // consultar_dados();
            break;

        case 4:
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

void menu_principal()
{
    // MENSAGEM DO "MALVADER'S BANK"

    int opcao;

    do
    {
        printf("MENU PRINCIPAL\n\n");
        printf("1 - Menu funcionario\n");
        printf("2 - Menu cliente\n");
        printf("3 - Sair\n\n");
        fflush(stdin);
        scanf("%d", &opcao);

        if (opcao > 0 && opcao < 4)
        {
            switch (opcao)
            {
            case 1:
                printf("Digite a senha:\n");
                scanf("%d", &senha_funcionario);
                menu_funcionario();
                break;


            case 2:
               menu_cliente();
                break;

            case 3:
                printf("Até logo!\n");
                printf("AQUI O SEU DINHEIRO GANHA FORÇA\n");
                break;
            }
        }
        else
        {
            printf("Numero digitado não corresponde as opções.\n");
        }
    } while (opcao < 0 || opcao > 3);
}

void menu_cliente(){
    
    int opcao;
    printf("MENU CLIENTE\n\n");
    printf("1- Saldo.\n2- Deposito.\n3- Saque.\n4- Extrato.\n5- Consultar limite.\n6- SAIR.\n");
    scanf("%d", &opcao);

    // verificar se o numero digitado é inteiro//

    if (opcao > 0 && opcao < 7)
    {
        switch (opcao)
        {
        case 1:
            // saldo_cliente();
            break;

        case 2:
            // deposito_cliente();
            break;

        case 3:
            // saque_cliente();
            break;

        case 4:
            // extrato_cliente();
            break;

        case 5:
            // consultar_limite();
            break;

        case 6:
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

#endif