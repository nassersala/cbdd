#include "spec.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

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
    //_print_stack_trace();
    assert(0 && "Expected equal integers but were not");
  }
}

void expect_equal_string(const char* lhs, const char* rhs) {
  if (0 != strcmp(lhs, rhs))  { 
    /* string are not matching */
    //_print_stack_trace();
    assert(0 && "Expected equal strings but were not");
  }
}

/*--------utility fn-------*/
void _print_stack_trace() {
  void* callstack[128];
  int i, frames = backtrace(callstack, 128);
  char** strs = backtrace_symbols(callstack, frames);
  for (i = 0; i < frames; ++i) {
    printf("%s\n", strs[i]);
  }
  free(strs);
}
