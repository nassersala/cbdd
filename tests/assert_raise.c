/* Copyright 2014, Nasser Ali Alzahrani @nassersala
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 * http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

#include "assert_raise.h"
#include <assert.h>
#include <stdio.h>

extern Except_T SomeException;
extern Except_T AnotherException;
extern Except_T NOT_EQUAL_EXCEPTION;

enum handled {
  Not_hanlded = 0,
  SomeException_handled = 1,
  Another_handled = 2,
  NOT_EQUAL_EXCEPTION_handled = 3 };

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
  EXCEPT(NOT_EQUAL_EXCEPTION)
    puts("Hanling NOT_EQUAL_EXCEPTION");
    the_handled = NOT_EQUAL_EXCEPTION_handled;
  END_TRY;

  if(is_same_exception(expected, SomeException) && the_handled == SomeException_handled) {
    puts("SomeException raised and handled");
    return;
  }
  else if(is_same_exception(expected, AnotherException) && the_handled == Another_handled) {
    puts("AnotherException raised and handled");
    return;
  }
  else if(is_same_exception(expected, NOT_EQUAL_EXCEPTION) && the_handled == NOT_EQUAL_EXCEPTION_handled) {
    puts("NOT_EQUAL_EXCEPTION raised and handled");
    return;
  }
  
  assert(0 && "didnt raise the expected exception");
}

int is_same_exception(Except_T e1, Except_T e2) {
  //they are the same exception if reason pointers are the same
  return e1.reason == e2.reason;
}
