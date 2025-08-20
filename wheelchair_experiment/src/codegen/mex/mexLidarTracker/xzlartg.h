//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  xzlartg.h
//
//  Code generation for function 'xzlartg'
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
  namespace internal
  {
    namespace reflapack
    {
      void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                   real_T *cs, creal_T *sn);
      void xzlartg(const emlrtStack *sp, const creal_T f, const creal_T g,
                   real_T *cs, creal_T *sn, creal_T *r);
    }
  }
}

// End of code generation (xzlartg.h)
