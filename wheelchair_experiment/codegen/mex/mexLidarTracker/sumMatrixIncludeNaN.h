/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumMatrixIncludeNaN.h
 *
 * Code generation for function 'sumMatrixIncludeNaN'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real32_T b_sumColumnB(const emlrtStack *sp, const emxArray_real32_T *x,
                      int32_T col, int32_T vlen, int32_T vstart);

real_T b_sumColumnB4(const emxArray_real_T *x, int32_T col, int32_T vstart);

real_T c_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T col,
                    int32_T vlen);

real_T d_sumColumnB(const emlrtStack *sp, const emxArray_real_T *x, int32_T col,
                    int32_T vlen, int32_T vstart);

real_T e_sumColumnB(uint32_T x);

real_T h_sumColumnB(const real_T x[3]);

real_T i_sumColumnB(void);

real_T j_sumColumnB(void);

real32_T sumColumnB(const emlrtStack *sp, const emxArray_real32_T *x,
                    int32_T col, int32_T vlen);

real32_T sumColumnB4(const emxArray_real32_T *x, int32_T col, int32_T vstart);

real_T sumMatrixColumns(const emlrtStack *sp, const emxArray_real_T *x,
                        int32_T vlen);

/* End of code generation (sumMatrixIncludeNaN.h) */
