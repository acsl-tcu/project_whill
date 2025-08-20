/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Faster_processingPcloud.h
 *
 * Code generation for function 'Faster_processingPcloud'
 *
 */

#pragma once

/* Include files */
#include "Faster_processingPcloud_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Faster_processingPcloud(const emlrtStack *sp, const emxArray_real_T *pt,
                             real_T theta, const real_T trans[3],
                             const real_T roi[6], real_T distThreshold,
                             real_T b_time, emxArray_real_T *detections,
                             emxArray_real_T *survivedIndices,
                             emxArray_real_T *obstacleIndices,
                             emxArray_real_T *labels, real_T *numClusters);

void Faster_processingPcloud_init(void);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

/* End of code generation (Faster_processingPcloud.h) */
