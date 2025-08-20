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
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void binary_expand_op_1(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3);

void binary_expand_op_2(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const emxArray_real_T *in4);

void binary_expand_op_3(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const real_T in4[5]);

void binary_expand_op_4(const emlrtStack *sp, emxArray_real_T *in1,
                        const emxArray_real_T *in3, const real_T in4[5]);

/* End of code generation (unsafeSxfun.h) */
