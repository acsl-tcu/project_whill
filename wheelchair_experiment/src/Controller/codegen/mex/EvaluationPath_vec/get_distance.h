/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * get_distance.h
 *
 * Code generation for function 'get_distance'
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
void get_distance(const emlrtStack *sp, const emxArray_real_T *A,
                  const emxArray_real_T *B, const emxArray_real_T *P,
                  emxArray_real_T *distance);

/* End of code generation (get_distance.h) */
