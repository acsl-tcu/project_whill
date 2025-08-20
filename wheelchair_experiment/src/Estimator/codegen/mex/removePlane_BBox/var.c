/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * var.c
 *
 * Code generation for function 'var'
 *
 */

/* Include files */
#include "var.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_BBox_data.h"
#include "removePlane_BBox_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo nd_emlrtRSI = {
    9,     /* lineNo */
    "var", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\var.m" /* pathName
                                                                        */
};

static emlrtRSInfo od_emlrtRSI = {
    105,      /* lineNo */
    "varstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\varstd"
    ".m" /* pathName */
};

static emlrtRSInfo pd_emlrtRSI = {
    105,       /* lineNo */
    "vvarstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pathName */
};

static emlrtRSInfo qd_emlrtRSI = {
    96,        /* lineNo */
    "vvarstd", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\vvarst"
    "d.m" /* pathName */
};

static emlrtRSInfo rd_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo sd_emlrtRSI = {
    107,                /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo td_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo ud_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T var(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  const real_T *x_data;
  real_T s;
  real_T y;
  int32_T ib;
  int32_T n;
  int32_T nfb;
  st.prev = sp;
  st.tls = sp->tls;
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
  x_data = x->data;
  st.site = &nd_emlrtRSI;
  n = x->size[0];
  b_st.site = &od_emlrtRSI;
  c_st.site = &qd_emlrtRSI;
  d_st.site = &rd_emlrtRSI;
  e_st.site = &sd_emlrtRSI;
  f_st.site = &td_emlrtRSI;
  if (x->size[0] < 4096) {
    g_st.site = &ud_emlrtRSI;
    s = sumColumnB(&g_st, x, x->size[0]);
  } else {
    int32_T inb;
    int32_T nleft;
    nfb = (int32_T)((uint32_T)x->size[0] >> 12);
    inb = nfb << 12;
    nleft = x->size[0] - inb;
    s = sumColumnB4(x, 1);
    for (ib = 2; ib <= nfb; ib++) {
      s += sumColumnB4(x, ((ib - 1) << 12) + 1);
    }
    if (nleft > 0) {
      g_st.site = &vd_emlrtRSI;
      s += b_sumColumnB(&g_st, x, nleft, inb + 1);
    }
  }
  s /= (real_T)x->size[0];
  y = 0.0;
  c_st.site = &pd_emlrtRSI;
  if (x->size[0] > 2147483646) {
    d_st.site = &r_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (nfb = 0; nfb < n; nfb++) {
    real_T t;
    t = x_data[nfb] - s;
    y += t * t;
  }
  y /= (real_T)x->size[0] - 1.0;
  return y;
}

/* End of code generation (var.c) */
