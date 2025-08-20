//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mexLidarTracker_types.h
//
//  Code generation for function 'mexLidarTracker'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T
{
  real_T X;
  real_T Y;
  real_T yaw;
};

class empty
{
};

struct struct1_T
{
  uint32_T TrackID;
  uint32_T BranchID;
  uint32_T SourceIndex;
  real_T UpdateTime;
  uint32_T Age;
  real_T State[6];
  real_T StateCovariance[36];
  real_T ObjectClassID;
  char_T TrackLogic[7];
  boolean_T TrackLogicState[10];
  boolean_T IsConfirmed;
  boolean_T IsCoasted;
  boolean_T IsSelfReported;
  coder::bounded_array<empty, 20U, 2U> ObjectAttributes;
};

// End of code generation (mexLidarTracker_types.h)
