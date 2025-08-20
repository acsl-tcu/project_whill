/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * soc.h
 *
 * Code generation for function 'soc'
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
boolean_T soc(const emlrtStack *sp, const real_T Hessian[25],
              const real_T grad[7], h_struct_T *TrialState,
              d_struct_T *memspace, i_struct_T *WorkingSet,
              e_struct_T *QRManager, f_struct_T *CholManager,
              struct_T *QPObjective, const k_struct_T *qpoptions);

/* End of code generation (soc.h) */
