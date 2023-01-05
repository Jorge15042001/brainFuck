#include "lexer.h"
#include "utils.h"
#include "token.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int BUFFER_SIZE = 3000;

int main(){

  printf("Brainkfuck interpreter");

  while (1) {

    printf("\nIngrese un sting de brainfuck a ser analizado: ");
    //leer una cadena de consola y pasarla por el analizador sintactico
    
    char * const brainfuck_src = inputString();
    char * const buffer = calloc(0, BUFFER_SIZE*sizeof(char));
    int pos = 0;

    // printf("\nResultado del analisis Lexico \n");
    LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));
    // printLexerResult(&r);


    printf("\nResultado del analisis Sintáctico \n");
    //aplicar analizador sintactico
    int unmatchedBracketCounter = 0;


    for (unsigned int i = 0; i < r.length; i++)
    {
      int t = r.tokens[i];
      // printf("%d\n", t);
      switch (t)
      {
      case PLUS:
        buffer[pos]++;
        break;

      case LESS_THAN:
        pos--;
        break;

      case GREATER_THAN:
        pos++;
        break;
      
      case MINUS:
        buffer[pos]--;
        break;

      case DOT:
        printf("%c",buffer[pos]);
        break;
      
      case COMMA:
        buffer[pos] = getchar();
        break;

      case LBRACE:

        if (buffer[pos] == 0)
        {
          unmatchedBracketCounter++;
          while (t != RBRACE || unmatchedBracketCounter != 0)
          {
            i++;
            t = r.tokens[i];
            if (t == LBRACE) unmatchedBracketCounter++;
            else if (t == RBRACE) unmatchedBracketCounter--;
          }
        }
        break;
      
      case RBRACE:
        if (buffer[pos] != 0)
          {
            unmatchedBracketCounter++;
            while (t != LBRACE || unmatchedBracketCounter != 0)
            {
              i--;
              t = r.tokens[i];
              if (t == RBRACE) unmatchedBracketCounter++;
              else if (t == LBRACE) unmatchedBracketCounter--;
            }
          }
          break;

      default:
        printf("Token no reconocido :c\n");
        break;
      }
    }
    
    //liberar los recursos
    free(brainfuck_src);
  }
}
