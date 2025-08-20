/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * acos.c
 *
 * Code generation for function 'acos'
 *
 */

/* Include files */
#include "acos.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void b_acos(real_T x_data[], const int32_T *x_size)
{
  int32_T k;
  for (k = 0; k < *x_size; k++) {
    x_data[k] = muDoubleScalarAcos(x_data[k]);
  }
}

/* End of code generation (acos.c) */
