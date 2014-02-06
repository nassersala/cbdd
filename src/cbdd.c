#include "cbdd.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>
#include <string.h>

#include "displayer.h"

static void (^before_block)();

//used by the tests only
static int EXPECTATION_FAILED = 0;

int _get_EXPECTATION_FALIED() {
  return EXPECTATION_FAILED;
}

/* Displyer is a 'role' that can be played by any module that implements
 * displayer.h inteface */
void Displayer_display_describe_name(const char* desc) {
  displays_describe_name_before_describe_block(desc);
}

void Displayer_display_example_name(const char* example) {
  displays_example_name_before_it_block(example);
}

void Displayer_display_example_failed(int actual, int expected) {
  displays_expect_equal_failed(actual, expected);
}

void Displayer_display_example_passed() {
  displays_expect_equal_passed();
}

void expect_equal_failed(int lhs, int rhs) {
  EXPECTATION_FAILED = 1;
  Displayer_display_example_failed(lhs, rhs);
}

void expect_equal_passed() {
  EXPECTATION_FAILED = 0;
  Displayer_display_example_passed();
}

void describe(const char *string, void (^block)()) {
  Displayer_display_describe_name(string);
  block();
}

void it(const char *string, void (^block)()) {
  if(before_block) before_block();
  Displayer_display_example_name(string);
  block();
}

void before_each(void (^block)()) {
  before_block = block;
}

void expect_equal(int lhs, int rhs) {
  if(lhs != rhs) {
    expect_equal_failed(lhs, rhs);
  } else {
    expect_equal_passed();
  }
}

void expect_equal_string(const char* lhs, const char* rhs) {
  if (0 != strcmp(lhs, rhs))  { 
    assert(0 && "Expected equal strings but were not");
  }
}

