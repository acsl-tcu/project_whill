/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xgemv.h
 *
 * Code generation for function 'xgemv'
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
void b_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[54],
             int32_T ia0, const real_T x[54], int32_T ix0, real_T y[6]);

void c_xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[27],
             int32_T ia0, const real_T x[27], int32_T ix0, real_T y[3]);

void xgemv(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
           int32_T ia0, const real_T x[9], int32_T ix0, real_T y[3]);

/* End of code generation (xgemv.h) */
