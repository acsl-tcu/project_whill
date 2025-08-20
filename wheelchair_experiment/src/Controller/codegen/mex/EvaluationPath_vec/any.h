/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * any.h
 *
 * Code generation for function 'any'
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
void any(const emlrtStack *sp, const emxArray_boolean_T *x,
         emxArray_boolean_T *y);

void b_any(const emlrtStack *sp, const emxArray_boolean_T *x,
           emxArray_boolean_T *y);

/* End of code generation (any.h) */
