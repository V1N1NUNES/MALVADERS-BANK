#ifndef banco.h
#define banco.h

//adicionando as bibliotecas que seram utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
#include <stdbool.h>
#include <errno.h>

//protótipos de funções, variaveis globais, ....
void menu_principal();
void menu_funcionario();
void menu_cliente();
void abertura_conta();
void conte_corrente();
void conta_poupanca();
void encerramento_conta();
void consultar_dados();
void consultar_contas();
void consultar_clientes();
void consultar_funcionarios();
void alterar_dados();
void alterar_conta();
void alterar_funcionarios();
void alterar_clientes();
void cadastro_funcionario();
void gerar_relatorios();


#define  tam 270
int senha_adm= 102938;
int senha_funcionario= 123456;
int senha_cliente= 123456;
int total_clientes=0;
int total_funcionarios=0;
int total_pessoas= total_clientes + total_funcionarios;



typedef struct{
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
    char bairro [tam];
    char cidade[tam];
    char estado[tam];
    int senha;
} poupanca;
poupanca cp[tam];
typedef struct{
    char agencia[tam];
    int num;
    int limite;
    int vencimento;
    char nome[tam];
    int cpf;
    int nascimento;
    int telefone;
    char endereco[tam];
    int cep;
    char local[tam];
    int casa;
    char bairro [tam];
    char cidade[tam];
    char estado[tam];
    int senha;
} corrente;
corrente cc[tam];






//1- abertura de contas
void conta_poupanca(){
    char resposta[5];
    do{
        for(int i=0;i<1;i++){
            printf("Digite qual a sua agencia:\n");
            scanf("%s", &cp[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%d", &cp[i].num);

            printf("Digite o nome do cliente:\n");
            fgets(cp[i].nome,tam,stdin);

            printf("Digite o CPF:\n");
            scanf("%d", &cp[i].cpf);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &cp[i].nascimento);

            printf("Digite o telefone/celular:\n");
            scanf("%d", cp[i].telefone);

            printf("Digite o endereco do cliente:\n");
            fgets(cp[i].endereco, tam, stdin);

            printf("Digite o CEP:\n");
            scanf("%d", &cp[i].cep);
            
            printf("Digite o local:\n");
            fgets(cp[i].local,tam,stdin);

            printf("Digite o numero da  casa:\n");
            scanf("%d", &cp[i].casa);

            printf("Digite o bairro:\n");
            fgets(cp[i].bairro,tam,stdin);

            printf("Digite a cidade:\n");
            fgets(cp[i].cidade,tam,stdin);

            printf("Digite o estado:\n");
            fgets(cp[i].estado,tam,stdin);

            printf("Digite a senha do cliente:\n");
            scanf("%d", &cp[i].senha);

        }
    total_funcionarios ++;  //adicionar conta como funcionarios ou clientes??//
    printf("Deseja cadastrar mais um cliente/funcionario?\n");
    scanf("%s", &resposta);
    }while (strcpy(resposta,"sim")==0);
    
}
void conta_corrente(){
    char resposta[5];
    do{
        for(int i=0;i<1;i++){
            printf("Digite qual a sua agencia:\n");
            scanf("%s", &cc[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%d", &cc[i].num);

            printf("Digite o limite da conta:\n");
            scanf("%f", &cc[i].limite);

            printf("Digite o a data de vencimento:\n");
            scanf("%d", &cc[i].vencimento);

            printf("Digite o nome do cliente:\n");
            fgets(cc[i].nome,tam,stdin);

            printf("Digite o CPF:\n");
            scanf("%d", &cc[i].cpf);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &cc[i].nascimento);

            printf("Digite o telefone/celular:\n");
            scanf("%d", cc[i].telefone);

            printf("Digite o endereco do cliente:\n");
            fgets(cc[i].endereco,tam,stdin);

            printf("Digite o CEP:\n");
            scanf("%d", &cc[i].cep);
            
            printf("Digite o local:\n");
            fgets(cc[i].local,tam,stdin);

            printf("Digite o numero da  casa:\n");
            scanf("%d", &cc[i].casa);

            printf("Digite o bairro:\n");
            fgets(cc[i].bairro,tam,stdin);

            printf("Digite a cidade:\n");
            fgets(cc[i].cidade,tam,stdin);

            printf("Digite o estado:\n");
            fgets(cc[i].estado,tam,stdin);

            printf("Digite a senha do cliente:\n");
            scanf("%d", &cc[i].senha);

        }
    total_funcionarios ++;  //adicionar conta como funcionarios ou clientes??//
    printf("Deseja cadastrar mais um cliente/funcionario?\n");
    scanf("%s", &resposta);
    }while (strcpy(resposta,"sim")==0);
}
void abertura_conta(){
    int opcao=0;
    printf("ABERTURA DE CONTA\n\n");
    printf("1- Conta poupança\n2- Conta corrente\n3- Voltar\n");
    scanf("%d", &opcao);
    if(opcao <= 0 && opcao >= 4){
        printf("numero informado invalido.\n");
        menu_funcionrio();
    }else if(opcao >= 1 && opcao <= 3){
        switch (opcao){
            case 1:
            conta_poupanca();
            break;

            case 2:
            conta_corrente();
            break;

            case 3:
            menu_funcionrio();
            break;
        }
    }
}


void menu_principal(){
//MENSAGEM DO "MALVADER'S BANK"

fopen 
    printf("MENU PRINCIPAL\n\n1-Funcionarios\n2-Clientes\n3-Sair do programa.\n ");
}





















#endif