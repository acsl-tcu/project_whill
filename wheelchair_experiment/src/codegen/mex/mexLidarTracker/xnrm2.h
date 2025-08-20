//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xnrm2.h
//
//  Code generation for function 'xnrm2'
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
      real_T b_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[36],
                     int32_T ix0);
      real_T c_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[6], int32_T
                     ix0);
      real_T d_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[54],
                     int32_T ix0);
      real_T e_xnrm2(const emlrtStack *sp, int32_T n, const real_T x[27],
                     int32_T ix0);
      real_T xnrm2(int32_T n, const real_T x[3]);
      real_T xnrm2(const emlrtStack *sp, const real_T x[3], int32_T ix0);
      real_T xnrm2(const emlrtStack *sp, int32_T n, const real_T x[9], int32_T
                   ix0);
    }
  }
}

// End of code generation (xnrm2.h)
