/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unsafeSxfun.c
 *
 * Code generation for function 'unsafeSxfun'
 *
 */

/* Include files */
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
int32_T binary_expand_op(real_T in1_data[], const real_T in3_data[],
                         const int32_T *in3_size, const real_T in4_data[],
                         const int32_T *in4_size)
{
  int32_T i;
  int32_T in1_size;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in4_size == 1) {
    in1_size = *in3_size;
  } else {
    in1_size = *in4_size;
  }
  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (*in4_size != 1);
  for (i = 0; i < in1_size; i++) {
    real_T varargin_1;
    varargin_1 = (in3_data[i * stride_0_0] + in4_data[i * stride_1_0]) - 1.0;
    in1_data[i] = varargin_1 * varargin_1;
  }
  return in1_size;
}

/* End of code generation (unsafeSxfun.c) */
