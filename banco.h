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

//variaveis globais
#define tam 270
int senha_adm= 102938;
int senha_funcionario= 123456;
int senha_cliente= 654321;
int total_funcionarios=0;
int total_clientes=0;
int total_pessoas = total_funcionarios + total_clientes;

// protótipos de funções
void menu_principal();
void menu_funcionario();
void menu_cliente();
void abertura_conta();
void conte_corrente();
void conta_poupanca();
void criarArquivoClientes();
void encerramento_conta();
void consultar_dados();
// void consultar_contas();
// void consultar_clientes();
// void consultar_funcionarios();
// void alterar_dados();
// void alterar_conta();
// void alterar_funcionarios();
// void alterar_clientes();
// void cadastro_funcionario();
// void gerar_relatorios();

// Dados
struct Cliente {
    float saldo;
    char agencia[tam];
    int num;
    float limite;
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
Cliente client[tam];
struct Poupanca{
    char agencia[tam];
    long int num;
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
    long int num;
    float limite;
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

//armazenamento no arquivo
void criarArquivoClientes(const char *nomeArquivo, struct Cliente clientes[], int numClientes){
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



//                  --  MENU FUNCIONARIO  --                               


//1- Abertura de conta - (erro na captura do local do usuario)
void conta_poupanca(){
    char resposta[10]; 
    do {
        for (int i = 0; i < 1; i++) {
            printf("Digite qual a sua agencia:\n");
            scanf("%s", cp[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%ld", &cp[i].num);
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

        printf("Deseja cadastrar mais um cliente/funcionario como conta poupanca? (sim/nao)\n");
        scanf("%s", resposta);
        getchar(); 
    } while (strcmp(resposta, "sim") == 0);
    menu_funcionario();
}
void conta_corrente(){
    char resposta[10]; 

    do {
        for (int i = 0; i < 1; i++) {
            printf("Digite qual a sua agencia:\n");
            scanf("%s", cc[i].agencia);

            printf("Digite o numero da conta:\n");
            scanf("%ld", &cc[i].num);
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
            fgets(cc[i].local,tam, stdin);

            printf("Digite o numero da casa/apartamento:\n");
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

        printf("Deseja cadastrar mais um cliente/funcionario como conta corrente? (sim/nao)\n");
        scanf("%s", resposta);
        getchar();
    } while (strcmp(resposta, "sim") == 0);
    menu_funcionario();
}
void abertura_conta(){    
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


//2- encerramento de conta - (erro na exclusão das contas)
void encerramento_conta(){ 
    int num;
    int opcao;
    char resposta[10];

    printf("ENCERRAMENTO DE CONTA\n\n");
    printf("1- Excluir Conta\n2- Voltar\n");
    scanf("%d", &opcao);

    if(opcao == 2){
        menu_funcionario();
        return;
    }

    do {
        printf("Digite o numero da conta que deseja excluir\n");
        scanf("%d", &num);
        int contaEncontrada = 0;

        // Verifica primeiro nas contas correntes
        for(int i = 0; i < total_pessoas; i++) {
            if(num == cc[i].num) {
                for(int j = i; j < total_pessoas - 1; j++) {
                    cc[j] = cc[j+1];
                }
                total_pessoas--;
                printf("Conta corrente excluida com sucesso!\n\n");
                contaEncontrada = 1;
                break;
            }
        }

        // Se não encontrou na conta corrente, verifica nas contas poupança
        if(!contaEncontrada) {
            for(int i = 0; i < total_pessoas; i++) {
                if(num == cp[i].num) {
                    for(int j = i; j < total_pessoas - 1; j++) {
                        cp[j] = cp[j+1];
                    }
                    total_pessoas--;
                    printf("Conta poupança excluida com sucesso!\n\n");
                    contaEncontrada = 1;
                    break;
                }
            }
        }

        if(!contaEncontrada) {
            printf("Conta excluida ou inexistente.\n\n\n");
            break;
        }

        // ... código posterior ...
    } while(strcmp(resposta, "nao") != 0);
    menu_funcionario();
}


//3- consultar dados - (consultar_contas (adicionar variaveis nas structs cc e cp))
void consultar_dados(){
    int opcao;
    do {
        printf("CONSULTA DE DADOS\n\n");
        printf("1- Consultar Conta\n2- Consultar Funcionario\n3- Consultar Cliente\n4- Voltar\n");
        scanf("%d", &opcao);
        while(getchar() != '\n'); // Limpa o buffer de entrada

        if(opcao >= 1 && opcao <= 4){
            switch (opcao){
                case 1:
                    void consultar_contas();
                    break;

                case 2:
                    //consulta_funcionarios()
                    break;

                case 3:
                    //consultar_clientes()
                    break;

                case 4:
                    menu_funcionario();
                    break;
            }
        } else {
            printf("Numero digitado invalido.\n");
        }
    } while(opcao < 1 || opcao > 4);
}
void consultar_contas(){ 
    int num, contaEncontrada = 0;
    printf("Digite o numero da conta que deseja consultar:\n");
    scanf("%d", &num);
    
    for(int i=0;i<total_pessoas;i++){
        if(num == cc[i].num){ //conta corrente
            contaEncontrada = 1;
            printf("tipo de conta: Conta corrente\n");
            printf("Nome:%s\n", cc[i].nome);
            printf("CPF:%d\n", cc[i].cpf);
            printf("Saldo da conta:%f\n"); // Supondo que saldo é um float
            printf("limite da conta:%f\n", cc[i].limite);
            printf("Data de vencimento:%d\n", cc[i].vencimento);
            system("pause");
            printf("Aperte qualquer tecla.\n");
            consultar_dados();
            break;
        }
        else if (num == cp[i].num){ //conta poupanca
            contaEncontrada = 1;
            printf("tipo de conta: Conta poupanca\n");
            printf("Nome:%s\n", cp[i].nome);
            printf("CPF:%d\n", cp[i].cpf);
            printf("Saldo da conta:%f\n"); // adicionar saldo na struct cp 
            printf("Limite:%f\n"); // adicionar saldo na struct cp
            printf("Data de vencimento:%d\n"); // adicionar saldo na struct 
            system("pause");
            printf("Aperte qualquer tecla.\n");
            consultar_dados();
            break;
        }   
    }
    
    if (!contaEncontrada){
        printf("Conta inexistente ou excluida.\n");
    }
    system("pause");
    menu_funcionario();
}


//4- alterar dados

//5- cadastro de funcionarios

//6- gerar relatorios




//                     -- MENU CLIENTE --  


//1-Saldo

//2-Deposito

//3-Saque

//4-Extrato

//5-Consultar limite




//- MENUS -
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

void menu_funcionario(){
    int opcao;
    int senha;
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
            printf("Digite a senha de administrador:\n");
            scanf("%d", &senha);
            if(senha == senha_adm){
                encerramento_conta();
            }else{
                printf("Senha nao corresponde.\n\n");
                menu_funcionario();
            }
            break;

        case 3:
            consultar_dados();
            break;

        case 4:
            //alterar_Dados
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
    // MENSAGEM DO "MALVADER'S BANK"

    int opcao;
    int senha=0;
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
                printf("Digite a senha de funcionario:\n");
                scanf("%d", &senha);
                if(senha == senha_funcionario){
                    menu_funcionario();
                }else{
                    printf("Senha nao corresponde.\n\n");
                    menu_principal();
                }
                break;


            case 2:
               printf("Digite a senha de cliente:\n");
               scanf("%d", &senha);
               if(senha == senha_cliente){
                 menu_cliente();
               }else{
                printf("Senha nao corresponde.\n\n");
                menu_funcionario();
               }
               
                break;

            case 3:
                printf("Até logo!\n\n");
                printf("AQUI O SEU DINHEIRO GANHA FORCA\n-MALVADER'S BANK\n\n\n");
                break;
            }
        }
        else
        {
            printf("Numero digitado não corresponde as opções.\n");
        }
    } while (opcao < 0 || opcao > 3);
}


#endif