#include <stdio.h>
#include "spec.h"
#include "assert_raise.h"
#include <assert.h>

#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();

Except_T SomeException = { "Some Exception" };
Except_T AnotherException = { "Another Exception" };
Except_T NOT_EQUAL_EXCEPTION = { "lhs does not equal rhs" };


/*--------------spec_tests--------*/
void test_that_it_can_pass() {
  describe("some thing", ^{
    it("has some property", ^{
    });
  });
}

void test_that_it_can_fail() {
  describe("some thing", ^{
    assert_raise(SomeException, ^{
      it("fails", ^{
        RAISE(SomeException);
      });
    });
  });
}

void test_expect_equal() {
  int x = 1;
  int y = 3;

  assert_raise(NOT_EQUAL_EXCEPTION, ^{
      expect_equal(x, y);
  });
}

void foo() {
  //expect_equal(2, 2);
}

int main() {
//  foo();

  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);

  run_test(test_expect_equal);

  puts("\nOK");
  return 0;

}

