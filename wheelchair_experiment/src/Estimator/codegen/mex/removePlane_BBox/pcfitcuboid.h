/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitcuboid.h
 *
 * Code generation for function 'pcfitcuboid'
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
real_T findBoundingBox(const emlrtStack *sp, const emxArray_real_T *X,
                       real_T boundingBox2d[5], real_T *score);

/* End of code generation (pcfitcuboid.h) */
