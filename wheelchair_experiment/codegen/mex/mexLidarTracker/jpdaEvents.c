/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * jpdaEvents.c
 *
 * Code generation for function 'jpdaEvents'
 *
 */

/* Include files */
#include "jpdaEvents.h"
#include "all.h"
#include "feasibleAndSortKBestEvents.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "numPotentialFeasibleEvents.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo tv_emlrtRSI = {
    94,                                                           /* lineNo */
    "jpdaEvents",                                                 /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/jpdaEvents.m" /* pathName */
};

static emlrtRSInfo uv_emlrtRSI = {
    62,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRSInfo vv_emlrtRSI = {
    48,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRSInfo wv_emlrtRSI = {
    34,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRSInfo xv_emlrtRSI = {
    31,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRSInfo yv_emlrtRSI = {
    29,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRSInfo aw_emlrtRSI = {
    14,                /* lineNo */
    "kbestJPDAEvents", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pathName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    34,                /* lineNo */
    23,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    31,                /* lineNo */
    23,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    29,                /* lineNo */
    23,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    24,                /* lineNo */
    23,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    23,                /* lineNo */
    23,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo nh_emlrtRTEI = {
    31,                /* lineNo */
    27,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo oh_emlrtRTEI = {
    34,                /* lineNo */
    31,                /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

static emlrtRTEInfo ph_emlrtRTEI = {
    42,                /* lineNo */
    5,                 /* colNo */
    "kbestJPDAEvents", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/fusion/fusion/+fusion/+internal/"
    "+assignment/kbestJPDAEvents.m" /* pName */
};

/* Function Definitions */
void jpdaEvents(const emlrtStack *sp, const emxArray_real_T *varargin_1,
                emxArray_boolean_T *varargout_1, emxArray_real_T *varargout_2)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_boolean_T *b_varargin_1;
  emxArray_boolean_T *validationMatrix;
  emxArray_real_T *c_varargin_1;
  real_T tmp_data[31];
  const real_T *varargin_1_data;
  real_T *c_varargin_1_data;
  int32_T varargin_1_size[2];
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T loop_ub;
  boolean_T b_varargin_1_data[31];
  boolean_T exitg1;
  boolean_T p;
  boolean_T *validationMatrix_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  varargin_1_data = varargin_1->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &tv_emlrtRSI;
  b_st.site = &aw_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  p = true;
  i = varargin_1->size[0] * varargin_1->size[1];
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if ((!muDoubleScalarIsInf(varargin_1_data[k])) &&
        (!muDoubleScalarIsNaN(varargin_1_data[k]))) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &h_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedFinite",
        "MATLAB:jpdaEvents:expectedFinite", 3, 4, 16, "likelihoodMatrix");
  }
  c_st.site = &jc_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k <= i - 1)) {
    if (!(varargin_1_data[k] < 0.0)) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &ib_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonnegative",
        "MATLAB:jpdaEvents:expectedNonnegative", 3, 4, 16, "likelihoodMatrix");
  }
  if (varargin_1->size[0] <= 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &yb_emlrtRTEI, "fusion:jpdaEvents:expectedLikelihoodMoreRows",
        "fusion:jpdaEvents:expectedLikelihoodMoreRows", 0);
  }
  if (varargin_1->size[1] <= 1) {
    emlrtErrorWithMessageIdR2018a(
        &st, &xb_emlrtRTEI, "fusion:jpdaEvents:expectedLikelihoodMoreColumns",
        "fusion:jpdaEvents:expectedLikelihoodMoreColumns", 0);
  }
  varargin_1_size[0] = 1;
  varargin_1_size[1] = varargin_1->size[1] - 1;
  k = varargin_1->size[1];
  for (i = 0; i <= k - 2; i++) {
    b_varargin_1_data[i] =
        (varargin_1_data[varargin_1->size[0] * (i + 1)] > 0.0);
  }
  b_st.site = &yv_emlrtRSI;
  if (!all(b_varargin_1_data, varargin_1_size)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &wb_emlrtRTEI,
        "fusion:jpdaEvents:expectedPositiveTrackUnassignment",
        "fusion:jpdaEvents:expectedPositiveTrackUnassignment", 0);
  }
  emxInit_boolean_T(&st, &b_varargin_1, 1, &nh_emlrtRTEI, true);
  i = b_varargin_1->size[0];
  b_varargin_1->size[0] = varargin_1->size[0] - 1;
  emxEnsureCapacity_boolean_T(&st, b_varargin_1, i, &nh_emlrtRTEI);
  validationMatrix_data = b_varargin_1->data;
  k = varargin_1->size[0];
  for (i = 0; i <= k - 2; i++) {
    validationMatrix_data[i] = (varargin_1_data[i + 1] > 0.0);
  }
  b_st.site = &xv_emlrtRSI;
  if (!b_all(&b_st, b_varargin_1)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &vb_emlrtRTEI,
        "fusion:jpdaEvents:expectedPositiveDetectionUnassignment",
        "fusion:jpdaEvents:expectedPositiveDetectionUnassignment", 0);
  }
  emxFree_boolean_T(&st, &b_varargin_1);
  emxInit_real_T(&st, &c_varargin_1, 2, &oh_emlrtRTEI, true);
  i = c_varargin_1->size[0] * c_varargin_1->size[1];
  c_varargin_1->size[0] = varargin_1->size[0] - 1;
  c_varargin_1->size[1] = varargin_1->size[1] - 1;
  emxEnsureCapacity_real_T(&st, c_varargin_1, i, &oh_emlrtRTEI);
  c_varargin_1_data = c_varargin_1->data;
  k = varargin_1->size[1];
  for (i = 0; i <= k - 2; i++) {
    loop_ub = varargin_1->size[0];
    for (i1 = 0; i1 <= loop_ub - 2; i1++) {
      c_varargin_1_data[i1 + c_varargin_1->size[0] * i] =
          varargin_1_data[(i1 + varargin_1->size[0] * (i + 1)) + 1];
    }
  }
  int32_T tmp_size[2];
  b_st.site = &wv_emlrtRSI;
  sum(&b_st, c_varargin_1, tmp_data, tmp_size);
  emxFree_real_T(&st, &c_varargin_1);
  varargin_1_size[0] = 1;
  varargin_1_size[1] = tmp_size[1];
  k = tmp_size[1];
  for (i = 0; i < k; i++) {
    b_varargin_1_data[i] = (tmp_data[i] >= 0.0);
  }
  b_st.site = &wv_emlrtRSI;
  if (!all(b_varargin_1_data, varargin_1_size)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &ub_emlrtRTEI, "fusion:jpdaEvents:expectedNonzeroLikelihoodColumn",
        "fusion:jpdaEvents:expectedNonzeroLikelihoodColumn", 0);
  }
  emxInit_boolean_T(&st, &validationMatrix, 2, &ph_emlrtRTEI, true);
  i = validationMatrix->size[0] * validationMatrix->size[1];
  validationMatrix->size[0] = varargin_1->size[0] - 1;
  validationMatrix->size[1] = varargin_1->size[1];
  emxEnsureCapacity_boolean_T(&st, validationMatrix, i, &ph_emlrtRTEI);
  validationMatrix_data = validationMatrix->data;
  k = varargin_1->size[1];
  for (i = 0; i < k; i++) {
    loop_ub = varargin_1->size[0];
    for (i1 = 0; i1 <= loop_ub - 2; i1++) {
      validationMatrix_data[i1 + validationMatrix->size[0] * i] =
          (varargin_1_data[(i1 + varargin_1->size[0] * i) + 1] > 0.0);
    }
  }
  b_st.site = &vv_emlrtRSI;
  numPotentialFeasibleEvents(&b_st, validationMatrix, varargin_1->size[0] - 1,
                             varargin_1->size[1] - 1);
  b_st.site = &uv_emlrtRSI;
  feasibleAndSortKBestEvents(&b_st, varargin_1, validationMatrix, varargout_1,
                             varargout_2);
  emxFree_boolean_T(&st, &validationMatrix);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (jpdaEvents.c) */
