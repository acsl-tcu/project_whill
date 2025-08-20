//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xgerc.h
//
//  Code generation for function 'xgerc'
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
      void b_xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
                   int32_T ix0, const real_T y[3], real_T A[27], int32_T ia0);
      void xgerc(const emlrtStack *sp, int32_T m, int32_T n, real_T alpha1,
                 int32_T ix0, const real_T y[6], real_T A[54], int32_T ia0);
    }
  }
}

// End of code generation (xgerc.h)
