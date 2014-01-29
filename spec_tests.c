#include <stdio.h>
#include <assert.h>
#include "except.h"

#include "spec.h"

#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();

Except_T SomeException = { "Some Exception" };
Except_T AnotherException = { "Another Exception" };

enum handled {
  Not_hanlded = 0,
  SomeException_handled = 1,
  Another_handled = 2 };

void assert_raise(Except_T expected, Block block);

int is_same_exception(Except_T e1, Except_T e2) {
  //they are the same exception if reason pointers are the same
  return e1.reason == e2.reason;
}

/*--------------spec_tests--------*/
void test_that_it_can_pass() {
  describe("some thing", ^{
    //it("has some property", ^{
    //});
  });
}

void test_that_it_can_fail() {
  describe("some thing", ^{
    it("fails", ^{
      RAISE(SomeException);
    });
  });
}

int main() {
  run_test(test_that_it_can_pass);
  run_test(test_that_it_can_fail);

  puts("\nOK");
  return 0;

}

void assert_raise(Except_T expected, Block block) {
  int the_handled = Not_hanlded;

  TRY
    block();
  EXCEPT(SomeException)
    puts("Hanling SomeException exception");
    the_handled = SomeException_handled;
  EXCEPT(AnotherException)
    puts("Hanling AnotherException");
    the_handled = Another_handled;
  END_TRY;

  if(is_same_exception(expected, SomeException) && the_handled == SomeException_handled) {
    puts("SomeException raised and handled");
    return;
  }
  else if(is_same_exception(expected, AnotherException) && the_handled == Another_handled) {
    puts("AnotherException raised and handled");
    return;
  }
  
  assert(0 && "didnt raise the expected exception");
}
