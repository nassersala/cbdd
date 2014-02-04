#include "cbdd.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>
#include <string.h>

#include "displayer.h"

/* Displyer is a 'role' that can be played by any module that implements
 * displayer.h inteface */ 
void Displayer_display_example_name(const char* example) {
  displays_example_name_before_it_block(example);
}

void Displayer_display_example_failed(int lhs, int rhs) {
  //printf(ANSI_COLOR_RED    "FAILED"     ANSI_COLOR_RESET "\n");
  //printf(ANSI_COLOR_RED    "expected: %d\n got:%d"     ANSI_COLOR_RESET "\n", rhs, lhs);
}

void Displayer_display_example_passed() {
  //printf(ANSI_COLOR_GREEN    "PASSED "     ANSI_COLOR_RESET "\n");
}

void expect_equal_failed(int lhs, int rhs) {
    Displayer_display_example_failed(lhs, rhs);
}

void expect_equal_passed(int lhs, int rhs) {
    Displayer_display_example_passed();
}

void describe(const char *string, void (^block)()) {
  printf("%s\n", string);
  block();
}

void it(const char *string, void (^block)()) {
  Displayer_display_example_name(string);
  block();
}

void expect_equal(int lhs, int rhs) {
  if(lhs != rhs) {
    expect_equal_failed(lhs, rhs);
  } else {
    expect_equal_passed(lhs, rhs);
  }
}

void expect_equal_string(const char* lhs, const char* rhs) {
  if (0 != strcmp(lhs, rhs))  { 
    assert(0 && "Expected equal strings but were not");
  }
}

