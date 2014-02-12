#include <stdio.h>
#include "../src/cbdd.h"
#include "assert_raise.h"
#include <assert.h>

#define run_test(function_name)\
  printf("%s\n", #function_name);\
  function_name();\
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
  __block int global_state = 0;
  describe("test for before_each", ^{
    before_each(^{
      global_state = 99;
    });

    it("change global_state", ^{
      assert(99 == global_state);
      global_state = 1;
    });

    it("should have the initial value", ^{
      assert(99 == global_state);
    });
  });
}

void test_before_each_only_runs_within_its_describe_context() {
  __block int global_state = 1001;
  describe("test for before_each should only run within its conext", ^{
      before_each(^{
        global_state = 99;
      });
    it("", ^{
      assert(99 == global_state);
      global_state = 101;
    });

    it("", ^{
      assert(99 == global_state);
      global_state = 101;
    });
  });

  describe("outside describe block", ^{
    it("should not see the outside before_each", ^{
      assert(99 != global_state);
    });
  });
}

void test_after_each_runs_after_every_it_block() { 
  __block int global_state = 1001;
  describe("test for after_each", ^{
    after_each(^{
      global_state = 22;
    });

    it("", ^{
      global_state = 101;
    });
  });
  assert(22 == global_state);
}

/*------expectations tests---------*/
void test_expect_equal_can_pass() {
  expect_equal(1, 1);
  assert(0 == _get_EXPECTATION_FALIED());

  expect_equal(NULL, NULL);
  assert(0 == _get_EXPECTATION_FALIED());

  expect_equal('z', 'z');
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_expect_equal_can_fail() {
  expect_equal(99, 1);
  assert(1 == _get_EXPECTATION_FALIED());

  expect_equal(NULL, 1);
  assert(1 == _get_EXPECTATION_FALIED());

  expect_equal('n', 'z');
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_can_pass() {
  refute_equal(99, 1);
  assert(0 == _get_EXPECTATION_FALIED());

  refute_equal(NULL, 99);
  assert(0 == _get_EXPECTATION_FALIED());

  refute_equal('n', 'z');
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_can_fail() {
  refute_equal(99, 99);
  assert(1 == _get_EXPECTATION_FALIED());

  refute_equal(NULL, NULL);
  assert(1 == _get_EXPECTATION_FALIED());

  refute_equal('z', 'z');
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_expect_equal_string_can_pass() {
  expect_equal_string("Hello", "Hello");
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_expect_equal_string_can_fail() {
  expect_equal_string("Hello", "Salam");
  assert(1 == _get_EXPECTATION_FALIED());

  expect_equal_string(NULL, "Salam");
  assert(1 == _get_EXPECTATION_FALIED());

  expect_equal_string( "Salam", NULL);
  assert(1 == _get_EXPECTATION_FALIED());

  expect_equal_string(NULL, NULL);
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_string_can_pass() {
  refute_equal_string("Hello", "Salam");
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_refute_equal_string_can_fail() {
  refute_equal_string("Salam", "Salam");
  assert(1 == _get_EXPECTATION_FALIED());

  refute_equal_string(NULL, "Salam");
  assert(1 == _get_EXPECTATION_FALIED());

  refute_equal_string("Salam", NULL);
  assert(1 == _get_EXPECTATION_FALIED());

  refute_equal_string(NULL, NULL);
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_expect_true_can_pass() {
  expect_true(1);
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_expect_true_can_fail() {
  expect_true(0);
  assert(1 == _get_EXPECTATION_FALIED());

  expect_true(NULL);
  assert(1 == _get_EXPECTATION_FALIED());
}

void test_expect_false_can_pass() {
  expect_false(0);
  assert(0 == _get_EXPECTATION_FALIED());

  expect_false(NULL);
  assert(0 == _get_EXPECTATION_FALIED());
}

void test_expect_false_can_fail() {
  expect_false(99);
  assert(1 == _get_EXPECTATION_FALIED());

  expect_false("Salam");
  assert(1 == _get_EXPECTATION_FALIED());
}

int main() {

  /*---------spec tests---------*/
  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);
  run_test(test_before_each_runs_before_every_it_block);
  run_test(test_before_each_only_runs_within_its_describe_context);
  run_test(test_after_each_runs_after_every_it_block);

  /*------expectations tests---------*/
  run_test(test_expect_equal_can_pass);
  run_test(test_expect_equal_can_fail);
  run_test(test_refute_equal_can_pass);
  run_test(test_refute_equal_can_fail);
  run_test(test_expect_equal_string_can_pass);
  run_test(test_expect_equal_string_can_fail);
  run_test(test_refute_equal_string_can_pass);
  run_test(test_refute_equal_string_can_fail);
  run_test(test_expect_true_can_pass);
  run_test(test_expect_true_can_fail);
  run_test(test_expect_false_can_pass);
  run_test(test_expect_false_can_fail);
  
  //run_test(test_expect_match);
  //run_test(test_refute_match);
  //run_test(

  puts("\nALL TESTS PASSED\n");
  return 0;
}
