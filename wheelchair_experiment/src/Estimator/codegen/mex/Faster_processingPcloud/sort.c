/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.c
 *
 * Code generation for function 'sort'
 *
 */

/* Include files */
#include "sort.h"
#include "Faster_processingPcloud_data.h"
#include "Faster_processingPcloud_emxutil.h"
#include "Faster_processingPcloud_types.h"
#include "eml_int_forloop_overflow_check.h"
#include "rt_nonfinite.h"
#include "sortIdx.h"

/* Variable Definitions */
static emlrtRSInfo hj_emlrtRSI = {
    76,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo ij_emlrtRSI = {
    79,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo jj_emlrtRSI = {
    81,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo kj_emlrtRSI = {
    84,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo lj_emlrtRSI = {
    87,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRSInfo mj_emlrtRSI = {
    90,     /* lineNo */
    "sort", /* fcnName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pathName
                                                                        */
};

static emlrtRTEInfo df_emlrtRTEI = {
    56,     /* lineNo */
    24,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo ef_emlrtRTEI = {
    75,     /* lineNo */
    26,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo ff_emlrtRTEI = {
    56,     /* lineNo */
    1,      /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

static emlrtRTEInfo gf_emlrtRTEI = {
    1,      /* lineNo */
    20,     /* colNo */
    "sort", /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/eml/+coder/+internal/sort.m" /* pName
                                                                        */
};

/* Function Definitions */
void sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *iidx;
  emxArray_real_T *vwork;
  real_T *vwork_data;
  real_T *x_data;
  int32_T dim;
  int32_T i;
  int32_T i1;
  int32_T j;
  int32_T vstride;
  int32_T *idx_data;
  int32_T *iidx_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtConstCTX)sp);
  dim = 2;
  if (x->size[0] != 1) {
    dim = 1;
  }
  if (dim <= 1) {
    i = x->size[0];
  } else {
    i = 1;
  }
  emxInit_real_T(sp, &vwork, 1, &ff_emlrtRTEI);
  i1 = vwork->size[0];
  vwork->size[0] = i;
  emxEnsureCapacity_real_T(sp, vwork, i1, &df_emlrtRTEI);
  vwork_data = vwork->data;
  i1 = idx->size[0];
  idx->size[0] = x->size[0];
  emxEnsureCapacity_int32_T(sp, idx, i1, &ef_emlrtRTEI);
  idx_data = idx->data;
  st.site = &hj_emlrtRSI;
  vstride = 1;
  i1 = dim - 2;
  for (dim = 0; dim <= i1; dim++) {
    vstride *= x->size[0];
  }
  st.site = &ij_emlrtRSI;
  st.site = &jj_emlrtRSI;
  if (vstride > 2147483646) {
    b_st.site = &ab_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  emxInit_int32_T(sp, &iidx, 1, &gf_emlrtRTEI);
  for (j = 0; j < vstride; j++) {
    st.site = &kj_emlrtRSI;
    if (i > 2147483646) {
      b_st.site = &ab_emlrtRSI;
      check_forloop_overflow_error(&b_st);
    }
    for (dim = 0; dim < i; dim++) {
      vwork_data[dim] = x_data[j + dim * vstride];
    }
    st.site = &lj_emlrtRSI;
    sortIdx(&st, vwork, iidx);
    iidx_data = iidx->data;
    vwork_data = vwork->data;
    st.site = &mj_emlrtRSI;
    for (dim = 0; dim < i; dim++) {
      i1 = j + dim * vstride;
      x_data[i1] = vwork_data[dim];
      idx_data[i1] = iidx_data[dim];
    }
  }
  emxFree_int32_T(sp, &iidx);
  emxFree_real_T(sp, &vwork);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtConstCTX)sp);
}

/* End of code generation (sort.c) */
