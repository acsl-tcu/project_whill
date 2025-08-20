/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ExtendedKalmanFilter.h
 *
 * Code generation for function 'ExtendedKalmanFilter'
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
trackingEKF *ExtendedKalmanFilter_clone(const trackingEKF *EKF,
                                        trackingEKF *iobj_0);

void c_ExtendedKalmanFilter_set_Meas(const emlrtStack *sp, trackingEKF *obj,
                                     real_T b_value[9]);

void c_ExtendedKalmanFilter_set_Stat(const emlrtStack *sp, trackingEKF *obj,
                                     real_T b_value[36]);

void c_ExtendedKalmanFilter_validate(const emlrtStack *sp, trackingEKF *obj);

/* End of code generation (ExtendedKalmanFilter.h) */
