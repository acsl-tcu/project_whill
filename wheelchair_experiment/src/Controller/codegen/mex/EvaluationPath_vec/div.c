/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * div.c
 *
 * Code generation for function 'div'
 *
 */

/* Include files */
#include "div.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void rdivide(const emlrtStack *sp, emxArray_real_T *in1,
             const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 4, &uf_emlrtRTEI);
  i = b_in1->size[0] * b_in1->size[1] * b_in1->size[2] * b_in1->size[3];
  b_in1->size[0] = 1;
  b_in1->size[1] = 1;
  if (in2->size[2] == 1) {
    loop_ub = in1->size[2];
  } else {
    loop_ub = in2->size[2];
  }
  b_in1->size[2] = loop_ub;
  if (in2->size[3] == 1) {
    b_loop_ub = in1->size[3];
  } else {
    b_loop_ub = in2->size[3];
  }
  b_in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &uf_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_2 = (in1->size[2] != 1);
  stride_0_3 = (in1->size[3] != 1);
  stride_1_2 = (in2->size[2] != 1);
  stride_1_3 = (in2->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[2] * i] =
          in1_data[i1 * stride_0_2 + in1->size[2] * aux_0_3] /
          in2_data[i1 * stride_1_2 + in2->size[2] * aux_1_3];
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 1;
  in1->size[1] = 1;
  in1->size[2] = loop_ub;
  in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &uf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[2] * i] = b_in1_data[i1 + b_in1->size[2] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (div.c) */
