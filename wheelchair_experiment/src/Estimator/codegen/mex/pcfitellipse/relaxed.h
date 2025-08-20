/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * relaxed.h
 *
 * Code generation for function 'relaxed'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void relaxed(const emlrtStack *sp, const real_T Hessian[25],
             const real_T grad[8], j_struct_T *TrialState,
             c_struct_T *MeritFunction, f_struct_T *memspace,
             k_struct_T *WorkingSet, g_struct_T *QRManager,
             h_struct_T *CholManager, b_struct_T *QPObjective,
             m_struct_T *qpoptions);

/* End of code generation (relaxed.h) */
