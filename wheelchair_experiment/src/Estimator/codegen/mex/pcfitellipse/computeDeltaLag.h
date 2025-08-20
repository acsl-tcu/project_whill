/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeDeltaLag.h
 *
 * Code generation for function 'computeDeltaLag'
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
void computeDeltaLag(const emlrtStack *sp, int32_T nVar, real_T workspace[8],
                     const real_T grad[8], const real_T JacIneqTrans[16],
                     const real_T grad_old[8], const real_T JacIneqTrans_old[8],
                     const real_T lambda[15], int32_T ineqL0);

/* End of code generation (computeDeltaLag.h) */
