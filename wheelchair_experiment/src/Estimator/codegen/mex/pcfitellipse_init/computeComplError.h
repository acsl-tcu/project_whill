/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeComplError.h
 *
 * Code generation for function 'computeComplError'
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
real_T computeComplError(const emlrtStack *sp, const real_T xCurrent[5],
                         real_T cIneq, const int32_T finiteLB[7], int32_T mLB,
                         const real_T lb[5], const int32_T finiteUB[7],
                         int32_T mUB, const real_T ub[5],
                         const real_T lambda[13], int32_T iL0);

/* End of code generation (computeComplError.h) */
