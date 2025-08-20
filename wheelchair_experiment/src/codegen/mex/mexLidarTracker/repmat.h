//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  repmat.h
//
//  Code generation for function 'repmat'
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
  void b_repmat(const emlrtStack *sp, const ::coder::array<boolean_T, 2U> &a,
                const real_T varargin_1[3], ::coder::array<boolean_T, 3U> &b);
  void repmat(const emlrtStack *sp, const real_T a_data[], const int32_T a_size
              [2], const real_T varargin_1[2], real_T b_data[], int32_T b_size[2]);
}

// End of code generation (repmat.h)
