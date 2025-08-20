/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_pcfitellipse_init_mex.h
 *
 * Code generation for function '_coder_pcfitellipse_init_mex'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_init_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void pcfitellipse_init_mexFunction(pcfitellipse_initStackData *SD, int32_T nlhs,
                                   mxArray *plhs[2], int32_T nrhs,
                                   const mxArray *prhs[13]);

/* End of code generation (_coder_pcfitellipse_init_mex.h) */
