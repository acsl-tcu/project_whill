/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * reshapeSizeChecks.c
 *
 * Code generation for function 'reshapeSizeChecks'
 *
 */

/* Include files */
#include "reshapeSizeChecks.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void b_num2cell_vector(const int32_T num[4], int32_T cell_vector[4])
{
  cell_vector[0] = 3;
  cell_vector[1] = 1;
  cell_vector[2] = num[2];
  cell_vector[3] = num[3];
}

void c_num2cell_vector(const int32_T num[4], int32_T cell_vector[4])
{
  cell_vector[0] = 1;
  cell_vector[1] = 1;
  cell_vector[2] = num[2];
  cell_vector[3] = num[3];
}

void num2cell_vector(const int32_T num[4], int32_T cell_vector[4])
{
  cell_vector[0] = 2;
  cell_vector[1] = 1;
  cell_vector[2] = num[2];
  cell_vector[3] = num[3];
}

/* End of code generation (reshapeSizeChecks.c) */
