/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sum.c
 *
 * Code generation for function 'sum'
 *
 */

/* Include files */
#include "sum.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo wk_emlrtRSI = {
    53,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo bw_emlrtRSI = {
    41,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cw_emlrtRSI = {
    50,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T b_sum(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vi_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &vh_emlrtRSI;
  c_st.site = &wi_emlrtRSI;
  if (x->size[0] == 0) {
    y = 0.0;
  } else {
    d_st.site = &vk_emlrtRSI;
    e_st.site = &yi_emlrtRSI;
    y = sumMatrixColumns(&e_st, x, x->size[0]);
  }
  return y;
}

void sum(const emlrtStack *sp, const emxArray_real_T *x, real_T y_data[],
         int32_T y_size[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack st;
  int32_T col;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &vi_emlrtRSI;
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
  b_st.site = &vh_emlrtRSI;
  c_st.site = &wi_emlrtRSI;
  if (x->size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    d_st.site = &vk_emlrtRSI;
    e_st.site = &yi_emlrtRSI;
    y_size[0] = 1;
    y_size[1] = x->size[1];
    if (x->size[0] < 4096) {
      int32_T i;
      f_st.site = &bw_emlrtRSI;
      if (x->size[1] > 2147483646) {
        g_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      i = (uint8_T)x->size[1];
      for (col = 0; col < i; col++) {
        f_st.site = &aj_emlrtRSI;
        y_data[col] = c_sumColumnB(&f_st, x, col + 1, x->size[0]);
      }
    } else {
      int32_T i;
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[0] >> 12);
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      f_st.site = &cw_emlrtRSI;
      if (x->size[1] > 2147483646) {
        g_st.site = &mb_emlrtRSI;
        check_forloop_overflow_error(&g_st);
      }
      i = (uint8_T)x->size[1];
      for (col = 0; col < i; col++) {
        real_T s;
        s = b_sumColumnB4(x, col + 1, 1);
        f_st.site = &wk_emlrtRSI;
        for (ib = 2; ib <= nfb; ib++) {
          s += b_sumColumnB4(x, col + 1, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          f_st.site = &xk_emlrtRSI;
          s += d_sumColumnB(&f_st, x, col + 1, nleft, inb + 1);
        }
        y_data[col] = s;
      }
    }
  }
}

/* End of code generation (sum.c) */
