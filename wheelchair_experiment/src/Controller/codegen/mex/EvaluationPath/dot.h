/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * dot.h
 *
 * Code generation for function 'dot'
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
int32_T dot(const emlrtStack *sp, const real_T a_data[],
            const int32_T a_size[2], const real_T b_data[],
            const int32_T b_size[2], real_T c_data[]);

/* End of code generation (dot.h) */
