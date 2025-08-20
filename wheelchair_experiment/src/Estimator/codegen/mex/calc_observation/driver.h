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
#include "calc_observation_internal_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void driver(const emlrtStack *sp, const real_T H[25], const real_T f[8],
            f_struct_T *solution, c_struct_T *memspace, g_struct_T *workingset,
            j_struct_T *qrmanager, k_struct_T *cholmanager,
            l_struct_T *objective, const m_struct_T *options,
            const m_struct_T *runTimeOptions);

/* End of code generation (driver.h) */
