//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// _coder_WP_extraction_mex.h
//
// Code generation for function '_coder_WP_extraction_mex'
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
void WP_extraction_mexFunction(WP_extractionStackData *SD, int32_T nlhs,
                               mxArray *plhs[1], int32_T nrhs,
                               const mxArray *prhs[4]);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS();

// End of code generation (_coder_WP_extraction_mex.h)
