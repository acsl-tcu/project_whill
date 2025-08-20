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
#include "calc_observation_data.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo tk_emlrtRSI = {
    42,      /* lineNo */
    "mrdiv", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "mrdivide_helper.m" /* pathName */
};

static emlrtRSInfo uk_emlrtRSI = {
    67,        /* lineNo */
    "lusolve", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo vk_emlrtRSI = {
    107,          /* lineNo */
    "lusolveNxN", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo wk_emlrtRSI = {
    112,          /* lineNo */
    "lusolveNxN", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo xk_emlrtRSI = {
    135,          /* lineNo */
    "XtimesInvA", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo yk_emlrtRSI = {
    140,          /* lineNo */
    "XtimesInvA", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
};

static emlrtRSInfo al_emlrtRSI =
    {
        30,       /* lineNo */
        "xgetrf", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+lapack/"
        "xgetrf.m" /* pathName */
};

static emlrtRSInfo bl_emlrtRSI = {
    41,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo cl_emlrtRSI = {
    55,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo dl_emlrtRSI = {
    63,        /* lineNo */
    "xzgetrf", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+reflapack/"
    "xzgetrf.m" /* pathName */
};

static emlrtRSInfo el_emlrtRSI =
    {
        45,      /* lineNo */
        "xgeru", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xgeru.m" /* pathName */
};

static emlrtRSInfo fl_emlrtRSI =
    {
        59,      /* lineNo */
        "xtrsm", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+blas/"
        "xtrsm.m" /* pathName */
};

static emlrtRSInfo gl_emlrtRSI =
    {
        143,     /* lineNo */
        "xtrsm", /* fcnName */
        "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/+refblas/"
        "xtrsm.m" /* pathName */
};

static emlrtRSInfo hl_emlrtRSI = {
    90,              /* lineNo */
    "warn_singular", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/lusolve.m" /* pathName
                                                                           */
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
  int32_T info;
  int32_T j;
  int32_T jA;
  int32_T jp1j;
  int32_T k;
  int8_T ipiv[5];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &tk_emlrtRSI;
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
  b_st.site = &uk_emlrtRSI;
  c_st.site = &vk_emlrtRSI;
  d_st.site = &xk_emlrtRSI;
  memcpy(&b_A[0], &B[0], 25U * sizeof(real_T));
  e_st.site = &al_emlrtRSI;
  for (A_tmp = 0; A_tmp < 5; A_tmp++) {
    ipiv[A_tmp] = (int8_T)(A_tmp + 1);
  }
  info = 0;
  for (j = 0; j < 4; j++) {
    int32_T b_tmp;
    int32_T mmj_tmp;
    mmj_tmp = 3 - j;
    b_tmp = j * 6;
    jp1j = b_tmp + 2;
    jA = 6 - j;
    f_st.site = &bl_emlrtRSI;
    g_st.site = &nf_emlrtRSI;
    a = 0;
    smax = muDoubleScalarAbs(b_A[b_tmp]);
    h_st.site = &of_emlrtRSI;
    for (k = 2; k < jA; k++) {
      real_T s;
      s = muDoubleScalarAbs(b_A[(b_tmp + k) - 1]);
      if (s > smax) {
        a = k - 1;
        smax = s;
      }
    }
    if (b_A[b_tmp + a] != 0.0) {
      if (a != 0) {
        a += j;
        ipiv[j] = (int8_T)(a + 1);
        for (k = 0; k < 5; k++) {
          jA = j + k * 5;
          smax = b_A[jA];
          A_tmp = a + k * 5;
          b_A[jA] = b_A[A_tmp];
          b_A[A_tmp] = smax;
        }
      }
      A_tmp = (b_tmp - j) + 5;
      f_st.site = &cl_emlrtRSI;
      for (a = jp1j; a <= A_tmp; a++) {
        b_A[a - 1] /= b_A[b_tmp];
      }
    } else {
      info = j + 1;
    }
    f_st.site = &dl_emlrtRSI;
    g_st.site = &el_emlrtRSI;
    h_st.site = &jg_emlrtRSI;
    i_st.site = &kg_emlrtRSI;
    jA = b_tmp + 7;
    j_st.site = &lg_emlrtRSI;
    for (A_tmp = 0; A_tmp <= mmj_tmp; A_tmp++) {
      smax = b_A[(b_tmp + A_tmp * 5) + 5];
      if (smax != 0.0) {
        a = (jA - j) + 3;
        j_st.site = &ri_emlrtRSI;
        if ((jA <= a) && (a > 2147483646)) {
          k_st.site = &u_emlrtRSI;
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
  d_st.site = &yk_emlrtRSI;
  e_st.site = &fl_emlrtRSI;
  for (j = 0; j < 5; j++) {
    jA = 5 * j;
    f_st.site = &gl_emlrtRSI;
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
    A_tmp = j + 2;
    for (k = A_tmp; k < 6; k++) {
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
    c_st.site = &wk_emlrtRSI;
    if (!emlrtSetWarningFlag(&c_st)) {
      d_st.site = &hl_emlrtRSI;
      warning(&d_st);
    }
  }
}

/* End of code generation (mrdivide_helper.c) */
