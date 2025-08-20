//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  dot.h
//
//  Code generation for function 'dot'
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
  void dot(const real_T a_data[], const real32_T b[3], real32_T c_data[],
           int32_T c_size[2]);
}

// End of code generation (dot.h)
