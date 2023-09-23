#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void removerCaracteresNaoNumericos(char cpf[]) {
    int len = strlen(cpf);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpf[k] = cpf[i];
            k++;
        }
    }
    cpf[k] = '\0'; // Adicione o terminador nulo ao final
}

int validarCPF(char cpf[]) {
    // Remova os caracteres de pontuação (.) e hífen (-) do CPF
    removerCaracteresNaoNumericos(cpf);

    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) ||
             (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
             (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
             (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
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
            return 0;

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
