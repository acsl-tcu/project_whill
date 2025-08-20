/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * trackingEKF.h
 *
 * Code generation for function 'trackingEKF'
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
trackingEKF *trackingEKF_clone(trackingEKF *obj, trackingEKF *iobj_0);

void trackingEKF_correctjpda(const emlrtStack *sp, trackingEKF *filter,
                             const emxArray_real_T *z,
                             const emxArray_real_T *jpda);

void trackingEKF_models_anonFcn1(const emlrtStack *sp,
                                 const real_T state_data[],
                                 const int32_T state_size[2], real_T dt,
                                 real_T varargout_1_data[],
                                 int32_T varargout_1_size[2]);

void trackingEKF_nullify(const emlrtStack *sp, trackingEKF *EKF);

void trackingEKF_residual(const emlrtStack *sp, trackingEKF *EKF,
                          const real_T z[3], real_T res[3], real_T S[9]);

void trackingEKF_sync(const emlrtStack *sp, trackingEKF *EKF,
                      trackingEKF *EKF2);

/* End of code generation (trackingEKF.h) */
