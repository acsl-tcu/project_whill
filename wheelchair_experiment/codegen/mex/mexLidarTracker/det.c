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
#include "eml_int_forloop_overflow_check.h"
#include "ixamax.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo de_emlrtRSI = {
    21,                                                            /* lineNo */
    "det",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/det.m" /* pathName
                                                                    */
};

static emlrtRSInfo ee_emlrtRSI =
    {
        31,       /* lineNo */
        "xgetrf", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" /* pathName */
};

static emlrtRSInfo fe_emlrtRSI = {
    36,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo ge_emlrtRSI = {
    50,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    58,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo ke_emlrtRSI =
    {
        45,      /* lineNo */
        "xgeru", /* fcnName */
        "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgeru.m" /* pathName */
};

/* Function Definitions */
real_T b_det(const emlrtStack *sp, const real_T x[16])
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
  int32_T ijA;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  int8_T ipiv[4];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &de_emlrtRSI;
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
  b_st.site = &ee_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    real_T smax;
    int32_T b_tmp;
    int32_T jA;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    jA = 4 - j;
    c_st.site = &fe_emlrtRSI;
    d_st.site = &ie_emlrtRSI;
    a = 0;
    smax = muDoubleScalarAbs(b_x[b_tmp]);
    e_st.site = &je_emlrtRSI;
    for (k = 2; k <= jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = (int8_T)(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 4];
        b_x[j + 4] = b_x[jA + 4];
        b_x[jA + 4] = smax;
        smax = b_x[j + 8];
        b_x[j + 8] = b_x[jA + 8];
        b_x[jA + 8] = smax;
        smax = b_x[j + 12];
        b_x[j + 12] = b_x[jA + 12];
        b_x[jA + 12] = smax;
      }
      k = (b_tmp - j) + 4;
      c_st.site = &ge_emlrtRSI;
      for (a = jp1j; a <= k; a++) {
        b_x[a - 1] /= b_x[b_tmp];
      }
    }
    k = 2 - j;
    c_st.site = &he_emlrtRSI;
    d_st.site = &ke_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    f_st.site = &me_emlrtRSI;
    jA = b_tmp + 6;
    g_st.site = &oe_emlrtRSI;
    for (jp1j = 0; jp1j <= k; jp1j++) {
      smax = b_x[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0) {
        a = (jA - j) + 2;
        g_st.site = &ne_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          h_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (ijA = jA; ijA <= a; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -smax;
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

real32_T c_det(const emlrtStack *sp, const real32_T x[16])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  int32_T a;
  int32_T ijA;
  int32_T j;
  int32_T jp1j;
  int32_T k;
  real32_T b_x[16];
  real32_T y;
  int8_T ipiv[4];
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &de_emlrtRSI;
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
  memcpy(&b_x[0], &x[0], 16U * sizeof(real32_T));
  b_st.site = &ee_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  for (j = 0; j < 3; j++) {
    int32_T b_tmp;
    int32_T jA;
    real32_T smax;
    b_tmp = j * 5;
    jp1j = b_tmp + 2;
    jA = 4 - j;
    c_st.site = &fe_emlrtRSI;
    d_st.site = &ie_emlrtRSI;
    a = 0;
    smax = muSingleScalarAbs(b_x[b_tmp]);
    e_st.site = &je_emlrtRSI;
    for (k = 2; k <= jA; k++) {
      real32_T s;
      s = muSingleScalarAbs(b_x[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_x[b_tmp + a] != 0.0F) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = (int8_T)(jA + 1);
        smax = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = smax;
        smax = b_x[j + 4];
        b_x[j + 4] = b_x[jA + 4];
        b_x[jA + 4] = smax;
        smax = b_x[j + 8];
        b_x[j + 8] = b_x[jA + 8];
        b_x[jA + 8] = smax;
        smax = b_x[j + 12];
        b_x[j + 12] = b_x[jA + 12];
        b_x[jA + 12] = smax;
      }
      k = (b_tmp - j) + 4;
      c_st.site = &ge_emlrtRSI;
      for (a = jp1j; a <= k; a++) {
        b_x[a - 1] /= b_x[b_tmp];
      }
    }
    k = 2 - j;
    c_st.site = &he_emlrtRSI;
    d_st.site = &ke_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    f_st.site = &me_emlrtRSI;
    jA = b_tmp + 6;
    g_st.site = &oe_emlrtRSI;
    for (jp1j = 0; jp1j <= k; jp1j++) {
      smax = b_x[(b_tmp + (jp1j << 2)) + 4];
      if (smax != 0.0F) {
        a = (jA - j) + 2;
        g_st.site = &ne_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          h_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (ijA = jA; ijA <= a; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -smax;
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

real_T det(const emlrtStack *sp, const real_T x[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  real_T b_x[9];
  real_T y;
  int32_T ipiv[3];
  int32_T b_j;
  int32_T ijA;
  int32_T j;
  int32_T jA;
  boolean_T isodd;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &de_emlrtRSI;
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
  memcpy(&b_x[0], &x[0], 9U * sizeof(real_T));
  b_st.site = &ee_emlrtRSI;
  ipiv[0] = 1;
  ipiv[1] = 2;
  for (j = 0; j < 2; j++) {
    real_T temp;
    int32_T b_tmp;
    int32_T i;
    int32_T jp1j;
    b_tmp = j << 2;
    jp1j = b_tmp + 2;
    c_st.site = &fe_emlrtRSI;
    jA = ixamax(&c_st, 3 - j, b_x, b_tmp + 1) - 1;
    if (b_x[b_tmp + jA] != 0.0) {
      if (jA != 0) {
        jA += j;
        ipiv[j] = jA + 1;
        temp = b_x[j];
        b_x[j] = b_x[jA];
        b_x[jA] = temp;
        temp = b_x[j + 3];
        b_x[j + 3] = b_x[jA + 3];
        b_x[jA + 3] = temp;
        temp = b_x[j + 6];
        b_x[j + 6] = b_x[jA + 6];
        b_x[jA + 6] = temp;
      }
      i = (b_tmp - j) + 3;
      c_st.site = &ge_emlrtRSI;
      for (jA = jp1j; jA <= i; jA++) {
        b_x[jA - 1] /= b_x[b_tmp];
      }
    }
    i = 1 - j;
    c_st.site = &he_emlrtRSI;
    d_st.site = &ke_emlrtRSI;
    e_st.site = &le_emlrtRSI;
    f_st.site = &me_emlrtRSI;
    jA = b_tmp + 5;
    g_st.site = &oe_emlrtRSI;
    for (b_j = 0; b_j <= i; b_j++) {
      temp = b_x[(b_tmp + b_j * 3) + 3];
      if (temp != 0.0) {
        jp1j = (jA - j) + 1;
        g_st.site = &ne_emlrtRSI;
        if ((jA <= jp1j) && (jp1j > 2147483646)) {
          h_st.site = &mb_emlrtRSI;
          check_forloop_overflow_error(&h_st);
        }
        for (ijA = jA; ijA <= jp1j; ijA++) {
          b_x[ijA - 1] += b_x[((b_tmp + ijA) - jA) + 1] * -temp;
        }
      }
      jA += 3;
    }
  }
  isodd = (ipiv[0] > 1);
  y = b_x[0] * b_x[4] * b_x[8];
  if (ipiv[1] > 2) {
    isodd = !isodd;
  }
  if (isodd) {
    y = -y;
  }
  return y;
}

/* End of code generation (det.c) */
