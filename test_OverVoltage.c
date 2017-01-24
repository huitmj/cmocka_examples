#include <stdlib.h>

#include <stdbool.h>
#include <stdarg.h>
#include <setjmp.h>
#include <cmocka.h>

#include "Adc.h"

int __wrap_getAdcValue(int address) { 
  check_expected(address);
  return mock_type(int)<< 2; 
}

bool isOverVoltage(int limit) { 
  return getAdcValue(1) > limit ? true : false; 
}

static void test_given10_whenAdcIs2_expectFalse(void **state) {
  expect_value(__wrap_getAdcValue,address,1);
  will_return(__wrap_getAdcValue, 2);
  assert_false(isOverVoltage(10));
}

static void test_given10_whenAdcIs40_expectTrue(void **state) {
  expect_value(__wrap_getAdcValue,address,1);
  will_return(__wrap_getAdcValue, 40);
  assert_true(isOverVoltage(10));
}

int main(void) {
  const struct CMUnitTest tests[] = {
    cmocka_unit_test(test_given10_whenAdcIs2_expectFalse),
    cmocka_unit_test(test_given10_whenAdcIs40_expectTrue),
  };

  return cmocka_run_group_tests(tests, NULL, NULL);
}
