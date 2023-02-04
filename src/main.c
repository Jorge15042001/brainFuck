#include "lexer.h"
#include "utils.h"
#include "token.h"
#include "interpreter.h"


#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>



int main(void){

  printf("Brainkfuck interpreter\n");

  while (1) {

    printf(">>");
    //leer una cadena de consola y pasarla por el analizador sintactico
    
    char * const brainfuck_src = inputString();
    if ( strcmp (brainfuck_src,"quit")==0)break;
    const LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));

    // create an interpreter

    ProgramState state = NewInterpreter(&r);

    executeProgram(&state);

    DelInterpreter(&state);

    //liberar los recursos
    free(brainfuck_src);
  }
}
