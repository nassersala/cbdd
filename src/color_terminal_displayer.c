#include "displayer.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

void displays_example_name_before_it_block(const char* example) {
  printf("%s\n", example);
}

void displays_expect_equal_failed(int actual, int expected) {
  printf(ANSI_COLOR_RED  "FAILED"  ANSI_COLOR_RESET "\n");
  printf(ANSI_COLOR_RED  "expected: %d\n got:%d"  ANSI_COLOR_RESET "\n", expected, actual);
}

void displays_expect_equal_passed() {
  printf(ANSI_COLOR_GREEN  "PASSED "   ANSI_COLOR_RESET "\n");
}

void  displays_describe_name_before_describe_block(const char* desc) {
  printf(ANSI_COLOR_CYAN    "%s"     ANSI_COLOR_RESET "\n", desc);
}
