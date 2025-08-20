/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * sort.h
 *
 * Code generation for function 'sort'
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
void b_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void c_sort(const emlrtStack *sp, emxArray_uint32_T *x);

void d_sort(const emlrtStack *sp, uint32_T x[20]);

void e_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void f_sort(const emlrtStack *sp, emxArray_real_T *x, emxArray_int32_T *idx);

void g_sort(const emlrtStack *sp, real_T x_data[], int32_T x_size[2],
            int32_T idx_data[], int32_T idx_size[2]);

void sort(const emlrtStack *sp, emxArray_uint32_T *x);

/* End of code generation (sort.h) */
