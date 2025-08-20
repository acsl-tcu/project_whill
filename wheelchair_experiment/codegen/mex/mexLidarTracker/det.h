/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * det.h
 *
 * Code generation for function 'det'
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
real_T b_det(const emlrtStack *sp, const real_T x[16]);

real32_T c_det(const emlrtStack *sp, const real32_T x[16]);

real_T det(const emlrtStack *sp, const real_T x[9]);

/* End of code generation (det.h) */
