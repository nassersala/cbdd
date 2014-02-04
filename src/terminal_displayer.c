#include "displayer.h"

void displays_example_name_before_it_block(const char* example) {
  printf("%s\n", example);
}
void displays_expect_equal_failed(int actual, int expected) {
  printf("FAILED\n");
  printf("expected: %d\n got:%d\n", expected, actual);
}

void displays_expect_equal_passed() {
  printf("PASSED\n");
}
