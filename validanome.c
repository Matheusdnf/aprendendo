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
 
// adicionar a parte que após um espaço precisa existir uma letra 
int valida_nome(char* nome) {   //feito com a ajuda do chat gpt
    int tam=strlen(nome); 
    for (int i=0; i<tam-1; i++){ //tam-1 é removendo o caracter nulo /0 
        if (tam==1){       //verificar se o usuário não digitou um espaço em branco 
            return 0; 
        }  
    } if (!isalpha(nome[0])) { //verifica se o primeiro caracter é um número, o ! inverto o valor lógico,como isalpha verifica se há letra 
        return 0;      //todas as letras que le o for encontrada dirá que é falsa e caso encontre um número se tornara verdadeiro logo será removida
    }for (int i = 1; i < tam - 1; i++) {
        if (nome[i] == ' ' && !isalpha(nome[i + 1])) {  // verifica se o caracter adiante não é uma letra,caso for ok caso não acaba
            return 0;                            //também vale caso for número 
        }
    }
    return 1;
} 