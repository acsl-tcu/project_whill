//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xswap.h
//
//  Code generation for function 'xswap'
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
    namespace blas
    {
      void b_xswap(real_T x[9], int32_T ix0, int32_T iy0);
      void xswap(real_T x[36], int32_T ix0, int32_T iy0);
    }
  }
}

// End of code generation (xswap.h)
