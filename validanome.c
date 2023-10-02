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
        }else if (n==0){ 
            printf("inválido\n"); 
        } 
    } 
}  
 

// Função personalizada para verificar se um caractere é uma letra (incluindo acentos)
// Desenvolvida com akuda do chat gpt
bool eh_letra_acentuada(char c) {   //recebe uma letra por vez
    //um char com as palavras que possam vir a ser acentuadas
    char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç"; 
    //ela roda um loop que termina até o caracter nulo do fgets
    for (int i = 0; letras_acentuadas[i] != '\0'; i++) {  
        // aí se a letra em questão for igual ao char letras_acentuadas retornará vdd
        //esse loop e esse if verificiarão toda as letras
        if (c == letras_acentuadas[i]) {
            return true;
        }
    }
    //verifica se a letra c é uma letra ou um espaço em branco 
    return isalpha(c) || c == ' ';
}

int valida_nome(char *nome) {
    // Pega o tamanho da variável nome
    int tam = strlen(nome);
    //só permite nome maiores que 2 letras 
    // é utilizado 3 para contar com o \n do teclado
    if (tam<3){
        return 0;
    }
    // Verificar se o usuário não digitou um espaço em branco,tanto no ínicio como no final
    if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) {
        return 0;
    }
    //esse loop serve para procurar a questão de números
    for (int j = 0; j < tam - 1; j++) {
        if (!eh_letra_acentuada(nome[j])) {
            return 0;
        }
    }
    // Verifica se dois espaços em branco consecutivos
    for (int i = 0; i < tam - 2; i++) {
        if ((isspace(nome[i])) && (isspace(nome[i + 1]))) {
            return 0;
        }
    }
    return 1;
}
