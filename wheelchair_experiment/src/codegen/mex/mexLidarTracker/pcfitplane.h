//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pcfitplane.h
//
//  Code generation for function 'pcfitplane'
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
  class planeModel;
}

// Function Declarations
namespace coder
{
  void evalPlane(const emlrtStack *sp, const real32_T model_data[], const
                 int32_T model_size[2], const ::coder::array<real32_T, 2U>
                 &points, ::coder::array<real32_T, 1U> &dis);
  void pcfitplane(const emlrtStack *sp, b_pointCloud *varargin_1, real_T
                  varargin_2, const real_T varargin_3[3], real_T varargin_4,
                  const ::coder::array<uint32_T, 1U> &varargin_6, planeModel
                  *iobj_0, planeModel **model, ::coder::array<real_T, 1U>
                  &inlierIndices, ::coder::array<real_T, 1U> &outlierIndices);
}

// End of code generation (pcfitplane.h)
