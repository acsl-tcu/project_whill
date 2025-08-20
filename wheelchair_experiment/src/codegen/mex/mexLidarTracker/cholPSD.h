//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cholPSD.h
//
//  Code generation for function 'cholPSD'
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
        void b_cholPSD(const emlrtStack *sp, const real_T A[9], real_T value[9]);
        void cholPSD(const emlrtStack *sp, const real_T A[36], real_T value[36]);
      }
    }
  }
}

// End of code generation (cholPSD.h)
