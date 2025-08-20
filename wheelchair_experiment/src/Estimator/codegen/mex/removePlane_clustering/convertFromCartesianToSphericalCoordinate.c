/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * convertFromCartesianToSphericalCoordinate.c
 *
 * Code generation for function 'convertFromCartesianToSphericalCoordinate'
 *
 */

/* Include files */
#include "convertFromCartesianToSphericalCoordinate.h"
#include "div.h"
#include "eml_int_forloop_overflow_check.h"
#include "indexShapeCheck.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <emmintrin.h>

/* Variable Definitions */
static emlrtRSInfo oe_emlrtRSI = {
    15,                                          /* lineNo */
    "convertFromCartesianToSphericalCoordinate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    16,                                          /* lineNo */
    "convertFromCartesianToSphericalCoordinate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    17,                                          /* lineNo */
    "convertFromCartesianToSphericalCoordinate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pathName */
};

static emlrtRSInfo re_emlrtRSI = {
    18,                                          /* lineNo */
    "convertFromCartesianToSphericalCoordinate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pathName */
};

static emlrtRSInfo se_emlrtRSI = {
    19,                                          /* lineNo */
    "convertFromCartesianToSphericalCoordinate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pathName */
};

static emlrtRSInfo te_emlrtRSI = {
    34,               /* lineNo */
    "rdivide_helper", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\rdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo ue_emlrtRSI = {
    51,    /* lineNo */
    "div", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" /* pathName
                                                                          */
};

static emlrtRSInfo ve_emlrtRSI = {
    17,     /* lineNo */
    "asin", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\asin.m" /* pathName
                                                                       */
};

static emlrtRSInfo we_emlrtRSI = {
    13,      /* lineNo */
    "atan2", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\atan2.m" /* pathName
                                                                        */
};

static emlrtRSInfo af_emlrtRSI =
    {
        130,   /* lineNo */
        "cat", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" /* pathName
                                                                          */
};

static emlrtRTEInfo s_emlrtRTEI =
    {
        91,    /* lineNo */
        27,    /* colNo */
        "cat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" /* pName
                                                                          */
};

static emlrtRTEInfo t_emlrtRTEI = {
    14,     /* lineNo */
    9,      /* colNo */
    "asin", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elfun\\asin.m" /* pName
                                                                       */
};

static emlrtRTEInfo u_emlrtRTEI = {
    13,                     /* lineNo */
    27,                     /* colNo */
    "assertCompatibleDims", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\assertCompatibleDims.m" /* pName */
};

static emlrtECInfo emlrtECI = {
    2,                                           /* nDims */
    15,                                          /* lineNo */
    18,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtECInfo b_emlrtECI = {
    1,                                           /* nDims */
    15,                                          /* lineNo */
    18,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    18,                                          /* lineNo */
    24,                                          /* colNo */
    "",                                          /* aName */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    18,                                          /* lineNo */
    5,                                           /* colNo */
    "",                                          /* aName */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    15,                                          /* lineNo */
    18,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    15,                                          /* lineNo */
    25,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    15,                                          /* lineNo */
    32,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    17,                                          /* lineNo */
    5,                                           /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    1,                                           /* lineNo */
    22,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    18,                                          /* lineNo */
    20,                                          /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI =
    {
        101,   /* lineNo */
        24,    /* colNo */
        "cat", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\cat.m" /* pName
                                                                          */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    15,                                          /* lineNo */
    5,                                           /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    16,                                          /* lineNo */
    5,                                           /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    18,                                          /* lineNo */
    9,                                           /* colNo */
    "convertFromCartesianToSphericalCoordinate", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\vision\\vision\\+vision\\+"
    "internal\\convertFromCartesianToSphericalCoordinate.m" /* pName */
};

static emlrtRSInfo th_emlrtRSI = {
    52,    /* lineNo */
    "div", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\div.m" /* pathName
                                                                          */
};

/* Function Declarations */
static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2);

/* Function Definitions */
static void plus(const emlrtStack *sp, emxArray_real_T *in1,
                 const emxArray_real_T *in2)
{
  emxArray_real_T *b_in1;
  const real_T *in2_data;
  real_T *b_in1_data;
  real_T *in1_data;
  int32_T aux_0_1;
  int32_T aux_1_1;
  int32_T b_loop_ub;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  int32_T stride_0_0;
  int32_T stride_0_1;
  int32_T stride_1_0;
  int32_T stride_1_1;
  in2_data = in2->data;
  in1_data = in1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  emxInit_real_T(sp, &b_in1, 2, &qc_emlrtRTEI);
  if (in2->size[0] == 1) {
    loop_ub = in1->size[0];
  } else {
    loop_ub = in2->size[0];
  }
  i = b_in1->size[0] * b_in1->size[1];
  b_in1->size[0] = loop_ub;
  if (in2->size[1] == 1) {
    b_loop_ub = in1->size[1];
  } else {
    b_loop_ub = in2->size[1];
  }
  b_in1->size[1] = b_loop_ub;
  emxEnsureCapacity_real_T(sp, b_in1, i, &qc_emlrtRTEI);
  b_in1_data = b_in1->data;
  stride_0_0 = (in1->size[0] != 1);
  stride_0_1 = (in1->size[1] != 1);
  stride_1_0 = (in2->size[0] != 1);
  stride_1_1 = (in2->size[1] != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  for (i = 0; i < b_loop_ub; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_in1_data[i1 + b_in1->size[0] * i] =
          in1_data[i1 * stride_0_0 + in1->size[0] * aux_0_1] +
          in2_data[i1 * stride_1_0 + in2->size[0] * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  i = in1->size[0] * in1->size[1];
  in1->size[0] = b_in1->size[0];
  in1->size[1] = b_in1->size[1];
  emxEnsureCapacity_real_T(sp, in1, i, &qc_emlrtRTEI);
  in1_data = in1->data;
  loop_ub = b_in1->size[1];
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in1->size[0];
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      in1_data[i1 + in1->size[0] * i] = b_in1_data[i1 + b_in1->size[0] * i];
    }
  }
  emxFree_real_T(sp, &b_in1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void c_convertFromCartesianToSpheric(const emlrtStack *sp,
                                     const emxArray_real_T *xyzData,
                                     emxArray_real_T *rangeData)
{
  __m128d r;
  __m128d r1;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *r2;
  emxArray_real_T *c_yaw;
  emxArray_real_T *pitch;
  emxArray_real_T *range;
  emxArray_real_T *yaw;
  const real_T *xyzData_data;
  real_T varargin_1;
  real_T *pitch_data;
  real_T *rangeData_data;
  real_T *range_data;
  real_T *yaw_data;
  int32_T ysize[3];
  int32_T b_i;
  int32_T i;
  int32_T iy;
  int32_T loop_ub;
  int32_T scalarLB;
  int32_T vectorUB;
  int32_T *r3;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  xyzData_data = xyzData->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &oe_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  emxInit_real_T(&b_st, &range, 2, &yc_emlrtRTEI);
  i = range->size[0] * range->size[1];
  range->size[0] = xyzData->size[0];
  range->size[1] = xyzData->size[1];
  emxEnsureCapacity_real_T(&b_st, range, i, &qc_emlrtRTEI);
  range_data = range->data;
  loop_ub = xyzData->size[1];
  for (i = 0; i < loop_ub; i++) {
    iy = xyzData->size[0];
    for (b_i = 0; b_i < iy; b_i++) {
      varargin_1 = xyzData_data[b_i + xyzData->size[0] * i];
      range_data[b_i + range->size[0] * i] = varargin_1 * varargin_1;
    }
  }
  st.site = &oe_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  emxInit_real_T(&b_st, &pitch, 2, &ad_emlrtRTEI);
  i = pitch->size[0] * pitch->size[1];
  pitch->size[0] = xyzData->size[0];
  pitch->size[1] = xyzData->size[1];
  emxEnsureCapacity_real_T(&b_st, pitch, i, &rc_emlrtRTEI);
  pitch_data = pitch->data;
  loop_ub = xyzData->size[1];
  for (i = 0; i < loop_ub; i++) {
    iy = xyzData->size[0];
    for (b_i = 0; b_i < iy; b_i++) {
      varargin_1 = xyzData_data[(b_i + xyzData->size[0] * i) +
                                xyzData->size[0] * xyzData->size[1]];
      pitch_data[b_i + pitch->size[0] * i] = varargin_1 * varargin_1;
    }
  }
  if ((range->size[0] != pitch->size[0]) &&
      ((range->size[0] != 1) && (pitch->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(range->size[0], pitch->size[0], &b_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((range->size[1] != pitch->size[1]) &&
      ((range->size[1] != 1) && (pitch->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(range->size[1], pitch->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((range->size[0] == pitch->size[0]) &&
      (range->size[1] == pitch->size[1])) {
    iy = range->size[0] * range->size[1];
    scalarLB = (iy / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&range_data[i]);
      r1 = _mm_loadu_pd(&pitch_data[i]);
      _mm_storeu_pd(&range_data[i], _mm_add_pd(r, r1));
    }
    for (i = scalarLB; i < iy; i++) {
      range_data[i] += pitch_data[i];
    }
  } else {
    st.site = &oe_emlrtRSI;
    plus(&st, range, pitch);
    range_data = range->data;
  }
  st.site = &oe_emlrtRSI;
  b_st.site = &pd_emlrtRSI;
  i = pitch->size[0] * pitch->size[1];
  pitch->size[0] = xyzData->size[0];
  pitch->size[1] = xyzData->size[1];
  emxEnsureCapacity_real_T(&b_st, pitch, i, &sc_emlrtRTEI);
  pitch_data = pitch->data;
  loop_ub = xyzData->size[1];
  for (i = 0; i < loop_ub; i++) {
    iy = xyzData->size[0];
    for (b_i = 0; b_i < iy; b_i++) {
      varargin_1 = xyzData_data[(b_i + xyzData->size[0] * i) +
                                xyzData->size[0] * xyzData->size[1] * 2];
      pitch_data[b_i + pitch->size[0] * i] = varargin_1 * varargin_1;
    }
  }
  if ((range->size[0] != pitch->size[0]) &&
      ((range->size[0] != 1) && (pitch->size[0] != 1))) {
    emlrtDimSizeImpxCheckR2021b(range->size[0], pitch->size[0], &b_emlrtECI,
                                (emlrtConstCTX)sp);
  }
  if ((range->size[1] != pitch->size[1]) &&
      ((range->size[1] != 1) && (pitch->size[1] != 1))) {
    emlrtDimSizeImpxCheckR2021b(range->size[1], pitch->size[1], &emlrtECI,
                                (emlrtConstCTX)sp);
  }
  st.site = &oe_emlrtRSI;
  if ((range->size[0] == pitch->size[0]) &&
      (range->size[1] == pitch->size[1])) {
    loop_ub = range->size[0] * range->size[1];
    scalarLB = (loop_ub / 2) << 1;
    vectorUB = scalarLB - 2;
    for (i = 0; i <= vectorUB; i += 2) {
      r = _mm_loadu_pd(&range_data[i]);
      r1 = _mm_loadu_pd(&pitch_data[i]);
      _mm_storeu_pd(&range_data[i], _mm_add_pd(r, r1));
    }
    for (i = scalarLB; i < loop_ub; i++) {
      range_data[i] += pitch_data[i];
    }
  } else {
    b_st.site = &oe_emlrtRSI;
    plus(&b_st, range, pitch);
    range_data = range->data;
  }
  p = false;
  i = range->size[0] * range->size[1];
  for (iy = 0; iy < i; iy++) {
    if (p || (range_data[iy] < 0.0)) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &v_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  if (i > 2147483646) {
    d_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  scalarLB = (i / 2) << 1;
  vectorUB = scalarLB - 2;
  for (iy = 0; iy <= vectorUB; iy += 2) {
    r = _mm_loadu_pd(&range_data[iy]);
    _mm_storeu_pd(&range_data[iy], _mm_sqrt_pd(r));
  }
  for (iy = scalarLB; iy < i; iy++) {
    range_data[iy] = muDoubleScalarSqrt(range_data[iy]);
  }
  st.site = &pe_emlrtRSI;
  b_st.site = &te_emlrtRSI;
  c_st.site = &ue_emlrtRSI;
  if (((xyzData->size[0] != 1) && (range->size[0] != 1) &&
       (xyzData->size[0] != range->size[0])) ||
      ((xyzData->size[1] != 1) && (range->size[1] != 1) &&
       (xyzData->size[1] != range->size[1]))) {
    emlrtErrorWithMessageIdR2018a(&c_st, &u_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
  if ((xyzData->size[0] == range->size[0]) &&
      (xyzData->size[1] == range->size[1])) {
    i = pitch->size[0] * pitch->size[1];
    pitch->size[0] = xyzData->size[0];
    pitch->size[1] = xyzData->size[1];
    emxEnsureCapacity_real_T(&b_st, pitch, i, &tc_emlrtRTEI);
    pitch_data = pitch->data;
    loop_ub = xyzData->size[1];
    for (i = 0; i < loop_ub; i++) {
      iy = xyzData->size[0];
      scalarLB = (xyzData->size[0] / 2) << 1;
      vectorUB = scalarLB - 2;
      for (b_i = 0; b_i <= vectorUB; b_i += 2) {
        r = _mm_loadu_pd(&range_data[b_i + range->size[0] * i]);
        _mm_storeu_pd(
            &pitch_data[b_i + pitch->size[0] * i],
            _mm_div_pd(
                _mm_loadu_pd(
                    &xyzData_data[(b_i + xyzData->size[0] * i) +
                                  xyzData->size[0] * xyzData->size[1] * 2]),
                r));
      }
      for (b_i = scalarLB; b_i < iy; b_i++) {
        pitch_data[b_i + pitch->size[0] * i] =
            xyzData_data[(b_i + xyzData->size[0] * i) +
                         xyzData->size[0] * xyzData->size[1] * 2] /
            range_data[b_i + range->size[0] * i];
      }
    }
  } else {
    c_st.site = &th_emlrtRSI;
    binary_expand_op(&c_st, pitch, xyzData, range);
    pitch_data = pitch->data;
  }
  st.site = &pe_emlrtRSI;
  p = false;
  vectorUB = pitch->size[0] * pitch->size[1];
  for (iy = 0; iy < vectorUB; iy++) {
    if (p || ((pitch_data[iy] < -1.0) || (pitch_data[iy] > 1.0))) {
      p = true;
    }
  }
  if (p) {
    emlrtErrorWithMessageIdR2018a(
        &st, &t_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "asin");
  }
  b_st.site = &ve_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  if (vectorUB > 2147483646) {
    d_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (iy = 0; iy < vectorUB; iy++) {
    pitch_data[iy] = muDoubleScalarAsin(pitch_data[iy]);
  }
  st.site = &qe_emlrtRSI;
  b_st.site = &we_emlrtRSI;
  c_st.site = &td_emlrtRSI;
  emxInit_real_T(&c_st, &yaw, 2, &uc_emlrtRTEI);
  i = yaw->size[0] * yaw->size[1];
  yaw->size[0] = xyzData->size[0];
  yaw->size[1] = xyzData->size[1];
  emxEnsureCapacity_real_T(&c_st, yaw, i, &uc_emlrtRTEI);
  yaw_data = yaw->data;
  loop_ub = xyzData->size[1];
  for (i = 0; i < loop_ub; i++) {
    iy = xyzData->size[0];
    for (b_i = 0; b_i < iy; b_i++) {
      real_T varargin_2;
      varargin_1 = xyzData_data[b_i + xyzData->size[0] * i];
      varargin_2 = xyzData_data[(b_i + xyzData->size[0] * i) +
                                xyzData->size[0] * xyzData->size[1]];
      yaw_data[b_i + yaw->size[0] * i] =
          muDoubleScalarAtan2(varargin_1, varargin_2);
    }
  }
  int32_T b_yaw[2];
  b_yaw[0] = yaw->size[0];
  b_yaw[1] = yaw->size[1];
  st.site = &re_emlrtRSI;
  b_indexShapeCheck(&st, yaw->size, b_yaw);
  scalarLB = yaw->size[0] * yaw->size[1];
  loop_ub = scalarLB - 1;
  iy = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (yaw_data[b_i] < 0.0) {
      iy++;
    }
  }
  emxInit_int32_T(sp, &r2, 1, &bd_emlrtRTEI);
  i = r2->size[0];
  r2->size[0] = iy;
  emxEnsureCapacity_int32_T(sp, r2, i, &vc_emlrtRTEI);
  r3 = r2->data;
  iy = 0;
  for (b_i = 0; b_i <= loop_ub; b_i++) {
    if (yaw_data[b_i] < 0.0) {
      r3[iy] = b_i;
      iy++;
    }
  }
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    if (r3[i] > scalarLB - 1) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 0, scalarLB - 1, &g_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
  }
  emxInit_real_T(sp, &c_yaw, 1, &wc_emlrtRTEI);
  i = c_yaw->size[0];
  c_yaw->size[0] = r2->size[0];
  emxEnsureCapacity_real_T(sp, c_yaw, i, &wc_emlrtRTEI);
  rangeData_data = c_yaw->data;
  loop_ub = r2->size[0];
  for (i = 0; i < loop_ub; i++) {
    rangeData_data[i] = yaw_data[r3[i]] + 6.2831853071795862;
  }
  loop_ub = c_yaw->size[0];
  for (i = 0; i < loop_ub; i++) {
    if (r3[i] > scalarLB - 1) {
      emlrtDynamicBoundsCheckR2012b(r3[i], 0, scalarLB - 1, &h_emlrtBCI,
                                    (emlrtConstCTX)sp);
    }
    yaw_data[r3[i]] = rangeData_data[i];
  }
  emxFree_real_T(sp, &c_yaw);
  emxFree_int32_T(sp, &r2);
  st.site = &se_emlrtRSI;
  ysize[0] = range->size[0];
  ysize[1] = range->size[1];
  ysize[2] = 3;
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (ysize[loop_ub] != range->size[loop_ub]) {
      emlrtErrorWithMessageIdR2018a(
          &st, &s_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      loop_ub++;
    }
  }
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (ysize[loop_ub] != pitch->size[loop_ub]) {
      emlrtErrorWithMessageIdR2018a(
          &st, &s_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      loop_ub++;
    }
  }
  loop_ub = 0;
  exitg1 = false;
  while ((!exitg1) && (loop_ub < 2)) {
    if (ysize[loop_ub] != yaw->size[loop_ub]) {
      emlrtErrorWithMessageIdR2018a(
          &st, &s_emlrtRTEI, "Coder:MATLAB:catenate_dimensionMismatch",
          "Coder:MATLAB:catenate_dimensionMismatch", 0);
    } else {
      loop_ub++;
    }
  }
  i = rangeData->size[0] * rangeData->size[1] * rangeData->size[2];
  rangeData->size[0] = range->size[0];
  rangeData->size[1] = range->size[1];
  rangeData->size[2] = 3;
  emxEnsureCapacity_real_T(&st, rangeData, i, &xc_emlrtRTEI);
  rangeData_data = rangeData->data;
  iy = range->size[0] * range->size[1];
  b_st.site = &af_emlrtRSI;
  if (iy > 2147483646) {
    c_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (loop_ub = 0; loop_ub < iy; loop_ub++) {
    rangeData_data[loop_ub] = range_data[loop_ub];
  }
  emxFree_real_T(&st, &range);
  b_st.site = &af_emlrtRSI;
  for (loop_ub = 0; loop_ub < vectorUB; loop_ub++) {
    rangeData_data[iy + loop_ub] = pitch_data[loop_ub];
  }
  emxFree_real_T(&st, &pitch);
  iy = (iy + vectorUB) - 1;
  vectorUB = yaw->size[0] * yaw->size[1];
  b_st.site = &af_emlrtRSI;
  if (vectorUB > 2147483646) {
    c_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (loop_ub = 0; loop_ub < vectorUB; loop_ub++) {
    rangeData_data[(iy + loop_ub) + 1] = yaw_data[loop_ub];
  }
  emxFree_real_T(&st, &yaw);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (convertFromCartesianToSphericalCoordinate.c) */
