#include "lexer.h"


#include <malloc.h>

LexerResult RunLexicalAnalisys(const char *buffer,const int length){
  int * const tokens = malloc(length*sizeof(int));

  //logica para leer tokens

  const LexerResult result={0,tokens,length};
  return result;
}
void printLexerResult(const LexerResult* const r){ 
  // imprimir los resultados del lexer
}

void freeLexerResult(LexerResult *const lr){
  free(lr->tokens);
}
