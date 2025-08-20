//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  EvaluationPath.h
//
//  Code generation for function 'EvaluationPath'
//


#pragma once

// Include files
#include "EvaluationPath_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void EvaluationPath(const emlrtStack *sp, const struct0_T *obj, const coder::
                    array<real_T, 3U> &px, const coder::array<real_T, 3U> &pu,
                    const cell_wrap_0 preobs[22], coder::array<real_T, 2U> &pw,
                    coder::array<boolean_T, 2U> &remove_sample);

// End of code generation (EvaluationPath.h)
