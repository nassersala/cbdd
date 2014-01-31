void describe(const char *string, void (^block)());
void it(const char *string, void (^block)());

void expect_equal(int lhs, int rhs);

/* private */
void _print_stack_trace();
