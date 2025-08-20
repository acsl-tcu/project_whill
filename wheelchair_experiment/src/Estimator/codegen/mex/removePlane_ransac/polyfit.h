/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * polyfit.h
 *
 * Code generation for function 'polyfit'
 *
 */

#pragma once

/* Include files */
#include "removePlane_ransac_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void polyfit(const emlrtStack *sp, const emxArray_real_T *x,
             const emxArray_real_T *y, real_T p[2]);

/* End of code generation (polyfit.h) */
