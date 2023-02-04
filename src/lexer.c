#include "lexer.h"
#include "../src/token.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

LexerResult RunLexicalAnalisys(const char *buffer, const size_t length) {
  int *const tokens = malloc(length * sizeof(int));
  int errs = 0;

  // logica para leer tokens
  for (size_t i = 0; i < length; i++) {
    char valor = buffer[i];

    switch (valor) {
    case '>':
      tokens[i] = GREATER_THAN;
      break;
    case '<':
      tokens[i] = LESS_THAN;
      break;
    case '+':
      tokens[i] = PLUS;
      break;
    case '-':
      tokens[i] = MINUS;
      break;
    case '.':
      tokens[i] = DOT;
      break;
    case ',':
      tokens[i] = COMMA;
      break;
    case ']':
      tokens[i] = RBRACE;
      break;
    case '[':
      tokens[i] = LBRACE;
      break;
    case 0:
      tokens[i] = EOF;
      break;
    default:
      tokens[i] = ILLEGAL;
      errs = 1;
      break;
    }
  }

  const LexerResult result = {errs, tokens, length};
  return result;
}

void printLexerResult(const LexerResult *const r) {
  // imprimir los resultados del lexer
  for (unsigned int i = 0; i < r->length; i++) {
    printf("\t%d ", r->tokens[i]);
  }
}

void printLexerResultWords(const LexerResult *const r) {
  // imprimir los resultados del lexer
  for (size_t i = 0; i < r->length; i++) {

    int valor = r->tokens[i];

    switch (valor) {
    case GREATER_THAN:
      printf("\tToken: GREATER_THAN\n");
      break;
    case LESS_THAN:
      printf("\tToken: LESS_THAN\n");
      break;
    case PLUS:
      printf("\tToken: PLUS\n");
      break;
    case MINUS:
      printf("\tToken: MINUS\n");
      break;
    case DOT:
      printf("\tToken: DOT\n");
      break;
    case COMMA:
      printf("\tToken: COMMA\n");
      break;
    case LBRACE:
      printf("\tToken: LBRACE\n");
      break;
    case RBRACE:
      printf("\tToken: RBRACE\n");
      break;
    case EOF:
      printf("\tToken: EOF\n");
      break;
    case ILLEGAL:
      printf("\tToken: ILLEGAL\n");
      break;
    }
  }
}

void freeLexerResult(LexerResult *const lr) { free(lr->tokens); }
