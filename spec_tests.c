//#include "except.h"
#include <stdio.h>

#include "spec.h"

#include "assert_raise.h"

#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();



/*--------------spec_tests--------*/
void test_that_it_can_pass() {
  describe("some thing", ^{
    //it("has some property", ^{
    //});
  });
}

void test_that_it_can_fail() {
  extern Except_T SomeException;
  describe("some thing", ^{
    assert_raise(SomeException, ^{
      it("fails", ^{
       RAISE(SomeException);
      });
    });
  });
}

int main() {
  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);

  puts("\nOK");
  return 0;

}

