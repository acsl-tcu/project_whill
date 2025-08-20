/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xcopy.h
 *
 * Code generation for function 'xcopy'
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
void b_xcopy(const emlrtStack *sp, int32_T n, real_T y[15]);

void c_xcopy(const emlrtStack *sp, int32_T n, const real_T x[120], int32_T ix0,
             real_T y[225], int32_T iy0);

void d_xcopy(const emlrtStack *sp, int32_T n, const real_T x[5], real_T y[8]);

void e_xcopy(const emlrtStack *sp, int32_T n, const real_T x[8], real_T y[8]);

void f_xcopy(const emlrtStack *sp, int32_T n, const real_T x[25], int32_T ix0,
             real_T y[225], int32_T iy0);

void g_xcopy(const emlrtStack *sp, int32_T n, real_T y[8]);

void h_xcopy(const emlrtStack *sp, int32_T n, real_T y[25], int32_T iy0);

void i_xcopy(const real_T x[2], real_T y[2]);

void xcopy(const emlrtStack *sp, int32_T n, const real_T x[15], real_T y[15]);

/* End of code generation (xcopy.h) */
