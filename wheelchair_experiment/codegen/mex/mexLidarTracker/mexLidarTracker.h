/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * mexLidarTracker.h
 *
 * Code generation for function 'mexLidarTracker'
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
void b_detectableTracksInput_not_emp(void);

void currentNumTracks_not_empty_init(void);

void mexLidarTracker(const emlrtStack *sp,
                     const emxArray_real32_T *ptCloudLocations, real_T b_time,
                     const struct0_T *Plant, const real_T wall[6], real_T axis,
                     real_T SP, emxArray_objectDetection *detections,
                     emxArray_real_T *obstacleIndices,
                     emxArray_real_T *croppedIndices,
                     struct1_T confirmedTracks_data[],
                     int32_T confirmedTracks_size[1], real_T modelProbs_data[],
                     int32_T modelProbs_size[2], real32_T *numClusters,
                     emxArray_uint32_T *labels);

void mexLidarTracker_free(const emlrtStack *sp);

void mexLidarTracker_init(const emlrtStack *sp);

/* End of code generation (mexLidarTracker.h) */
