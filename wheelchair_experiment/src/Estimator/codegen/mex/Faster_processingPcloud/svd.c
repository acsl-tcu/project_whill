/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * svd.c
 *
 * Code generation for function 'svd'
 *
 */

/* Include files */
#include "svd.h"
#include "rt_nonfinite.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = {
    14,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

static emlrtRSInfo ac_emlrtRSI = {
    18,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

static emlrtRSInfo bc_emlrtRSI =
    {
        29,             /* lineNo */
        "anyNonFinite", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
        "anyNonFinite.m" /* pathName */
};

static emlrtRSInfo
    cc_emlrtRSI =
        {
            44,          /* lineNo */
            "vAllOrAny", /* fcnName */
            "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
            "vAllOrAny.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    28,    /* lineNo */
    "svd", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo fc_emlrtRSI = {
    107,          /* lineNo */
    "callLAPACK", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

static emlrtRSInfo gc_emlrtRSI =
    {
        34,       /* lineNo */
        "xgesvd", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgesvd.m" /* pathName */
};

/* Function Definitions */
void svd(const emlrtStack *sp, const real_T A[9], real_T U[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T b_A[9];
  int32_T k;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &bc_emlrtRSI;
  c_st.site = &cc_emlrtRSI;
  p = true;
  for (k = 0; k < 9; k++) {
    if (p) {
      real_T d;
      d = A[k];
      if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
        p = false;
      }
    } else {
      p = false;
    }
  }
  if (p) {
    st.site = &ac_emlrtRSI;
    b_st.site = &ec_emlrtRSI;
    c_st.site = &fc_emlrtRSI;
    memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
    d_st.site = &gc_emlrtRSI;
    xzsvdc(&d_st, b_A, U);
  } else {
    U[0] = rtNaN;
    U[1] = rtNaN;
    U[2] = rtNaN;
  }
}

/* End of code generation (svd.c) */
