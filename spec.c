#include "spec.h"
#include "assert_raise.h"

void describe(const char *string, Block block) {
  block();
}

void it(const char *string, Block block) {
  block();
}
