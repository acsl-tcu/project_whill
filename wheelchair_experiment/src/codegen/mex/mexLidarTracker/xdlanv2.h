//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xdlanv2.h
//
//  Code generation for function 'xdlanv2'
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
      void xdlanv2(real_T *a, real_T *b, real_T *c, real_T *d, real_T *rt1r,
                   real_T *rt1i, real_T *rt2r, real_T *rt2i, real_T *cs, real_T *
                   sn);
    }
  }
}

// End of code generation (xdlanv2.h)
