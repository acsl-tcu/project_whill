/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * all.c
 *
 * Code generation for function 'all'
 *
 */

/* Include files */
#include "all.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo mib_emlrtRSI = {
    139,        /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    18,                               /* lineNo */
    27,                               /* colNo */
    "eml_int_forloop_overflow_check", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/eml/"
    "eml_int_forloop_overflow_check.m" /* pName */
};

static emlrtRTEInfo ml_emlrtRTEI = {
    16,                                                         /* lineNo */
    5,                                                          /* colNo */
    "all",                                                      /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/all.m" /* pName */
};

/* Function Definitions */
boolean_T all(const boolean_T x_data[], const int32_T x_size[2])
{
  int32_T ix;
  boolean_T exitg1;
  boolean_T y;
  y = true;
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x_size[1])) {
    if (!x_data[ix - 1]) {
      y = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

boolean_T b_all(const emlrtStack *sp, const emxArray_boolean_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ix;
  const boolean_T *x_data;
  boolean_T exitg1;
  boolean_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &ol_emlrtRSI;
  y = true;
  b_st.site = &pl_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  ix = 1;
  exitg1 = false;
  while ((!exitg1) && (ix <= x->size[0])) {
    if (!x_data[ix - 1]) {
      y = false;
      exitg1 = true;
    } else {
      ix++;
    }
  }
  return y;
}

void c_all(const emlrtStack *sp, const emxArray_boolean_T *x,
           emxArray_boolean_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i1;
  int32_T i2;
  int32_T j;
  int32_T vstride;
  const boolean_T *x_data;
  boolean_T *y_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &lib_emlrtRSI;
  i2 = y->size[0];
  y->size[0] = x->size[0];
  emxEnsureCapacity_boolean_T(&st, y, i2, &ml_emlrtRTEI);
  y_data = y->data;
  vstride = x->size[0];
  for (i2 = 0; i2 < vstride; i2++) {
    y_data[i2] = true;
  }
  vstride = x->size[0];
  i2 = (x->size[1] - 1) * x->size[0];
  i1 = 0;
  b_st.site = &mib_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (j = 0; j < vstride; j++) {
    int32_T ix;
    boolean_T exitg1;
    boolean_T overflow;
    i1++;
    i2++;
    b_st.site = &pl_emlrtRSI;
    if ((vstride == 0) || (i1 > i2)) {
      overflow = false;
    } else {
      overflow = (i2 > MAX_int32_T - vstride);
    }
    if (vstride == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &wc_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    ix = i1;
    exitg1 = false;
    while ((!exitg1) && (ix <= i2)) {
      if (!x_data[ix - 1]) {
        y_data[j] = false;
        exitg1 = true;
      } else {
        ix += vstride;
      }
    }
  }
}

void d_all(boolean_T y[3])
{
  y[0] = false;
  y[1] = false;
  y[2] = false;
}

/* End of code generation (all.c) */
