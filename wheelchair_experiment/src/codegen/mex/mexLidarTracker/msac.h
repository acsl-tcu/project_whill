//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  msac.h
//
//  Code generation for function 'msac'
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

// Function Declarations
namespace coder
{
  namespace vision
  {
    namespace internal
    {
      namespace ransac
      {
        void msac(const emlrtStack *sp, const ::coder::array<real32_T, 2U>
                  &allPoints, real_T params_maxDistance, const real_T
                  varargin_1_data[], real_T varargin_2, boolean_T *isFound,
                  real32_T bestModelParams_data[], int32_T bestModelParams_size
                  [2]);
      }
    }
  }
}

// End of code generation (msac.h)
