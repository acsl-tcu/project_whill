/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * colon.c
 *
 * Code generation for function 'colon'
 *
 */

/* Include files */
#include "colon.h"
#include "eml_int_forloop_overflow_check.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo bbb_emlrtRSI = {
    148,                                                          /* lineNo */
    "eml_integer_colon_dispatcher",                               /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtRSInfo cbb_emlrtRSI = {
    176,                                                          /* lineNo */
    "eml_signed_integer_colon",                                   /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/colon.m" /* pathName */
};

static emlrtRTEInfo tj_emlrtRTEI = {
    172,                                                          /* lineNo */
    20,                                                           /* colNo */
    "colon",                                                      /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/ops/colon.m" /* pName */
};

/* Function Definitions */
void eml_integer_colon_dispatcher(const emlrtStack *sp, int32_T b,
                                  emxArray_int32_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T k;
  int32_T n;
  int32_T yk;
  int32_T *y_data;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bbb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  if (b < 1) {
    n = 0;
  } else {
    n = b;
  }
  yk = y->size[0] * y->size[1];
  y->size[0] = 1;
  y->size[1] = n;
  emxEnsureCapacity_int32_T(&st, y, yk, &tj_emlrtRTEI);
  y_data = y->data;
  if (n > 0) {
    y_data[0] = 1;
    yk = 1;
    b_st.site = &cbb_emlrtRSI;
    if (n > 2147483646) {
      c_st.site = &mb_emlrtRSI;
      check_forloop_overflow_error(&c_st);
    }
    for (k = 2; k <= n; k++) {
      yk++;
      y_data[k - 1] = yk;
    }
  }
}

/* End of code generation (colon.c) */
