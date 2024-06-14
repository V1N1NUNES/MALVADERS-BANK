#include <stdio.h>
#include "banco.h"

int main(){
//abrindo o arquivo para leitura
    FILE *file = fopen("funcionarios.txt", "r");

//verificando se tiver erro
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo 'funcionarios.txt'\n");
        return 1;
    }
    
//chamando a função principal
    menu_principal();

//fechando o arquivo
    fclose(file);
    return 0;
}