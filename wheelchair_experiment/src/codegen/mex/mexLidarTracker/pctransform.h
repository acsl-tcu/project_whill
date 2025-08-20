//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  pctransform.h
//
//  Code generation for function 'pctransform'
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
  class b_pointCloud;
  class rigid3d;
}

// Function Declarations
namespace coder
{
  b_pointCloud *pctransform(const emlrtStack *sp, const b_pointCloud *ptCloudIn,
    const rigid3d *tform, b_pointCloud *iobj_0);
}

// End of code generation (pctransform.h)
