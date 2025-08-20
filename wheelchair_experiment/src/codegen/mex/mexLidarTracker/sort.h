//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sort.h
//
//  Code generation for function 'sort'
//


#pragma once

// Include files
#include "rtwtypes.h"
#include "coder_array.h"
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
    void sort(const emlrtStack *sp, ::coder::array<uint32_T, 1U> &x);
    void sort(const emlrtStack *sp, ::coder::array<real_T, 2U> &x, ::coder::
              array<int32_T, 2U> &idx);
  }
}

// End of code generation (sort.h)
