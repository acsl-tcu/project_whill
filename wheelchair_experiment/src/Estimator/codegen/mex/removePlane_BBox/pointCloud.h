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
#include "removePlane_BBox_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
pointCloud *pointCloud_pointCloud(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *varargin_1);

pointCloud *pointCloud_removeInvalidPoints(const emlrtStack *sp,
                                           const pointCloud *this,
                                           pointCloud *iobj_0);

/* End of code generation (pointCloud.h) */
