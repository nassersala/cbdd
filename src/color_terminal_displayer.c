#include "displayer.h"
#include "stdio.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

static void color_print(const char* color, const char* text) {
  printf("%s%s"ANSI_COLOR_RESET"\n", color, text);
}

void  displays_describe_name_before_describe_block(const char* desc) {
  color_print(ANSI_COLOR_MAGENTA, desc);
}

void displays_example_name_before_it_block(const char* example) {
  color_print(ANSI_COLOR_RESET, example);
}

void displays_example_passed() {
  color_print(ANSI_COLOR_GREEN, "PASSED");
}

void displays_expect_equal_failed(long exp, long act, const char*file, int line) {
  char text[80];
  sprintf(text, "FAILED\nexpected: %ld\ngot: %ld\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}


void displays_refute_equal_failed(long actual, long expected, const char*file, int line) {
  char text[80];
  sprintf(text, "FAILED\nexpected (%ld) and (%ld) not to be equal\n%s:%d", expected, actual, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_string_equal_failed(const char*exp, const char*act, const char*file, int line) {
  char text[80];
  sprintf(text, "FAILED\nexpected: %s\ngot: %s\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_string_refute_failed(const char*exp, const char*act, const char*file, int line) {
  char text[80];
  sprintf(text, "FAILED\nexpected (%s) not to equal (%s)\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}
