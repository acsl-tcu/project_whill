/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * norm.c
 *
 * Code generation for function 'norm'
 *
 */

/* Include files */
#include "norm.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo jb_emlrtRSI = {
    119,    /* lineNo */
    "norm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/norm.m" /* pathName
                                                                     */
};

static emlrtRSInfo kb_emlrtRSI = {
    156,        /* lineNo */
    "mat2norm", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/norm.m" /* pathName
                                                                     */
};

static emlrtRSInfo lb_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo mb_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo nb_emlrtRSI =
    {
        34,       /* lineNo */
        "xgesvd", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pathName */
};

/* Function Definitions */
real_T b_norm(const emlrtStack *sp, const real_T x[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T y;
  int32_T i;
  int32_T i1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &jb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  y = 0.0;
  for (i = 0; i < 6; i++) {
    real_T absx;
    absx = muDoubleScalarAbs(x[i]);
    if (muDoubleScalarIsNaN(absx) || (absx > y)) {
      y = absx;
    }
  }
  if ((!muDoubleScalarIsInf(y)) && (!muDoubleScalarIsNaN(y))) {
    real_T b_x[6];
    b_st.site = &kb_emlrtRSI;
    c_st.site = &lb_emlrtRSI;
    d_st.site = &mb_emlrtRSI;
    for (i1 = 0; i1 < 6; i1++) {
      b_x[i1] = x[i1];
    }
    real_T s[2];
    e_st.site = &nb_emlrtRSI;
    xzsvdc(&e_st, b_x, s);
    y = s[0];
  }
  return y;
}

/* End of code generation (norm.c) */
