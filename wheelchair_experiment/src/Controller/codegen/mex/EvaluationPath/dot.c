/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.c
 *
 * Code generation for function 'dot'
 *
 */

/* Include files */
#include "dot.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo k_emlrtRTEI = {
    12,                                                             /* lineNo */
    23,                                                             /* colNo */
    "dot",                                                          /* fName */
    "/usr/local/MATLAB/R2024b/toolbox/eml/lib/matlab/specfun/dot.m" /* pName */
};

/* Function Definitions */
int32_T dot(const emlrtStack *sp, const real_T a_data[],
            const int32_T a_size[2], const real_T b_data[],
            const int32_T b_size[2], real_T c_data[])
{
  int32_T c_size;
  int32_T i1;
  int32_T j;
  int32_T vstride;
  int8_T sz[2];
  int8_T varargin_2[2];
  boolean_T exitg1;
  boolean_T p;
  sz[0] = (int8_T)a_size[0];
  varargin_2[0] = (int8_T)b_size[0];
  sz[1] = 2;
  varargin_2[1] = 2;
  p = true;
  vstride = 0;
  exitg1 = false;
  while ((!exitg1) && (vstride < 2)) {
    if (sz[vstride] != varargin_2[vstride]) {
      p = false;
      exitg1 = true;
    } else {
      vstride++;
    }
  }
  if ((!p) && ((a_size[0] != 1) || (b_size[0] != 1))) {
    emlrtErrorWithMessageIdR2018a(sp, &k_emlrtRTEI,
                                  "MATLAB:dot:InputSizeMismatch",
                                  "MATLAB:dot:InputSizeMismatch", 0);
  }
  c_size = (int8_T)a_size[0];
  vstride = a_size[0];
  i1 = -1;
  for (j = 0; j < vstride; j++) {
    int32_T c_tmp;
    i1++;
    c_tmp = i1 + vstride;
    c_data[j] = a_data[i1] * b_data[i1] + a_data[c_tmp] * b_data[c_tmp];
  }
  return c_size;
}

/* End of code generation (dot.c) */
