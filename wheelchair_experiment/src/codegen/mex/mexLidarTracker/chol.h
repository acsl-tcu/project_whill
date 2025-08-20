//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  chol.h
//
//  Code generation for function 'chol'
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
  int32_T cholesky(const emlrtStack *sp, real_T A_data[], int32_T A_size[2]);
}

// End of code generation (chol.h)
