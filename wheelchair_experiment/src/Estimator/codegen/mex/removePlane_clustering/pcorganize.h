/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcorganize.h
 *
 * Code generation for function 'pcorganize'
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
pointCloud *pcorganizeImpl(const emlrtStack *sp, const pointCloud *ptCloud,
                           const real_T vbeamAngles_data[],
                           const real_T hbeamAngles[1024], pointCloud *iobj_0);

/* End of code generation (pcorganize.h) */
