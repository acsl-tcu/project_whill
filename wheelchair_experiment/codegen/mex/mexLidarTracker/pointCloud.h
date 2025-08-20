/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pointCloud.h
 *
 * Code generation for function 'pointCloud'
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
pointCloud *b_pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                    const emxArray_real32_T *varargin_1,
                                    const emxArray_uint8_T *varargin_3,
                                    const emxArray_real32_T *varargin_5,
                                    const emxArray_real32_T *varargin_7);

void c_pointCloud_findNeighborsInRad(const emlrtStack *sp, pointCloud *this,
                                     const real32_T varargin_1[3],
                                     real32_T varargin_2,
                                     emxArray_uint32_T *indices);

void pointCloud_buildKdtree(const emlrtStack *sp, pointCloud *this);

pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real32_T *varargin_1);

pointCloud *pointCloud_select(const emlrtStack *sp, const pointCloud *this,
                              const emxArray_real_T *varargin_1,
                              pointCloud *iobj_0);

/* End of code generation (pointCloud.h) */
