/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * step.h
 *
 * Code generation for function 'step'
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
void step(const emlrtStack *sp, b_struct_T *stepFlags, real_T Hessian[25],
          const real_T lb[5], const real_T ub[5], f_struct_T *TrialState,
          i_struct_T *MeritFunction, c_struct_T *memspace,
          g_struct_T *WorkingSet, j_struct_T *QRManager,
          k_struct_T *CholManager, l_struct_T *QPObjective,
          m_struct_T *qpoptions);

/* End of code generation (step.h) */
