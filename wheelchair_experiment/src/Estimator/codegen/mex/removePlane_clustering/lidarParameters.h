/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * lidarParameters.h
 *
 * Code generation for function 'lidarParameters'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T lidarParameters_lidarParameters(const emlrtStack *sp,
                                       real_T *this_VerticalResolution,
                                       real_T this_VerticalBeamAngles_data[],
                                       int32_T this_VerticalBeamAngles_size[2],
                                       real_T this_HorizontalBeamAngles[1024]);

/* End of code generation (lidarParameters.h) */
