#include <stdio.h>
#include "../src/spec.h"
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
  /*this should blow up when uncomented. Don't forget to recoment it*/
  //expect_equal(1, 99);
  expect_equal(1, 1);
}

void test_expect_equal_string() {
  /*this should blow up when uncomented. Don't forget to recoment it*/
  //expect_equal_string("Hello", "Goodbuy");
  expect_equal_string("Hello", "Hello");
}

void foo() {
  //expect_equal(3, 2);
  expect_equal_string("nasser", "nasser");
}

int main() {
  //foo();

  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);

  run_test(test_expect_equal);
  run_test(test_expect_equal_string);
  
  //run_test(test_refute_equal_string);
  //run_test(test_refute_equal);
  //run_test(test_expect_match);
  //run_test(test_refute_match);
  //run_test(

  puts("\nOK");
  return 0;

}
