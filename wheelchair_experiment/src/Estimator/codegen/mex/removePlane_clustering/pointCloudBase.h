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
#include "removePlane_clustering_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                                const emxArray_uint8_T *b_value);

void b_pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *this,
                                    const emxArray_real_T *b_value);

void pointCloudBase_set_Color(const emlrtStack *sp, pointCloud *this,
                              const emxArray_uint8_T *b_value);

void pointCloudBase_set_Intensity(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *b_value);

void pointCloudBase_set_Normal(const emlrtStack *sp, pointCloud *this,
                               const emxArray_real_T *b_value);

void pointCloudBase_set_RangeData(const emlrtStack *sp, pointCloud *this,
                                  const emxArray_real_T *b_value);

void pointCloudBase_subsetImpl(const emlrtStack *sp, const pointCloud *this,
                               const emxArray_real_T *indices,
                               emxArray_real_T *loc, emxArray_uint8_T *c,
                               emxArray_real_T *nv, emxArray_real_T *intensity,
                               emxArray_real_T *r);

/* End of code generation (pointCloudBase.h) */
