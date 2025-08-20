//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  initializeEKF.h
//
//  Code generation for function 'initializeEKF'
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

// Type Declarations
namespace coder
{
  class objectDetection;
  class trackingEKF;
}

// Function Declarations
coder::trackingEKF *initializeEKF(const emlrtStack *sp, const coder::
  objectDetection *Detection, coder::trackingEKF *iobj_0);

// End of code generation (initializeEKF.h)
