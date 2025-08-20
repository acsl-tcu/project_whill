/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * JPDATracker.h
 *
 * Code generation for function 'JPDATracker'
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
int32_T JPDATracker_stepImpl(const emlrtStack *sp, trackerJPDA *obj,
                             const emxArray_objectDetection *detsIn,
                             real_T varargin_1, const real_T varargin_2_data[],
                             const int32_T varargin_2_size[2],
                             struct1_T varargout_1_data[],
                             struct1_T varargout_2_data[],
                             struct1_T varargout_3_data[],
                             int32_T *varargout_2_size,
                             int32_T *varargout_3_size);

void JPDATracker_validateInputsImpl(const emlrtStack *sp, real_T varargin_1);

/* End of code generation (JPDATracker.h) */
