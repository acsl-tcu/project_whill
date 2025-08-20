//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// inpolygon.h
//
// Code generation for function 'inpolygon'
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
namespace coder {
void computeRange(const emlrtStack *sp, const real_T xv[4], int32_T nloops,
                  const int32_T first[4], const int32_T last[4], real_T *minxv,
                  real_T *maxxv);

void contrib(real_T x1, real_T b_y1, real_T x2, real_T y2, int8_T quad1,
             int8_T quad2, real_T scale, int8_T *diffQuad, boolean_T *onj);

} // namespace coder

// End of code generation (inpolygon.h)
