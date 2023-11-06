#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool v = true;
bool f = false;

void teste(void);
void ler_diciplina(char *diciplina);
int valida_diciplina(char *diciplina);
void limpar_buffer();
void diciplinas(void);
void letra_maiuscula(char* algo);

int main(void) {
    diciplinas(); // Exibe a lista de disciplinas
    teste();
    return 0;
}

void teste(void) {
    char diciplina[3]; 
    ler_diciplina(diciplina);
}

void ler_diciplina(char *diciplina) {
    int t;
    while (v) {
        printf("Digite a disciplina (somente maiúsculas):");
        scanf("%s", diciplina);
        fflush(stdin);
        t = valida_diciplina(diciplina);
        printf("%d\n",t);
        if (t == 1) {
            printf("válido\n");
            v = f; 
        } else{
            printf("inválido\n");
        }
    }
}


int valida_diciplina(char *diciplina) {
    //feito com ajuda de maria eloisa
    int tam = strlen(diciplina);
    //Só é permitidos 1 ou 2 matérias por vez
    //string que contem todas as iniciais referentes as diciplinas
    if ((tam!=2) && (tam!=1)){
        return 0;
    }
    //não permitir que o usuário digite duas letras iguais
    else if (tam==2 && diciplina[0]==diciplina[1]){
        return 0;
    }
    int cont=0;
    //permitir que o usuário digite a letra da maneira que preferir
    //apos isso chamara essa função que tratara os dados
    letra_maiuscula(diciplina);
    //um array com as iniciais das letras das matérias
    char materia[]="PIEAHGLOSMBQF";
    //caso o usuário digitar só uma letra cairá nesse if
    if (tam==1){
        //rodará 13 vezes que é referente a quantidade de diciplinas
        for (int i=0 ; i<13;i++){
            //diciplina [0] referindo ao primeiro índice
            if (diciplina[0] == materia[i]) {
                return 1;
            }
        }
    }
    //caso o usuário digitar duas matérias
    else if (tam==2 ){
        //esse for vai rodar 2 vezes para pegar ambas as posições
        for (int i=0 ; i<2;i++){
            //rodará 13 vezes que é referente a quantidade de diciplinas
            for (int j=0 ; j<13;j++){
                if (diciplina[i] == materia[j]){
                    cont++;
                }
            }
        }
        //para poder rodar duas vezes e conferir ambos os caracter
        if (cont!=2){
            return 0;
        }
        else{
            return 1;
        }
    }
    //verificar a questão dos espaços e a ocorrência de números
    for (int i = 0; i < tam; i++) {
        if (!isalpha(diciplina[i]) && !isspace(diciplina[i])) {
            return 0;
        }
    }
    return 1;
}

void diciplinas(void) {
    printf("P-Português\n");
    printf("I-Inglês\n");
    printf("E-Espanhol\n");
    printf("A-Artes\n");
    printf("H-História\n");
    printf("G-Geografia\n");
    printf("L-Literatura\n");
    printf("É-Filosofia\n");
    printf("S-Sociologia\n");
    printf("M-Matemática\n");
    printf("B-Biologia\n");
    printf("Q-Química\n");
    printf("F-Física\n");
}

void letra_maiuscula(char* algo) {
    //pega o tamanho para saber até onde tera que rodar
    int tam = strlen(algo);
    for (int i = 0; i < tam; i++) {
        algo[i] = toupper(algo[i]);
    }
}