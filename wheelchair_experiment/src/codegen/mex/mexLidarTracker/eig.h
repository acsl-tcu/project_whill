//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  eig.h
//
//  Code generation for function 'eig'
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
  void b_eig(const emlrtStack *sp, const real_T A[36], creal_T V[6]);
  void eig(const emlrtStack *sp, const real_T A[9], creal_T V[3]);
}

// End of code generation (eig.h)
