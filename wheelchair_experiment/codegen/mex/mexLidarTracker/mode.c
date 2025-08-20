/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mode.c
 *
 * Code generation for function 'mode'
 *
 */

/* Include files */
#include "mode.h"
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"
#include "sort.h"

/* Variable Definitions */
static emlrtRSInfo rj_emlrtRSI = {
    93,          /* lineNo */
    "arraymode", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mode.m" /* pathName
                                                                      */
};

static emlrtRSInfo sj_emlrtRSI = {
    148,          /* lineNo */
    "vectormode", /* fcnName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mode.m" /* pathName
                                                                      */
};

static emlrtRTEInfo kh_emlrtRTEI = {
    148,    /* lineNo */
    1,      /* colNo */
    "mode", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mode.m" /* pName */
};

static emlrtRTEInfo lh_emlrtRTEI = {
    93,     /* lineNo */
    24,     /* colNo */
    "mode", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/datafun/mode.m" /* pName */
};

/* Function Definitions */
uint32_T arraymode(const emlrtStack *sp, const emxArray_uint32_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_uint32_T *v;
  int32_T i;
  int32_T k;
  const uint32_T *x_data;
  uint32_T M;
  uint32_T *v_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  if (x->size[0] == 0) {
    M = 0U;
  } else {
    int32_T ftmp;
    int32_T loop_ub;
    uint32_T mtmp;
    st.site = &rj_emlrtRSI;
    b_st.site = &sj_emlrtRSI;
    emxInit_uint32_T(&b_st, &v, 1, &lh_emlrtRTEI, true);
    i = v->size[0];
    v->size[0] = x->size[0];
    emxEnsureCapacity_uint32_T(&b_st, v, i, &kh_emlrtRTEI);
    v_data = v->data;
    loop_ub = x->size[0];
    for (i = 0; i < loop_ub; i++) {
      v_data[i] = x_data[i];
    }
    c_st.site = &tj_emlrtRSI;
    sort(&c_st, v);
    v_data = v->data;
    M = v_data[0];
    loop_ub = 1;
    mtmp = v_data[0];
    ftmp = 1;
    i = v->size[0];
    for (k = 0; k <= i - 2; k++) {
      uint32_T u;
      u = v_data[k + 1];
      if (u == mtmp) {
        ftmp++;
      } else {
        if (ftmp > loop_ub) {
          M = mtmp;
          loop_ub = ftmp;
        }
        mtmp = u;
        ftmp = 1;
      }
    }
    emxFree_uint32_T(&st, &v);
    if (ftmp > loop_ub) {
      M = mtmp;
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
  return M;
}

/* End of code generation (mode.c) */
