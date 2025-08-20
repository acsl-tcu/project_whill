/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertCompatibleDims.c
 *
 * Code generation for function 'assertCompatibleDims'
 *
 */

/* Include files */
#include "assertCompatibleDims.h"
#include "EvaluationPath_vec_data.h"
#include "EvaluationPath_vec_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                          const emxArray_real_T *y)
{
  if (((x->size[0] != 1) && (y->size[0] != 1) && (x->size[0] != y->size[0])) ||
      ((x->size[2] != 1) && (y->size[2] != 1) && (x->size[2] != y->size[2])) ||
      ((x->size[3] != 1) && (y->size[3] != 1) && (x->size[3] != y->size[3]))) {
    emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
}

void b_assertCompatibleDims(const emlrtStack *sp, const int32_T x_size[3],
                            const emxArray_real_T *y)
{
  if (((x_size[0] != 1) && (y->size[0] != 1) && (x_size[0] != y->size[0])) ||
      ((x_size[2] != 1) && (y->size[2] != 1) && (x_size[2] != y->size[2]))) {
    emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
}

void c_assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                            const int32_T y_size[3])
{
  if (((x->size[0] != 1) && (y_size[0] != 1) && (x->size[0] != y_size[0])) ||
      ((x->size[2] != 1) && (y_size[2] != 1) && (x->size[2] != y_size[2]))) {
    emlrtErrorWithMessageIdR2018a(sp, &o_emlrtRTEI,
                                  "MATLAB:sizeDimensionsMustMatch",
                                  "MATLAB:sizeDimensionsMustMatch", 0);
  }
}

/* End of code generation (assertCompatibleDims.c) */
