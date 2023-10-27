#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
#include <locale.h>
 
bool v=true; 
bool f=false; 
 
int verificarnum(char* algo);
char geraid(void);
int verificatam(char *algo);

int main(void) {
    char nome[100]; 
    geraid();

    return 0;
}

int verificarnum(char* algo){
    int tam = strlen(algo);
    for (int i=0; i<tam; i++){
        if (isalpha(algo[i])){
            return 0;
        }
    }
    return 1;
}

int verificatam(char *algo){
    int tam = strlen(algo);
    if (tam!=4){
        return 0;
    }
    return 1;
}

char geraid(void){
    //usar um contador para contar os ids caso sejam repetidos
    //não poder ser letra
    //ser composto por 4 digitos

}