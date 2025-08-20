//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFPredictorNonAdditive.h
//
//  Code generation for function 'EKFPredictorNonAdditive'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Type Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        class EKFPredictorNonAdditive
        {
         public:
          static void validateStateTransitionFcn(const emlrtStack *sp, const
            real_T x[6], real_T varargin_1);
          static void predict(const emlrtStack *sp, const real_T Qs[9], real_T
                              x[6], real_T S[36], real_T varargin_1);
        };
      }
    }
  }
}

// End of code generation (EKFPredictorNonAdditive.h)
