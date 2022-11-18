#include "lexer.h"
#include "utils.h"


#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main(){
  printf("Brainkfuck interpreter \n");
  while (1) {
    //leer una cadena de consola y pasarla por el analizador sintactico


    printf("Ingrese un sting de brainfuck a ser analizado: ");
    char * const brainfuck_src = inputString();
    //aplicar analizador sintactico


    printf("\nResultado del analisis Lexico \n");
    printf("\nAun no ha sido implentado... :c  \n");



    //liberar los recursos
    free(brainfuck_src);
  }
  

}
