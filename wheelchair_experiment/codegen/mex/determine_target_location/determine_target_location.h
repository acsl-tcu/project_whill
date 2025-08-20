//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  determine_target_location.h
//
//  Code generation for function 'determine_target_location'
//


#pragma once

// Include files
#include "determine_target_location_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void determine_target_location(const emlrtStack *sp, struct0_T *obj, const coder::
  array<real_T, 3U> &px, coder::array<real_T, 3U> &tgt, coder::array<real_T, 3U>
  &lim, coder::array<real_T, 2U> &tgt_n);

// End of code generation (determine_target_location.h)
