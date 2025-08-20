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
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_emxutil.h"
#include "EvaluationPath_vec_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo cc_emlrtRSI = {
    149,                     /* lineNo */
    "combineVectorElements", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo dc_emlrtRSI = {
    188,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRSInfo ec_emlrtRSI = {
    209,                /* lineNo */
    "colMajorFlatIter", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pathName */
};

static emlrtRTEInfo qd_emlrtRTEI = {
    108,                     /* lineNo */
    13,                      /* colNo */
    "combineVectorElements", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pName */
};

static emlrtRTEInfo rd_emlrtRTEI = {
    181,                     /* lineNo */
    24,                      /* colNo */
    "combineVectorElements", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/datafun/private/"
    "combineVectorElements.m" /* pName */
};

/* Function Definitions */
void combineVectorElements(const emlrtStack *sp, const emxArray_boolean_T *x,
                           emxArray_int32_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  int32_T vlen;
  int32_T *y_data;
  const boolean_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  vlen = x->size[2];
  if ((x->size[2] == 0) || (x->size[3] == 0)) {
    int32_T xpageoffset;
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_int32_T(sp, y, i, &qd_emlrtRTEI);
    y_data = y->data;
    xpageoffset = x->size[3];
    for (i = 0; i < xpageoffset; i++) {
      y_data[i] = 0;
    }
  } else {
    int32_T npages_tmp;
    boolean_T overflow;
    st.site = &cc_emlrtRSI;
    npages_tmp = x->size[3];
    i = y->size[0] * y->size[1] * y->size[2] * y->size[3];
    y->size[0] = 1;
    y->size[1] = 1;
    y->size[2] = 1;
    y->size[3] = x->size[3];
    emxEnsureCapacity_int32_T(&st, y, i, &rd_emlrtRTEI);
    y_data = y->data;
    b_st.site = &dc_emlrtRSI;
    if (x->size[3] > 2147483646) {
      c_st.site = &gb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    overflow = (x->size[2] > 2147483646);
    for (i = 0; i < npages_tmp; i++) {
      int32_T xpageoffset;
      xpageoffset = i * x->size[2];
      y_data[i] = x_data[xpageoffset];
      b_st.site = &ec_emlrtRSI;
      if (overflow) {
        c_st.site = &gb_emlrtRSI;
        check_forloop_overflow_error(&c_st);
      }
      for (k = 2; k <= vlen; k++) {
        y_data[i] += x_data[(xpageoffset + k) - 1];
      }
    }
  }
}

/* End of code generation (combineVectorElements.c) */
