#pragma once

#include "lexer.h"
#include <stddef.h>

static const size_t BUFFER_SIZE = 3000;

typedef struct {
  size_t program_counter;
  const LexerResult * const tokens;
  char * const buffer;
  size_t buff_ptr;

} ProgramState;

ProgramState NewInterpreter(const LexerResult *toks);
void DelInterpreter(ProgramState* state);
void executeProgramStep(ProgramState* state);
void executeProgram(ProgramState* state);
