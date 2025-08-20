/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation_mexutil.c
 *
 * Code generation for function 'calc_observation_mexutil'
 *
 */

/* Include files */
#include "calc_observation_mexutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int32_T div_nde_s32_floor(int32_T numerator)
{
  int32_T quotient;
  if ((numerator < 0) && (numerator % 15 != 0)) {
    quotient = -1;
  } else {
    quotient = 0;
  }
  quotient += numerator / 15;
  return quotient;
}

/* End of code generation (calc_observation_mexutil.c) */
