#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> 
#include <stdbool.h>
#include <locale.h>



int main() {
    char *palavra;
    printf("Digite um palavra:");
    scanf("%s",palavra);
    for (int i=0;palavra[i];i++){
        printf("essa é a %d° palavra %c\n",i,palavra[i]);
    }
    return 0;
}