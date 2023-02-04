#include "interpreter.h"
#include "token.h"

#include <malloc.h>

ProgramState NewInterpreter(const LexerResult *const toks) {
  char *const buffer = calloc(BUFFER_SIZE, sizeof(char));
  ProgramState state = {0, toks, buffer, 0};
  return state;
}

void DelInterpreter(ProgramState *state) { free(state->buffer); }

void executeProgramStep(ProgramState *state) {
  int t = state->tokens->tokens[state->program_counter];
  switch (t) {
  case PLUS:
    state->buffer[state->buff_ptr]++;
    break;

  case LESS_THAN:
    (state->buff_ptr)--;
    break;

  case GREATER_THAN:
    (state->buff_ptr)++;
    break;

  case MINUS:
    state->buffer[state->buff_ptr]--;
    break;

  case DOT:
    printf("%c", state->buffer[state->buff_ptr]);
    break;

  case COMMA:
    state->buffer[state->buff_ptr] = (char)getchar();
    break;

  case LBRACE: {
    int unmatchedBracketCounter = 0;

    if (state->buffer[state->buff_ptr] == 0) {
      unmatchedBracketCounter++;
      while (t != RBRACE || unmatchedBracketCounter != 0) {
        state->program_counter++;
        t = state->tokens->tokens[state->program_counter];
        if (t == LBRACE)
          unmatchedBracketCounter++;
        else if (t == RBRACE)
          unmatchedBracketCounter--;
      }
    }
    break;
  }

  case RBRACE: {
    int unmatchedBracketCounter = 0;

    if (state->buffer[state->buff_ptr] != 0) {
      unmatchedBracketCounter++;
      while (t != LBRACE || unmatchedBracketCounter != 0) {
        state->program_counter--;
        t = state->tokens->tokens[state->program_counter];
        if (t == RBRACE)
          unmatchedBracketCounter++;
        else if (t == LBRACE)
          unmatchedBracketCounter--;
      }
    }
    break;
  }

  default:
    printf("Token no reconocido :c\n");
    break;
  }
  state->program_counter++;
}
void executeProgram(ProgramState* state){
    while (state->program_counter<state->tokens->length) {
      executeProgramStep(state);
    }
}
