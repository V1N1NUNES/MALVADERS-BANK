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

void encerramento_conta();

void consultar_dados();
void consultar_contas();
// void consultar_clientes();
void consultar_funcionario();

// void alterar_dados();
// void alterar_conta();
// void alterar_funcionarios();
// void alterar_clientes();

void cadastro_funcionario();

// void gerar_relatorios();

void extrato_cliente();
void criarArquivoClientes();
void deposito_cliente();
void saque_cliente();

// Dados
struct Registro
   { 
     float codigo;
    char cargo[tam];
    char nome[tam];
    int cpf;
    int nascimento;
    int telefone;
    char endereco[tam];
    int cep;
    int casa;
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
    int senha;
    int excluido; // Para marcar se o registro está excluído (0 ou 1)
   };
struct Funcionario{
    float saldo;
    char agencia[tam];
    int num;
    float limite;
    int codigo;
    char cargo[30];
    char nome[20];
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
};
Funcionario employee[tam];

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
    int casa;
    char bairro[tam];
    char cidade[tam];
    char estado[tam];
};
Cliente client[tam];

struct Poupanca{
    int saldo;
    int limite;
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
    int datav;
    int senha;
};
struct ContaCorrente {
    int saldo;
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
int Consulta_registro(FILE *arquivo, Registro registro)
 {
  Registro registro_lido;
  int posicao;
  if(arquivo != NULL)
    {
	  fseek(arquivo, 0L, SEEK_SET);
      posicao = 0;
      // repete enquanto nao chega ao final do arquivo
      while(fread(&registro_lido, sizeof(registro_lido), 1, arquivo))
        {
          if(strcmpi(registro_lido.nome, registro.nome)==0 && (registro_lido.excluido == 0))
          return posicao;
          posicao++;
        };
    }
   return -1;
 }
// Função que insere um registro no arquivo
// Retorna:
// 1 se o registro foi incluído com sucesso
// 0 se o registro não pode ser incluído

int Insere_registro(FILE *arquivo, Registro registro)
 {
   Registro registro_lido;
   int posicao ;
   if(arquivo != NULL)
    {
	  posicao = 0;
      if(Consulta_registro(arquivo, registro))
        {
		  fseek(arquivo, 0L, SEEK_SET);
          // repete enquanto nao chega ao final do arquivo
          while(fread(&registro_lido, sizeof(registro_lido), 1, arquivo))
            { 
			  if(registro_lido.excluido == 1)
                break;
                posicao++;
            };
          fseek(arquivo, posicao*sizeof(registro), SEEK_SET);
          registro.excluido = 0;
          if(fwrite(&registro, sizeof(registro), 1, arquivo)) // grava registro
             return 1;
        }
    }
   return 0;
 }
// Função Exclui um registro do arquivo
// Retorna:
// 1 se o registro foi excluído com sucesso
// 0 se o registro não pode ser excluído

int Exclui_registro(FILE *arquivo, Registro registro)
 { 
   int posicao;
   if(arquivo != NULL)
       { 
	      posicao = Consulta_registro(arquivo, registro);
          if(posicao != -1)
            { 
			   fseek(arquivo, posicao*sizeof(registro), SEEK_SET);
               registro.excluido = 1;
               if(fwrite(&registro, sizeof(registro), 1, arquivo))
                  return 1;
            }
        }
    return 0;
 }
// Função que altera um registro do arquivo
// Retorna:
// 1 se o registro foi alterado com sucesso
// 0 se o registro não pode ser alterado

int Altera_registro(FILE *arquivo, Registro registro_antigo, Registro registro_novo)
 { 
    int posicao;

    if (arquivo != NULL) {
        posicao = Consulta_registro(arquivo, registro_antigo);
        if (posicao != -1) {
            fseek(arquivo, posicao * sizeof(Registro), SEEK_SET);
            fread(&registro_antigo, sizeof(Registro), 1, arquivo);
            // Atualiza os dados com os novos valores
            registro_antigo.codigo = registro_novo.codigo;
            strcpy(registro_antigo.cargo, registro_novo.cargo);
            strcpy(registro_antigo.nome, registro_novo.nome);
            registro_antigo.cpf = registro_novo.cpf;
            registro_antigo.nascimento = registro_novo.nascimento;
            registro_antigo.telefone = registro_novo.telefone;
            strcpy(registro_antigo.endereco, registro_novo.endereco);
            registro_antigo.cep = registro_novo.cep;
            registro_antigo.casa = registro_novo.casa;
            strcpy(registro_antigo.bairro, registro_novo.bairro);
            strcpy(registro_antigo.cidade, registro_novo.cidade);
            strcpy(registro_antigo.estado, registro_novo.estado);
            registro_antigo.senha = registro_novo.senha;
            // Volta para a posição do registro no arquivo e escreve as alterações
            fseek(arquivo, posicao * sizeof(Registro), SEEK_SET);
            fwrite(&registro_antigo, sizeof(Registro), 1, arquivo);
            return 1; // Sucesso na alteração
        }
    }
    return 0; // Falha na alteração (registro não encontrado ou erro de arquivo)
}

void incluirFuncionario() {
  FILE *Arquivo;
    Registro novoFuncionario;

    Arquivo = fopen("funcionarios.txt", "a+");
    if (Arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

	printf("\n Preencha os campos para cadastramento do novo Funcionario. \n\n");

    printf("Digite o codigo do funcionario: \n");
    scanf("%f", &novoFuncionario.codigo);

    printf("Digite o cargo do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.cargo);

    printf("Digite o nome do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.nome);

    printf("Digite o CPF do funcionario: \n");
    scanf("%d", &novoFuncionario.cpf);

    printf("Digite a data de nascimento do funcionario: \n");
    scanf("%d", &novoFuncionario.nascimento);

    printf("Digite o telefone do funcionario: \n");
    scanf("%d", &novoFuncionario.telefone);

    printf("Digite o endereco do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.endereco);

    printf("Digite o CEP do funcionario: \n");
    scanf("%d", &novoFuncionario.cep);

    printf("Digite o numero da casa do funcionario: \n");
    scanf("%d", &novoFuncionario.casa);

    printf("Digite o bairro do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.bairro);

    printf("Digite a cidade do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.cidade);

    printf("Digite o estado do funcionario: \n");
    scanf(" %[^\n]", novoFuncionario.estado);

    printf("Digite a senha do funcionario: \n");
    scanf("%d", &novoFuncionario.senha);

    Insere_registro(Arquivo, novoFuncionario);

    fclose(Arquivo);
    
    return menu_funcionario();
}





//                  --  MENU FUNCIONARIO  --                               


// 1- Abertura de conta - (erro na captura do local do usuario)
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
        total_pessoas++; // Incrementa o contador de funcionários/clientes

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
        total_pessoas++; 

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



// 2- encerramento de conta - (erro na exclusão das contas)
void encerramento_conta(){ 
    int num;
    int opcao;
    char resposta[tam];

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
        printf("Deseja excluir mais contas?\n");
        scanf("%s", resposta);
        getchar();
        // ... código posterior ...
    } while(strcmp(resposta, "nao") != 0);
    menu_funcionario();
}



// 3- consultar dados - //consultar_contas (saber o porque não esta funcionando a função)//  - //Consultar_funcionarios (revisar a função)// )
void consultar_dados(){
    int opcao;
    do {
        printf("CONSULTA DE DADOS\n\n");
        printf("1- Consultar Contas\n2- Consultar Funcionario\n3- Consultar Cliente\n4- Voltar\n");
        scanf("%d", &opcao);
        if(opcao >= 1 && opcao <= 4){
            switch (opcao){
                case 1:
                    void consultar_contas();
                    break;

                case 2:
                    void consultar_funcionarios();
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
    int num;
    int contaEncontrada = 0;
    printf("Digite o numero da conta que deseja consultar:\n");
    scanf("%d", &num);
    
    for(int i=0;i<total_pessoas;i++){
        if(num == cc[i].num){ //conta corrente
            contaEncontrada = 1;
            printf("tipo de conta: Conta corrente\n");
            printf("Nome:%s\n", cc[i].nome);
            printf("CPF:%d\n", cc[i].cpf);
            printf("Saldo da conta: %d\n", cc[i].saldo);
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
            printf("Saldo da conta: %d\n", cp[i].saldo);
            printf("Limite: %d\n",cp[i].limite);
            printf("Data de vencimento:%d\n", cp[i].datav);
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
void consultar_clientes(){
    int num;
    int contaEncontrada;

    printf("Digite o numero da conta que deseja consultar:\n");
    scanf("%d", &num);

    for(int i=0;i<total_clientes;i++){
        if(num == client[i].num){
            contaEncontrada = 1;
            printf("Nome:%s\n",client[i].nome);
            printf("CPF:%d\n",client[i].cpf);
            printf("Data de nascimento:%d\n", client[i].nascimento);
            printf("Telefone:%d\n", client[i].telefone);
            printf("Endereço:%s\n", client[i].endereco);
            printf("N. casa/apt:%d\n", client[i].casa);
            printf("CEP:%d", client[i].cep);
            printf("Bairro:%s", client[i].bairro);
            printf("Cidade:%s", client[i].cidade);
            printf("Estado:%s", client[i].estado);
            break;
        }
    }
    if (!contaEncontrada){
        printf("Conta inexistente ou excluida.\n");
    }
    system("pause");
    menu_funcionario();
}
void consultar_funcionarios() {
    FILE *Arquivo;
    Registro registro_lido;

    Arquivo = fopen("funcionarios.txt", "r");
    if (Arquivo == NULL) {
        printf("Erro na abertura do arquivo.\n");
        return;
    }

    printf("Funcionários cadastrados:\n");

    // Lê e imprime todos os registros não excluídos
    while (fread(&registro_lido, sizeof(Registro), 1, Arquivo) == 1) {
        if (registro_lido.excluido == 0) {
            printf("Código: %.2f\n", registro_lido.codigo);
            printf("Cargo: %s\n", registro_lido.cargo);
            printf("Nome: %s\n", registro_lido.nome);
            printf("CPF: %d\n", registro_lido.cpf);
            printf("Nascimento: %d\n", registro_lido.nascimento);
            printf("Telefone: %d\n", registro_lido.telefone);
            printf("Endereço: %s\n", registro_lido.endereco);
            printf("CEP: %d\n", registro_lido.cep);
            printf("Casa: %d\n", registro_lido.casa);
            printf("Bairro: %s\n", registro_lido.bairro);
            printf("Cidade: %s\n", registro_lido.cidade);
            printf("Estado: %s\n", registro_lido.estado);
            printf("Senha: %d\n", registro_lido.senha);
            printf("--------------------\n");
        }
    }

    fclose(Arquivo);
}



// 4- alterar dados
// void alterar_dados()
// void alterar_conta
// void alterar_funcionarios
// void alterar_clientes



// 5- cadastro de funcionarios
void cadastro_funcionarios(){
    char resposta[10];
    do{
       for(int i=0;i<1;i++){
        printf("CADASTRO DE FUNCIONARIO\n\n");

            printf("Digite o codigo do funcionario:\n");
            printf("Digite o nome:\n");
            getchar(); 
            fgets(cc[i].nome, tam, stdin);

            printf("Digite o CPF:\n");
            scanf("%d", &employee[i].cpf);

            printf("Digite a data de nascimento:\n");
            scanf("%d", &employee[i].nascimento);

            printf("Digite o telefone/celular:\n");
            scanf("%d", &employee[i].telefone);
            getchar(); 

            printf("Digite o endereco do cliente:\n");
            fgets(employee[i].endereco, tam, stdin);

            printf("Digite o CEP:\n");
            scanf("%d", &employee[i].cep);

            printf("Digite o numero da casa/apartamento:\n");
            scanf("%d",&employee[i].casa);
            getchar(); 

            printf("Digite o bairro:\n");
            fgets(employee[i].bairro, tam, stdin);

            printf("Digite a cidade:\n");
            fgets(employee[i].cidade, tam, stdin);

            printf("Digite o estado:\n");
            fgets(employee[i].estado, tam, stdin);

            printf("Digite a senha do funcionario:\n");
            scanf("%d", &employee[i].senha);
       }
        printf("Conta cadastrada com sucesso!!\n");
        total_funcionarios++;  
        printf("Deseja cadastrar mais um cliente?\n");
        scanf("%s", resposta);
    }while (strcmp(resposta, "sim") == 0);
    menu_cliente();

}


// 6- gerar relatorios
//  void gerar_relaroios
// void relatorio_geral



//                     -- MENU CLIENTE --  


//1-Saldo



//2-Deposito - //revisar a função//
void deposito_cliente() {
    int saldo = 2000; // Saldo inicial de 2000 reais
    int valor;

    // Entrada do valor a ser depositado
    printf("Digite o valor a ser depositado: ");
    if (scanf("%d", &valor) != 1 || valor <= 0) {
        printf("Valor de depósito inválido.\n");
        return;
    }

    // Atualização do saldo
    saldo += valor;
    printf("Depósito realizado com sucesso.\n");
    printf("Novo saldo: %d\n", saldo);
}


//3-Saque - //revisar a função//
void saque_cliente() {
    int valores_notas[] = {100, 50, 20, 10, 5, 2, 1};
    int saldo = 2000; // Saldo inicial de 2000 reais
    int notas[7] = {0}; // Inicializar array de notas com zero
    int valor;


    // Entrada do valor do saque
    printf("Digite o valor do saque: ");
    if (scanf("%d", &valor) != 1 || valor < 0) {
        printf("Entrada inválida.\n");
        return;
    }

    // Verificação do saldo
    if (valor > saldo) {
        printf("Saldo insuficiente.\n");
        return;
    }

    // Processo de saque
    for (int i = 0; i < 7; i++) {
        notas[i] = valor / valores_notas[i];
        valor %= valores_notas[i];
    }

    // Imprimir as notas
    printf("Notas:\n");
    for (int i = 0; i < 7; i++) {
        if (notas[i] > 0) {
            printf("%d notas de %d\n", notas[i], valores_notas[i]);
        }
    }

    // Atualizar o saldo
    saldo -= valor;
    printf("Dinheiro sacado com sucesso.\n");
    printf("Novo saldo: %d\n", saldo);
}


//4-Extrato
void extrato_cliente(){
    char comando[100];
    char nomeArquivo[] = "extrato.xlsx";

    // Construir o comando para iniciar o Excel com o arquivo .xlsx
    sprintf(comando, "start excel.exe %s", nomeArquivo);

    // Executar o comando usando system
    int status = system(comando);

    if (status == 0) {
        printf("Excel foi aberto com sucesso.\n");
    } else {
        printf("Erro ao abrir Excel.\n");
    }

    return ;
}

//5-Consultar limite


//6-cadastro cliente
void cadastro_cliente(){ //verificar se esta funcionando//
    char resposta[tam];
    do{
       for(int i=0;i<1;i++){
        printf("CADASTRO DE CLIENTES\n\n");

        printf("Digite o nome:\n");
        scanf("%s", client[i].nome);

        printf("Digite o CPF:\n");
        scanf("%d", &client[i].cpf);

        printf("Digite a data de nascimento:\n");
        scanf("%d", &client[i].nascimento);

        printf("Digite o telefone de contato:\n");
        scanf("%d",&client[i].telefone);
        getchar();

        printf("Digite o endereco do cliente:\n");
        fgets(client[i].endereco, tam, stdin);  

        printf("Digite o CEP:\n");
        scanf("%d", &client[i].cep);

        printf("Digite o numero da casa/apartamento:\n");
        scanf("%d", &client[i].casa);
        getchar(); 

        printf("Digite o bairro:\n");
        fgets(client[i].bairro, tam, stdin);

        printf("Digite a cidade:\n");
        fgets(client[i].cidade, tam, stdin);

        printf("Digite o estado:\n");
        fgets(client[i].estado, tam, stdin);
        }

        total_clientes++;
        printf("Conta cadastrada com sucesso!!\n");
        printf("Deseja cadastrar mais um cliente?\n");
        scanf("%s", resposta);
    }while (strcmp(resposta, "sim") == 0);
    menu_cliente();
}


//7- sair


//- MENUS -
void menu_cliente(){
    int senha=0;
    int opcao;
    printf("MENU CLIENTE\n\n");
    printf("1- Saldo.\n2- Deposito.\n3- Saque.\n4- Extrato.\n5- Consultar limite.\n6- Cadastrar cliente\n7- Voltar\n");
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
            printf("Digite a senha de administrador:\n");
            scanf("%d", &senha);
            if(senha == senha_adm){
                cadastro_cliente();
            }else{
                printf("Senha nao corresponde.\n\n");
                menu_cliente();
            }
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

void menu_funcionario(){
    int opcao;
    int senha=0;
    printf("MENU FUNCIONARIO\n\n");
    printf("1- Abertura de conta.\n2- Encerramento da conta.\n3- Consultar dados.\n4- Alterar dados.\n5- Cadastro de funcionario.\n6- Gerar relatoios.\n7- Voltar\n");
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
            printf("Digite a senha de administrador:\n");
            scanf("%d", &senha);
            if(senha == senha_adm){
                cadastro_funcionario();
            }else{
                printf("Senha nao corresponde.\n\n");
                menu_funcionario();
            }
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