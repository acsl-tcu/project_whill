/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver1.h
 *
 * Code generation for function 'driver1'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_init_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_driver(const emlrtStack *sp, real_T bineq, const real_T lb[5],
              const real_T ub[5], h_struct_T *TrialState,
              b_struct_T *MeritFunction,
              const i_coder_internal_stickyStruct *FcnEvaluator,
              j_struct_T *FiniteDifferences, d_struct_T *memspace,
              i_struct_T *WorkingSet, real_T Hessian[25], e_struct_T *QRManager,
              f_struct_T *CholManager, struct_T *QPObjective);

/* End of code generation (driver1.h) */
