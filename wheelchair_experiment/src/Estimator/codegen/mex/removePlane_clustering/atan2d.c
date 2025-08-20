/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atan2d.c
 *
 * Code generation for function 'atan2d'
 *
 */

/* Include files */
#include "atan2d.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo vd_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\ixfun.m" /* pathName
                                                                            */
};

static emlrtRSInfo wd_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    19,             /* lineNo */
    "scalexpAlloc", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpAlloc."
    "m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    216,        /* lineNo */
    "flatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRTEInfo q_emlrtRTEI = {
    14,             /* lineNo */
    15,             /* colNo */
    "scalexpCheck", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\scalexpCheck."
    "m" /* pName */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    129,                         /* lineNo */
    6,                           /* colNo */
    "applyBinaryScalarFunction", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyBinaryScalarFunction.m" /* pName */
};

/* Function Definitions */
void b_atan2d(const emlrtStack *sp, const emxArray_real_T *y,
              const emxArray_real_T *x, emxArray_real_T *r)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  const real_T *x_data;
  const real_T *y_data;
  real_T *r_data;
  int32_T k;
  int32_T z_size_idx_0_tmp;
  boolean_T p;
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
  x_data = x->data;
  y_data = y->data;
  st.site = &sd_emlrtRSI;
  b_st.site = &vd_emlrtRSI;
  c_st.site = &wd_emlrtRSI;
  z_size_idx_0_tmp = muIntScalarMin_sint32(y->size[0], x->size[0]);
  d_st.site = &yd_emlrtRSI;
  p = true;
  if (z_size_idx_0_tmp == y->size[0]) {
    if (z_size_idx_0_tmp != x->size[0]) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &q_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &xd_emlrtRSI;
  k = r->size[0];
  r->size[0] = z_size_idx_0_tmp;
  emxEnsureCapacity_real_T(&c_st, r, k, &oc_emlrtRTEI);
  r_data = r->data;
  d_st.site = &ae_emlrtRSI;
  if (z_size_idx_0_tmp > 2147483646) {
    e_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < z_size_idx_0_tmp; k++) {
    r_data[k] = 57.295779513082323 * muDoubleScalarAtan2(y_data[k], x_data[k]);
  }
}

/* End of code generation (atan2d.c) */
