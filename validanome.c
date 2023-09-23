#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool v=true;
bool f=false;

void teste(void);
void ler_nome(char* nome);
int valida_nome(char* nome);

int main() {
    teste();
    return 0;
}

void teste(void){
    char nome[100];
    ler_nome(nome);
}

void ler_nome(char* nome){
    int n;
    while (v){
        printf("Digite seu nome:");
        fgets(nome,100,stdin);
        n=valida_nome(nome);
        if (n==1){
            printf("válido\n");
            v=f;
        }else if (n==0){
            printf("inválido\n");
        }
    }
} 

// adicionar a parte que após um espaço precisa existir uma letra
int valida_nome(char* nome) {
    int tam=strlen(nome);
    for (int i=0; i<tam-1; i++){ //tam-1 é removendo o caracter nulo /0
        if (tam==1){       //verificar se o usuário não digitou um espaço em branco
            return 0;
        } 
    for (int i=0 ; i<tam ;i++){   //i<tam circula até o tamanho máximo do char   //circula toda a palavra a procura de um número
        if (isalpha(nome[i])==0){   
            return 0;  
        }
        return 1;
        }
    }
}


