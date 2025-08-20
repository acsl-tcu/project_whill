/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sin.c
 *
 * Code generation for function 'sin'
 *
 */

/* Include files */
#include "sin.h"
#include "EvaluationPath_data.h"
#include "EvaluationPath_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo r_emlrtRSI = {
    11,                                                           /* lineNo */
    "sin",                                                        /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/elfun/sin.m" /* pathName */
};

/* Function Definitions */
void b_sin(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T k;
  int32_T nx_tmp;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &r_emlrtRSI;
  nx_tmp = x->size[0] * x->size[1];
  b_st.site = &s_emlrtRSI;
  if (nx_tmp > 2147483646) {
    c_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx_tmp; k++) {
    x_data[k] = muDoubleScalarSin(x_data[k]);
  }
}

void c_sin(const emlrtStack *sp, emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T *x_data;
  int32_T k;
  int32_T nx;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &r_emlrtRSI;
  nx = x->size[0];
  b_st.site = &s_emlrtRSI;
  if (x->size[0] > 2147483646) {
    c_st.site = &t_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (k = 0; k < nx; k++) {
    x_data[k] = muDoubleScalarSin(x_data[k]);
  }
}

/* End of code generation (sin.c) */
