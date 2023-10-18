#include <stdio.h>


// Declaração da função
int valida_data(int dia, int mes, int ano);


int main(void) {
   int dia, mes, ano;
   printf("Digite o dia no formato dd/mm/aa: ");
   scanf("%d%*c%d%*c%d", &dia, &mes, &ano);
   if (valida_data(dia, mes, ano)) {
       printf("Data válida.\n");
   } else {
       printf("Data inválida.\n");
   }
   return 0;
}


// Definição da função
// função retirada do site vivao linux por angelito monteiro goulart
int valida_data(int dia, int mes, int ano)
   {
   if ((dia >= 1 && dia <= 31) && (mes >= 1 && mes <= 12) && (ano >= 1900 && ano <= 2100)) //verifica se os numeros sao validos
       {
           if ((dia == 29 && mes == 2) && ((ano % 4) == 0)) //verifica se o ano e bissexto
           {
               return 1;
           }
           if (dia <= 28 && mes == 2) //verifica o mes de feveireiro
           {
               return 1;
           }
           if ((dia <= 30) && (mes == 4 || mes == 6 || mes == 9 || mes == 11)) //verifica os meses de 30 dias
           {
               return 1;
           }
           if ((dia <=31) && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes ==8 || mes == 10 || mes == 12)) //verifica os meses de 31 dias
           {
               return 1;
           }
           else
           {
               return 0;
           }
     }
      else
          {
               return 0;
          }
}

