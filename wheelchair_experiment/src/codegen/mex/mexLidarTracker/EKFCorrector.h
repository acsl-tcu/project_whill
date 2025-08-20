//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EKFCorrector.h
//
//  Code generation for function 'EKFCorrector'
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

// Type Definitions
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        class EKFCorrector
        {
         public:
          static void residual(const emlrtStack *sp, const real_T z[3], const
                               real_T Rs[9], const real_T x[6], const real_T S
                               [36], real_T res[3], real_T b_S[9]);
          static void correctjpda(const emlrtStack *sp, const ::coder::array<
            real_T, 2U> &z, const ::coder::array<real_T, 1U> &beta, const real_T
            zcov[9], real_T x[6], real_T P[36]);
          static void correctjpda(const emlrtStack *sp, const real_T z[3], const
            real_T zcov[9], real_T x[6], real_T P[36]);
        };
      }
    }
  }
}

// End of code generation (EKFCorrector.h)
