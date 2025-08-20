/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * assertCompatibleDims.h
 *
 * Code generation for function 'assertCompatibleDims'
 *
 */

#pragma once

/* Include files */
#include "EvaluationPath_vec_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                          const emxArray_real_T *y);

void b_assertCompatibleDims(const emlrtStack *sp, const int32_T x_size[3],
                            const emxArray_real_T *y);

void c_assertCompatibleDims(const emlrtStack *sp, const emxArray_real_T *x,
                            const int32_T y_size[3]);

/* End of code generation (assertCompatibleDims.h) */
