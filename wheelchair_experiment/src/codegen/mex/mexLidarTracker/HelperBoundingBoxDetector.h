//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  HelperBoundingBoxDetector.h
//
//  Code generation for function 'HelperBoundingBoxDetector'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Declarations
namespace coder
{
  class b_pointCloud;
  class objectDetection;
}

// Type Definitions
class HelperBoundingBoxDetector
{
 public:
  HelperBoundingBoxDetector *init();
  boolean_T isLockedAndNotReleased() const;
  void step(const emlrtStack *sp, coder::b_pointCloud *varargin_1, real_T
            varargin_2, real_T varargin_3_X, real_T varargin_3_Y, real_T
            varargin_3_yaw, const real_T varargin_4[6], real_T varargin_5,
            real_T varargin_6, coder::array<coder::objectDetection, 2U>
            &varargout_1, coder::array<real_T, 1U> &varargout_2, coder::array<
            real_T, 1U> &varargout_3, coder::array<real_T, 1U> &varargout_4,
            real32_T *varargout_5, coder::array<uint32_T, 1U> &varargout_6);
  void setupAndReset(const emlrtStack *sp);
  void setup(const emlrtStack *sp);
 private:
  static void getBoundingBoxes(const emlrtStack *sp, coder::b_pointCloud
    *ptCloud, real_T minDistance, real_T minDetsPerCluster, real_T maxZDistance,
    real_T minZDistance, real_T Plant_X, real_T Plant_Y, real_T Plant_yaw,
    real_T b_time, real_T SP, coder::array<real_T, 2U> &bboxes, real32_T
    *numClusters, coder::array<uint32_T, 1U> &labels);
 public:
  real_T GroundMaxDistance;
  real_T GroundReferenceVector[3];
  real_T roi[6];
  real_T GroundMaxAngularDistance;
  real_T SegmentationMinDistance;
  real_T MinDetectionsPerCluster;
  real_T MaxZDistanceCluster;
  real_T MinZDistanceCluster;
  real_T MeasurementNoise[9];
 private:
  int32_T isInitialized;
};

// End of code generation (HelperBoundingBoxDetector.h)
