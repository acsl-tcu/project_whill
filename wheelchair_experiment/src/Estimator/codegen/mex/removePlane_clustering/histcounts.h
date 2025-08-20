/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * histcounts.h
 *
 * Code generation for function 'histcounts'
 *
 */

#pragma once

/* Include files */
#include "removePlane_clustering_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_histcounts(const emlrtStack *sp, const emxArray_real_T *x,
                  const real_T varargin_1[1025], real_T n[1024],
                  emxArray_real_T *bin);

void histcounts(const emlrtStack *sp, const emxArray_real_T *x,
                const real_T varargin_1_data[], real_T n_data[],
                int32_T n_size[2], emxArray_real_T *bin);

/* End of code generation (histcounts.h) */
