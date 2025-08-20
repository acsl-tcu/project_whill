/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * FPM_capsule_v3_3vec.h
 *
 * Code generation for function 'FPM_capsule_v3_3vec'
 *
 */

#pragma once

/* Include files */
#include "EvaluationPath_vec_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void FPM_capsule_v3_3vec(const emlrtStack *sp, real_T obj_K, real_T obj_NP,
                         real_T obj_ObsNum, real_T obj_wheel_width,
                         real_T obj_wheel_len_front,
                         const emxArray_real_T *obj_target_n,
                         const real_T obj_th_target_w_data[],
                         int32_T obj_th_target_w_size, const emxArray_real_T *x,
                         const emxArray_real_T *y, const emxArray_real_T *th,
                         const real_T obs_now_data[],
                         const int32_T obs_now_size[3], real_T param_FPM_eta,
                         real_T param_FPM_alpha, real_T param_FPM_margin,
                         emxArray_real_T *Grade);

/* End of code generation (FPM_capsule_v3_3vec.h) */
