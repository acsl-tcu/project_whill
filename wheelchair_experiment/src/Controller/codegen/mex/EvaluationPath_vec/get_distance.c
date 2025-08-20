/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_distance.c
 *
 * Code generation for function 'get_distance'
 *
 */

/* Include files */
#include "get_distance.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "abs.h"
#include "div.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo dg_emlrtRSI = {
    10,             /* lineNo */
    "get_distance", /* fcnName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pathName */
};

static emlrtRSInfo eg_emlrtRSI = {
    12,             /* lineNo */
    "get_distance", /* fcnName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI = {
    14,             /* lineNo */
    "get_distance", /* fcnName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pathName */
};

static emlrtECInfo pf_emlrtECI = {
    3,              /* nDims */
    4,              /* lineNo */
    10,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo qf_emlrtECI = {
    4,              /* nDims */
    4,              /* lineNo */
    10,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo rf_emlrtECI = {
    3,              /* nDims */
    6,              /* lineNo */
    10,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo sf_emlrtECI = {
    4,              /* nDims */
    6,              /* lineNo */
    10,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo tf_emlrtECI = {
    3,              /* nDims */
    10,             /* lineNo */
    35,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo uf_emlrtECI = {
    4,              /* nDims */
    10,             /* lineNo */
    35,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo vf_emlrtECI = {
    3,              /* nDims */
    10,             /* lineNo */
    64,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtECInfo wf_emlrtECI = {
    4,              /* nDims */
    10,             /* lineNo */
    64,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo ei_emlrtRTEI = {
    4,              /* lineNo */
    5,              /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo fi_emlrtRTEI = {
    6,              /* lineNo */
    5,              /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo gi_emlrtRTEI = {
    10,             /* lineNo */
    35,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo hi_emlrtRTEI = {
    10,             /* lineNo */
    64,             /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo ii_emlrtRTEI = {
    12,             /* lineNo */
    5,              /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRTEInfo ji_emlrtRTEI = {
    14,             /* lineNo */
    5,              /* colNo */
    "get_distance", /* fName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pName */
};

static emlrtRSInfo rg_emlrtRSI = {
    54,    /* lineNo */
    "div", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/div.m" /* pathName
                                                                       */
};

static emlrtRSInfo tg_emlrtRSI = {
    6,              /* lineNo */
    "get_distance", /* fcnName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    4,              /* lineNo */
    "get_distance", /* fcnName */
    "/home/takumi/Document/10\xe5\x8f\xb7\xe9\xa4\xa8"
    "4\xe9\x9a\x8e\xe9\x80\x9a\xe8\xb7\xaf\xe8\xb5\xb0\xe8\xa1\x8c_2025_06_07/"
    "caps"
    "uele_v5.3_\xe8\xa4\x87\xe6\x95\xb0\xe6\xad\xa9\xe8\xa1\x8c\xe8\x80\x85/"
    "src/Controller/get_distance.m" /* pathName */
};

/* Function Declarations */
static void binary_expand_op_45(const emlrtStack *sp, emxArray_real_T *in1,
                                const emlrtRSInfo in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4);

static void binary_expand_op_46(const emlrtStack *sp, emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3);

static void binary_expand_op_47(const emlrtStack *sp, emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3);

static void e_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2, const emxArray_real_T *in3);

/* Function Definitions */
static void binary_expand_op_45(const emlrtStack *sp, emxArray_real_T *in1,
                                const emlrtRSInfo in2,
                                const emxArray_real_T *in3,
                                const emxArray_real_T *in4)
{
  emlrtStack st;
  emxArray_real_T *b_in3;
  const real_T *in3_data;
  const real_T *in4_data;
  real_T *b_in3_data;
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
  st.prev = sp;
  st.tls = sp->tls;
  in4_data = in4->data;
  in3_data = in3->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in3, 4, &gi_emlrtRTEI);
  i = b_in3->size[0] * b_in3->size[1] * b_in3->size[2] * b_in3->size[3];
  b_in3->size[0] = 1;
  b_in3->size[1] = 1;
  if (in4->size[2] == 1) {
    loop_ub = in3->size[2];
  } else {
    loop_ub = in4->size[2];
  }
  b_in3->size[2] = loop_ub;
  if (in4->size[3] == 1) {
    b_loop_ub = in3->size[3];
  } else {
    b_loop_ub = in4->size[3];
  }
  b_in3->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in3, i, &gi_emlrtRTEI);
  b_in3_data = b_in3->data;
  stride_0_2 = (in3->size[2] != 1);
  stride_0_3 = (in3->size[3] != 1);
  stride_1_2 = (in4->size[2] != 1);
  stride_1_3 = (in4->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in3_data[i1 + b_in3->size[2] * i] =
          in3_data[i1 * stride_0_2 + in3->size[2] * aux_0_3] -
          in4_data[i1 * stride_1_2 + in4->size[2] * aux_1_3];
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
  st.site = (emlrtRSInfo *)&in2;
  b_abs(&st, b_in3, in1);
  emxFree_real_T(sp, &b_in3);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

static void binary_expand_op_46(const emlrtStack *sp, emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
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
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 1;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &hi_emlrtRTEI);
  if (in3->size[2] == 1) {
    loop_ub = in2->size[2];
  } else {
    loop_ub = in3->size[2];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &hi_emlrtRTEI);
  if (in3->size[3] == 1) {
    b_loop_ub = in2->size[3];
  } else {
    b_loop_ub = in3->size[3];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &hi_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[2] * i] =
          in2_data[2 * (i1 * stride_0_2) + 2 * in2->size[2] * aux_0_3] *
          in3_data[(2 * (i1 * stride_1_2) + 2 * in3->size[2] * aux_1_3) + 1];
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void binary_expand_op_47(const emlrtStack *sp, emxArray_real_T *in1,
                                const emxArray_real_T *in2,
                                const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
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
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 1;
  in1->size[1] = 1;
  emxEnsureCapacity_real_T(sp, in1, i, &gi_emlrtRTEI);
  if (in3->size[2] == 1) {
    loop_ub = in2->size[2];
  } else {
    loop_ub = in3->size[2];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &gi_emlrtRTEI);
  if (in3->size[3] == 1) {
    b_loop_ub = in2->size[3];
  } else {
    b_loop_ub = in3->size[3];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &gi_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      in1_data[i1 + in1->size[2] * i] =
          in2_data[2 * (i1 * stride_0_2) + 2 * in2->size[2] * aux_0_3] *
          in3_data[(2 * (i1 * stride_1_2) + 2 * in3->size[2] * aux_1_3) + 1];
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

static void e_minus(const emlrtStack *sp, emxArray_real_T *in1,
                    const emxArray_real_T *in2, const emxArray_real_T *in3)
{
  const real_T *in2_data;
  const real_T *in3_data;
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
  in3_data = in3->data;
  in2_data = in2->data;
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[0] = 1;
  in1->size[1] = 2;
  emxEnsureCapacity_real_T(sp, in1, i, &fi_emlrtRTEI);
  if (in3->size[2] == 1) {
    loop_ub = in2->size[2];
  } else {
    loop_ub = in3->size[2];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[2] = loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &fi_emlrtRTEI);
  if (in3->size[3] == 1) {
    b_loop_ub = in2->size[3];
  } else {
    b_loop_ub = in3->size[3];
  }
  i = in1->size[0] * in1->size[1] * in1->size[2] * in1->size[3];
  in1->size[3] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, in1, i, &fi_emlrtRTEI);
  in1_data = in1->data;
  stride_0_2 = (in2->size[2] != 1);
  stride_0_3 = (in2->size[3] != 1);
  stride_1_2 = (in3->size[2] != 1);
  stride_1_3 = (in3->size[3] != 1);
  aux_0_3 = 0;
  aux_1_3 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    int32_T aux_0_2;
    int32_T aux_1_2;
    aux_0_2 = 0;
    aux_1_2 = 0;
    for (i1 = 0; i1 < loop_ub; i1++) {
      __m128d r;
      __m128d r1;
      r = _mm_loadu_pd(&in2_data[2 * aux_0_2 + 2 * in2->size[2] * aux_0_3]);
      r1 = _mm_loadu_pd(&in3_data[2 * aux_1_2 + 2 * in3->size[2] * aux_1_3]);
      _mm_storeu_pd(&in1_data[2 * i1 + 2 * in1->size[2] * i],
                    _mm_sub_pd(r, r1));
      aux_1_2 += stride_1_2;
      aux_0_2 += stride_0_2;
    }
    aux_1_3 += stride_1_3;
    aux_0_3 += stride_0_3;
  }
}

void get_distance(const emlrtStack *sp, const emxArray_real_T *A,
                  const emxArray_real_T *B, const emxArray_real_T *P,
                  emxArray_real_T *distance)
{
  __m128d r2;
  __m128d r3;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *AB;
  emxArray_real_T *AP;
  emxArray_real_T *b_norm_AB;
  emxArray_real_T *norm_AB;
  emxArray_real_T *r;
  const real_T *A_data;
  const real_T *B_data;
  const real_T *P_data;
  real_T *AB_data;
  real_T *AP_data;
  real_T *norm_AB_data;
  real_T *r1;
  int32_T i;
  int32_T npages;
  int32_T scalarLB;
  int32_T vectorUB;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  P_data = P->data;
  B_data = B->data;
  A_data = A->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emlrtMEXProfilingFunctionEntry((char_T *)get_distance_complete_name,
                                 isMexOutdated);
  /*  2点A, Bを通る直線と点Pとの距離を計算 */
  /*  点Aから点Bへのベクトル */
  emlrtMEXProfilingStatement(1, isMexOutdated);
  if ((B->size[2] != A->size[2]) && ((B->size[2] != 1) && (A->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(B->size[2], A->size[2], &pf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((B->size[3] != A->size[3]) && ((B->size[3] != 1) && (A->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(B->size[3], A->size[3], &qf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &AB, 4, &ei_emlrtRTEI);
  if ((B->size[2] == A->size[2]) && (B->size[3] == A->size[3])) {
    i = AB->size[0] * AB->size[1] * AB->size[2] * AB->size[3];
    AB->size[0] = 1;
    AB->size[1] = 2;
    AB->size[2] = B->size[2];
    AB->size[3] = B->size[3];
    emxEnsureCapacity_real_T(sp, AB, i, &ei_emlrtRTEI);
    AB_data = AB->data;
    npages = (B->size[2] << 1) * B->size[3];
    scalarLB = (npages / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      _mm_storeu_pd(&AB_data[i], _mm_sub_pd(_mm_loadu_pd(&B_data[i]),
                                            _mm_loadu_pd(&A_data[i])));
    }
    for (i = scalarLB; i < npages; i++) {
      AB_data[i] = B_data[i] - A_data[i];
    }
  } else {
    st.site = &ug_emlrtRSI;
    e_minus(&st, AB, B, A);
    AB_data = AB->data;
  }
  /*  点Aから点Pへのベクトル */
  emlrtMEXProfilingStatement(2, isMexOutdated);
  if ((P->size[2] != A->size[2]) && ((P->size[2] != 1) && (A->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(P->size[2], A->size[2], &rf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((P->size[3] != A->size[3]) && ((P->size[3] != 1) && (A->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(P->size[3], A->size[3], &sf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &AP, 4, &fi_emlrtRTEI);
  if ((P->size[2] == A->size[2]) && (P->size[3] == A->size[3])) {
    i = AP->size[0] * AP->size[1] * AP->size[2] * AP->size[3];
    AP->size[0] = 1;
    AP->size[1] = 2;
    AP->size[2] = P->size[2];
    AP->size[3] = P->size[3];
    emxEnsureCapacity_real_T(sp, AP, i, &fi_emlrtRTEI);
    AP_data = AP->data;
    npages = (P->size[2] << 1) * P->size[3];
    scalarLB = (npages / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      _mm_storeu_pd(&AP_data[i], _mm_sub_pd(_mm_loadu_pd(&P_data[i]),
                                            _mm_loadu_pd(&A_data[i])));
    }
    for (i = scalarLB; i < npages; i++) {
      AP_data[i] = P_data[i] - A_data[i];
    }
  } else {
    st.site = &tg_emlrtRSI;
    e_minus(&st, AP, P, A);
    AP_data = AP->data;
  }
  /*  面積の公式から距離を計算する --- */
  /*  d = |AP x AB| / |AB| */
  /*  外積の大きさ |AP(1)*AB(2) - AP(2)*AB(1)| */
  emlrtMEXProfilingStatement(3, isMexOutdated);
  npages = AP->size[2];
  if ((AP->size[2] != AB->size[2]) &&
      ((AP->size[2] != 1) && (AB->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(AP->size[2], AB->size[2], &tf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  scalarLB = AP->size[3];
  if ((AP->size[3] != AB->size[3]) &&
      ((AP->size[3] != 1) && (AB->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(AP->size[3], AB->size[3], &uf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((AP->size[2] != AB->size[2]) &&
      ((AP->size[2] != 1) && (AB->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(AP->size[2], AB->size[2], &vf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((AP->size[3] != AB->size[3]) &&
      ((AP->size[3] != 1) && (AB->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(AP->size[3], AB->size[3], &wf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  emxInit_real_T(sp, &norm_AB, 4, &ii_emlrtRTEI);
  if ((AP->size[2] == AB->size[2]) && (AP->size[3] == AB->size[3])) {
    i = norm_AB->size[0] * norm_AB->size[1] * norm_AB->size[2] *
        norm_AB->size[3];
    norm_AB->size[0] = 1;
    norm_AB->size[1] = 1;
    norm_AB->size[2] = AP->size[2];
    norm_AB->size[3] = AP->size[3];
    emxEnsureCapacity_real_T(sp, norm_AB, i, &gi_emlrtRTEI);
    norm_AB_data = norm_AB->data;
    for (i = 0; i < scalarLB; i++) {
      for (vectorUB = 0; vectorUB < npages; vectorUB++) {
        norm_AB_data[vectorUB + norm_AB->size[2] * i] =
            AP_data[2 * vectorUB + 2 * AP->size[2] * i] *
            AB_data[(2 * vectorUB + 2 * AB->size[2] * i) + 1];
      }
    }
  } else {
    st.site = &dg_emlrtRSI;
    binary_expand_op_47(&st, norm_AB, AP, AB);
    norm_AB_data = norm_AB->data;
  }
  emxInit_real_T(sp, &r, 4, &gi_emlrtRTEI);
  if ((AB->size[2] == AP->size[2]) && (AB->size[3] == AP->size[3])) {
    i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
    r->size[0] = 1;
    r->size[1] = 1;
    npages = AB->size[2];
    r->size[2] = AB->size[2];
    scalarLB = AB->size[3];
    r->size[3] = AB->size[3];
    emxEnsureCapacity_real_T(sp, r, i, &hi_emlrtRTEI);
    r1 = r->data;
    for (i = 0; i < scalarLB; i++) {
      for (vectorUB = 0; vectorUB < npages; vectorUB++) {
        r1[vectorUB + r->size[2] * i] =
            AB_data[2 * vectorUB + 2 * AB->size[2] * i] *
            AP_data[(2 * vectorUB + 2 * AP->size[2] * i) + 1];
      }
    }
  } else {
    st.site = &dg_emlrtRSI;
    binary_expand_op_46(&st, r, AB, AP);
    r1 = r->data;
  }
  emxFree_real_T(sp, &AP);
  if ((norm_AB->size[2] != r->size[2]) &&
      ((norm_AB->size[2] != 1) && (r->size[2] != 1))) {
    emlrtDimSizeImpxCheckR2021b(norm_AB->size[2], r->size[2], &tf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((norm_AB->size[3] != r->size[3]) &&
      ((norm_AB->size[3] != 1) && (r->size[3] != 1))) {
    emlrtDimSizeImpxCheckR2021b(norm_AB->size[3], r->size[3], &uf_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((norm_AB->size[2] == r->size[2]) && (norm_AB->size[3] == r->size[3])) {
    emxInit_real_T(sp, &b_norm_AB, 4, &gi_emlrtRTEI);
    i = b_norm_AB->size[0] * b_norm_AB->size[1] * b_norm_AB->size[2] *
        b_norm_AB->size[3];
    b_norm_AB->size[0] = 1;
    b_norm_AB->size[1] = 1;
    b_norm_AB->size[2] = norm_AB->size[2];
    b_norm_AB->size[3] = norm_AB->size[3];
    emxEnsureCapacity_real_T(sp, b_norm_AB, i, &gi_emlrtRTEI);
    AP_data = b_norm_AB->data;
    npages = norm_AB->size[2] * norm_AB->size[3];
    scalarLB = (npages / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&norm_AB_data[i]);
      r3 = _mm_loadu_pd(&r1[i]);
      _mm_storeu_pd(&AP_data[i], _mm_sub_pd(r2, r3));
    }
    for (i = scalarLB; i < npages; i++) {
      AP_data[i] = norm_AB_data[i] - r1[i];
    }
    st.site = &dg_emlrtRSI;
    b_abs(&st, b_norm_AB, distance);
    emxFree_real_T(sp, &b_norm_AB);
  } else {
    st.site = &dg_emlrtRSI;
    binary_expand_op_45(&st, distance, dg_emlrtRSI, norm_AB, r);
  }
  emxFree_real_T(sp, &r);
  /*  ベクトルABの大きさ */
  emlrtMEXProfilingStatement(4, isMexOutdated);
  st.site = &eg_emlrtRSI;
  b_st.site = &se_emlrtRSI;
  i = norm_AB->size[0] * norm_AB->size[1] * norm_AB->size[2] * norm_AB->size[3];
  norm_AB->size[0] = 1;
  norm_AB->size[1] = 1;
  norm_AB->size[2] = AB->size[2];
  norm_AB->size[3] = AB->size[3];
  emxEnsureCapacity_real_T(&b_st, norm_AB, i, &ii_emlrtRTEI);
  norm_AB_data = norm_AB->data;
  npages = AB->size[2] * AB->size[3];
  for (i = 0; i < npages; i++) {
    norm_AB_data[i] = 0.0;
  }
  c_st.site = &te_emlrtRSI;
  npages = AB->size[2] * AB->size[3];
  d_st.site = &ue_emlrtRSI;
  if (npages > 2147483646) {
    e_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (vectorUB = 0; vectorUB < npages; vectorUB++) {
    real_T absxk;
    real_T scale;
    real_T t;
    real_T varargout_1;
    scalarLB = vectorUB << 1;
    scale = 3.3121686421112381E-170;
    absxk = muDoubleScalarAbs(AB_data[scalarLB]);
    if (absxk > 3.3121686421112381E-170) {
      varargout_1 = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      varargout_1 = t * t;
    }
    absxk = muDoubleScalarAbs(AB_data[scalarLB + 1]);
    if (absxk > scale) {
      t = scale / absxk;
      varargout_1 = varargout_1 * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      varargout_1 += t * t;
    }
    norm_AB_data[vectorUB] = scale * muDoubleScalarSqrt(varargout_1);
  }
  emxFree_real_T(&c_st, &AB);
  /*  距離 */
  emlrtMEXProfilingStatement(5, isMexOutdated);
  st.site = &fg_emlrtRSI;
  b_st.site = &qe_emlrtRSI;
  c_st.site = &re_emlrtRSI;
  if (((distance->size[2] != 1) && (norm_AB->size[2] != 1) &&
       (distance->size[2] != norm_AB->size[2])) ||
      ((distance->size[3] != 1) && (norm_AB->size[3] != 1) &&
       (distance->size[3] != norm_AB->size[3]))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &o_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  if ((distance->size[2] == norm_AB->size[2]) &&
      (distance->size[3] == norm_AB->size[3])) {
    npages = distance->size[2] * distance->size[3];
    i = distance->size[0] * distance->size[1] * distance->size[2] *
        distance->size[3];
    distance->size[0] = 1;
    distance->size[1] = 1;
    emxEnsureCapacity_real_T(&b_st, distance, i, &ji_emlrtRTEI);
    AP_data = distance->data;
    scalarLB = (npages / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r2 = _mm_loadu_pd(&AP_data[i]);
      r3 = _mm_loadu_pd(&norm_AB_data[i]);
      _mm_storeu_pd(&AP_data[i], _mm_div_pd(r2, r3));
    }
    for (i = scalarLB; i < npages; i++) {
      AP_data[i] /= norm_AB_data[i];
    }
  } else {
    c_st.site = &rg_emlrtRSI;
    rdivide(&c_st, distance, norm_AB);
  }
  emxFree_real_T(&b_st, &norm_AB);
  emlrtMEXProfilingStatement(6, isMexOutdated);
  emlrtMEXProfilingFunctionExit(isMexOutdated);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (get_distance.c) */
