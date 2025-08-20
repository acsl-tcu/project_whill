//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker.h
//
//  Code generation for function 'mexLidarTracker'
//


#pragma once

// Include files
#include "mexLidarTracker_types.h"
#include "objectDetection.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void b_detectableTracksInput_not_emp();
void currentNumTracks_not_empty_init();
void mexLidarTracker(const emlrtStack *sp, const coder::array<real32_T, 2U>
                     &ptCloudLocations, real_T b_time, const struct0_T *Plant,
                     const real_T wall[6], real_T axis, real_T SP, coder::array<
                     coder::objectDetection, 2U> &detections, coder::array<
                     real_T, 1U> &obstacleIndices, coder::array<real_T, 1U>
                     &groundIndices, coder::array<real_T, 1U> &croppedIndices,
                     struct1_T confirmedTracks_data[], int32_T
                     confirmedTracks_size[1], real_T modelProbs_data[], int32_T
                     modelProbs_size[2], real32_T *numClusters, coder::array<
                     uint32_T, 1U> &labels);
void mexLidarTracker_free();
void mexLidarTracker_init();

// End of code generation (mexLidarTracker.h)
