/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * msac.h
 *
 * Code generation for function 'msac'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_internal_types.h"
#include "pcfitellipse_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
boolean_T msac(pcfitellipseStackData *SD, const emlrtStack *sp,
               const real_T allPoints_data[], const int32_T allPoints_size[2],
               real_T params_sampleSize, real_T params_maxDistance,
               real_T params_confidence, real_T params_maxNumTrials,
               real_T params_maxSkipTrials,
               const real_T funcs_fitFunc_workspace_a0[5],
               const real_T funcs_fitFunc_workspace_A[5],
               real_T funcs_fitFunc_workspace_B,
               const real_T funcs_fitFunc_workspace_lb[5],
               const real_T funcs_fitFunc_workspace_ub[5],
               const real_T c_funcs_fitFunc_workspace_nonlc[2],
               const e_struct_T *funcs_checkFunc_workspace,
               real_T bestModelParams_data[], int32_T bestModelParams_size[2],
               boolean_T inliers_data[], int32_T *inliers_size,
               boolean_T *reachedMaxSkipTrials);

/* End of code generation (msac.h) */
