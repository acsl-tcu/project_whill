//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  validateAndParseRansacInputs.h
//
//  Code generation for function 'validateAndParseRansacInputs'
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
  namespace vision
  {
    namespace internal
    {
      namespace ransac
      {
        void validateAndParseRansacInputs(const emlrtStack *sp, b_pointCloud
          *varargin_1, real_T varargin_2, const real_T varargin_3[3], real_T
          varargin_4, const ::coder::array<uint32_T, 1U> &varargin_6,
          b_pointCloud **ptCloud, real_T *ransacParams_maxDistance, real_T
          *ransacParams_maxNumTrials, real_T *ransacParams_confidence, ::coder::
          array<real_T, 2U> &sampleIndices, real_T referenceVector_data[],
          int32_T referenceVector_size[2], real_T *maxAngularDistance);
      }
    }
  }
}

// End of code generation (validateAndParseRansacInputs.h)
