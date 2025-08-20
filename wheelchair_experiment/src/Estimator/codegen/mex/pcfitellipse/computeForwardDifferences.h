/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeForwardDifferences.h
 *
 * Code generation for function 'computeForwardDifferences'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
boolean_T computeForwardDifferences(const emlrtStack *sp, l_struct_T *obj,
                                    real_T fCurrent,
                                    const real_T cIneqCurrent[2], real_T xk[5],
                                    real_T gradf[8], real_T JacCineqTrans[16],
                                    const real_T lb[5], const real_T ub[5]);

/* End of code generation (computeForwardDifferences.h) */
