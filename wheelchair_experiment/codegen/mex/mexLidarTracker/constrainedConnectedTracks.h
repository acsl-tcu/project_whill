/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * constrainedConnectedTracks.h
 *
 * Code generation for function 'constrainedConnectedTracks'
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
int32_T constrainedConnectedTracks(const emlrtStack *sp,
                                   const emxArray_boolean_T *connMatrix,
                                   emxArray_int32_T *clustRows,
                                   int32_T clustCols_data[],
                                   int32_T clustCols_size[2],
                                   int32_T *currentMaxRowsPerCluster,
                                   int32_T *currentMaxColumnsPerCluster);

/* End of code generation (constrainedConnectedTracks.h) */
