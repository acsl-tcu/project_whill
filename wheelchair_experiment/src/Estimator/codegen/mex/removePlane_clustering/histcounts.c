/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * histcounts.c
 *
 * Code generation for function 'histcounts'
 *
 */

/* Include files */
#include "histcounts.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ge_emlrtRSI =
    {
        27,           /* lineNo */
        "histcounts", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI =
    {
        43,           /* lineNo */
        "histcounts", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pathName */
};

static emlrtRSInfo ie_emlrtRSI =
    {
        87,           /* lineNo */
        "parseinput", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pathName */
};

static emlrtRSInfo je_emlrtRSI =
    {
        266,          /* lineNo */
        "HistCounts", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI = {
    30,                  /* lineNo */
    "mapElementsToBins", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\mapEle"
    "mentsToBins.m" /* pathName */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    13,                      /* lineNo */
    37,                      /* colNo */
    "validatenondecreasing", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenondecreasing.m" /* pName */
};

static emlrtRTEInfo nf_emlrtRTEI = {
    23,                  /* lineNo */
    5,                   /* colNo */
    "mapElementsToBins", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\mapEle"
    "mentsToBins.m" /* pName */
};

static emlrtRTEInfo of_emlrtRTEI =
    {
        49,           /* lineNo */
        5,            /* colNo */
        "histcounts", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pName */
};

static emlrtRTEInfo pf_emlrtRTEI =
    {
        1,            /* lineNo */
        26,           /* colNo */
        "histcounts", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\histcounts."
        "m" /* pName */
};

/* Function Definitions */
void b_histcounts(const emlrtStack *sp, const emxArray_real_T *x,
                  const real_T varargin_1[1025], real_T n[1024],
                  emxArray_real_T *bin)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *b_bin;
  const real_T *x_data;
  real_T delta;
  real_T leftEdge;
  real_T *b_bin_data;
  int32_T b_n[1024];
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T nx;
  int32_T *bin_data;
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
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ge_emlrtRSI;
  b_st.site = &ie_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 1024)) {
    if (!(varargin_1[k] <= varargin_1[k + 1])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &jb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonDecreasing",
        "MATLAB:histcounts:expectedNonDecreasing", 3, 4, 22,
        "input number 2, edges,");
  }
  st.site = &he_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  memset(&b_n[0], 0, 1024U * sizeof(int32_T));
  emxInit_int32_T(&b_st, &b_bin, 1, &pf_emlrtRTEI);
  low_ip1 = b_bin->size[0];
  b_bin->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&b_st, b_bin, low_ip1, &nf_emlrtRTEI);
  bin_data = b_bin->data;
  low_i = x->size[0];
  for (low_ip1 = 0; low_ip1 < low_i; low_ip1++) {
    bin_data[low_ip1] = 0;
  }
  nx = x->size[0];
  leftEdge = varargin_1[0];
  delta = varargin_1[1] - varargin_1[0];
  c_st.site = &ke_emlrtRSI;
  if (x->size[0] > 2147483646) {
    d_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if ((x_data[k] >= leftEdge) && (x_data[k] <= varargin_1[1024])) {
      real_T bGuess;
      boolean_T guard1;
      bGuess = muDoubleScalarCeil((x_data[k] - leftEdge) / delta);
      guard1 = false;
      if ((bGuess >= 1.0) && (bGuess < 1025.0)) {
        low_ip1 = (int32_T)bGuess;
        if ((x_data[k] >= varargin_1[low_ip1 - 1]) &&
            (x_data[k] < varargin_1[low_ip1])) {
          b_n[low_ip1 - 1]++;
          bin_data[k] = low_ip1;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        int32_T high_i;
        low_i = 1;
        low_ip1 = 2;
        high_i = 1025;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i + high_i) >> 1;
          if (x_data[k] >= varargin_1[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }
        b_n[low_i - 1]++;
        bin_data[k] = low_i;
      }
    }
  }
  low_ip1 = bin->size[0];
  bin->size[0] = b_bin->size[0];
  emxEnsureCapacity_real_T(sp, bin, low_ip1, &of_emlrtRTEI);
  b_bin_data = bin->data;
  low_i = b_bin->size[0];
  for (low_ip1 = 0; low_ip1 < low_i; low_ip1++) {
    b_bin_data[low_ip1] = bin_data[low_ip1];
  }
  emxFree_int32_T(sp, &b_bin);
  for (low_ip1 = 0; low_ip1 < 1024; low_ip1++) {
    n[low_ip1] = b_n[low_ip1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

void histcounts(const emlrtStack *sp, const emxArray_real_T *x,
                const real_T varargin_1_data[], real_T n_data[],
                int32_T n_size[2], emxArray_real_T *bin)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_int32_T *b_bin;
  const real_T *x_data;
  real_T delta;
  real_T leftEdge;
  real_T *b_bin_data;
  int32_T b_n_data[16];
  int32_T k;
  int32_T low_i;
  int32_T low_ip1;
  int32_T nx;
  int32_T *bin_data;
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
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  st.site = &ge_emlrtRSI;
  b_st.site = &ie_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 16)) {
    if (!(varargin_1_data[k] <= varargin_1_data[k + 1])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &jb_emlrtRTEI,
        "Coder:toolbox:ValidateattributesexpectedNonDecreasing",
        "MATLAB:histcounts:expectedNonDecreasing", 3, 4, 22,
        "input number 2, edges,");
  }
  st.site = &he_emlrtRSI;
  b_st.site = &je_emlrtRSI;
  memset(&b_n_data[0], 0, 16U * sizeof(int32_T));
  emxInit_int32_T(&b_st, &b_bin, 1, &pf_emlrtRTEI);
  low_ip1 = b_bin->size[0];
  b_bin->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(&b_st, b_bin, low_ip1, &nf_emlrtRTEI);
  bin_data = b_bin->data;
  low_i = x->size[0];
  for (low_ip1 = 0; low_ip1 < low_i; low_ip1++) {
    bin_data[low_ip1] = 0;
  }
  nx = x->size[0];
  leftEdge = varargin_1_data[0];
  delta = varargin_1_data[1] - varargin_1_data[0];
  c_st.site = &ke_emlrtRSI;
  if (x->size[0] > 2147483646) {
    d_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    if ((x_data[k] >= leftEdge) && (x_data[k] <= varargin_1_data[16])) {
      real_T bGuess;
      boolean_T guard1;
      bGuess = muDoubleScalarCeil((x_data[k] - leftEdge) / delta);
      guard1 = false;
      if ((bGuess >= 1.0) && (bGuess < 17.0)) {
        low_ip1 = (int32_T)bGuess;
        if ((x_data[k] >= varargin_1_data[low_ip1 - 1]) &&
            (x_data[k] < varargin_1_data[low_ip1])) {
          b_n_data[low_ip1 - 1]++;
          bin_data[k] = low_ip1;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      if (guard1) {
        int32_T high_i;
        low_i = 1;
        low_ip1 = 2;
        high_i = 17;
        while (high_i > low_ip1) {
          int32_T mid_i;
          mid_i = (low_i >> 1) + (high_i >> 1);
          if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
            mid_i++;
          }
          if (x_data[k] >= varargin_1_data[mid_i - 1]) {
            low_i = mid_i;
            low_ip1 = mid_i + 1;
          } else {
            high_i = mid_i;
          }
        }
        b_n_data[low_i - 1]++;
        bin_data[k] = low_i;
      }
    }
  }
  low_ip1 = bin->size[0];
  bin->size[0] = b_bin->size[0];
  emxEnsureCapacity_real_T(sp, bin, low_ip1, &of_emlrtRTEI);
  b_bin_data = bin->data;
  low_i = b_bin->size[0];
  for (low_ip1 = 0; low_ip1 < low_i; low_ip1++) {
    b_bin_data[low_ip1] = bin_data[low_ip1];
  }
  emxFree_int32_T(sp, &b_bin);
  n_size[0] = 1;
  n_size[1] = 16;
  for (low_ip1 = 0; low_ip1 < 16; low_ip1++) {
    n_data[low_ip1] = b_n_data[low_ip1];
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (histcounts.c) */
