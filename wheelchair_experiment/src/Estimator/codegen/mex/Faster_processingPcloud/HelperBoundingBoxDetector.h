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
#include "Faster_processingPcloud_internal_types.h"
#include "Faster_processingPcloud_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T c_HelperBoundingBoxDetector_ste(
    const emlrtStack *sp, const HelperBoundingBoxDetector *obj,
    pointCloud *currentPointCloud, real_T Plant_X, real_T Plant_Y,
    real_T Plant_Z, real_T Plant_yaw, const real_T wall[6],
    emxArray_real_T *detBBoxes, emxArray_real_T *survivedIndices,
    emxArray_real_T *croppedIndices, emxArray_real_T *obstacleIndices,
    emxArray_real_T *groundIndices, emxArray_real_T *labels);

/* End of code generation (HelperBoundingBoxDetector.h) */
