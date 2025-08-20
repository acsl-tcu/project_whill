/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * unsafeSxfun.h
 *
 * Code generation for function 'unsafeSxfun'
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
void binary_expand_op_25(const emlrtStack *sp, emxArray_real_T *in1,
                         const real_T in3_data[], const int32_T in3_size[3],
                         const emxArray_real_T *in4);

void binary_expand_op_28(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3,
                         const emxArray_real_T *in4);

void binary_expand_op_30(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3);

void binary_expand_op_38(const emlrtStack *sp, emxArray_real_T *in1,
                         const emxArray_real_T *in3);

/* End of code generation (unsafeSxfun.h) */
