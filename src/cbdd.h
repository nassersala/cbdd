/* Copyright 2014, Nasser Ali Alzahrani @nassersala
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at

 * http://www.apache.org/licenses/LICENSE-2.0

 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License. */

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

void _refute_null(void *act, const char* file, int line);
#define refute_null(act) _refute_null(act, __FILE__, __LINE__)

//this is used by the lib tests
int cbdd_expectation_failed();
