void describe(const char *string, void (^block)());
void it(const char *string, void (^block)());
void before_each(void (^block)());
void after_each(void (^block)());

/*----expectations------*/
void _expect_equal(long exp, long act, const char* file, int line);
#define expect_equal(exp, act) _expect_equal(exp, act, __FILE__, __LINE__)

void _refute_equal(long exp, long act, const char* file, int line);
#define refute_equal(exp, act) _refute_equal(exp, act, __FILE__, __LINE__)

void _expect_equal_string(const char *exp, const char* act, const char* file, int line);
#define expect_equal_string(exp, act) _expect_equal_string(exp, act, __FILE__, __LINE__)

void _refute_equal_string(const char *exp, const char* act, const char* file, int line);
#define refute_equal_string(exp, act) _refute_equal_string(exp, act, __FILE__, __LINE__)

void _expect_true(int act, const char* file, int line);
#define expect_true(act) _expect_true(act, __FILE__, __LINE__)

void _expect_false(int act, const char* file, int line);
#define expect_false(act) _expect_false(act, __FILE__, __LINE__)

void _expect_null(void *act, const char* file, int line);
#define expect_null(act) _expect_null(act, __FILE__, __LINE__)

//TODO 
//reftue_null

/*--------private functions--------*/
//this is used by the lib tests
int cbdd_expectation_failed();
