/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * hypot.c
 *
 * Code generation for function 'hypot'
 *
 */

/* Include files */
#include "hypot.h"
#include "calc_observation_data.h"
#include "calc_observation_emxutil.h"
#include "calc_observation_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hc_emlrtRSI = {
    14,      /* lineNo */
    "hypot", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/hypot.m" /* pathName
                                                                     */
};

static emlrtRSInfo ic_emlrtRSI = {
    66,      /* lineNo */
    "ixfun", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/ixfun.m" /* pathName
                                                                         */
};

static emlrtRSInfo jc_emlrtRSI = {
    45,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    66,                          /* lineNo */
    "applyBinaryScalarFunction", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI =
    {
        19,             /* lineNo */
        "scalexpAlloc", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "scalexpAlloc.m" /* pathName */
};

static emlrtRSInfo mc_emlrtRSI = {
    221,        /* lineNo */
    "flatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pathName */
};

static emlrtRTEInfo g_emlrtRTEI =
    {
        14,             /* lineNo */
        15,             /* colNo */
        "scalexpCheck", /* fName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "scalexpCheck.m" /* pName */
};

static emlrtRTEInfo ac_emlrtRTEI = {
    129,                         /* lineNo */
    6,                           /* colNo */
    "applyBinaryScalarFunction", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyBinaryScalarFunction.m" /* pName */
};

/* Function Definitions */
void b_hypot(const emlrtStack *sp, const emxArray_real_T *x,
             const emxArray_real_T *y, emxArray_real_T *r)
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
  int32_T k;
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
  y_data = y->data;
  x_data = x->data;
  st.site = &hc_emlrtRSI;
  b_st.site = &ic_emlrtRSI;
  c_st.site = &jc_emlrtRSI;
  csz_idx_0_tmp = muIntScalarMin_sint32(x->size[0], y->size[0]);
  d_st.site = &lc_emlrtRSI;
  p = true;
  if (csz_idx_0_tmp == x->size[0]) {
    if (csz_idx_0_tmp != y->size[0]) {
      p = false;
    }
  } else {
    p = false;
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(&d_st, &g_emlrtRTEI, "MATLAB:dimagree",
                                  "MATLAB:dimagree", 0);
  }
  c_st.site = &kc_emlrtRSI;
  k = r->size[0];
  r->size[0] = csz_idx_0_tmp;
  emxEnsureCapacity_real_T(&c_st, r, k, &ac_emlrtRTEI);
  r_data = r->data;
  d_st.site = &mc_emlrtRSI;
  if (csz_idx_0_tmp > 2147483646) {
    e_st.site = &u_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  for (k = 0; k < csz_idx_0_tmp; k++) {
    r_data[k] = muDoubleScalarHypot(x_data[k], y_data[k]);
  }
}

/* End of code generation (hypot.c) */
