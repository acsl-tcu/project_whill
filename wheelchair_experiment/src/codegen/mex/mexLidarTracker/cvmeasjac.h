//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cvmeasjac.h
//
//  Code generation for function 'cvmeasjac'
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
  void cvmeasjac(const emlrtStack *sp, const real_T state[6], real_T jacobian[18]);
}

// End of code generation (cvmeasjac.h)
