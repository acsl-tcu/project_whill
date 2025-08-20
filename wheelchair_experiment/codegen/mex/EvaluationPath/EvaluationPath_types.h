//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EvaluationPath_types.h
//
//  Code generation for function 'EvaluationPath'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"

// Type Definitions
struct struct0_T
{
  real_T K;
  real_T NP;
  real_T ObsNum;
  real_T r_wheel;
  real_T r_obs;
  real_T R[2];
  real_T W;
  real_T Wo;
  real_T Vref;
  coder::array<real_T, 3U> limit;
  coder::array<real_T, 3U> target;
  real_T ltheta[16];
  real_T wall_penalty1;
  real_T wall_penalty2;
  real_T wall_threshold;
};

struct cell_wrap_0
{
  coder::bounded_array<real_T, 40U, 2U> f1;
};

// End of code generation (EvaluationPath_types.h)
