//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// EvaluationPath_GPU.h
//
// Code generation for function 'EvaluationPath_GPU'
//

#pragma once

// Include files
#include "EvaluationPath_GPU_types.h"
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
void EvaluationPath_GPU(const struct0_T *obj, const real_T px[63000],
                        const real_T pu[42000], const cell_wrap_0 preobs[22],
                        emxArray_real_T *pw, emxArray_boolean_T *remove_sample);

// End of code generation (EvaluationPath_GPU.h)
