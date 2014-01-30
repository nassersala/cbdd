
#include "assert_raise.h"
#include <assert.h>
#include <stdio.h>

Except_T SomeException = { "Some Exception" };
Except_T AnotherException = { "Another Exception" };

enum handled {
  Not_hanlded = 0,
  SomeException_handled = 1,
  Another_handled = 2 };

void assert_raise(Except_T expected, void (^block)() ) {
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

int is_same_exception(Except_T e1, Except_T e2) {
  //they are the same exception if reason pointers are the same
  return e1.reason == e2.reason;
}
