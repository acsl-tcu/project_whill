/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkLinearInputs.h
 *
 * Code generation for function 'checkLinearInputs'
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
real_T checkLinearInputs(const emlrtStack *sp, const real_T Aineq[5],
                         real_T bineq, const real_T lb[5], const real_T ub[5]);

/* End of code generation (checkLinearInputs.h) */
