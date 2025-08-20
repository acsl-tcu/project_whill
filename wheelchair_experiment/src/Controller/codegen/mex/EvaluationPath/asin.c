/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * asin.c
 *
 * Code generation for function 'asin'
 *
 */

/* Include files */
#include "asin.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_asin(real_T x_data[], const int32_T *x_size)
{
  int32_T k;
  for (k = 0; k < *x_size; k++) {
    x_data[k] = muDoubleScalarAsin(x_data[k]);
  }
}

/* End of code generation (asin.c) */
