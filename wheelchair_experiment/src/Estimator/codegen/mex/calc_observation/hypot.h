/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * hypot.h
 *
 * Code generation for function 'hypot'
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
void b_hypot(const emlrtStack *sp, const emxArray_real_T *x,
             const emxArray_real_T *y, emxArray_real_T *r);

/* End of code generation (hypot.h) */
