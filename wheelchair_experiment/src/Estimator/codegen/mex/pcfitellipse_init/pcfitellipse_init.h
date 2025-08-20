/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse_init.h
 *
 * Code generation for function 'pcfitellipse_init'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_init_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T c_pcfitellipse_init_anonFcn1_an(const emlrtStack *sp,
                                       const real_T points_data[],
                                       const int32_T points_size[2],
                                       const real_T a[5]);

void pcfitellipse_init(pcfitellipse_initStackData *SD, const emlrtStack *sp,
                       const real32_T x_data[], const int32_T x_size[1],
                       const real32_T y_data[], const int32_T y_size[1],
                       const real_T a0[5], real_T sampleSize,
                       real_T maxDistance, const real_T A[5], real_T B,
                       const real_T lb[5], const real_T ub[5], real_T Num,
                       real_T CNum, real_T modelRANSAC_data[],
                       int32_T modelRANSAC_size[2], real_T inlier_data[],
                       int32_T inlier_size[2]);

void pcfitellipse_init_anonFcn1(const emlrtStack *sp, const real_T a0[5],
                                const real_T A[5], real_T B, const real_T lb[5],
                                const real_T ub[5], const real_T points_data[],
                                const int32_T points_size[2],
                                real_T varargout_1[5]);

int32_T pcfitellipse_init_anonFcn2(const emlrtStack *sp, const real_T model[5],
                                   const real_T points_data[],
                                   const int32_T points_size[2],
                                   real_T varargout_1_data[]);

/* End of code generation (pcfitellipse_init.h) */
