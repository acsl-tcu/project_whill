//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// WP_extraction.h
//
// Code generation for function 'WP_extraction'
//

#pragma once

// Include files
#include "WP_extraction_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

// Function Declarations
void WP_extraction(const emlrtStack *sp, const struct0_T *obj,
                   const real_T px[63000], real_T i, real_T j,
                   real_T WPtemp_data[], int32_T WPtemp_size[2]);

// End of code generation (WP_extraction.h)
