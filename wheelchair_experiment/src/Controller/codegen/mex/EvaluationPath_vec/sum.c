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
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo vf_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pathName
                                                                     */
};

static emlrtRSInfo wf_emlrtRSI = {
    86,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo xf_emlrtRSI = {
    112,                /* lineNo */
    "blockedSummation", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo yf_emlrtRSI = {
    168,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo ag_emlrtRSI = {
    190,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo bg_emlrtRSI = {
    204,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    225,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pathName */
};

static emlrtRTEInfo ci_emlrtRTEI = {
    20,                                                             /* lineNo */
    1,                                                              /* colNo */
    "sum",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/sum.m" /* pName */
};

static emlrtRTEInfo di_emlrtRTEI = {
    146,                /* lineNo */
    24,                 /* colNo */
    "blockedSummation", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "blockedSummation.m" /* pName */
};

/* Function Definitions */
void b_sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T k;
  int32_T xi;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &vf_emlrtRSI;
  b_st.site = &bc_emlrtRSI;
  c_st.site = &wf_emlrtRSI;
  if (x->size[2] == 0) {
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 0;
  } else {
    int32_T i;
    int32_T xpageoffset;
    d_st.site = &xf_emlrtRSI;
    i = x->size[2];
    xpageoffset = y->size[0] * y->size[1] * y->size[2];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = x->size[2];
    emxEnsureCapacity_real_T(&d_st, y, xpageoffset, &di_emlrtRTEI);
    y_data = y->data;
    for (xi = 0; xi < i; xi++) {
      real_T d;
      xpageoffset = xi * 20;
      d = x_data[xpageoffset];
      for (k = 0; k < 19; k++) {
        d += x_data[(xpageoffset + k) + 1];
      }
      y_data[xi] = d;
    }
  }
}

void sum(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T ib;
  int32_T k;
  int32_T nblocks;
  int32_T xi;
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
  x_data = x->data;
  st.site = &vf_emlrtRSI;
  b_st.site = &bc_emlrtRSI;
  c_st.site = &wf_emlrtRSI;
  if ((x->size[2] == 0) || (x->size[3] == 0)) {
    int32_T firstBlockLength;
    nblocks = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&c_st, y, nblocks, &ci_emlrtRTEI);
    y_data = y->data;
    firstBlockLength = x->size[3];
    for (nblocks = 0; nblocks < firstBlockLength; nblocks++) {
      y_data[nblocks] = 0.0;
    }
  } else {
    int32_T firstBlockLength;
    int32_T lastBlockLength;
    int32_T npages_tmp;
    d_st.site = &xf_emlrtRSI;
    npages_tmp = x->size[3];
    nblocks = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_real_T(&d_st, y, nblocks, &di_emlrtRTEI);
    y_data = y->data;
    if (x->size[2] <= 1024) {
      firstBlockLength = x->size[2];
      lastBlockLength = 0;
      nblocks = 1;
    } else {
      firstBlockLength = 1024;
      nblocks = (int32_T)((uint32_T)x->size[2] >> 10);
      lastBlockLength = x->size[2] - (nblocks << 10);
      if (lastBlockLength > 0) {
        nblocks++;
      } else {
        lastBlockLength = 1024;
      }
    }
    e_st.site = &yf_emlrtRSI;
    if (x->size[3] > 2147483646) {
      f_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&f_st);
    }
    for (xi = 0; xi < npages_tmp; xi++) {
      int32_T xpageoffset;
      xpageoffset = xi * x->size[2];
      y_data[xi] = x_data[xpageoffset];
      e_st.site = &ag_emlrtRSI;
      for (k = 2; k <= firstBlockLength; k++) {
        y_data[xi] += x_data[(xpageoffset + k) - 1];
      }
      e_st.site = &bg_emlrtRSI;
      for (ib = 2; ib <= nblocks; ib++) {
        real_T bsum;
        int32_T hi;
        int32_T xblockoffset;
        xblockoffset = xpageoffset + ((ib - 1) << 10);
        bsum = x_data[xblockoffset];
        if (ib == nblocks) {
          hi = lastBlockLength;
        } else {
          hi = 1024;
        }
        e_st.site = &cg_emlrtRSI;
        for (k = 2; k <= hi; k++) {
          bsum += x_data[(xblockoffset + k) - 1];
        }
        y_data[xi] += bsum;
      }
    }
  }
}

/* End of code generation (sum.c) */
