//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xdhseqr.h
//
//  Code generation for function 'xdhseqr'
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
      int32_T eml_dlahqr(const emlrtStack *sp, real_T h[36]);
    }
  }
}

// End of code generation (xdhseqr.h)
