/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker_mexutil.c
 *
 * Code generation for function 'mexLidarTracker_mexutil'
 *
 */

/* Include files */
#include "mexLidarTracker_mexutil.h"
#include "rt_nonfinite.h"

/* Function Definitions */
int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T i;
  if (((numerator < 0) != (denominator < 0)) &&
      (numerator % denominator != 0)) {
    i = -1;
  } else {
    i = 0;
  }
  return numerator / denominator + i;
}

/* End of code generation (mexLidarTracker_mexutil.c) */
