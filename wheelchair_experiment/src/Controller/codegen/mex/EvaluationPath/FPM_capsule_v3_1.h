/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FPM_capsule_v3_1.h
 *
 * Code generation for function 'FPM_capsule_v3_1'
 *
 */

#pragma once

/* Include files */
#include "EvaluationPath_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T FPM_capsule_v3_1(const emlrtStack *sp, real_T obj_ObsNum,
                        real_T obj_wheel_width, real_T obj_wheel_len_front,
                        real_T x, real_T y, real_T th,
                        const real_T obs_now_data[],
                        const int32_T obs_now_size[2], const real_T target[2],
                        real_T param_FPM_eta, real_T param_FPM_alpha,
                        real_T param_FPM_margin, real_T param_FPM_obs_cost,
                        emxArray_real_T *phi_o);

/* End of code generation (FPM_capsule_v3_1.h) */
