/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * HelperBoundingBoxDetector.h
 *
 * Code generation for function 'HelperBoundingBoxDetector'
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
void b_and(const emlrtStack *sp, emxArray_boolean_T *in1,
           const emxArray_boolean_T *in2);

real32_T getBoundingBoxes(const emlrtStack *sp, const pointCloud *ptCloud,
                          real_T minDistance, real_T minDetsPerCluster,
                          real_T maxZDistance, real_T minZDistance,
                          real_T Plant_X, real_T Plant_Y, real_T Plant_yaw,
                          real_T SP, emxArray_real_T *bboxes,
                          emxArray_uint32_T *labels);

/* End of code generation (HelperBoundingBoxDetector.h) */
