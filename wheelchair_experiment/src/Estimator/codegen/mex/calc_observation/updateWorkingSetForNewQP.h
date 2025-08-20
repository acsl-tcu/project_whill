/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * updateWorkingSetForNewQP.h
 *
 * Code generation for function 'updateWorkingSetForNewQP'
 *
 */

#pragma once

/* Include files */
#include "calc_observation_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                                g_struct_T *WorkingSet, const real_T cIneq[2],
                                int32_T mLB, const real_T lb[5], int32_T mUB,
                                const real_T ub[5], int32_T mFixed);

void updateWorkingSetForNewQP(const emlrtStack *sp, const real_T xk[5],
                              g_struct_T *WorkingSet, const real_T cIneq[2],
                              int32_T mLB, const real_T lb[5], int32_T mUB,
                              const real_T ub[5], int32_T mFixed);

/* End of code generation (updateWorkingSetForNewQP.h) */
