/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeGradLag.h
 *
 * Code generation for function 'computeGradLag'
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
void b_computeGradLag(const emlrtStack *sp, real_T workspace[120], int32_T nVar,
                      const real_T grad[8], const real_T AineqTrans[16],
                      const int32_T finiteFixed[8], int32_T mFixed,
                      const int32_T finiteLB[8], int32_T mLB,
                      const int32_T finiteUB[8], int32_T mUB,
                      const real_T lambda[15]);

void computeGradLag(const emlrtStack *sp, real_T workspace[8], int32_T nVar,
                    const real_T grad[8], const real_T AineqTrans[16],
                    const int32_T finiteFixed[8], int32_T mFixed,
                    const int32_T finiteLB[8], int32_T mLB,
                    const int32_T finiteUB[8], int32_T mUB,
                    const real_T lambda[15]);

/* End of code generation (computeGradLag.h) */
