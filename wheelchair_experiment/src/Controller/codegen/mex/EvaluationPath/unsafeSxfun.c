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
#include "EvaluationPath_data.h"
#include "EvaluationPath_emxutil.h"
#include "EvaluationPath_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void binary_expand_op_14(real_T in1_data[], int32_T *in1_size,
                         const real_T in3_data[], const int32_T *in3_size)
{
  real_T b_in3_data[30];
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in1_size == 1) {
    loop_ub = *in3_size;
  } else {
    loop_ub = *in1_size;
  }
  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (*in1_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] = in3_data[i * stride_0_0] / in1_data[i * stride_1_0];
  }
  *in1_size = loop_ub;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = muDoubleScalarMax(0.0, muDoubleScalarMin(1.0, b_in3_data[i]));
  }
}

void binary_expand_op_9(const emlrtStack *sp, emxArray_real_T *in1,
                        const real_T in3_data[], const int32_T *in3_size,
                        const real_T in4_data[], const int32_T *in4_size)
{
  real_T b_in3_data[30];
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  if (*in4_size == 1) {
    loop_ub = *in3_size;
  } else {
    loop_ub = *in4_size;
  }
  stride_0_0 = (*in3_size != 1);
  stride_1_0 = (*in4_size != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] = in3_data[i * stride_0_0] / in4_data[i * stride_1_0];
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &rd_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] =
        muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, b_in3_data[i]));
  }
}

/* End of code generation (unsafeSxfun.c) */
