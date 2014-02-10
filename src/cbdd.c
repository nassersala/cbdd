#include "cbdd.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>
#include <string.h>
#include "displayer.h"

//used by the tests only
static int EXPECTATION_FAILED = 0;

static void (^before_block)();
static void (^after_block)();

/* Displyer is a 'role' that can be played by any module that implements
 * displayer.h inteface */
void Displayer_display_describe_name(const char* desc) {
  displays_describe_name_before_describe_block(desc);
}

void Displayer_display_example_name(const char* example) {
  displays_example_name_before_it_block(example);
}

void Displayer_display_expect_equal_failed(int exp, int act, const char*file, int line) {
  displays_expect_equal_failed(exp, act, file, line);
}

void Displayer_display_example_passed() {
  displays_example_passed();
}

void Displayer_display_refute_equal_failed(int exp, int act, const char*file, int line) {
  displays_refute_equal_failed(exp, act, file, line);
}

void Displayer_display_string_equal_failed(const char*exp, const char*act, const char*file, int line) {
  displays_string_equal_failed(exp, act, file, line);
}

/*-------expectations func------*/
void expect_equal_failed(long exp, long act, const char*file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_expect_equal_failed(exp, act, file, line);
}

void expect_equal_passed() {
  EXPECTATION_FAILED = 0;
  Displayer_display_example_passed();
}

void refute_equal_failed(long exp, long act, const char* file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_refute_equal_failed(exp, act, file, line);
}

void refute_equal_passed() {
  EXPECTATION_FAILED = 0;
  Displayer_display_example_passed();
}

void expect_equal_string_failed(const char* exp, const char* act, const char*file, int line)  {
  EXPECTATION_FAILED = 1;
  Displayer_display_string_equal_failed(exp, act, file, line);
}

void expect_equal_string_passed()  {
  EXPECTATION_FAILED = 0;
  Displayer_display_example_passed();
}

void _expect_equal(long exp, long act, const char* file, int line) {
  if (exp != act) {
    expect_equal_failed(exp, act, file, line);
  } else {
    expect_equal_passed();
  }
}

void _refute_equal(long exp, long act, const char* file, int line) {
  if(exp != act) {
    refute_equal_passed();
  } else {
    refute_equal_failed(exp, act, file, line);
  }
}

void _expect_equal_string(const char* exp, const char* act, const char *file, int line) {
  if (0 != strcmp(exp, act))  { 
    expect_equal_string_failed(exp, act, file, line);
  } else {
    expect_equal_string_passed();
  }
}

/*------spec functions--------*/
void describe(const char *string, void (^block)()) {
  Displayer_display_describe_name(string);
  block();
  before_block = NULL;
  after_block = NULL;
}

void it(const char *string, void (^block)()) {
  if(before_block) before_block();
  Displayer_display_example_name(string);
  block();
  if(after_block) after_block();
}

void before_each(void (^block)()) {
  before_block = block;
}
 
void after_each(void (^block)()) {
  after_block = block;
}

/*-------private functions------*/
int _get_EXPECTATION_FALIED() {
  return EXPECTATION_FAILED;
}
