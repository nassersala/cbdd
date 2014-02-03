#include "cbdd.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>
#include <string.h>

void describe(const char *string, void (^block)()) {
  printf("%s\n", string);
  block();
}

void it(const char *string, void (^block)()) {
  printf("%s\n", string);
  block();
  printf(" - OK\n");
}

void expect_equal(int lhs, int rhs) {
  if(lhs != rhs) {
    printf("FAILED\n");
    assert(0 && "Expected equal integers but were not");
  } else {
    printf("FAILED\n");
  }
}

void expect_equal_string(const char* lhs, const char* rhs) {
  if (0 != strcmp(lhs, rhs))  { 
    assert(0 && "Expected equal strings but were not");
  }
}

