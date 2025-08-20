/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * det.c
 *
 * Code generation for function 'det'
 *
 */

/* Include files */
#include "det.h"
#include "Faster_processingPcloud_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Function Definitions */
real_T det(const emlrtStack *sp, const real_T x[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_x[16];
  real_T y;
  int32_T a;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  int8_T ipiv[4];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gd_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  memcpy(&b_x[0], &x[0], 16U * sizeof(real_T));
  b_st.site = &hd_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    int32_T b_tmp;
    int32_T jA;
    int32_T mmj_tmp;
    mmj_tmp = 2 - j;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    jA = 5 - j;
    a = 0;
    y = muDoubleScalarAbs(b_x[b_tmp]);
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > y) {
        a = k - 1;
        y = s;
      }
    }
    if (b_x[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = (int8_T)(jA + 1);
        y = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = y;
        y = b_x[j + 4];
        b_x[j + 4] = b_x[jA + 4];
        b_x[jA + 4] = y;
        y = b_x[j + 8];
        b_x[j + 8] = b_x[jA + 8];
        b_x[jA + 8] = y;
        y = b_x[j + 12];
        b_x[j + 12] = b_x[jA + 12];
        b_x[jA + 12] = y;
      }
      jA = (b_tmp - j) + 4;
      c_st.site = &id_emlrtRSI;
      for (a = jp1j; a <= jA; a++) {
        b_x[a - 1] /= b_x[b_tmp];
      }
    }
    c_st.site = &jd_emlrtRSI;
    d_st.site = &kd_emlrtRSI;
    e_st.site = &ld_emlrtRSI;
    f_st.site = &md_emlrtRSI;
    jA = b_tmp + 6;
    g_st.site = &nd_emlrtRSI;
    for (jp1j = 0; jp1j <= mmj_tmp; jp1j++) {
      y = b_x[(b_tmp + (jp1j << 2)) + 4];
      if (y != 0.0) {
        a = (jA - j) + 2;
        g_st.site = &od_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          h_st.site = &ab_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (k = jA; k <= a; k++) {
          b_x[k - 1] += b_x[((b_tmp + k) - jA) + 1] * -y;
        }
      }
      jA += 4;
    }
  }
  isodd = (ipiv[0] > 1);
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  y = b_x[0] * b_x[5] * b_x[10] * b_x[15];
  if (ipiv[2] > 3) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

/* End of code generation (det.c) */
