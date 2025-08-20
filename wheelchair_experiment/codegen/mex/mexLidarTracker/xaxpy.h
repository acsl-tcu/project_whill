/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * xaxpy.h
 *
 * Code generation for function 'xaxpy'
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
void b_xaxpy(int32_T n, real32_T a, int32_T ix0, real32_T y[9], int32_T iy0);

void c_xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[36], int32_T iy0);

void d_xaxpy(int32_T n, real_T a, const real_T x[36], int32_T ix0, real_T y[6],
             int32_T iy0);

void e_xaxpy(int32_T n, real_T a, const real_T x[6], int32_T ix0, real_T y[36],
             int32_T iy0);

void f_xaxpy(real_T a, const real_T x[9], int32_T ix0, real_T y[3]);

void g_xaxpy(real_T a, const real_T x[3], real_T y[9], int32_T iy0);

void h_xaxpy(real32_T a, const real32_T x[9], int32_T ix0, real32_T y[3]);

void i_xaxpy(real32_T a, const real32_T x[3], real32_T y[9], int32_T iy0);

void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[9], int32_T iy0);

/* End of code generation (xaxpy.h) */
