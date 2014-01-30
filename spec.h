#include <Block.h>

typedef void (^Block)();

void describe(const char *string, Block block);
void it(const char *string, Block block);
