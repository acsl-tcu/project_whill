//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  svdPSD.h
//
//  Code generation for function 'svdPSD'
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

// Function Declarations
namespace coder
{
  namespace matlabshared
  {
    namespace tracking
    {
      namespace internal
      {
        void svdPSD(const emlrtStack *sp, const real_T A[9], real_T R[9]);
      }
    }
  }
}

// End of code generation (svdPSD.h)
