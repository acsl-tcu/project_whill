/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unique.h
 *
 * Code generation for function 'unique'
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
void b_unique_vector(const emlrtStack *sp, const emxArray_real_T *a,
                     emxArray_real_T *b);

void unique_vector(const emlrtStack *sp, const emxArray_uint32_T *a,
                   emxArray_uint32_T *b);

/* End of code generation (unique.h) */
