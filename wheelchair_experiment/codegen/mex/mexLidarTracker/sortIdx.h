/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sortIdx.h
 *
 * Code generation for function 'sortIdx'
 *
 */

#pragma once

/* Include files */
#include "mexLidarTracker_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void b_sortIdx(const emlrtStack *sp, emxArray_uint32_T *x,
               emxArray_int32_T *idx);

void c_merge(const emlrtStack *sp, int32_T idx[20], uint32_T x[20],
             int32_T offset, int32_T np, int32_T nq, int32_T iwork[20],
             uint32_T xwork[20]);

void c_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void d_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void e_sortIdx(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void merge_block(const emlrtStack *sp, emxArray_int32_T *idx,
                 emxArray_uint32_T *x, int32_T offset, int32_T n,
                 int32_T preSortLevel, emxArray_int32_T *iwork,
                 emxArray_uint32_T *xwork);

void sortIdx(const emlrtStack *sp, const emxArray_int32_T *x,
             emxArray_int32_T *idx);

/* End of code generation (sortIdx.h) */
