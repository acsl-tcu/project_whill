/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constvel.h
 *
 * Code generation for function 'constvel'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void binary_expand_op(real_T in1_data[], int32_T in1_size[2],
                      const real_T in2_data[], const int32_T in2_size[2],
                      int32_T in3);

void constvel(const emlrtStack *sp, real_T state[6], real_T varargin_2);

void plus(real_T in1_data[], int32_T in1_size[2], const real_T in2_data[],
          const int32_T in2_size[2]);

/* End of code generation (constvel.h) */
