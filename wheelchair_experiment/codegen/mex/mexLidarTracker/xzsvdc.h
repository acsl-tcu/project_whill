/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xzsvdc.h
 *
 * Code generation for function 'xzsvdc'
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
void b_xzsvdc(const emlrtStack *sp, real32_T A[9], real32_T S[3]);

void c_xzsvdc(const emlrtStack *sp, real_T A[36], real_T U[36], real_T S[6],
              real_T V[36]);

void d_xzsvdc(const emlrtStack *sp, real_T A[9], real_T U[9], real_T S[3],
              real_T V[9]);

void xzsvdc(const emlrtStack *sp, real_T A[9], real_T S[3]);

/* End of code generation (xzsvdc.h) */
