#pragma once


typedef struct{
  int error;// 1 si hubo algun error, O si no hubo errores
  int*tokens;// list of tokens
  unsigned int length;// numero de tokens encontrados
}LexerResult ;

LexerResult RunLexicalAnalisys(const char *buffer,const int length);

void printLexerResult(const LexerResult* const r);

void printLexerResultWords(const LexerResult* const r);

void freeLexerResult(LexerResult *const lr);
