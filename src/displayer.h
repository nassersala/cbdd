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

void displays_describe_name_before_describe_block(const char* desc);
void displays_example_name_before_it_block(const char* example);

void displays_expect_equal_failed(long exp, long act, const char* file, int line);
void displays_example_passed();

void displays_refute_equal_failed(long exp, long act, const char* file, int line);

void displays_string_equal_failed(const char*exp, const char*act, const char*file, int line);
void displays_string_refute_failed(const char*exp, const char*act, const char*file, int line);

void displays_expect_true_failed(int act, const char*file, int line);
void displays_expect_false_failed(int act, const char*file, int line);

void displays_expect_null_failed(void *act, const char*file, int line);
void displays_refute_null_failed(void *act, const char* file, int line);
