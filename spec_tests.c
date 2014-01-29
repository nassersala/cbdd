#include <stdio.h>
#include <assert.h>

#define run_test(fn_name)\
  printf("%s\n", #fn_name);\
  fn_name();


int main() {
  return 0;
}
