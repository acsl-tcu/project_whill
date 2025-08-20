/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * calc_observation.h
 *
 * Code generation for function 'calc_observation'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void calc_observation(const emlrtStack *sp, const struct0_T *RANSAC,
                      real_T numAssignments, const uint32_T assignment_data[],
                      const int32_T assignment_size[2],
                      const real_T Xhbar_observed_ellipse_data[],
                      const int32_T Xhbar_observed_ellipse_size[2],
                      const cell_wrap_0 Pbar_observed_ellipse_data[],
                      const int32_T Pbar_observed_ellipse_size[1],
                      const emxArray_real_T *ObsptClouds, real_T doRANSAC,
                      const real_T R[25], const real_T Xhbar_observed_data[],
                      const int32_T Xhbar_observed_size[2],
                      const real_T trans[3], const struct1_T *Plant,
                      emxArray_real_T *isObserved, emxArray_struct2_T *model1);

emlrtCTX emlrtGetRootTLSGlobal(void);

void emlrtLockerFunction(EmlrtLockeeFunction aLockee, emlrtConstCTX aTLS,
                         void *aData);

int32_T getThreadID(void);

void initThreadID(const emlrtStack *sp);

/* End of code generation (calc_observation.h) */
