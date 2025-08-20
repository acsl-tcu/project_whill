/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcsegdist.h
 *
 * Code generation for function 'pcsegdist'
 *
 */

#pragma once

/* Include files */
#include "removePlane_clustering_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T pcsegdist(const emlrtStack *sp, pointCloud *ptCloud, real_T minDistance,
                 const real_T varargin_2[2], emxArray_uint32_T *labels);

/* End of code generation (pcsegdist.h) */
