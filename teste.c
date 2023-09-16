#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
#include <locale.h>

void esc_semana(void);
void esc_periodo(void);
char valida_periodo(char periodo);


int verdade = 1;
char periodo; // margem de segurança
int main() {
    setlocale(LC_ALL, "Portuguese_Brazil"); // Define a localização para português do Brasil em UTF-8
    while (verdade) {
        esc_periodo(); // Mostra as opções de período
        printf("Digite o período do dia (M, T ou N): ");        
        scanf(" %c",&periodo);
        if (valida_periodo(periodo) == 1) { //[0] está se referindo ao primeiro caracter
            verdade = 0; 
            printf("Entrada válida: %c\n", periodo);
        } else {
            printf("Entrada inválida!\n");
        }
    }
    return 0;
}
void esc_semana(void){   //escolha do dia da semana
    printf("     2-Segunda\n");
    printf("     3-Terça\n");
    printf("     4-Quarta\n");
    printf("     5-Quintsa\n");
    printf("     6-Sexta\n");
    printf("     7-Sábado\n");
}

char valida_periodo(char periodo) {
    char periodo_M = toupper(periodo);
    if (periodo_M == 'M' || periodo_M == 'T' || periodo_M == 'N') {
        return 1;
    } else {
        return 0;
    }
}

void esc_periodo(void) { // Escolha do período do dia
    printf("\n");
    printf("     M-Manhã\n");
    printf("     T-Tarde\n");
    printf("     N-Noite\n");
}
