//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// determine_target_location_gpu.h
//
// Code generation for function 'determine_target_location_gpu'
//

#pragma once

// Include files
#include "determine_target_location_gpu_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Custom Header Code

#ifdef __CUDA_ARCH__
#undef printf
#endif

// Function Declarations
void determine_target_location_gpu(const struct0_T *cpu_obj,
                                   const real_T cpu_px_data[],
                                   const int32_T px_size[3],
                                   real_T cpu_tgt_n_data[],
                                   int32_T tgt_n_size[2]);

// End of code generation (determine_target_location_gpu.h)
