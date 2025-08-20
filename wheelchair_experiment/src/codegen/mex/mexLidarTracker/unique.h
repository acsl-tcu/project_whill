//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  unique.h
//
//  Code generation for function 'unique'
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
  void unique_vector(const emlrtStack *sp, const ::coder::array<uint32_T, 1U> &a,
                     ::coder::array<uint32_T, 1U> &b);
  void unique_vector(const emlrtStack *sp, const ::coder::array<real_T, 2U> &a, ::
                     coder::array<real_T, 2U> &b);
}

// End of code generation (unique.h)
