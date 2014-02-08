void displays_describe_name_before_describe_block(const char* desc);
void displays_example_name_before_it_block(const char* example);

void displays_expect_equal_failed(long exp, long act, const char* file, int line);
void displays_expect_equal_passed();

void displays_refute_equal_failed(long exp, long act, const char* file, int line);
