//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// determine_target_location_gpu_types.h
//
// Code generation for function 'determine_target_location_gpu'
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
struct emxArray_real_T_50x2 {
  real_T data[100];
  int32_T size[2];
};

struct emxArray_real_T_21x10000 {
  real_T data[210000];
  int32_T size[2];
};

struct struct0_T {
  real_T NP;
  real_T K;
  emxArray_real_T_50x2 waypoint;
  emxArray_real_T_21x10000 target_n;
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

struct c_determine_target_location_gpu {
  struct0_T obj;
};

struct d_determine_target_location_gpu {
  c_determine_target_location_gpu f0;
};

// End of code generation (determine_target_location_gpu_types.h)
