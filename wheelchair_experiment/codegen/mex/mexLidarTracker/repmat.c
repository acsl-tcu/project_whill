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
#include "mexLidarTracker_data.h"
#include "mexLidarTracker_emxutil.h"
#include "mexLidarTracker_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo wk_emlrtRTEI = {
    53,       /* lineNo */
    9,        /* colNo */
    "repmat", /* fName */
    "/usr/local/MATLAB/R2023a/toolbox/eml/lib/matlab/elmat/repmat.m" /* pName */
};

/* Function Definitions */
void repmat(const emlrtStack *sp, int32_T varargin_2, emxArray_int32_T *b)
{
  int32_T i;
  int32_T *b_data;
  if (varargin_2 < 0) {
    emlrtNonNegativeCheckR2012b(varargin_2, &g_emlrtDCI, (emlrtConstCTX)sp);
  }
  i = b->size[0] * b->size[1];
  b->size[0] = 1;
  b->size[1] = varargin_2;
  emxEnsureCapacity_int32_T(sp, b, i, &wk_emlrtRTEI);
  b_data = b->data;
  for (i = 0; i < varargin_2; i++) {
    b_data[i] = 0;
  }
}

/* End of code generation (repmat.c) */
