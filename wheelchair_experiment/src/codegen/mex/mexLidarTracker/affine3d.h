//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  affine3d.h
//
//  Code generation for function 'affine3d'
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

// Type Definitions
namespace coder
{
  class affine3d
  {
   public:
    void init(const emlrtStack *sp, const real_T A[16]);
    void set_T(const emlrtStack *sp, const real_T b_T[16]);
    real_T T[16];
  };
}

// End of code generation (affine3d.h)
