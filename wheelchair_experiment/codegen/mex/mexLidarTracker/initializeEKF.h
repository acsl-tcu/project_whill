/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initializeEKF.h
 *
 * Code generation for function 'initializeEKF'
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
trackingEKF *initializeEKF(const emlrtStack *sp,
                           const real_T Detection_Measurement[3],
                           const real_T Detection_pMeasurementNoise[9],
                           trackingEKF *iobj_0);

/* End of code generation (initializeEKF.h) */
