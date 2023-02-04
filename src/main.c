#include "lexer.h"
#include "utils.h"
#include "token.h"
#include "interpreter.h"


#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(void){

  printf("Brainkfuck interpreter");

  while (1) {

    printf("\nIngrese un sting de brainfuck a ser analizado: ");
    //leer una cadena de consola y pasarla por el analizador sintactico
    
    char * const brainfuck_src = inputString();
    const LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));

    // create an interpreter

    ProgramState state = NewInterpreter(&r);

    executeProgram(&state);

    DelInterpreter(&state);

    //liberar los recursos
    free(brainfuck_src);
  }
}
