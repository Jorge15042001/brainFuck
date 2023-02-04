#pragma once


#include <stddef.h>
typedef struct{
  int error;// 1 si hubo algun error, O si no hubo errores
  int* tokens;// list of tokens
  size_t length;// numero de tokens encontrados
}LexerResult ;

LexerResult RunLexicalAnalisys(const char *buffer,const size_t length);

void printLexerResult(const LexerResult* const r);

void printLexerResultWords(const LexerResult* const r);

void freeLexerResult(LexerResult *const lr);
