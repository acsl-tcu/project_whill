/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.c
 *
 * Code generation for function 'xgemv'
 *
 */

/* Include files */
#include "xgemv.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_mexutil.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo xm_emlrtRSI =
    {
        51,      /* lineNo */
        "xgemv", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xgemv.m" /* pathName */
};

/* Function Definitions */
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[54],
             int32_T ia0, const real_T x[54], int32_T ix0, real_T y[6])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vm_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n != 0) {
    int32_T i;
    b_st.site = &ym_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)n;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    i = ia0 + 9 * (n - 1);
    for (iac = ia0; iac <= i; iac += 9) {
      real_T c;
      int32_T b;
      c = 0.0;
      b = (iac + m) - 1;
      b_st.site = &fn_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
      }
      b = div_nde_s32_floor(iac - ia0, 9);
      y[b] += c;
    }
  }
}

void c_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[27],
             int32_T ia0, const real_T x[27], int32_T ix0, real_T y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vm_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (n != 0) {
    int32_T i;
    b_st.site = &ym_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)n;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    i = ia0 + 9 * (n - 1);
    for (iac = ia0; iac <= i; iac += 9) {
      real_T c;
      int32_T b;
      c = 0.0;
      b = (iac + m) - 1;
      b_st.site = &fn_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        c += A[ia - 1] * x[((ix0 + ia) - iac) - 1];
      }
      b = div_nde_s32_floor(iac - ia0, 9);
      y[b] += c;
    }
  }
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
           int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vm_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    int32_T b;
    int32_T i;
    int32_T ix;
    b_st.site = &ym_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)m;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    ix = ix0;
    b = ia0 + 3 * (n - 1);
    b_st.site = &xm_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483644)) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = ia0; iac <= b; iac += 3) {
      int32_T b_b;
      b_b = (iac + m) - 1;
      b_st.site = &wm_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b_b; ia++) {
        i = ia - iac;
        y[i] += A[ia - 1] * x[ix - 1];
      }
      ix++;
    }
  }
}

/* End of code generation (xgemv.c) */
