/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
real_T xdotc(const real_T x[6], const real_T y[6], int32_T iy0)
{
  return x[0] * y[iy0 - 1] + x[1] * y[iy0];
}

/* End of code generation (xdotc.c) */
