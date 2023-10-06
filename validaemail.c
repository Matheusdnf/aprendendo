#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool v=true; 
bool f=false; 

void ler_email(char *email);
int valida_email(char* email);

int valida_email(char* email) {
  int tam = strlen(email);
  int arroba = 0, ponto = 0, antesPonto = 0, depoisPonto = 0, i;

  for (i = 0; i < tam; i++) {
    char c = email[i];
    if (c == '@') {
      if (arroba)
        break; // não pode ter uma segunda @
      arroba = 1;
      if (i < 3)
        break; // se @ vier antes de 3 caracteres, erro
    } else if (arroba) { // se já encontrou @
      if (ponto) { // se já encontrou . depois de @
        depoisPonto++;
      } else if (c == '.') {
        ponto = 1;
        if (antesPonto < 3) {
          break; // se . depois de @ vier antes de 3 caracteres, erro
        }
      } else {
        antesPonto++;
      }
    }
  }

  if (i == tam && depoisPonto > 1)
    return 1; // É um email válido
  else
    return 0; // Não é um email válido
}

int main(void) {
  char email[50];
  ler_email(email);
}

void ler_email(char *email){
    int n; 
    while (v){ 
      printf("Digite um endereço de e-mail: ");
      scanf("%s", email);
      n=valida_email(email); 
      if (n==1){ 
        printf("válido\n"); 
      }else if (n==0){ 
        printf("inválido\n"); 
        } 
    } 
}  


