#include "../src/lexer.h"
#include "../src/token.h"


#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

/*
 *
 * >>.                     Cell #2 has value 72 which is 'H'
 * >---.                   Subtract 3 from Cell #3 to get 101 which is 'e'
 * +++++++..+++.           Likewise for 'llo' from Cell #3
 * >>.                     Cell #5 is 32 for the space
 * <-.                     Subtract 1 from Cell #4 for 87 to give a 'W'
 * <.                      Cell #3 was set to 'o' from the end of 'Hello'
 * +++.------.--------.    Cell #3 for 'rl' and 'd'
 * >>+.                    Add 1 to Cell #5 gives us an exclamation point
 * >++.                    And finally a newline from Cell #6
 *
 * */

Test(test1, test1) {
  const char *const brainfuck_src = ">>.";
  LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));

  cr_expect(r.tokens[0] == GREATER_THAN, "Token must be GREATER_THAN");
  cr_expect(r.tokens[1] == GREATER_THAN, "Token must be GREATER_THAN");
  cr_expect(r.tokens[2] == DOT, "Token must be DOT");

  printf("Test 1: %s\n",brainfuck_src);
  printLexerResultWords(&r);
}

Test(test2, test2) {
  const char *const brainfuck_src = ">---.";
  LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));

  cr_expect(r.tokens[0] == GREATER_THAN, "Token must be GREATER_THAN");
  cr_expect(r.tokens[1] == MINUS, "Token must be MINUS");
  cr_expect(r.tokens[2] == MINUS, "Token must be MINUS");
  cr_expect(r.tokens[3] == MINUS, "Token must be MINUS");
  cr_expect(r.tokens[4] == DOT, "Token must be DOT");

  printf("Test 2: %s\n",brainfuck_src);
  printLexerResultWords(&r);
}

Test(test3, test3) {
  const char *const brainfuck_src = "+++++++..+++.?";
  LexerResult r = RunLexicalAnalisys(brainfuck_src, strlen(brainfuck_src));

  cr_expect(r.tokens[0] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[1] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[2] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[3] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[4] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[5] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[6] == PLUS, "Token must be PLUS");

  cr_expect(r.tokens[7] == DOT, "Token must be DOT");
  cr_expect(r.tokens[8] == DOT, "Token must be DOT");

  cr_expect(r.tokens[9] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[10] == PLUS, "Token must be PLUS");
  cr_expect(r.tokens[11] == PLUS, "Token must be PLUS");

  cr_expect(r.tokens[12] == DOT, "Token must be DOT");
  cr_expect(r.tokens[13] == ILLEGAL, "Token must be ILLEGAL");

  printf("Test 3: %s\n",brainfuck_src);
  printLexerResultWords(&r);
}
