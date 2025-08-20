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
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void b_xgemv(const emlrtStack *sp, int32_T m, const real_T A[16],
             const real_T x[8], real_T y[120])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &vf_emlrtRSI;
  y[0] = -y[0];
  y[1] = -y[1];
  b_st.site = &tc_emlrtRSI;
  for (iac = 0; iac <= 8; iac += 8) {
    real_T c;
    int32_T b;
    c = 0.0;
    b = iac + m;
    b_st.site = &uc_emlrtRSI;
    if ((iac + 1 <= b) && (b > 2147483646)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (ia = iac + 1; ia <= b; ia++) {
      c += A[ia - 1] * x[(ia - iac) - 1];
    }
    b = iac >> 3;
    y[b] += c;
  }
}

void c_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[225],
             int32_T ia0, const real_T x[120], real_T y[8])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (m != 0) {
    int32_T b;
    int32_T ix;
    b_st.site = &ce_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    memset(&y[0], 0, (uint32_T)m * sizeof(real_T));
    ix = 0;
    b = ia0 + 15 * (n - 1);
    b_st.site = &hd_emlrtRSI;
    if ((ia0 <= b) && (b > 2147483632)) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = ia0; iac <= b; iac += 15) {
      int32_T b_b;
      b_b = (iac + m) - 1;
      b_st.site = &gd_emlrtRSI;
      if ((iac <= b_b) && (b_b > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b_b; ia++) {
        int32_T i;
        i = ia - iac;
        y[i] += A[ia - 1] * x[ix];
      }
      ix++;
    }
  }
}

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[25],
           int32_T lda, const real_T x[8], real_T y[7])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T ia;
  int32_T iac;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &sc_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if ((m != 0) && (n != 0)) {
    int32_T b_tmp;
    int32_T i;
    int32_T ix;
    boolean_T overflow;
    b_st.site = &ce_emlrtRSI;
    if (m > 2147483646) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    i = (uint8_T)m;
    memset(&y[0], 0, (uint32_T)i * sizeof(real_T));
    ix = 0;
    b_tmp = lda * (n - 1) + 1;
    b_st.site = &hd_emlrtRSI;
    if ((lda == 0) || (b_tmp < 1)) {
      overflow = false;
    } else {
      overflow = (b_tmp > MAX_int32_T - lda);
    }
    if (lda == 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &w_emlrtRTEI,
                                    "Coder:builtins:VectorStride",
                                    "Coder:builtins:VectorStride", 0);
    }
    if (overflow) {
      c_st.site = &o_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (iac = 1; lda < 0 ? iac >= b_tmp : iac <= b_tmp; iac += lda) {
      int32_T b;
      b = (iac + m) - 1;
      b_st.site = &gd_emlrtRSI;
      if ((iac <= b) && (b > 2147483646)) {
        c_st.site = &o_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (ia = iac; ia <= b; ia++) {
        i = ia - iac;
        y[i] += A[ia - 1] * x[ix];
      }
      ix++;
    }
  }
}

/* End of code generation (xgemv.c) */
