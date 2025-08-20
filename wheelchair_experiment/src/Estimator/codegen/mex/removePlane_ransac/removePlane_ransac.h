/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_ransac.h
 *
 * Code generation for function 'removePlane_ransac'
 *
 */

#pragma once

/* Include files */
#include "removePlane_ransac_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void removePlane_ransac(const emlrtStack *sp, const emxArray_real_T *data,
                        real_T sampleSize, real_T maxDistance,
                        real_T model_data[], int32_T model_size[2],
                        emxArray_boolean_T *inlierIdx);

void removePlane_ransac_anonFcn2(const emlrtStack *sp, const real_T model[2],
                                 const emxArray_real_T *points,
                                 emxArray_real_T *varargout_1);

/* End of code generation (removePlane_ransac.h) */
