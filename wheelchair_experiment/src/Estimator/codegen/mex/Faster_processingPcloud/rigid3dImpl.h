/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * rigid3dImpl.h
 *
 * Code generation for function 'rigid3dImpl'
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
boolean_T c_rigid3dImpl_isTransformationM(const emlrtStack *sp,
                                          const real_T T[16]);

void validateRotationMatrix(const emlrtStack *sp, const real_T rot[9]);

void validateTranslationVector(const emlrtStack *sp, const real_T trans[3]);

/* End of code generation (rigid3dImpl.h) */
