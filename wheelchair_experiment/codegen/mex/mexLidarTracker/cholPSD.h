/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cholPSD.h
 *
 * Code generation for function 'cholPSD'
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
void b_cholPSD(const emlrtStack *sp, const real_T A[9], real_T b_value[9]);

void cholPSD(const emlrtStack *sp, const real_T A[36], real_T b_value[36]);

/* End of code generation (cholPSD.h) */
