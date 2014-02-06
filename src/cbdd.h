void describe(const char *string, void (^block)());
void it(const char *string, void (^block)());

/*----expectations------*/
void expect_equal(int lhs, int rhs);
void expect_equal_string(const char* lhs, const char* rhs);

/*--------private functions--------*/
//this is used by the lib tests
int _get_EXPECTATION_FALIED();
