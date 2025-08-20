/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.c
 *
 * Code generation for function 'xaxpy'
 *
 */

/* Include files */
#include "xaxpy.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void xaxpy(real_T a, real_T y[6], int32_T iy0)
{
  if (!(a == 0.0)) {
    y[iy0 - 1] += a * y[0];
    y[iy0] += a * y[1];
  }
}

/* End of code generation (xaxpy.c) */
