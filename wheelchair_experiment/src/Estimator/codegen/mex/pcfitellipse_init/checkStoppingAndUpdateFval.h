/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * checkStoppingAndUpdateFval.h
 *
 * Code generation for function 'checkStoppingAndUpdateFval'
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
void checkStoppingAndUpdateFval(const emlrtStack *sp,
                                int32_T *activeSetChangeID, const real_T f[7],
                                h_struct_T *solution, d_struct_T *memspace,
                                const struct_T *objective,
                                i_struct_T *workingset, e_struct_T *qrmanager,
                                real_T options_ObjectiveLimit,
                                int32_T runTimeOptions_MaxIterations,
                                boolean_T updateFval);

/* End of code generation (checkStoppingAndUpdateFval.h) */
