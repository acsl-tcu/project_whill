/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * repmat.c
 *
 * Code generation for function 'repmat'
 *
 */

/* Include files */
#include "repmat.h"
#include "assertValidSizeArg.h"
#include "removePlane_clustering_data.h"
#include "removePlane_clustering_emxutil.h"
#include "removePlane_clustering_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo ed_emlrtRTEI = {
    53,       /* lineNo */
    9,        /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2023a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, const real_T varargin_1[2],
            emxArray_real_T *b)
{
  emlrtStack st;
  real_T *b_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &t_emlrtRSI;
  assertValidSizeArg(&st, varargin_1);
  i = b->size[0] * b->size[1];
  b->size[0] = (int32_T)varargin_1[0];
  b->size[1] = (int32_T)varargin_1[1];
  emxEnsureCapacity_real_T(sp, b, i, &ed_emlrtRTEI);
  b_data = b->data;
  loop_ub = (int32_T)varargin_1[0] * (int32_T)varargin_1[1];
  for (i = 0; i < loop_ub; i++) {
    b_data[i] = rtNaN;
  }
}

/* End of code generation (repmat.c) */
