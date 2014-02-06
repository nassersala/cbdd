#include <stdio.h>
#include "../src/cbdd.h"
#include "assert_raise.h"
#include <assert.h>

#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();\
  printf("\n");

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

void test_before_each_runs_before_every_it_block() {
  __block int global_state = 0;;
  describe("test for before_each", ^{
    before_each(^{
      global_state = 99;
    });

    it("change global_state", ^{
      global_state = 1;
    });

    it("should have the initial value", ^{
      assert(99 == global_state);
    });
  });
}

/*------expectations tests---------*/
void test_expect_equal_can_pass() {
  expect_equal(1, 1);
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_expect_equal_can_fail() {
  expect_equal(99, 1);
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_can_pass() {
  refute_equal(99, 1);
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_can_fail() {
  refute_equal(99, 99);
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_expect_equal_string() {
  expect_equal_string("Hello", "Hello");
}

int main() {

/*------spec tests---------*/
  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);
  run_test(test_before_each_runs_before_every_it_block);

/*------expectations tests---------*/
  run_test(test_expect_equal_can_pass);
  run_test(test_expect_equal_can_fail);
  run_test(test_refute_equal_can_pass);
  run_test(test_refute_equal_can_fail);
  run_test(test_expect_equal_string);
  
  //run_test(test_refute_equal_string);
  //run_test(test_refute_equal);
  //run_test(test_expect_match);
  //run_test(test_refute_match);
  //run_test(

  puts("\nALL TESTS PASSED\n");
  return 0;
}

