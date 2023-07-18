#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../s21_matrix.h"
#include "tests.h"

int main() {
  int no_failed = 0;

  Suite *suites[] = {basic_suite(),
                     comparison_suite(),
                     arithmetic_suite(),
                     determinant_suite(),
                     other_operations_suite(),
                     inverse_suite(),
                     NULL};
  for (Suite **pS = suites; *pS != NULL; pS++) {
    SRunner *sr = srunner_create(*pS);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
  }

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
