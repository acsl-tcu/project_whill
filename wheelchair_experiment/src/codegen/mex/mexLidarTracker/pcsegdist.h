//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pcsegdist.h
//
//  Code generation for function 'pcsegdist'
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
}

// Function Declarations
namespace coder
{
  void pcsegdist(const emlrtStack *sp, b_pointCloud *ptCloud, real_T minDistance,
                 ::coder::array<uint32_T, 1U> &labels, real32_T *numClusters);
}

// End of code generation (pcsegdist.h)
