/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * allOrAny.c
 *
 * Code generation for function 'allOrAny'
 *
 */

/* Include files */
#include "allOrAny.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo vb_emlrtRSI = {
    56,                                                             /* lineNo */
    "@(x)coder.internal.allOrAny(op,x,coder.internal.indexInt(1))", /* fcnName
                                                                     */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo wb_emlrtRSI = {
    136,        /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRSInfo xb_emlrtRSI = {
    143,        /* lineNo */
    "allOrAny", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pathName
                                                                            */
};

static emlrtRTEInfo pd_emlrtRTEI = {
    56,         /* lineNo */
    14,         /* colNo */
    "allOrAny", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/allOrAny.m" /* pName
                                                                            */
};

/* Function Definitions */
void allOrAny_anonFcn1(const emlrtStack *sp, const emxArray_boolean_T *x,
                       emxArray_boolean_T *varargout_1)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T i2;
  int32_T npages;
  const boolean_T *x_data;
  boolean_T *varargout_1_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  st.site = &vb_emlrtRSI;
  i2 = varargout_1->size[0] * varargout_1->size[1];
  varargout_1->size[0] = 1;
  varargout_1->size[1] = x->size[1];
  emxEnsureCapacity_boolean_T(&st, varargout_1, i2, &pd_emlrtRTEI);
  varargout_1_data = varargout_1->data;
  npages = x->size[1];
  for (i2 = 0; i2 < npages; i2++) {
    varargout_1_data[i2] = false;
  }
  npages = x->size[1];
  i2 = 0;
  b_st.site = &wb_emlrtRSI;
  if (x->size[1] > 2147483646) {
    c_st.site = &gb_emlrtRSI;
    check_forloop_overflow_error(&c_st);
  }
  for (i = 0; i < npages; i++) {
    int32_T a_tmp;
    int32_T i1;
    boolean_T exitg1;
    a_tmp = i2 + x->size[0];
    i1 = i2 + 1;
    i2 = a_tmp;
    b_st.site = &xb_emlrtRSI;
    if ((i1 <= a_tmp) && (a_tmp > 2147483646)) {
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    exitg1 = false;
    while ((!exitg1) && (i1 <= a_tmp)) {
      if (x_data[i1 - 1]) {
        varargout_1_data[i] = true;
        exitg1 = true;
      } else {
        i1++;
      }
    }
  }
}

/* End of code generation (allOrAny.c) */
