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
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void binary_expand_op_25(const emlrtStack *sp, emxArray_real_T *in1,
                         const real_T in3_data[], const int32_T in3_size[3],
                         const emxArray_real_T *in4)
{
  emxArray_real_T *in3;
  const real_T *in4_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T in3_idx_0;
  int32_T in3_idx_2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  int32_T stride_1_2;
  in4_data = in4->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  in3_idx_0 = in3_size[0];
  in3_idx_2 = in3_size[2];
  emxInit_real_T(sp, &in3, 4, &uf_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3_idx_0;
  } else {
    loop_ub = in4->size[0];
  }
  i = in3->size[0] * in3->size[1] * in3->size[2] * in3->size[3];
  in3->size[0] = loop_ub;
  in3->size[1] = 1;
  if (in4->size[2] == 1) {
    b_loop_ub = in3_idx_2;
  } else {
    b_loop_ub = in4->size[2];
  }
  in3->size[2] = b_loop_ub;
  c_loop_ub = in4->size[3];
  in3->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in3, i, &uf_emlrtRTEI);
  b_in3_data = in3->data;
  stride_0_0 = (in3_idx_0 != 1);
  in3_idx_2 = (in3_idx_2 != 1);
  stride_1_0 = (in4->size[0] != 1);
  stride_1_2 = (in4->size[2] != 1);
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + in3->size[0] * i1) + in3->size[0] * in3->size[2] * i] =
            in3_data[i2 * stride_0_0 + in3_idx_0 * aux_0_2] /
            in4_data[(i2 * stride_1_0 + in4->size[0] * aux_1_2) +
                     in4->size[0] * in4->size[2] * i];
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += in3_idx_2;
    }
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &xf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_1;
        varargin_1 = b_in3_data[(i2 + in3->size[0] * i1) +
                                in3->size[0] * in3->size[2] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
            muDoubleScalarMax(-1.0, muDoubleScalarMin(varargin_1, 1.0));
      }
    }
  }
  emxFree_real_T(sp, &in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_28(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3, const emxArray_real_T *in4)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 4, &uf_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 1;
  if (in4->size[2] == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in4->size[2];
  }
  b_in3->size[2] = b_loop_ub;
  if (in4->size[3] == 1) {
    c_loop_ub = in3->size[3];
  } else {
    c_loop_ub = in4->size[3];
  }
  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &uf_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_0 = (in4->size[0] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + b_in3->size[0] * i1) +
                   b_in3->size[0] * b_in3->size[2] * i] =
            in3_data[(i2 * stride_0_0 + in3->size[0] * aux_0_2) +
                     in3->size[0] * in3->size[2] * aux_0_3] /
            in4_data[(i2 * stride_1_0 + in4->size[0] * aux_1_2) +
                     in4->size[0] * in4->size[2] * aux_1_3];
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &pf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_2;
        varargin_2 = b_in3_data[(i2 + b_in3->size[0] * i1) +
                                b_in3->size[0] * b_in3->size[2] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
            muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, varargin_2));
      }
    }
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_30(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 4, &uf_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 1;
  if (in1->size[2] == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in1->size[2];
  }
  b_in3->size[2] = b_loop_ub;
  if (in1->size[3] == 1) {
    c_loop_ub = in3->size[3];
  } else {
    c_loop_ub = in1->size[3];
  }
  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &uf_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_2 = (in1->size[2] != 1);
  stride_1_3 = (in1->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + b_in3->size[0] * i1) +
                   b_in3->size[0] * b_in3->size[2] * i] =
            in3_data[(i2 * stride_0_0 + in3->size[0] * aux_0_2) +
                     in3->size[0] * in3->size[2] * aux_0_3] /
            in1_data[(i2 * stride_1_0 + in1->size[0] * aux_1_2) +
                     in1->size[0] * in1->size[2] * aux_1_3];
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &lf_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_2;
        varargin_2 = b_in3_data[(i2 + b_in3->size[0] * i1) +
                                b_in3->size[0] * b_in3->size[2] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
            muDoubleScalarMax(-1.0, muDoubleScalarMin(1.0, varargin_2));
      }
    }
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_38(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T aux_0_3;
  int32_T aux_1_3;
  int32_T b_loop_ub;
  int32_T c_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_2;
  int32_T stride_0_3;
  int32_T stride_1_0;
  int32_T stride_1_2;
  int32_T stride_1_3;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 4, &uf_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = loop_ub;
  b_in3->size[1] = 1;
  if (in1->size[2] == 1) {
    b_loop_ub = in3->size[2];
  } else {
    b_loop_ub = in1->size[2];
  }
  b_in3->size[2] = b_loop_ub;
  if (in1->size[3] == 1) {
    c_loop_ub = in3->size[3];
  } else {
    c_loop_ub = in1->size[3];
  }
  b_in3->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &uf_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_0 = (in1->size[0] != 1);
  stride_1_2 = (in1->size[2] != 1);
  stride_1_3 = (in1->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < c_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        b_in3_data[(i2 + b_in3->size[0] * i1) +
                   b_in3->size[0] * b_in3->size[2] * i] =
            in3_data[(i2 * stride_0_0 + in3->size[0] * aux_0_2) +
                     in3->size[0] * in3->size[2] * aux_0_3] /
            in1_data[(i2 * stride_1_0 + in1->size[0] * aux_1_2) +
                     in1->size[0] * in1->size[2] * aux_1_3];
      }
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = loop_ub;
  in1->size[1] = 1;
  in1->size[2] = b_loop_ub;
  in1->size[3] = c_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &we_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < c_loop_ub; i++) {
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      for (i2 = 0; i2 < loop_ub; i2++) {
        real_T varargin_2;
        varargin_2 = b_in3_data[(i2 + b_in3->size[0] * i1) +
                                b_in3->size[0] * b_in3->size[2] * i];
        in1_data[(i2 + in1->size[0] * i1) + in1->size[0] * in1->size[2] * i] =
            muDoubleScalarMax(0.0, muDoubleScalarMin(1.0, varargin_2));
      }
    }
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unsafeSxfun.c) */
