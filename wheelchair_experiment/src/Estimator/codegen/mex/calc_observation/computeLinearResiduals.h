/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeLinearResiduals.h
 *
 * Code generation for function 'computeLinearResiduals'
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
void computeLinearResiduals(const emlrtStack *sp, const real_T x[5],
                            int32_T nVar, real_T workspaceIneq[2],
                            const real_T AineqT[16], real_T bineq);

/* End of code generation (computeLinearResiduals.h) */
