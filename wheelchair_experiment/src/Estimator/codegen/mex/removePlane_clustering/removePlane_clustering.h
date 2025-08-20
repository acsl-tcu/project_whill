/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * removePlane_clustering.h
 *
 * Code generation for function 'removePlane_clustering'
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
void removePlane_clustering(const emlrtStack *sp,
                            const emxArray_real_T *ptCloudLocation,
                            const real_T roi[6], real_T minDistance,
                            const real_T rangeCP[2], emxArray_real_T *notGround,
                            emxArray_uint32_T *labels, real_T *numClusters);

/* End of code generation (removePlane_clustering.h) */
