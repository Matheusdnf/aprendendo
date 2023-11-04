#include <stdio.h>
#include <string.h>
#include <ctype.h>

void letra_maiuscula_com_espacos(char* algo);

int main(void) {
    char palavra[100];
    
    printf("\nDigite uma palavra ou frase: ");
    scanf(" %[^\n]", palavra); // Usando %[^\n] para ler toda a linha, incluindo espaços.
    
    letra_maiuscula_com_espacos(palavra);

    printf("Palavra/frase em maiúsculas: %s\n", palavra);
    
    return 0;
}

void letra_maiuscula_com_espacos(char* algo) {
    int tam = strlen(algo);
    for (int i = 0; i < tam; i++) {
        algo[i] = toupper(algo[i]);
    }
}
