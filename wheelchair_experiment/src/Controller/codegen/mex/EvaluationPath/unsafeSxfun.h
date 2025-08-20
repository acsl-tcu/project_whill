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
#include "EvaluationPath_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void binary_expand_op_14(real_T in1_data[], int32_T *in1_size,
                         const real_T in3_data[], const int32_T *in3_size);

void binary_expand_op_9(const emlrtStack *sp, emxArray_real_T *in1,
                        const real_T in3_data[], const int32_T *in3_size,
                        const real_T in4_data[], const int32_T *in4_size);

/* End of code generation (unsafeSxfun.h) */
