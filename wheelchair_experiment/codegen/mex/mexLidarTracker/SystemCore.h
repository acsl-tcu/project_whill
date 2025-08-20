/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * SystemCore.h
 *
 * Code generation for function 'SystemCore'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_internal_types.h"
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real32_T SystemCore_step(const emlrtStack *sp, HelperBoundingBoxDetector *obj,
                         pointCloud *varargin_1, real_T varargin_2,
                         real_T varargin_3_X, real_T varargin_3_Y,
                         real_T varargin_3_yaw, const real_T varargin_4[6],
                         real_T varargin_5, real_T varargin_6,
                         emxArray_objectDetection *varargout_1,
                         emxArray_real_T *varargout_2,
                         emxArray_real_T *varargout_3,
                         emxArray_uint32_T *varargout_5);

void b_SystemCore_setup(const emlrtStack *sp,
                        e_matlabshared_tracking_interna *obj,
                        const emxArray_objectDetection *varargin_1);

int32_T b_SystemCore_step(const emlrtStack *sp, trackerJPDA *obj,
                          const emxArray_objectDetection *varargin_1,
                          real_T varargin_2, const real_T varargin_3_data[],
                          const int32_T varargin_3_size[2],
                          struct1_T varargout_1_data[],
                          struct1_T varargout_2_data[],
                          struct1_T varargout_3_data[],
                          int32_T *varargout_2_size, int32_T *varargout_3_size);

/* End of code generation (SystemCore.h) */
