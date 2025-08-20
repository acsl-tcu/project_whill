/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xnrm2.c
 *
 * Code generation for function 'xnrm2'
 *
 */

/* Include files */
#include "xnrm2.h"
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI =
    {
        23,      /* lineNo */
        "xnrm2", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xnrm2.m" /* pathName */
};

static emlrtRSInfo fg_emlrtRSI =
    {
        38,      /* lineNo */
        "xnrm2", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xnrm2.m" /* pathName */
};

/* Function Definitions */
real_T b_xnrm2(const real_T x[3])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(x[1]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = muDoubleScalarAbs(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  return scale * muDoubleScalarSqrt(y);
}

real_T c_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[8])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T y;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = muDoubleScalarAbs(x[0]);
    } else {
      real_T scale;
      scale = 3.3121686421112381E-170;
      b_st.site = &fg_emlrtRSI;
      if (n > 2147483646) {
        c_st.site = &u_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 0; k < n; k++) {
        real_T absxk;
        absxk = muDoubleScalarAbs(x[k]);
        if (absxk > scale) {
          real_T t;
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          real_T t;
          t = absxk / scale;
          y += t * t;
        }
      }
      y = scale * muDoubleScalarSqrt(y);
    }
  }
  return y;
}

real_T xnrm2(const real_T x[6])
{
  real_T absxk;
  real_T scale;
  real_T t;
  real_T y;
  scale = 3.3121686421112381E-170;
  absxk = muDoubleScalarAbs(x[0]);
  if (absxk > 3.3121686421112381E-170) {
    y = 1.0;
    scale = absxk;
  } else {
    t = absxk / 3.3121686421112381E-170;
    y = t * t;
  }
  absxk = muDoubleScalarAbs(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }
  return scale * muDoubleScalarSqrt(y);
}

/* End of code generation (xnrm2.c) */
