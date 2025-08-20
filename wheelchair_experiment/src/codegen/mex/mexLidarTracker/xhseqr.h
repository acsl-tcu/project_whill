//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xhseqr.h
//
//  Code generation for function 'xhseqr'
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
    namespace lapack
    {
      int32_T xhseqr(const emlrtStack *sp, real_T h[9]);
    }
  }
}

// End of code generation (xhseqr.h)
