/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgerc.h
 *
 * Code generation for function 'xgerc'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
             int32_T ix0, const real_T y[6], real_T A[54], int32_T ia0);

void c_xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
             int32_T ix0, const real_T y[3], real_T A[27], int32_T ia0);

void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
           const real_T x[3], int32_T iy0, real_T A[9], int32_T ia0);

/* End of code generation (xgerc.h) */
