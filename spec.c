#include "spec.h"

void describe(const char *string, void (^block)()) {
  block();
}

void it(const char *string, void (^block)()) {
  block();
}
