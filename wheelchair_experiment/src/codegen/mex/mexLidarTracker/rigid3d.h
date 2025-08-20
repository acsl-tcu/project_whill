//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  rigid3d.h
//
//  Code generation for function 'rigid3d'
//


#pragma once

// Include files
#include "affine3d.h"
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
  class rigid3d
  {
   public:
    void init(const emlrtStack *sp, const real_T varargin_1[9], const real_T
              varargin_2[3]);
    void get_T(real_T T[16]) const;
   private:
    affine3d AffineTform;
  };
}

// End of code generation (rigid3d.h)
