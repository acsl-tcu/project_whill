//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  cvmeas.h
//
//  Code generation for function 'cvmeas'
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
  void cvmeas(const emlrtStack *sp, const real_T state[6], real_T measurement[3]);
}

// End of code generation (cvmeas.h)
