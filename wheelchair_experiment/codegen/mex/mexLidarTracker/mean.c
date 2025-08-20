/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "mean.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo xi_emlrtRSI = {
    99,                 /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo uk_emlrtRSI = {
    49,     /* lineNo */
    "mean", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mean.m" /* pathName
                                                                      */
};

/* Function Definitions */
real_T b_mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_real_T c_x;
  real_T y;
  int32_T d_x;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uk_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  b_st.site = &wi_emlrtRSI;
  if (x->size[1] == 0) {
    y = 0.0;
  } else {
    int32_T b_x;
    c_st.site = &xi_emlrtRSI;
    b_x = x->size[1];
    c_x = *x;
    d_x = b_x;
    c_x.size = &d_x;
    c_x.numDimensions = 1;
    d_st.site = &yi_emlrtRSI;
    y = sumMatrixColumns(&d_st, &c_x, x->size[1]);
  }
  y /= (real_T)x->size[1];
  return y;
}

void mean(const emlrtStack *sp, const emxArray_real32_T *x, real32_T y[3])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  int32_T col;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &uk_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &wi_emlrtRSI;
  if (x->size[0] == 0) {
    y[0] = 0.0F;
    y[1] = 0.0F;
    y[2] = 0.0F;
  } else {
    c_st.site = &vk_emlrtRSI;
    d_st.site = &yi_emlrtRSI;
    if (x->size[0] < 4096) {
      e_st.site = &aj_emlrtRSI;
      y[0] = sumColumnB(&e_st, x, 1, x->size[0]);
      e_st.site = &aj_emlrtRSI;
      y[1] = sumColumnB(&e_st, x, 2, x->size[0]);
      e_st.site = &aj_emlrtRSI;
      y[2] = sumColumnB(&e_st, x, 3, x->size[0]);
    } else {
      int32_T inb;
      int32_T nfb;
      int32_T nleft;
      nfb = (int32_T)((uint32_T)x->size[0] >> 12);
      inb = nfb << 12;
      nleft = x->size[0] - inb;
      for (col = 0; col < 3; col++) {
        real32_T s;
        s = sumColumnB4(x, col + 1, 1);
        for (ib = 2; ib <= nfb; ib++) {
          s += sumColumnB4(x, col + 1, ((ib - 1) << 12) + 1);
        }
        if (nleft > 0) {
          e_st.site = &xk_emlrtRSI;
          s += b_sumColumnB(&e_st, x, col + 1, nleft, inb + 1);
        }
        y[col] = s;
      }
    }
  }
  y[0] /= (real32_T)x->size[0];
  y[1] /= (real32_T)x->size[0];
  y[2] /= (real32_T)x->size[0];
}

/* End of code generation (mean.c) */
