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
#include "pcfitellipse_data.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo e_emlrtRSI = {
    49,     /* lineNo */
    "mean", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" /* pathName
                                                                         */
};

/* Function Definitions */
real_T mean(const emlrtStack *sp, const real_T x_data[], int32_T x_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T y;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &e_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &f_emlrtRSI;
  if (x_size == 0) {
    y = 0.0;
  } else {
    c_st.site = &g_emlrtRSI;
    d_st.site = &h_emlrtRSI;
    e_st.site = &i_emlrtRSI;
    y = sumColumnB(&e_st, x_data, x_size);
  }
  y /= (real_T)x_size;
  return y;
}

/* End of code generation (mean.c) */
