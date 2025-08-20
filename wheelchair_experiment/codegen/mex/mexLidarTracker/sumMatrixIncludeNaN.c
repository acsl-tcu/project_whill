/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.c
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

/* Include files */
#include "sumMatrixIncludeNaN.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bj_emlrtRSI = {
    178,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cj_emlrtRSI = {
    210,         /* lineNo */
    "sumColumn", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo yk_emlrtRSI = {
    182,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo al_emlrtRSI = {
    183,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo bl_emlrtRSI = {
    184,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo cl_emlrtRSI = {
    189,          /* lineNo */
    "sumColumnB", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/private/"
    "sumMatrixIncludeNaN.m" /* pathName */
};

/* Function Declarations */
static real_T c_sumColumnB4(const emxArray_real_T *x, int32_T vstart);

static real_T f_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                           int32_T vlen);

static real_T g_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                           int32_T vlen, int32_T vstart);

/* Function Definitions */
static real_T c_sumColumnB4(const emxArray_real_T *x, int32_T vstart)
{
  const real_T *x_data;
  real_T psum1;
  real_T psum2;
  real_T psum3;
  real_T psum4;
  int32_T k;
  x_data = x->data;
  psum1 = x_data[vstart - 1];
  psum2 = x_data[vstart + 1023];
  psum3 = x_data[vstart + 2047];
  psum4 = x_data[vstart + 3071];
  for (k = 0; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = vstart + k;
    psum1 += x_data[psum1_tmp];
    psum2 += x_data[psum1_tmp + 1024];
    psum3 += x_data[psum1_tmp + 2048];
    psum4 += x_data[psum1_tmp + 3072];
  }
  return (psum1 + psum2) + (psum3 + psum4);
}

static real_T f_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                           int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    st.site = &bj_emlrtRSI;
    y = x_data[0];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[k + 1];
    }
  } else {
    real_T b_y;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    y = x_data[0];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[k + 1];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      int32_T vstart;
      st.site = &bl_emlrtRSI;
      vstart = (k - 1) << 10;
      b_y = x_data[vstart];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[(vstart + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &cl_emlrtRSI;
      b_y = x_data[inb];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[(inb + k) + 1];
      }
      y += b_y;
    }
  }
  return y;
}

static real_T g_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x,
                           int32_T vlen, int32_T vstart)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    st.site = &bj_emlrtRSI;
    y = x_data[vstart - 1];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[vstart + k];
    }
  } else {
    real_T b_y;
    int32_T b_vstart;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    y = x_data[vstart - 1];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[vstart + k];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &bl_emlrtRSI;
      b_vstart = vstart + ((k - 1) << 10);
      b_y = x_data[b_vstart - 1];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[b_vstart + b_k];
      }
      y += b_y;
    }
    if (vlen > inb) {
      b_vstart = vstart + inb;
      st.site = &cl_emlrtRSI;
      b_y = x_data[b_vstart - 1];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[b_vstart + k];
      }
      y += b_y;
    }
  }
  return y;
}

real32_T b_sumColumnB(const emlrtStack *sp, const emxArray_real32_T *x,
                      int32_T col, int32_T vlen, int32_T vstart)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_k;
  int32_T k;
  const real32_T *x_data;
  real32_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    int32_T i0;
    st.site = &bj_emlrtRSI;
    i0 = vstart + (col - 1) * x->size[0];
    y = x_data[i0 - 1];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[i0 + k];
    }
  } else {
    int32_T i0;
    int32_T i0_tmp;
    int32_T inb;
    int32_T nfb;
    real32_T b_y;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    i0_tmp = (col - 1) * x->size[0];
    i0 = vstart + i0_tmp;
    y = x_data[i0 - 1];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[i0 + k];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &bl_emlrtRSI;
      i0 = (vstart + ((k - 1) << 10)) + i0_tmp;
      b_y = x_data[i0 - 1];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[i0 + b_k];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &cl_emlrtRSI;
      i0 = (vstart + inb) + i0_tmp;
      b_y = x_data[i0 - 1];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[i0 + k];
      }
      y += b_y;
    }
  }
  return y;
}

real_T b_sumColumnB4(const emxArray_real_T *x, int32_T col, int32_T vstart)
{
  const real_T *x_data;
  real_T psum1;
  real_T psum2;
  real_T psum3;
  real_T psum4;
  int32_T i1;
  int32_T k;
  x_data = x->data;
  i1 = vstart + (col - 1) * x->size[0];
  psum1 = x_data[i1 - 1];
  psum2 = x_data[i1 + 1023];
  psum3 = x_data[i1 + 2047];
  psum4 = x_data[i1 + 3071];
  for (k = 0; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = i1 + k;
    psum1 += x_data[psum1_tmp];
    psum2 += x_data[psum1_tmp + 1024];
    psum3 += x_data[psum1_tmp + 2048];
    psum4 += x_data[psum1_tmp + 3072];
  }
  return (psum1 + psum2) + (psum3 + psum4);
}

real_T c_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T col,
                    int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    int32_T i0;
    st.site = &bj_emlrtRSI;
    i0 = (col - 1) * x->size[0];
    y = x_data[i0];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[(i0 + k) + 1];
    }
  } else {
    real_T b_y;
    int32_T i0;
    int32_T i0_tmp;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    i0_tmp = (col - 1) * x->size[0];
    y = x_data[i0_tmp];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[(i0_tmp + k) + 1];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &bl_emlrtRSI;
      i0 = ((k - 1) << 10) + i0_tmp;
      b_y = x_data[i0];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[(i0 + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &cl_emlrtRSI;
      i0 = (inb + i0_tmp) + 1;
      b_y = x_data[i0 - 1];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[i0 + k];
      }
      y += b_y;
    }
  }
  return y;
}

real_T d_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T col,
                    int32_T vlen, int32_T vstart)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *x_data;
  real_T y;
  int32_T b_k;
  int32_T k;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    int32_T i0;
    st.site = &bj_emlrtRSI;
    i0 = vstart + (col - 1) * x->size[0];
    y = x_data[i0 - 1];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[i0 + k];
    }
  } else {
    real_T b_y;
    int32_T i0;
    int32_T i0_tmp;
    int32_T inb;
    int32_T nfb;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    i0_tmp = (col - 1) * x->size[0];
    i0 = vstart + i0_tmp;
    y = x_data[i0 - 1];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[i0 + k];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &bl_emlrtRSI;
      i0 = (vstart + ((k - 1) << 10)) + i0_tmp;
      b_y = x_data[i0 - 1];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[i0 + b_k];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &cl_emlrtRSI;
      i0 = (vstart + inb) + i0_tmp;
      b_y = x_data[i0 - 1];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[i0 + k];
      }
      y += b_y;
    }
  }
  return y;
}

real_T e_sumColumnB(uint32_T x)
{
  return x;
}

real_T h_sumColumnB(const real_T x[3])
{
  return (x[0] + x[1]) + x[2];
}

real_T i_sumColumnB(void)
{
  return 1.0;
}

real_T j_sumColumnB(void)
{
  return 1.0;
}

real32_T sumColumnB(const emlrtStack *sp, const emxArray_real32_T *x,
                    int32_T col, int32_T vlen)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T b_k;
  int32_T k;
  const real32_T *x_data;
  real32_T y;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (vlen <= 1024) {
    int32_T i0;
    st.site = &bj_emlrtRSI;
    i0 = (col - 1) * x->size[0];
    y = x_data[i0];
    b_st.site = &cj_emlrtRSI;
    if (vlen - 1 > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 0; k <= vlen - 2; k++) {
      y += x_data[(i0 + k) + 1];
    }
  } else {
    int32_T i0;
    int32_T i0_tmp;
    int32_T inb;
    int32_T nfb;
    real32_T b_y;
    nfb = vlen / 1024;
    inb = nfb << 10;
    st.site = &yk_emlrtRSI;
    i0_tmp = (col - 1) * x->size[0];
    y = x_data[i0_tmp];
    b_st.site = &cj_emlrtRSI;
    for (k = 0; k < 1023; k++) {
      y += x_data[(i0_tmp + k) + 1];
    }
    st.site = &al_emlrtRSI;
    for (k = 2; k <= nfb; k++) {
      st.site = &bl_emlrtRSI;
      i0 = ((k - 1) << 10) + i0_tmp;
      b_y = x_data[i0];
      b_st.site = &cj_emlrtRSI;
      for (b_k = 0; b_k < 1023; b_k++) {
        b_y += x_data[(i0 + b_k) + 1];
      }
      y += b_y;
    }
    if (vlen > inb) {
      st.site = &cl_emlrtRSI;
      i0 = (inb + i0_tmp) + 1;
      b_y = x_data[i0 - 1];
      nfb = vlen - inb;
      b_st.site = &cj_emlrtRSI;
      for (k = 0; k <= nfb - 2; k++) {
        b_y += x_data[i0 + k];
      }
      y += b_y;
    }
  }
  return y;
}

real32_T sumColumnB4(const emxArray_real32_T *x, int32_T col, int32_T vstart)
{
  int32_T i1;
  int32_T k;
  const real32_T *x_data;
  real32_T psum1;
  real32_T psum2;
  real32_T psum3;
  real32_T psum4;
  x_data = x->data;
  i1 = vstart + (col - 1) * x->size[0];
  psum1 = x_data[i1 - 1];
  psum2 = x_data[i1 + 1023];
  psum3 = x_data[i1 + 2047];
  psum4 = x_data[i1 + 3071];
  for (k = 0; k < 1023; k++) {
    int32_T psum1_tmp;
    psum1_tmp = i1 + k;
    psum1 += x_data[psum1_tmp];
    psum2 += x_data[psum1_tmp + 1024];
    psum3 += x_data[psum1_tmp + 2048];
    psum4 += x_data[psum1_tmp + 3072];
  }
  return (psum1 + psum2) + (psum3 + psum4);
}

real_T sumMatrixColumns(const emlrtStack *sp, const emxArray_real_T *x,
                        int32_T vlen)
{
  emlrtStack st;
  real_T y;
  int32_T ib;
  st.prev = sp;
  st.tls = sp->tls;
  if (vlen < 4096) {
    st.site = &aj_emlrtRSI;
    y = f_sumColumnB(&st, x, vlen);
  } else {
    int32_T inb;
    int32_T nfb;
    int32_T nleft;
    nfb = vlen / 4096;
    inb = nfb << 12;
    nleft = vlen - inb;
    y = c_sumColumnB4(x, 1);
    for (ib = 2; ib <= nfb; ib++) {
      y += c_sumColumnB4(x, ((ib - 1) << 12) + 1);
    }
    if (nleft > 0) {
      st.site = &xk_emlrtRSI;
      y += g_sumColumnB(&st, x, nleft, inb + 1);
    }
  }
  return y;
}

/* End of code generation (sumMatrixIncludeNaN.c) */
