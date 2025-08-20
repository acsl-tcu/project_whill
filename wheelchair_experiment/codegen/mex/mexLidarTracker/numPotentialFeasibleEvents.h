/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * numPotentialFeasibleEvents.h
 *
 * Code generation for function 'numPotentialFeasibleEvents'
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
int32_T numPotentialFeasibleEvents(const emlrtStack *sp,
                                   const emxArray_boolean_T *validationMatrix,
                                   int32_T numMeas, int32_T numTracks);

/* End of code generation (numPotentialFeasibleEvents.h) */
