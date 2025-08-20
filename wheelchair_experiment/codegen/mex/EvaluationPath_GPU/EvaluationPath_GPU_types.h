//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EvaluationPath_GPU_types.h
//
// Code generation for function 'EvaluationPath_GPU'
//

#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"

// Custom Header Code

#ifdef __CUDA_ARCH__
#undef printf
#endif

// Type Definitions
struct struct0_T {
  real_T K;
  real_T NP;
  real_T ObsNum;
  real_T r_wheel;
  real_T r_obs;
  real_T R[2];
  real_T W;
  real_T Vref;
  real_T limit[84000];
  real_T target[42000];
};

struct cell_wrap_0 {
  real_T f1[2];
};

struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct emxArray_boolean_T {
  boolean_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

struct EvaluationPath_GPU_api {
  struct0_T obj;
};

struct EvaluationPath_GPUStackData {
  EvaluationPath_GPU_api f0;
};

// End of code generation (EvaluationPath_GPU_types.h)
