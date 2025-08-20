/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * finDiffEvalAndChkErr.h
 *
 * Code generation for function 'finDiffEvalAndChkErr'
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
boolean_T finDiffEvalAndChkErr(
    const emlrtStack *sp, const emxArray_real_T *obj_objfun_workspace_points,
    const real_T obj_nonlin_workspace_COG_init[2],
    real_T obj_nonlin_workspace_Plant_X, real_T obj_nonlin_workspace_Plant_Y,
    real_T obj_nonlin_workspace_Plant_yaw, real_T *cIneqPlus, int32_T dim,
    real_T delta, real_T xk[5], real_T *fplus);

/* End of code generation (finDiffEvalAndChkErr.h) */
