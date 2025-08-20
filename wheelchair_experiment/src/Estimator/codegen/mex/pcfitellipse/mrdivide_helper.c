/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mrdivide_helper.c
 *
 * Code generation for function 'mrdivide_helper'
 *
 */

/* Include files */
#include "mrdivide_helper.h"
#include "eml_int_forloop_overflow_check.h"
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ri_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\mrdivide_"
    "helper.m" /* pathName */
};

static emlrtRSInfo
    si_emlrtRSI =
        {
            67,        /* lineNo */
            "lusolve", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    ti_emlrtRSI =
        {
            107,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    ui_emlrtRSI =
        {
            112,          /* lineNo */
            "lusolveNxN", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    vi_emlrtRSI =
        {
            135,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    wi_emlrtRSI =
        {
            140,          /* lineNo */
            "XtimesInvA", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo xi_emlrtRSI = {
    31,       /* lineNo */
    "xgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "lapack\\xgetrf.m" /* pathName */
};

static emlrtRSInfo yi_emlrtRSI = {
    36,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo aj_emlrtRSI = {
    50,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo bj_emlrtRSI = {
    58,        /* lineNo */
    "xzgetrf", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "reflapack\\xzgetrf.m" /* pathName */
};

static emlrtRSInfo cj_emlrtRSI = {
    45,      /* lineNo */
    "xgeru", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xgeru."
    "m" /* pathName */
};

static emlrtRSInfo dj_emlrtRSI = {
    59,      /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+blas\\xtrsm."
    "m" /* pathName */
};

static emlrtRSInfo ej_emlrtRSI = {
    143,     /* lineNo */
    "xtrsm", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "refblas\\xtrsm.m" /* pathName */
};

static emlrtRSInfo
    fj_emlrtRSI =
        {
            90,              /* lineNo */
            "warn_singular", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2023a\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

/* Function Definitions */
void mrdiv(const emlrtStack *sp, real_T A[5], const real_T B[25])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack j_st;
  emlrtStack k_st;
  emlrtStack st;
  real_T b_A[25];
  real_T smax;
  int32_T A_tmp;
  int32_T a;
  int32_T i;
  int32_T info;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int8_T ipiv[5];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ri_emlrtRSI;
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
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  j_st.prev = &i_st;
  j_st.tls = i_st.tls;
  k_st.prev = &j_st;
  k_st.tls = j_st.tls;
  b_st.site = &si_emlrtRSI;
  c_st.site = &ti_emlrtRSI;
  d_st.site = &vi_emlrtRSI;
  memcpy(&b_A[0], &B[0], 25U * sizeof(real_T));
  e_st.site = &xi_emlrtRSI;
  for (i = 0; i < 5; i++) {
    ipiv[i] = (int8_T)(i + 1);
  }
  info = 0;
  for (j = 0; j < 4; j++) {
    int32_T b_tmp;
    b_tmp = j * 6;
    jp1j = b_tmp + 2;
    jA = 5 - j;
    f_st.site = &yi_emlrtRSI;
    g_st.site = &id_emlrtRSI;
    a = 0;
    smax = muDoubleScalarAbs(b_A[b_tmp]);
    h_st.site = &jd_emlrtRSI;
    for (k = 2; k <= jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_A[b_tmp + a] != 0.0) {
      if (a != 0) {
        jA = j + a;
        ipiv[j] = (int8_T)(jA + 1);
        for (k = 0; k < 5; k++) {
          a = j + k * 5;
          smax = b_A[a];
          A_tmp = jA + k * 5;
          b_A[a] = b_A[A_tmp];
          b_A[A_tmp] = smax;
        }
      }
      i = (b_tmp - j) + 5;
      f_st.site = &aj_emlrtRSI;
      for (a = jp1j; a <= i; a++) {
        b_A[a - 1] /= b_A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    i = 3 - j;
    f_st.site = &bj_emlrtRSI;
    g_st.site = &cj_emlrtRSI;
    h_st.site = &de_emlrtRSI;
    i_st.site = &ee_emlrtRSI;
    jA = b_tmp + 7;
    j_st.site = &fe_emlrtRSI;
    for (A_tmp = 0; A_tmp <= i; A_tmp++) {
      smax = b_A[(b_tmp + A_tmp * 5) + 5];
      if (smax != 0.0) {
        a = (jA - j) + 3;
        j_st.site = &sg_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          k_st.site = &o_emlrtRSI;
          check_forloop_overflow_error(&k_st);
        }
        for (jp1j = jA; jp1j <= a; jp1j++) {
          b_A[jp1j - 1] += b_A[((b_tmp + jp1j) - jA) + 1] * -smax;
        }
      }
      jA += 5;
    }
  }
  if ((info == 0) && (!(b_A[24] != 0.0))) {
    info = 5;
  }
  d_st.site = &wi_emlrtRSI;
  e_st.site = &dj_emlrtRSI;
  for (j = 0; j < 5; j++) {
    jA = 5 * j;
    f_st.site = &ej_emlrtRSI;
    for (k = 0; k < j; k++) {
      smax = b_A[k + jA];
      if (smax != 0.0) {
        A[j] -= smax * A[k];
      }
    }
    A[j] *= 1.0 / b_A[j + jA];
  }
  for (j = 4; j >= 0; j--) {
    jA = 5 * j - 1;
    i = j + 2;
    for (k = i; k < 6; k++) {
      smax = b_A[k + jA];
      if (smax != 0.0) {
        A[j] -= smax * A[k - 1];
      }
    }
  }
  if (ipiv[3] != 4) {
    smax = A[3];
    A[3] = A[ipiv[3] - 1];
    A[ipiv[3] - 1] = smax;
  }
  if (ipiv[2] != 3) {
    smax = A[2];
    A[2] = A[ipiv[2] - 1];
    A[ipiv[2] - 1] = smax;
  }
  if (ipiv[1] != 2) {
    smax = A[1];
    A[1] = A[ipiv[1] - 1];
    A[ipiv[1] - 1] = smax;
  }
  if (ipiv[0] != 1) {
    smax = A[0];
    A[0] = A[ipiv[0] - 1];
    A[ipiv[0] - 1] = smax;
  }
  if (info > 0) {
    c_st.site = &ui_emlrtRSI;
    d_st.site = &fj_emlrtRSI;
    warning(&d_st);
  }
}

/* End of code generation (mrdivide_helper.c) */
