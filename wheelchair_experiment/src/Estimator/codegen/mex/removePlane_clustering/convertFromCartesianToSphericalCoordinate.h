/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * convertFromCartesianToSphericalCoordinate.h
 *
 * Code generation for function 'convertFromCartesianToSphericalCoordinate'
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
void c_convertFromCartesianToSpheric(const emlrtStack *sp,
                                     const emxArray_real_T *xyzData,
                                     emxArray_real_T *rangeData);

/* End of code generation (convertFromCartesianToSphericalCoordinate.h) */
