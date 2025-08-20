/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pctransform.h
 *
 * Code generation for function 'pctransform'
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
pointCloud *pctransform(const emlrtStack *sp, const pointCloud *ptCloudIn,
                        const real_T tform_AffineTform_T[16],
                        pointCloud *iobj_0);

/* End of code generation (pctransform.h) */
