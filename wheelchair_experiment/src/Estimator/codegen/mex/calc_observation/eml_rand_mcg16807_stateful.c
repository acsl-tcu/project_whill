/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * eml_rand_mcg16807_stateful.c
 *
 * Code generation for function 'eml_rand_mcg16807_stateful'
 *
 */

/* Include files */
#include "eml_rand_mcg16807_stateful.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void eml_rand_mcg16807_stateful_init(void)
{
  static uint32_T b_state;
  static boolean_T b_state_not_empty;
  b_state = 1144108930U;
  b_state_not_empty = true;
}

/* End of code generation (eml_rand_mcg16807_stateful.c) */
