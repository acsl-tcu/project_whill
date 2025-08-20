/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzlarf.h
 *
 * Code generation for function 'xzlarf'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
int32_T b_ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[27],
                 int32_T ia0);

void b_xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0,
              real_T tau, real_T C[36], int32_T ic0, real_T work[6]);

int32_T ilazlc(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[54],
               int32_T ia0);

int32_T ilazlr(const emlrtStack *sp, int32_T m, int32_T n, const real_T A[9],
               int32_T ia0);

void xzlarf(const emlrtStack *sp, int32_T m, int32_T n, int32_T iv0, real_T tau,
            real_T C[9], int32_T ic0, real_T work[3]);

/* End of code generation (xzlarf.h) */
