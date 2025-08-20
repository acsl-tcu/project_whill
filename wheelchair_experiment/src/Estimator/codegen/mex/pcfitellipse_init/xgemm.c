/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemm.c
 *
 * Code generation for function 'xgemm'
 *
 */

/* Include files */
#include "xgemm.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_init_data.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include <emmintrin.h>
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo sg_emlrtRSI = {
    63,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgemm."
    "m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    64,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    65,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    85,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    87,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    90,      /* lineNo */
    "xgemm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xgemm.m" /* pathName */
};

/* Function Definitions */
void b_xgemm(int32_T m, int32_T n, int32_T k, const real_T A[169], int32_T ia0,
             const real_T B[91], real_T C[169])
{
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  real_T alpha1;
  real_T beta1;
  char_T TRANSA1;
  char_T TRANSB1;
  if ((m >= 1) && (n >= 1) && (k >= 1)) {
    alpha1 = 1.0;
    beta1 = 0.0;
    TRANSB1 = 'N';
    TRANSA1 = 'T';
    m_t = (ptrdiff_t)m;
    n_t = (ptrdiff_t)n;
    k_t = (ptrdiff_t)k;
    lda_t = (ptrdiff_t)13;
    ldb_t = (ptrdiff_t)13;
    ldc_t = (ptrdiff_t)13;
    dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[ia0 - 1],
          &lda_t, (real_T *)&B[0], &ldb_t, &beta1, &C[0], &ldc_t);
  }
}

void xgemm(const emlrtStack *sp, int32_T m, int32_T n, int32_T k,
           const real_T A[25], int32_T lda, const real_T B[169], int32_T ib0,
           real_T C[91])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T cr;
  int32_T ib;
  int32_T ic;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    int32_T a;
    int32_T b;
    int32_T br;
    int32_T lastColC;
    br = ib0;
    lastColC = 13 * (n - 1);
    b_st.site = &tg_emlrtRSI;
    if (lastColC > 2147483634) {
      c_st.site = &hb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (cr = 0; cr <= lastColC; cr += 13) {
      a = cr + 1;
      b = cr + m;
      b_st.site = &ug_emlrtRSI;
      if ((cr + 1 <= b) && (b > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      if (a <= b) {
        memset(&C[a + -1], 0, (uint32_T)((b - a) + 1) * sizeof(real_T));
      }
    }
    b_st.site = &vg_emlrtRSI;
    for (cr = 0; cr <= lastColC; cr += 13) {
      int32_T ar;
      ar = -1;
      b = (br + k) - 1;
      b_st.site = &wg_emlrtRSI;
      if ((br <= b) && (b > 2147483646)) {
        c_st.site = &hb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ib = br; ib <= b; ib++) {
        int32_T b_b;
        int32_T scalarLB;
        int32_T vectorUB;
        a = cr + 1;
        b_b = cr + m;
        b_st.site = &xg_emlrtRSI;
        if ((cr + 1 <= b_b) && (b_b > 2147483646)) {
          c_st.site = &hb_emlrtRSI;
          check_forloop_overflow_error(&c_st);
        }
        scalarLB = ((b_b - a) + 1) / 2 * 2 + a;
        vectorUB = scalarLB - 2;
        for (ic = a; ic <= vectorUB; ic += 2) {
          __m128d r;
          __m128d r1;
          r = _mm_loadu_pd(&A[(ar + ic) - cr]);
          r = _mm_mul_pd(_mm_set1_pd(B[ib - 1]), r);
          r1 = _mm_loadu_pd(&C[ic - 1]);
          r = _mm_add_pd(r1, r);
          _mm_storeu_pd(&C[ic - 1], r);
        }
        for (ic = scalarLB; ic <= b_b; ic++) {
          C[ic - 1] += B[ib - 1] * A[(ar + ic) - cr];
        }
        ar += lda;
      }
      br += 13;
    }
  }
}

/* End of code generation (xgemm.c) */
