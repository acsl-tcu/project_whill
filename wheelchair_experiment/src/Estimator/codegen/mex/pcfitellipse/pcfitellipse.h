/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * pcfitellipse.h
 *
 * Code generation for function 'pcfitellipse'
 *
 */

#pragma once

/* Include files */
#include "pcfitellipse_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void pcfitellipse(pcfitellipseStackData *SD, const emlrtStack *sp,
                  const real_T points_data[], const int32_T points_size[2],
                  const real_T a0[5], real_T sampleSize, real_T maxDistance,
                  const real_T A[5], real_T B, const real_T lb[5],
                  const real_T ub[5], real_T Num, real_T CNum,
                  const real_T Pbar[36], const real_T c[30], const real_T R[25],
                  real_T MD_threshold, real_T MSANum, const real_T Xhbar[6],
                  real_T eta, real_T Y[5], real_T inlier_data[],
                  int32_T inlier_size[2], real_T *SBreakFlag, real_T *MD,
                  real_T S_final[25]);

void pcfitellipse_anonFcn2(pcfitellipseStackData *SD, const emlrtStack *sp,
                           const real_T a0[5], const real_T A[5], real_T B,
                           const real_T lb[5], const real_T ub[5],
                           const real_T nonlcon_workspace_COG_init[2],
                           const real_T points_data[],
                           const int32_T points_size[2], real_T varargout_1[5]);

real_T pcfitellipse_anonFcn2_anonFcn1(const emlrtStack *sp,
                                      const real_T points_data[],
                                      const int32_T points_size[2],
                                      const real_T a[5]);

int32_T pcfitellipse_anonFcn3(const emlrtStack *sp, const real_T model[5],
                              const real_T points_data[],
                              const int32_T points_size[2],
                              real_T varargout_1_data[]);

boolean_T pcfitellipse_anonFcn4(const emlrtStack *sp, const real_T Pbar[36],
                                const real_T c[30], const real_T R[25],
                                const real_T Yhbar[5], real_T MD_threshold,
                                const real_T model_data[], int32_T model_size);

/* End of code generation (pcfitellipse.h) */
