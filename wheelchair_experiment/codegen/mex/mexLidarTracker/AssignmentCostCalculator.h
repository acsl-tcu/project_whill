/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * AssignmentCostCalculator.h
 *
 * Code generation for function 'AssignmentCostCalculator'
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
void c_AssignmentCostCalculator_find(
    const emlrtStack *sp, d_matlabshared_tracking_interna *tracks[30],
    const emxArray_objectDetection *detections, int32_T numLiveTracks,
    const emxArray_uint32_T *detIndices, emxArray_boolean_T *toCalculate);

void c_AssignmentCostCalculator_vali(const emlrtStack *sp,
                                     int32_T numLiveTracks);

/* End of code generation (AssignmentCostCalculator.h) */
