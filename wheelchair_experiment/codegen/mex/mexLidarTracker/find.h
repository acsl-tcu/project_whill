/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
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
void b_binary_expand_op(const emlrtStack *sp, emxArray_int32_T *in1,
                        const emlrtRSInfo in2, const emxArray_boolean_T *in3,
                        const emxArray_boolean_T *in4);

void b_eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
                emxArray_int32_T *i);

void c_eml_find(const boolean_T x[30], int32_T i_data[], int32_T i_size[2]);

void d_eml_find(const boolean_T x[20], int32_T i_data[], int32_T i_size[2]);

void eml_find(const emlrtStack *sp, const emxArray_boolean_T *x,
              emxArray_int32_T *i);

/* End of code generation (find.h) */
