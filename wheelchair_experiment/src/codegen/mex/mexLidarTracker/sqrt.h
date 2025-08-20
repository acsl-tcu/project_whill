//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  sqrt.h
//
//  Code generation for function 'sqrt'
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
  void b_sqrt(const emlrtStack *sp, real_T x_data[], const int32_T x_size[2]);
  void b_sqrt(creal_T *x);
}

// End of code generation (sqrt.h)
