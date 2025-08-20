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
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real32_T pcsegdist(const emlrtStack *sp, const pointCloud *ptCloud,
                   real_T minDistance, emxArray_uint32_T *labels);

/* End of code generation (pcsegdist.h) */
