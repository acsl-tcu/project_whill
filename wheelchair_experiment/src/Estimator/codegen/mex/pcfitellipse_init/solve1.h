/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * solve1.h
 *
 * Code generation for function 'solve1'
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
void b_solve(const emlrtStack *sp, const f_struct_T *obj, real_T rhs[7]);

void c_solve(const emlrtStack *sp, const f_struct_T *obj, real_T rhs[91]);

/* End of code generation (solve1.h) */
