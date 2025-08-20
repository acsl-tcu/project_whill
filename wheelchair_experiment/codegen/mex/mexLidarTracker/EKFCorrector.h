/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EKFCorrector.h
 *
 * Code generation for function 'EKFCorrector'
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
void c_EKFCorrector_correctStateAndC(const emlrtStack *sp, real_T x[6],
                                     real_T P[36], const real_T y[3],
                                     const real_T Pxy[18], const real_T Pyy[9],
                                     const real_T dHdx[18], real_T gain[18]);

/* End of code generation (EKFCorrector.h) */
