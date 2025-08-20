/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ixfun.h
 *
 * Code generation for function 'ixfun'
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
void expand_mod(const emlrtStack *sp, const emxArray_real_T *a,
                const real_T b_data[], int32_T b_size, emxArray_real_T *c);

/* End of code generation (ixfun.h) */
