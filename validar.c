#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int validarCPF(char cpf[]) {  //validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
    int i, j, digito1 = 0, digito2 = 0;
    if (strlen(cpf) != 11)//strlen calcula o tamanho da string
        return 0;
    else if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) || (strcmp(cpf,"22222222222") == 0) ||
            (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) || (strcmp(cpf,"55555555555") == 0) ||
            (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) || (strcmp(cpf,"88888888888") == 0) ||
            (strcmp(cpf,"99999999999") == 0))
        return 0; // Se o CPF tiver todos os números iguais, ele é inválido.
    else {
        // Digito 1
        for (i = 0, j = 10; i < 9; i++, j--) {
            digito1 += (cpf[i] - '0') * j;
        }
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0; // Se o dígito 1 não for o mesmo que o da validação, o CPF é inválido.
        else {
            // Digito 2
            for (i = 0, j = 11; i < 10; i++, j--) {
                digito2 += (cpf[i] - '0') * j;
            }
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - '0') != digito2)
                return 0; // Se o dígito 2 não for o mesmo que o da validação, o CPF é inválido.
        }
    }
    return 1; // O CPF é válido.
}

bool v=true;
bool f=false;

int main(void) {
    char cpf[12]; // Matriz de caracteres para armazenar o CPF.
    int teste;
    while (v){
        printf("Digite o CPF sem '.' e '-':");
        scanf("%s", cpf);
        teste = validarCPF(cpf);
        if (teste == 1) {
            printf("CPF válido.\n");
            v=f;
        } else {
            printf("CPF inválido.\n");
        } 
    }
        return 0;
    }


