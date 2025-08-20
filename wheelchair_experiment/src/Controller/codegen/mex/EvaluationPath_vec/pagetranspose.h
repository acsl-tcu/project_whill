/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pagetranspose.h
 *
 * Code generation for function 'pagetranspose'
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
void b_pagetranspose(const emlrtStack *sp, const real_T x_data[],
                     const int32_T x_size[3], real_T y_data[],
                     int32_T y_size[3]);

void c_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);

void d_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);

void e_pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                     emxArray_real_T *y);

void pagetranspose(const emlrtStack *sp, const emxArray_real_T *x,
                   emxArray_real_T *y);

/* End of code generation (pagetranspose.h) */
