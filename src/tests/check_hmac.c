// Apache License. Version 2.0, January 2004
//
// Copyright (c) 2016, 2017, 2018 Trusona Inc (https://trusona.com) All Rights Reserved
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include <check.h>
#include "../hmac.h"

START_TEST(will_generate_MD5_hash_successfully)
{
  ck_assert_str_eq(generate_md5("  test  "), "deb1e90255bbe7954ad0220868fe6529");
  ck_assert_str_eq(generate_md5("test"), "098f6bcd4621d373cade4e832627b4f6");
  ck_assert_str_eq(generate_md5(" "), "7215ee9c7d9dc229d2921a40e899ec5f");
  ck_assert_str_eq(generate_md5(""), "d41d8cd98f00b204e9800998ecf8427e");
}
END_TEST;

START_TEST(will_return_NULL_on_input_is_NULL)
{
  ck_assert_pstr_eq(generate_md5(NULL), NULL);
}
END_TEST;

Suite *utils_suite(void)
{
  Suite *suite;
  TCase *tests;

  suite = suite_create("HMAC Tests");
  tests = tcase_create("tests");

  tcase_add_test(tests, will_generate_MD5_hash_successfully);
  tcase_add_test(tests, will_return_NULL_on_input_is_NULL);

  suite_add_tcase(suite, tests);

  return(suite);
}

int main(void)
{
  int      failures;
  Suite *  suite;
  SRunner *runner;

  suite    = utils_suite();
  runner   = srunner_create(suite);
  failures = -1;

  srunner_run_all(runner, CK_NORMAL);
  failures = srunner_ntests_failed(runner);
  srunner_free(runner);
  return((failures == 0) ? EXIT_SUCCESS : EXIT_FAILURE);
}