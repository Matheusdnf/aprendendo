#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int validarCPF(char cpf[]) {
    // Remove os caracteres de pontuação (.) e hífen (-) do CPF
    char cpfNumerico[12]; // Usamos 12 para garantir espaço para o terminador nulo
    int i, j, digito1 = 0, digito2 = 0;

    int len = strlen(cpf);
    int k = 0;

    for (i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpfNumerico[k] = cpf[i];
            k++;
        }
    }

    cpfNumerico[k] = '\0'; // Adiciona o terminador nulo ao final

    if (strlen(cpfNumerico) != 11)
        return 0;
    else if ((strcmp(cpfNumerico, "00000000000") == 0) || (strcmp(cpfNumerico, "11111111111") == 0) ||
             (strcmp(cpfNumerico, "22222222222") == 0) || (strcmp(cpfNumerico, "33333333333") == 0) ||
             (strcmp(cpfNumerico, "44444444444") == 0) || (strcmp(cpfNumerico, "55555555555") == 0) ||
             (strcmp(cpfNumerico, "66666666666") == 0) || (strcmp(cpfNumerico, "77777777777") == 0) ||
             (strcmp(cpfNumerico, "88888888888") == 0) || (strcmp(cpfNumerico, "99999999999") == 0))
        return 0;
    else {
        // Digito 1
        for (i = 0, j = 10; i < 9; i++, j--) {
            digito1 += (cpfNumerico[i] - '0') * j;
        }
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpfNumerico[9] - '0') != digito1)
            return 0;

        // Digito 2
        for (i = 0, j = 11; i < 10; i++, j--) {
            digito2 += (cpfNumerico[i] - '0') * j;
        }
        digito2 %= 11;
        if (digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if ((cpfNumerico[10] - '0') != digito2)
            return 0;
    }

    return 1;
}


int main(void) {
    char cpf[15]; // Matriz de caracteres para armazenar o CPF com espaço para pontos e hífen.
    int teste;
    bool v = true;
    bool f = false;

    while (v) {
        printf("Digite o CPF com ou sem '.' e '-': ");
        scanf("%s", cpf);
        
        // Remova os pontos (.) e hífen (-) do CPF
        int len = strlen(cpf);
        int k = 0;
        for (int i = 0; i < len; i++) {
            if (cpf[i] >= '0' && cpf[i] <= '9') {
                cpf[k] = cpf[i];
                k++;
            }
        }
        cpf[k] = '\0'; // Adicione o terminador nulo ao final

        teste = validarCPF(cpf);
        printf("Como está o CPF: %s\n", cpf);
        
        if (teste == 1) {
            printf("CPF válido.\n");
            v = f;
        } else {
            printf("CPF inválido.\n");
        }
    }

    return 0;
}
