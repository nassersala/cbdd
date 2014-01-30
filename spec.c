#include "spec.h"
#include <assert.h>
#include "assert_raise.h"

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>


void describe(const char *string, void (^block)()) {
  block();
}

void it(const char *string, void (^block)()) {
  block();
}

void print_stack_trace() {
  void* callstack[128];
  int i, frames = backtrace(callstack, 128);
  char** strs = backtrace_symbols(callstack, frames);
  for (i = 0; i < frames; ++i) {
    printf("%s\n", strs[i]);
  }
  free(strs);
}

void expect_equal(int lhs, int rhs) {
  extern Except_T NOT_EQUAL_EXCEPTION;
  if(lhs != rhs) {
    print_stack_trace();
    RAISE(NOT_EQUAL_EXCEPTION);
 //   assert(0 && "TESTO");
  }
}
