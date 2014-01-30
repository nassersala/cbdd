#ifndef ASSERT_RAISE_
#define ASSERT_RAISE_

#include "except.h"

void assert_raise(Except_T expected, void (^block)() );

/*private */
int is_same_exception(Except_T e1, Except_T e2);

#endif
