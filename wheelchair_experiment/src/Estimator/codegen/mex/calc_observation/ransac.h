/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ransac.h
 *
 * Code generation for function 'ransac'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_internal_types.h"
#include "calc_observation_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void ransac(const emlrtStack *sp, const emxArray_real_T *data,
            const real_T fitFun_workspace_a0[5],
            const real_T fitFun_workspace_A[5], real_T fitFun_workspace_B,
            const real_T fitFun_workspace_lb[5],
            const real_T fitFun_workspace_ub[5],
            const real_T c_fitFun_workspace_nonlcon_work[2],
            real_T d_fitFun_workspace_nonlcon_work,
            real_T e_fitFun_workspace_nonlcon_work,
            real_T f_fitFun_workspace_nonlcon_work, real_T sampleSize,
            real_T maxDistance, real_T varargin_2, real_T varargin_4,
            real_T varargin_6, const e_struct_T *varargin_8_workspace,
            real_T model_data[], int32_T model_size[2],
            emxArray_boolean_T *inlierIdx);

/* End of code generation (ransac.h) */
