//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  qrFactor.h
//
//  Code generation for function 'qrFactor'
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
        void qrFactor(const emlrtStack *sp, const real_T A[36], real_T S[36],
                      const real_T Ns[18]);
      }
    }
  }
}

// End of code generation (qrFactor.h)
