/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predictTrackFilter.h
 *
 * Code generation for function 'predictTrackFilter'
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
void predictTrackFilter(const emlrtStack *sp, trackingEKF *filter, real_T dt);

/* End of code generation (predictTrackFilter.h) */
