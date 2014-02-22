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

#include "cbdd.h"
//assert.h is needed otherwise it will use Except_t assert
#include <assert.h>
#include <string.h>
#include "displayer.h"

//used by the tests only
static int EXPECTATION_FAILED = 0;

static int BEFORE_ALL_CALLED = 0;

static void (^before_each_block)();
static void (^after_each_block)();
static void (^before_all_block)();
static void (^after_all_block)();

/* Displyer is a 'role' that can be played by any module that implements
 * displayer.h inteface */
void Displayer_display_describe_name(const char* desc) {
  displays_describe_name_before_describe_block(desc);
}

void Displayer_display_example_name(const char* example) {
  displays_example_name_before_it_block(example);
}

void Displayer_display_example_passed() {
  displays_example_passed();
}

void Displayer_display_expect_equal_failed(int exp, int act, const char*file, int line) {
  displays_expect_equal_failed(exp, act, file, line);
}

void Displayer_display_refute_equal_failed(int exp, int act, const char*file, int line) {
  displays_refute_equal_failed(exp, act, file, line);
}

void Displayer_display_string_equal_failed(const char*exp, const char*act, const char*file, int line) {
  displays_string_equal_failed(exp, act, file, line);
}

void Displayer_display_refute_equal_string_failed(const char*exp, const char*act, const char*file, int line) {
  displays_string_refute_failed(exp, act, file, line);
}
void Displayer_display_expect_true_failed(int act, const char*file, int line) {
  displays_expect_true_failed(act, file, line);
}

void Displayer_display_expect_false_failed(int act, const char*file, int line) {
  displays_expect_false_failed(act, file, line);
}

void Displayer_display_expect_null_failed(void *act, const char*file, int line) {
  displays_expect_null_failed(act, file, line);
}

void  Displayer_display_refute_null_failed(void *act, const char* file, int line) {
  displays_refute_null_failed(act, file, line);
}

/*-------expectations func------*/
void expect_equal_failed(long exp, long act, const char*file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_expect_equal_failed(exp, act, file, line);
}

void refute_equal_failed(long exp, long act, const char* file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_refute_equal_failed(exp, act, file, line);
}

void expect_equal_string_failed(const char* exp, const char* act, const char*file, int line)  {
  EXPECTATION_FAILED = 1;
  Displayer_display_string_equal_failed(exp, act, file, line);
}

void refute_equal_string_failed(const char* exp, const char* act, const char *file, int line) { 
  EXPECTATION_FAILED = 1;
  Displayer_display_refute_equal_string_failed(exp, act, file, line);
}

void expect_true_failed(int act, const char*file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_expect_true_failed(act, file, line);
}

void expect_false_failed(int act, const char*file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_expect_false_failed(act, file, line);
}

void expect_null_failed(void *act, const char* file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_expect_null_failed(act, file, line);
}

void refute_null_failed(void *act, const char* file, int line) {
  EXPECTATION_FAILED = 1;
  Displayer_display_refute_null_failed(act, file, line);
}

void expectation_passed()  {
  EXPECTATION_FAILED = 0;
  Displayer_display_example_passed();
}

void _expect_equal(long exp, long act, const char* file, int line) {
  if (exp == act)
    expectation_passed();
  else
    expect_equal_failed(exp, act, file, line);
}

void _refute_equal(long exp, long act, const char* file, int line) {
  if(exp == act)
    refute_equal_failed(exp, act, file, line);
  else
    expectation_passed();
}

int is_equal_string(const char* lhs, const char* rhs) {
  return (0 == strcmp(lhs, rhs));
}

int either_or_both_is_null(const char* exp, const char* act) {
  return ((exp == NULL && act != NULL) ||
      (exp != NULL && act == NULL) ||
      (exp == NULL && act == NULL));
}

void _expect_equal_string(const char* exp, const char* act, const char* file, int line) {
  if (either_or_both_is_null(exp, act) || !is_equal_string(exp, act))
    expect_equal_string_failed(exp, act, file, line);
  else
    expectation_passed();
}

void _refute_equal_string(const char* exp, const char* act, const char* file, int line) {
  if (either_or_both_is_null(exp, act) || is_equal_string(exp, act))
    refute_equal_string_failed(exp, act, file, line);
  else
    expectation_passed();
}

void _expect_true(int act, const char* file, int line) {
  if((act) == 0)
    expect_true_failed(act, file, line);
  else
    expectation_passed();
}

void _expect_false(int act, const char* file, int line) {
  if((act) == 0)
    expectation_passed();
  else
    expect_false_failed(act, file, line);
}

void _expect_null(void *act, const char* file, int line) {
  if((act) == NULL)
    expectation_passed();
  else
    expect_null_failed(act, file, line);
}

void _refute_null(void *act, const char* file, int line) {
  if((act) == NULL)
    refute_null_failed(act, file, line);
  else
    expectation_passed();
}

/*------spec functions--------*/
void clear_global_blocks() {
  before_each_block = NULL;
  after_each_block = NULL;
  before_all_block = NULL;
  after_all_block = NULL;
}

void exec_the_before_all_block_once() {
  if(!BEFORE_ALL_CALLED && before_all_block) {
    before_all_block();
    BEFORE_ALL_CALLED = 1;
  }
}

void describe(const char *string, void (^block)()) {
  Displayer_display_describe_name(string);
  block();

  if(after_all_block) after_all_block();

  clear_global_blocks();

  //clear it so it will work with other describe blocks
  BEFORE_ALL_CALLED = 0;
}

void it(const char *string, void (^block)()) {
  exec_the_before_all_block_once();
  if(before_each_block) before_each_block();
  Displayer_display_example_name(string);
  block();
  if(after_each_block) after_each_block();
}

void before_each(void (^block)()) {
  before_each_block = block;
}

void after_each(void (^block)()) {
  after_each_block = block;
}

void before_all(void (^block)()) {
  before_all_block = block;
}

void after_all(void (^block)()) {
  after_all_block = block;
}

/*-------private functions------*/
int cbdd_expectation_failed() {
  return EXPECTATION_FAILED;
}
