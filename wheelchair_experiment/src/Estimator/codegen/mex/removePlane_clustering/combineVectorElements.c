/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * combineVectorElements.c
 *
 * Code generation for function 'combineVectorElements'
 *
 */

/* Include files */
#include "combineVectorElements.h"
#include "eml_int_forloop_overflow_check.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo md_emlrtRSI = {
    138,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo nd_emlrtRSI = {
    182,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo od_emlrtRSI = {
    200,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    170,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pName */
};

/* Function Definitions */
void combineVectorElements(const emlrtStack *sp, const emxArray_boolean_T *x,
                           emxArray_int32_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T j;
  int32_T k;
  int32_T *y_data;
  const boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  if (x->size[0] == 0) {
    y->size[0] = 0;
  } else {
    int32_T vstride;
    int32_T xoffset;
    st.site = &md_emlrtRSI;
    vstride = x->size[0];
    xoffset = y->size[0];
    y->size[0] = x->size[0];
    emxEnsureCapacity_int32_T(&st, y, xoffset, &mc_emlrtRTEI);
    y_data = y->data;
    b_st.site = &nd_emlrtRSI;
    if (x->size[0] > 2147483646) {
      c_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (j = 0; j < vstride; j++) {
      y_data[j] = x_data[j];
    }
    for (k = 0; k < 2; k++) {
      xoffset = (k + 1) * vstride;
      b_st.site = &od_emlrtRSI;
      for (j = 0; j < vstride; j++) {
        y_data[j] += x_data[xoffset + j];
      }
    }
  }
}

/* End of code generation (combineVectorElements.c) */
