//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xrot.h
//
//  Code generation for function 'xrot'
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
      void b_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                  int32_T iy0, real_T c, real_T s);
      void b_xrot(real_T x[9], int32_T ix0, int32_T iy0, real_T c, real_T s);
      void c_xrot(const emlrtStack *sp, int32_T n, real_T x[36], int32_T ix0,
                  int32_T iy0, real_T c, real_T s);
      void xrot(const emlrtStack *sp, int32_T n, real_T x[9], int32_T ix0,
                int32_T iy0, real_T c, real_T s);
      void xrot(int32_T n, real_T x[9], int32_T ix0, int32_T iy0, real_T c,
                real_T s);
      void xrot(real_T x[36], int32_T ix0, int32_T iy0, real_T c, real_T s);
    }
  }
}

// End of code generation (xrot.h)
