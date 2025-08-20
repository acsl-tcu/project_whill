//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  determine_target_location_types.h
//
//  Code generation for function 'determine_target_location'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T
{
  real_T NP;
  real_T K;
  coder::bounded_array<real_T, 100U, 2U> waypoint;
  coder::array<real_T, 2U> target_n;
  coder::array<real_T, 3U> target;
  coder::array<real_T, 3U> limit;
  coder::bounded_array<real_T, 200U, 2U> wall;
  coder::bounded_array<real_T, 150U, 2U> abc;
};

// End of code generation (determine_target_location_types.h)
