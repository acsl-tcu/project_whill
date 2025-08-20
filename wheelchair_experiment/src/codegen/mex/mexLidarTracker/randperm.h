//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  randperm.h
//
//  Code generation for function 'randperm'
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
  void randperm(const emlrtStack *sp, real_T n, real_T p_data[], int32_T p_size
                [2]);
}

// End of code generation (randperm.h)
