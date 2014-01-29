#include <stdio.h>
#include <assert.h>
#include "spec.h"


#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();

void test_that_it_can_pass() {
  describe("some thing", ^{
      //it("has some property", ^{
        //});
      });
}

int main() {
  run_test(test_that_it_can_pass);
  return 0;
}
