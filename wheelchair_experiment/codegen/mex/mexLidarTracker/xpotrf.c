/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xpotrf.c
 *
 * Code generation for function 'xpotrf'
 *
 */

/* Include files */
#include "xpotrf.h"
#include "rt_nonfinite.h"
#include "xdotc.h"
#include "xscal.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>

/* Variable Definitions */
static emlrtRSInfo rr_emlrtRSI =
    {
        16,       /* lineNo */
        "xpotrf", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xpotrf.m" /* pathName */
};

static emlrtRSInfo sr_emlrtRSI = {
    19,        /* lineNo */
    "xzpotrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzpotrf.m" /* pathName */
};

static emlrtRSInfo wr_emlrtRSI = {
    42,        /* lineNo */
    "zpotrfU", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzpotrf.m" /* pathName */
};

static emlrtRSInfo os_emlrtRSI = {
    61,        /* lineNo */
    "zpotrfU", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzpotrf.m" /* pathName */
};

/* Function Definitions */
int32_T b_xpotrf(const emlrtStack *sp, real_T A[9])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T info;
  int32_T j;
  char_T TRANSA;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rr_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sr_emlrtRSI;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 3)) {
    real_T ssq;
    int32_T idxA1j;
    int32_T idxAjj;
    idxA1j = j * 3 + 1;
    idxAjj = (idxA1j + j) - 1;
    c_st.site = &wr_emlrtRSI;
    ssq = xdotc(&c_st, j, A, idxA1j, A, idxA1j);
    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = muDoubleScalarSqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < 3) {
        if (j >= 1) {
          alpha1 = -1.0;
          beta1 = 1.0;
          TRANSA = 'T';
          m_t = (ptrdiff_t)j;
          n_t = (ptrdiff_t)(2 - j);
          lda_t = (ptrdiff_t)3;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)3;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A[idxA1j + 2], &lda_t,
                &A[idxA1j - 1], &incx_t, &beta1, &A[idxAjj + 3], &incy_t);
        }
        c_st.site = &os_emlrtRSI;
        d_xscal(&c_st, 2 - j, 1.0 / ssq, A, idxAjj + 4);
      }
      j++;
    } else {
      A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

int32_T xpotrf(const emlrtStack *sp, real_T A[36])
{
  ptrdiff_t incx_t;
  ptrdiff_t incy_t;
  ptrdiff_t lda_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T alpha1;
  real_T beta1;
  int32_T idxAjj;
  int32_T info;
  int32_T j;
  char_T TRANSA;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &rr_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &sr_emlrtRSI;
  info = 0;
  j = 0;
  exitg1 = false;
  while ((!exitg1) && (j < 6)) {
    real_T ssq;
    int32_T idxA1j;
    idxA1j = j * 6 + 1;
    idxAjj = (idxA1j + j) - 1;
    c_st.site = &wr_emlrtRSI;
    ssq = c_xdotc(&c_st, j, A, idxA1j, A, idxA1j);
    ssq = A[idxAjj] - ssq;
    if (ssq > 0.0) {
      ssq = muDoubleScalarSqrt(ssq);
      A[idxAjj] = ssq;
      if (j + 1 < 6) {
        int32_T idxAjjp1;
        idxAjjp1 = idxAjj + 7;
        if (j >= 1) {
          alpha1 = -1.0;
          beta1 = 1.0;
          TRANSA = 'T';
          m_t = (ptrdiff_t)j;
          n_t = (ptrdiff_t)(5 - j);
          lda_t = (ptrdiff_t)6;
          incx_t = (ptrdiff_t)1;
          incy_t = (ptrdiff_t)6;
          dgemv(&TRANSA, &m_t, &n_t, &alpha1, &A[idxA1j + 5], &lda_t,
                &A[idxA1j - 1], &incx_t, &beta1, &A[idxAjj + 6], &incy_t);
        }
        ssq = 1.0 / ssq;
        idxA1j = (idxAjj + 6 * (4 - j)) + 7;
        for (idxAjj = idxAjjp1; idxAjj <= idxA1j; idxAjj += 6) {
          A[idxAjj - 1] *= ssq;
        }
      }
      j++;
    } else {
      A[idxAjj] = ssq;
      info = j + 1;
      exitg1 = true;
    }
  }
  return info;
}

/* End of code generation (xpotrf.c) */
