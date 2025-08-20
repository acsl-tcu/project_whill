/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * wrapResidual.c
 *
 * Code generation for function 'wrapResidual'
 *
 */

/* Include files */
#include "wrapResidual.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void c_binary_expand_op(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in2, const real_T in3[6],
                        const int8_T in4_data[], const int32_T *in4_size)
{
  const real_T *in2_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T in4_idx_0;
  int32_T loop_ub;
  int32_T stride_0_0;
  in2_data = in2->data;
  in4_idx_0 = *in4_size;
  if (in4_idx_0 == 1) {
    loop_ub = in2->size[0];
  } else {
    loop_ub = in4_idx_0;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = loop_ub;
  in1->size[1] = in2->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &fn_emlrtRTEI);
  in1_data = in1->data;
  stride_0_0 = (in2->size[0] != 1);
  in4_idx_0 = (in4_idx_0 != 1);
  b_loop_ub = in2->size[1];
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] =
          in2_data[i1 * stride_0_0 + in2->size[0] * i] +
          in3[in4_data[i1 * in4_idx_0]];
    }
  }
}

/* End of code generation (wrapResidual.c) */
