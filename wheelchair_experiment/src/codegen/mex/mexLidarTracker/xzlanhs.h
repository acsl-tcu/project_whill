//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlanhs.h
//
//  Code generation for function 'xzlanhs'
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
  namespace internal
  {
    namespace reflapack
    {
      real_T xzlanhs(const emlrtStack *sp, const creal_T A[9], int32_T ilo,
                     int32_T ihi);
    }
  }
}

// End of code generation (xzlanhs.h)
