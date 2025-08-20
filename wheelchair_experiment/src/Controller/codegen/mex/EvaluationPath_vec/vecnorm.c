/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * vecnorm.c
 *
 * Code generation for function 'vecnorm'
 *
 */

/* Include files */
#include "vecnorm.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "blas.h"
#include "mwmathutil.h"
#include <stddef.h>
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo ve_emlrtRSI = {
    149,        /* lineNo */
    "looper1D", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

static emlrtRSInfo we_emlrtRSI = {
    154,        /* lineNo */
    "looper1D", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

static emlrtRSInfo xe_emlrtRSI = {
    170,          /* lineNo */
    "copyVector", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

static emlrtRSInfo ye_emlrtRSI = {
    172,          /* lineNo */
    "copyVector", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/"
    "applyVectorFunction.m" /* pathName */
};

static emlrtRTEInfo bi_emlrtRTEI = {
    56,        /* lineNo */
    5,         /* colNo */
    "vecnorm", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/matfun/vecnorm.m" /* pName
                                                                        */
};

/* Function Definitions */
void b_vecnorm(const emlrtStack *sp, const emxArray_real_T *x,
               emxArray_real_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const real_T *x_data;
  real_T *y_data;
  int32_T i;
  int32_T j;
  int32_T npages;
  int32_T p;
  int32_T stride;
  int32_T xpagesize_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  x_data = x->data;
  st.site = &se_emlrtRSI;
  i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = x->size[0];
  y->size[1] = 1;
  y->size[2] = x->size[2];
  y->size[3] = x->size[3];
  emxEnsureCapacity_real_T(&st, y, i, &bi_emlrtRTEI);
  y_data = y->data;
  npages = x->size[0] * x->size[2] * x->size[3];
  for (i = 0; i < npages; i++) {
    y_data[i] = 0.0;
  }
  b_st.site = &te_emlrtRSI;
  npages = x->size[2] * x->size[3];
  stride = x->size[0];
  xpagesize_tmp = x->size[0] << 1;
  c_st.site = &ue_emlrtRSI;
  if (npages > 2147483646) {
    d_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (p = 0; p < npages; p++) {
    int32_T xpageoffset;
    int32_T ypageoffset;
    xpageoffset = p * xpagesize_tmp - 1;
    ypageoffset = p * stride;
    c_st.site = &ve_emlrtRSI;
    if (stride > 2147483646) {
      d_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    i = (uint8_T)stride;
    for (j = 0; j < i; j++) {
      real_T absxk;
      real_T scale;
      real_T t;
      real_T varargout_1;
      int32_T workspace_ixfirst;
      workspace_ixfirst = (xpageoffset + j) + 1;
      scale = 3.3121686421112381E-170;
      absxk = muDoubleScalarAbs(x_data[workspace_ixfirst]);
      if (absxk > 3.3121686421112381E-170) {
        varargout_1 = 1.0;
        scale = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        varargout_1 = t * t;
      }
      absxk = muDoubleScalarAbs(x_data[workspace_ixfirst + stride]);
      if (absxk > scale) {
        t = scale / absxk;
        varargout_1 = varargout_1 * t * t + 1.0;
        scale = absxk;
      } else {
        t = absxk / scale;
        varargout_1 += t * t;
      }
      y_data[ypageoffset + j] = scale * muDoubleScalarSqrt(varargout_1);
    }
  }
}

void vecnorm(const emlrtStack *sp, const emxArray_real_T *x, emxArray_real_T *y)
{
  ptrdiff_t incx_t;
  ptrdiff_t n_t;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T xv_data[30];
  const real_T *x_data;
  real_T *y_data;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T k;
  int32_T loop_ub;
  int32_T npages;
  int32_T outsize_idx_0;
  int32_T p;
  int32_T stride;
  int32_T xpagesize_tmp;
  boolean_T b_overflow = false;
  boolean_T overflow = false;
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
  x_data = x->data;
  st.site = &se_emlrtRSI;
  stride = y->size[0] * y->size[1] * y->size[2] * y->size[3];
  y->size[0] = x->size[0];
  y->size[1] = 1;
  y->size[2] = x->size[2];
  y->size[3] = x->size[3];
  emxEnsureCapacity_real_T(&st, y, stride, &bi_emlrtRTEI);
  y_data = y->data;
  npages = x->size[0] * x->size[2] * x->size[3];
  for (stride = 0; stride < npages; stride++) {
    y_data[stride] = 0.0;
  }
  b_st.site = &te_emlrtRSI;
  npages = x->size[2] * x->size[3];
  stride = x->size[0];
  xpagesize_tmp = x->size[0] * x->size[1];
  c_st.site = &ue_emlrtRSI;
  if (npages > 2147483646) {
    d_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  if (npages - 1 >= 0) {
    overflow = (x->size[0] > 2147483646);
    i = (uint8_T)x->size[0];
    if ((uint8_T)x->size[0] - 1 >= 0) {
      outsize_idx_0 = x->size[1];
      loop_ub = x->size[1];
      b_overflow = (x->size[1] > 2147483646);
      i1 = (uint8_T)x->size[1];
    }
  }
  for (p = 0; p < npages; p++) {
    int32_T xpageoffset;
    int32_T ypageoffset;
    xpageoffset = p * xpagesize_tmp - 1;
    ypageoffset = p * stride - 1;
    c_st.site = &ve_emlrtRSI;
    if (overflow) {
      d_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (j = 0; j < i; j++) {
      int32_T workspace_ixfirst;
      workspace_ixfirst = (xpageoffset + j) + 1;
      c_st.site = &we_emlrtRSI;
      d_st.site = &xe_emlrtRSI;
      if (loop_ub - 1 >= 0) {
        memset(&xv_data[0], 0, (uint32_T)loop_ub * sizeof(real_T));
      }
      d_st.site = &ye_emlrtRSI;
      if (b_overflow) {
        e_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&e_st);
      }
      for (k = 0; k < i1; k++) {
        xv_data[k] = x_data[workspace_ixfirst + k * stride];
      }
      if (outsize_idx_0 == 0) {
        y_data[(ypageoffset + j) + 1] = 0.0;
      } else {
        n_t = (ptrdiff_t)outsize_idx_0;
        incx_t = (ptrdiff_t)1;
        y_data[(ypageoffset + j) + 1] = dnrm2(&n_t, &xv_data[0], &incx_t);
      }
    }
  }
}

/* End of code generation (vecnorm.c) */
