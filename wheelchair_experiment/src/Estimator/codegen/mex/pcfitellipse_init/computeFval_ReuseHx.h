/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * computeFval_ReuseHx.h
 *
 * Code generation for function 'computeFval_ReuseHx'
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
real_T computeFval_ReuseHx(const emlrtStack *sp, const struct_T *obj,
                           real_T workspace[91], const real_T f[7],
                           const real_T x[7]);

/* End of code generation (computeFval_ReuseHx.h) */
