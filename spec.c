#include "spec.h"

void describe(const char *string, Block block) {
  block();
}

void it(const char *string, Block block) {
//  RAISE(SomeException);
}
