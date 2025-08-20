/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xdotc.c
 *
 * Code generation for function 'xdotc'
 *
 */

/* Include files */
#include "xdotc.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo pd_emlrtRSI =
    {
        32,      /* lineNo */
        "xdotc", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xdotc.m" /* pathName */
};

static emlrtRSInfo
    qd_emlrtRSI =
        {
            35,     /* lineNo */
            "xdot", /* fcnName */
            "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
            "xdot.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI =
    {
        15,     /* lineNo */
        "xdot", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xdot.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI =
    {
        42,      /* lineNo */
        "xdotx", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xdotx.m" /* pathName */
};

/* Function Definitions */
real32_T b_xdotc(const emlrtStack *sp, int32_T n, const real32_T x[9],
                 int32_T ix0, const real32_T y[9], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  real32_T d;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d = 0.0F;
  d_st.site = &sd_emlrtRSI;
  if (n > 2147483646) {
    e_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&e_st);
  }
  i = (uint8_T)n;
  for (k = 0; k < i; k++) {
    d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
  }
  return d;
}

real_T c_xdotc(const emlrtStack *sp, int32_T n, const real_T x[36], int32_T ix0,
               const real_T y[36], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    int32_T i;
    d_st.site = &sd_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i = (uint8_T)n;
    for (k = 0; k < i; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

real_T xdotc(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T ix0,
             const real_T y[9], int32_T iy0)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T d;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &pd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &qd_emlrtRSI;
  c_st.site = &rd_emlrtRSI;
  d = 0.0;
  if (n >= 1) {
    int32_T i;
    d_st.site = &sd_emlrtRSI;
    if (n > 2147483646) {
      e_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&e_st);
    }
    i = (uint8_T)n;
    for (k = 0; k < i; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

/* End of code generation (xdotc.c) */
