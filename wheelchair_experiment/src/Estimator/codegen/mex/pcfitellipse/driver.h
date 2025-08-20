/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * driver.h
 *
 * Code generation for function 'driver'
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
void driver(const emlrtStack *sp, const real_T H[25], const real_T f[8],
            j_struct_T *solution, f_struct_T *memspace, k_struct_T *workingset,
            g_struct_T *qrmanager, h_struct_T *cholmanager,
            b_struct_T *objective, m_struct_T *options,
            int32_T runTimeOptions_MaxIterations);

/* End of code generation (driver.h) */
