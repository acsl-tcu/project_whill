/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cholPSD.c
 *
 * Code generation for function 'cholPSD'
 *
 */

/* Include files */
#include "cholPSD.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "rt_nonfinite.h"
#include "xpotrf.h"
#include "xzsvdc.h"
#include "mwmathutil.h"
#include <emmintrin.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kr_emlrtRSI = {
    15,        /* lineNo */
    "cholPSD", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/cholPSD.m" /* pathName */
};

static emlrtRSInfo lr_emlrtRSI = {
    18,        /* lineNo */
    "cholPSD", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/cholPSD.m" /* pathName */
};

static emlrtRSInfo mr_emlrtRSI = {
    20,        /* lineNo */
    "cholPSD", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/cholPSD.m" /* pathName */
};

static emlrtRSInfo nr_emlrtRSI = {
    15,     /* lineNo */
    "chol", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/chol.m" /* pathName
                                                                     */
};

static emlrtRSInfo or_emlrtRSI = {
    84,     /* lineNo */
    "chol", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo pr_emlrtRSI = {
    100,    /* lineNo */
    "chol", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo qr_emlrtRSI = {
    101,    /* lineNo */
    "chol", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/chol.m" /* pathName
                                                                        */
};

static emlrtRSInfo bs_emlrtRSI = {
    12,     /* lineNo */
    "chol", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/chol.m" /* pathName
                                                                     */
};

static emlrtRSInfo cs_emlrtRSI = {
    15,       /* lineNo */
    "svdPSD", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/svdPSD.m" /* pathName */
};

static emlrtRSInfo ds_emlrtRSI = {
    17,       /* lineNo */
    "svdPSD", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/shared/tracking/trackinglib/"
    "+matlabshared/+tracking/+internal/svdPSD.m" /* pathName */
};

static emlrtRSInfo es_emlrtRSI = {
    36,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

static emlrtRSInfo fs_emlrtRSI = {
    42,                                                            /* lineNo */
    "svd",                                                         /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/matfun/svd.m" /* pathName
                                                                    */
};

static emlrtRSInfo gs_emlrtRSI = {
    52,    /* lineNo */
    "svd", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/svd.m" /* pathName
                                                                       */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    109,    /* lineNo */
    27,     /* colNo */
    "chol", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/eml/+coder/+internal/chol.m" /* pName
                                                                        */
};

/* Function Definitions */
void b_cholPSD(const emlrtStack *sp, const real_T A[9], real_T b_value[9])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T Ss[9];
  real_T b_A[9];
  int32_T a;
  int32_T info;
  int32_T j;
  int32_T jmax;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kr_emlrtRSI;
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
  b_st.site = &nr_emlrtRSI;
  memcpy(&Ss[0], &A[0], 9U * sizeof(real_T));
  c_st.site = &or_emlrtRSI;
  info = b_xpotrf(&c_st, Ss);
  if (info == 0) {
    jmax = 3;
  } else {
    jmax = info - 1;
  }
  c_st.site = &pr_emlrtRSI;
  if (jmax - 1 > 2147483646) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (j = 0; j <= jmax - 2; j++) {
    c_st.site = &qr_emlrtRSI;
    if ((j + 2 <= jmax) && (jmax > 2147483646)) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }
  if (info == 0) {
    st.site = &lr_emlrtRSI;
    b_st.site = &bs_emlrtRSI;
    memcpy(&Ss[0], &A[0], 9U * sizeof(real_T));
    c_st.site = &or_emlrtRSI;
    info = b_xpotrf(&c_st, Ss);
    if (info == 0) {
      jmax = 3;
    } else {
      jmax = info - 1;
    }
    c_st.site = &pr_emlrtRSI;
    if (jmax - 1 > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= jmax - 2; j++) {
      a = j + 2;
      c_st.site = &qr_emlrtRSI;
      if ((j + 2 <= jmax) && (jmax > 2147483646)) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      if (a <= jmax) {
        memset(&Ss[(j * 3 + a) + -1], 0,
               (uint32_T)((jmax - a) + 1) * sizeof(real_T));
      }
    }
    if (info != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &tb_emlrtRTEI, "MATLAB:posdef",
                                    "MATLAB:posdef", 0);
    }
    for (jmax = 0; jmax < 3; jmax++) {
      b_value[3 * jmax] = Ss[jmax];
      b_value[3 * jmax + 1] = Ss[jmax + 3];
      b_value[3 * jmax + 2] = Ss[jmax + 6];
    }
  } else {
    __m128d r;
    real_T V[9];
    real_T s[3];
    real_T d;
    boolean_T p;
    st.site = &mr_emlrtRSI;
    b_st.site = &cs_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &qc_emlrtRSI;
    e_st.site = &rc_emlrtRSI;
    p = true;
    for (jmax = 0; jmax < 9; jmax++) {
      if (p) {
        d = A[jmax];
        if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
          p = false;
        }
      } else {
        p = false;
      }
    }
    if (p) {
      c_st.site = &es_emlrtRSI;
      d_st.site = &gs_emlrtRSI;
      e_st.site = &uc_emlrtRSI;
      memcpy(&b_A[0], &A[0], 9U * sizeof(real_T));
      f_st.site = &vc_emlrtRSI;
      d_xzsvdc(&f_st, b_A, Ss, s, V);
    } else {
      c_st.site = &fs_emlrtRSI;
      d_st.site = &gs_emlrtRSI;
      e_st.site = &uc_emlrtRSI;
      memset(&b_A[0], 0, 9U * sizeof(real_T));
      f_st.site = &vc_emlrtRSI;
      d_xzsvdc(&f_st, b_A, Ss, s, V);
      s[0] = rtNaN;
      s[1] = rtNaN;
      s[2] = rtNaN;
      for (jmax = 0; jmax < 9; jmax++) {
        V[jmax] = rtNaN;
      }
    }
    memset(&Ss[0], 0, 9U * sizeof(real_T));
    Ss[0] = s[0];
    Ss[4] = s[1];
    Ss[8] = s[2];
    b_st.site = &ds_emlrtRSI;
    p = false;
    for (jmax = 0; jmax < 9; jmax++) {
      if (p || (Ss[jmax] < 0.0)) {
        p = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    r = _mm_loadu_pd(&Ss[0]);
    _mm_storeu_pd(&Ss[0], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[2]);
    _mm_storeu_pd(&Ss[2], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[4]);
    _mm_storeu_pd(&Ss[4], _mm_sqrt_pd(r));
    r = _mm_loadu_pd(&Ss[6]);
    _mm_storeu_pd(&Ss[6], _mm_sqrt_pd(r));
    Ss[8] = muDoubleScalarSqrt(Ss[8]);
    for (jmax = 0; jmax < 3; jmax++) {
      real_T d1;
      real_T d2;
      d = V[jmax];
      d1 = V[jmax + 3];
      d2 = V[jmax + 6];
      for (a = 0; a < 3; a++) {
        b_value[jmax + 3 * a] =
            (d * Ss[3 * a] + d1 * Ss[3 * a + 1]) + d2 * Ss[3 * a + 2];
      }
    }
  }
}

void cholPSD(const emlrtStack *sp, const real_T A[36], real_T b_value[36])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T Ss[36];
  real_T b_A[36];
  int32_T a;
  int32_T i;
  int32_T info;
  int32_T j;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &kr_emlrtRSI;
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
  b_st.site = &nr_emlrtRSI;
  memcpy(&Ss[0], &A[0], 36U * sizeof(real_T));
  c_st.site = &or_emlrtRSI;
  info = xpotrf(&c_st, Ss);
  if (info == 0) {
    i = 6;
  } else {
    i = info - 1;
  }
  c_st.site = &pr_emlrtRSI;
  if (i - 1 > 2147483646) {
    d_st.site = &mb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (j = 0; j <= i - 2; j++) {
    c_st.site = &qr_emlrtRSI;
    if ((j + 2 <= i) && (i > 2147483646)) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
  }
  if (info == 0) {
    st.site = &lr_emlrtRSI;
    b_st.site = &bs_emlrtRSI;
    memcpy(&Ss[0], &A[0], 36U * sizeof(real_T));
    c_st.site = &or_emlrtRSI;
    info = xpotrf(&c_st, Ss);
    if (info == 0) {
      i = 6;
    } else {
      i = info - 1;
    }
    c_st.site = &pr_emlrtRSI;
    if (i - 1 > 2147483646) {
      d_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j <= i - 2; j++) {
      a = j + 2;
      c_st.site = &qr_emlrtRSI;
      if ((j + 2 <= i) && (i > 2147483646)) {
        d_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&d_st);
      }
      if (a <= i) {
        memset(&Ss[(j * 6 + a) + -1], 0,
               (uint32_T)((i - a) + 1) * sizeof(real_T));
      }
    }
    if (info != 0) {
      emlrtErrorWithMessageIdR2018a(&b_st, &tb_emlrtRTEI, "MATLAB:posdef",
                                    "MATLAB:posdef", 0);
    }
    for (a = 0; a < 6; a++) {
      for (info = 0; info < 6; info++) {
        b_value[info + 6 * a] = Ss[a + 6 * info];
      }
    }
  } else {
    real_T V[36];
    real_T s[6];
    real_T d;
    boolean_T p;
    st.site = &mr_emlrtRSI;
    b_st.site = &cs_emlrtRSI;
    c_st.site = &oc_emlrtRSI;
    d_st.site = &qc_emlrtRSI;
    e_st.site = &rc_emlrtRSI;
    p = true;
    for (i = 0; i < 36; i++) {
      if (p) {
        d = A[i];
        if (muDoubleScalarIsInf(d) || muDoubleScalarIsNaN(d)) {
          p = false;
        }
      } else {
        p = false;
      }
    }
    if (p) {
      c_st.site = &es_emlrtRSI;
      d_st.site = &gs_emlrtRSI;
      e_st.site = &uc_emlrtRSI;
      memcpy(&b_A[0], &A[0], 36U * sizeof(real_T));
      f_st.site = &vc_emlrtRSI;
      c_xzsvdc(&f_st, b_A, Ss, s, V);
    } else {
      c_st.site = &fs_emlrtRSI;
      d_st.site = &gs_emlrtRSI;
      e_st.site = &uc_emlrtRSI;
      memset(&b_A[0], 0, 36U * sizeof(real_T));
      f_st.site = &vc_emlrtRSI;
      c_xzsvdc(&f_st, b_A, Ss, s, V);
      for (i = 0; i < 6; i++) {
        s[i] = rtNaN;
      }
      for (a = 0; a < 36; a++) {
        V[a] = rtNaN;
      }
    }
    memset(&Ss[0], 0, 36U * sizeof(real_T));
    for (i = 0; i < 6; i++) {
      Ss[i + 6 * i] = s[i];
    }
    b_st.site = &ds_emlrtRSI;
    p = false;
    for (i = 0; i < 36; i++) {
      if (p || (Ss[i] < 0.0)) {
        p = true;
      }
    }
    if (p) {
      emlrtErrorWithMessageIdR2018a(
          &b_st, &hb_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
          "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
    }
    for (i = 0; i <= 34; i += 2) {
      __m128d r;
      r = _mm_loadu_pd(&Ss[i]);
      _mm_storeu_pd(&Ss[i], _mm_sqrt_pd(r));
    }
    for (a = 0; a < 6; a++) {
      for (info = 0; info < 6; info++) {
        d = 0.0;
        for (i = 0; i < 6; i++) {
          d += V[a + 6 * i] * Ss[i + 6 * info];
        }
        b_value[a + 6 * info] = d;
      }
    }
  }
}

/* End of code generation (cholPSD.c) */
