/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * atan2.c
 *
 * Code generation for function 'atan2'
 *
 */

/* Include files */
#include "atan2.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "ixfun.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo sd_emlrtRSI = {
    13,      /* lineNo */
    "atan2", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/atan2.m" /* pathName
                                                                     */
};

static emlrtRSInfo td_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

static emlrtRSInfo ud_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI =
    {
        19,             /* lineNo */
        "scalexpAlloc", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "scalexpAlloc.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    221,        /* lineNo */
    "flatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRTEInfo j_emlrtRTEI =
    {
        14,             /* lineNo */
        15,             /* colNo */
        "scalexpCheck", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "scalexpCheck.m" /* pName */
};

static emlrtRTEInfo th_emlrtRTEI = {
    129,                         /* lineNo */
    6,                           /* colNo */
    "applyBinaryScalarFunction", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pName */
};

static emlrtRTEInfo vh_emlrtRTEI = {
    13,                                                             /* lineNo */
    1,                                                              /* colNo */
    "atan2",                                                        /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/atan2.m" /* pName */
};

/* Function Definitions */
void b_atan2(const emlrtStack *sp, const emxArray_real_T *y,
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
  int32_T csz_idx_2_tmp;
  int32_T csz_idx_3_tmp;
  int32_T i;
  boolean_T b_p;
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
  b_st.site = &td_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  csz_idx_2_tmp = muIntScalarMin_sint32(y->size[2], x->size[2]);
  csz_idx_3_tmp = muIntScalarMin_sint32(y->size[3], x->size[3]);
  d_st.site = &wd_emlrtRSI;
  p = true;
  b_p = true;
  if (csz_idx_2_tmp != y->size[2]) {
    b_p = false;
  } else if (csz_idx_3_tmp != y->size[3]) {
    b_p = false;
  }
  if (b_p) {
    b_p = true;
    if (csz_idx_2_tmp != x->size[2]) {
      b_p = false;
    } else if (csz_idx_3_tmp != x->size[3]) {
      b_p = false;
    }
    if (!b_p) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &vd_emlrtRSI;
  i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
  r->size[0] = 1;
  r->size[1] = 1;
  r->size[2] = csz_idx_2_tmp;
  r->size[3] = csz_idx_3_tmp;
  emxEnsureCapacity_real_T(&c_st, r, i, &th_emlrtRTEI);
  r_data = r->data;
  csz_idx_2_tmp *= csz_idx_3_tmp;
  d_st.site = &xd_emlrtRSI;
  if (csz_idx_2_tmp > 2147483646) {
    e_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (csz_idx_3_tmp = 0; csz_idx_3_tmp < csz_idx_2_tmp; csz_idx_3_tmp++) {
    r_data[csz_idx_3_tmp] =
        muDoubleScalarAtan2(y_data[csz_idx_3_tmp], x_data[csz_idx_3_tmp]);
  }
}

void c_atan2(const emlrtStack *sp, const emxArray_real_T *y,
             const emxArray_real_T *x, emxArray_real_T *r)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  const real_T *y_data;
  real_T *r_data;
  int32_T i;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  y_data = y->data;
  st.site = &sd_emlrtRSI;
  b_st.site = &be_emlrtRSI;
  if ((y->size[0] == x->size[0]) && (y->size[2] == x->size[2]) &&
      (y->size[3] == x->size[3])) {
    int32_T loop_ub_tmp;
    i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
    r->size[0] = y->size[0];
    r->size[1] = 1;
    r->size[2] = y->size[2];
    r->size[3] = y->size[3];
    emxEnsureCapacity_real_T(&b_st, r, i, &vh_emlrtRTEI);
    r_data = r->data;
    loop_ub_tmp = y->size[0] * y->size[2] * y->size[3];
    for (i = 0; i < loop_ub_tmp; i++) {
      real_T varargin_1;
      real_T varargin_2;
      varargin_1 = y_data[i];
      varargin_2 = x_data[i];
      r_data[i] = muDoubleScalarAtan2(varargin_1, varargin_2);
    }
  } else {
    c_st.site = &ce_emlrtRSI;
    expand_atan2(&c_st, y, x, r);
  }
}

void d_atan2(const emlrtStack *sp, const emxArray_real_T *y,
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
  int32_T csz_idx_0_tmp;
  int32_T csz_idx_2_tmp;
  int32_T csz_idx_3_tmp;
  int32_T i;
  boolean_T b_p;
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
  b_st.site = &td_emlrtRSI;
  c_st.site = &ud_emlrtRSI;
  csz_idx_0_tmp = muIntScalarMin_sint32(y->size[0], x->size[0]);
  csz_idx_2_tmp = muIntScalarMin_sint32(y->size[2], x->size[2]);
  csz_idx_3_tmp = muIntScalarMin_sint32(y->size[3], x->size[3]);
  d_st.site = &wd_emlrtRSI;
  p = true;
  b_p = true;
  if (csz_idx_0_tmp != y->size[0]) {
    b_p = false;
  } else if (csz_idx_2_tmp != y->size[2]) {
    b_p = false;
  } else if (csz_idx_3_tmp != y->size[3]) {
    b_p = false;
  }
  if (b_p) {
    b_p = true;
    if (csz_idx_0_tmp != x->size[0]) {
      b_p = false;
    } else if (csz_idx_2_tmp != x->size[2]) {
      b_p = false;
    } else if (csz_idx_3_tmp != x->size[3]) {
      b_p = false;
    }
    if (!b_p) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &j_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &vd_emlrtRSI;
  i = r->size[0] * r->size[1] * r->size[2] * r->size[3];
  r->size[0] = csz_idx_0_tmp;
  r->size[1] = 1;
  r->size[2] = csz_idx_2_tmp;
  r->size[3] = csz_idx_3_tmp;
  emxEnsureCapacity_real_T(&c_st, r, i, &th_emlrtRTEI);
  r_data = r->data;
  csz_idx_0_tmp = csz_idx_0_tmp * csz_idx_2_tmp * csz_idx_3_tmp;
  d_st.site = &xd_emlrtRSI;
  if (csz_idx_0_tmp > 2147483646) {
    e_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (csz_idx_2_tmp = 0; csz_idx_2_tmp < csz_idx_0_tmp; csz_idx_2_tmp++) {
    r_data[csz_idx_2_tmp] =
        muDoubleScalarAtan2(y_data[csz_idx_2_tmp], x_data[csz_idx_2_tmp]);
  }
}

/* End of code generation (atan2.c) */
