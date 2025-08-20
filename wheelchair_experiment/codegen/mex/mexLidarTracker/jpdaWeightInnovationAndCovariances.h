/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * jpdaWeightInnovationAndCovariances.h
 *
 * Code generation for function 'jpdaWeightInnovationAndCovariances'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void c_jpdaWeightInnovationAndCovari(const emlrtStack *sp,
                                     const emxArray_real_T *z,
                                     const real_T zEstimated[3],
                                     const emxArray_real_T *beta,
                                     const real_T wrapping[6], real_T y[3],
                                     real_T yy[9]);

/* End of code generation (jpdaWeightInnovationAndCovariances.h) */
