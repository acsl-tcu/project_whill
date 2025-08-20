//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mrdivide_helper.h
//
//  Code generation for function 'mrdivide_helper'
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
    void mrdiv(const emlrtStack *sp, const real_T A[3], const real_T B[9],
               real_T Y[3]);
  }
}

// End of code generation (mrdivide_helper.h)
