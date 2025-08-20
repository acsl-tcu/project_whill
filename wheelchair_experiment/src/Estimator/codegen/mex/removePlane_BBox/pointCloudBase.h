/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pointCloudBase.h
 *
 * Code generation for function 'pointCloudBase'
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
void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                              const emxArray_uint8_T *b_value);

void pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *b_value);

/* End of code generation (pointCloudBase.h) */
