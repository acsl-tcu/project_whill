/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vAllOrAny.c
 *
 * Code generation for function 'vAllOrAny'
 *
 */

/* Include files */
#include "vAllOrAny.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
boolean_T flatVectorAllOrAny(const real_T x_data[], const int32_T x_size[2])
{
  int32_T i;
  int32_T k;
  boolean_T p;
  i = x_size[0] * x_size[1];
  p = true;
  for (k = 0; k < i; k++) {
    if (p) {
      real_T d;
      d = x_data[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  return p;
}

/* End of code generation (vAllOrAny.c) */
