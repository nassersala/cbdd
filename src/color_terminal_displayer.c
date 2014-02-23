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

#include "displayer.h"
#include "stdio.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TEXT_SIZE 256

static void color_print(const char* color, const char* text) {
  printf("%s%s"ANSI_COLOR_RESET"\n", color, text);
}

void  displays_describe_name_before_describe_block(const char* desc) {
  color_print(ANSI_COLOR_RESET, desc);
}

void displays_example_name_before_it_block(const char* example) {
  printf("- ");
  color_print(ANSI_COLOR_RESET, example);
}

void displays_example_passed() {
  //color_print(ANSI_COLOR_GREEN, "PASSED");
}

void displays_expect_equal_failed(long exp, long act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected: %ld\ngot: %ld\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}


void displays_refute_equal_failed(long actual, long expected, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected (%ld) and (%ld) not to be equal\n%s:%d", expected, actual, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_string_equal_failed(const char*exp, const char*act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected: %s\ngot: %s\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_string_refute_failed(const char*exp, const char*act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected \"%s\" not to equal \"%s\"\n%s:%d", exp, act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_expect_true_failed(int act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected %d to be true, got false\n%s:%d", act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_expect_false_failed(int act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected %d to be false, got true\n%s:%d", act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_expect_null_failed(void *act, const char*file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nexpected %p to point to NULL\n%s:%d", act, file, line);
  color_print(ANSI_COLOR_RED, text);
}

void displays_refute_null_failed(void *act, const char* file, int line) {
  char text[TEXT_SIZE];
  sprintf(text, "FAILED\nunexpected null\ngot: %p\n%s:%d", act, file, line);
  color_print(ANSI_COLOR_RED, text);
}
