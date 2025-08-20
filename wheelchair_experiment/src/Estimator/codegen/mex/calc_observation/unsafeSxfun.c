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
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo nd_emlrtRTEI = {
    24,             /* lineNo */
    49,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo od_emlrtRTEI = {
    109,            /* lineNo */
    21,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    109,            /* lineNo */
    87,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    109,            /* lineNo */
    22,             /* colNo */
    "pcfitellipse", /* fName */
    "/home/student/Document/HaziqTest/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025"
    "_08_08/"
    "capsuele_v5.3_"
    "\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/src/"
    "Estimator/pcfitellipse.m" /* pName */
};

/* Function Definitions */
void binary_expand_op_1(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3)
{
  emxArray_real_T *b_in1;
  const real_T *in3_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 1, &nd_emlrtRTEI);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &nd_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] = (in1_data[i * stride_0_0] + in3_data[i * stride_1_0]) - 1.0;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &nd_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = in1_data[i];
    in1_data[i] = varargin_1 * varargin_1;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_2(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const emxArray_real_T *in4)
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 1, &od_emlrtRTEI);
  if (in4->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in4->size[0];
  }
  i = b_in3->size[0];
  b_in3->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &od_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in4->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] = (in3_data[i * stride_0_0] + in4_data[i * stride_1_0]) - 1.0;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &ed_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    real_T varargin_1;
    varargin_1 = b_in3_data[i];
    in1_data[i] = varargin_1 * varargin_1;
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const real_T in4[5])
{
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  real_T b_in4;
  real_T *b_in3_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_in4 = in4[3];
  emxInit_real_T(sp, &b_in3, 1, &pd_emlrtRTEI);
  if (in1->size[0] == 1) {
    loop_ub = in3->size[0];
  } else {
    loop_ub = in1->size[0];
  }
  i = b_in3->size[0];
  b_in3->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &pd_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_0 = (in3->size[0] != 1);
  stride_1_0 = (in1->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in3_data[i] =
        (in3_data[i * stride_0_0] + in1_data[i * stride_1_0]) / b_in4;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &dd_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    b_in4 = b_in3_data[i];
    in1_data[i] = b_in4 * b_in4;
  }
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const real_T in4[5])
{
  emxArray_real_T *b_in1;
  const real_T *in3_data;
  real_T b_in4;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T i;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_1_0;
  in3_data = in3->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  b_in4 = in4[2];
  emxInit_real_T(sp, &b_in1, 1, &qd_emlrtRTEI);
  if (in3->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in3->size[0];
  }
  i = b_in1->size[0];
  b_in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &qd_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_1_0 = (in3->size[0] != 1);
  for (i = 0; i < loop_ub; i++) {
    b_in1_data[i] =
        (in1_data[i * stride_0_0] + in3_data[i * stride_1_0]) / b_in4;
  }
  i = in1->size[0];
  in1->size[0] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &qd_emlrtRTEI);
  in1_data = in1->data;
  for (i = 0; i < loop_ub; i++) {
    in1_data[i] = b_in1_data[i];
  }
  emxFree_real_T(sp, &b_in1);
  for (i = 0; i < loop_ub; i++) {
    b_in4 = in1_data[i];
    in1_data[i] = b_in4 * b_in4;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (unsafeSxfun.c) */
