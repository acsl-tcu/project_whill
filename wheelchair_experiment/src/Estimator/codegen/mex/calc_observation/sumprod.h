/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sumprod.h
 *
 * Code generation for function 'sumprod'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T binary_expand_op(const emlrtStack *sp, const emlrtRSInfo in1,
                        const emxArray_real_T *in2, const emxArray_real_T *in3);

/* End of code generation (sumprod.h) */
